#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Sort items by decreasing value/weight ratio (Bubble Sort)
void sortItems(struct Item items[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Fractional Knapsack function
float fractionalKnapsack(struct Item items[], int n, int capacity) {
    float totalProfit = 0.0;

    for(int i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            // Take full item
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take fraction
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter value and weight of each item:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort items based on ratio
    sortItems(items, n);

    float maxProfit = fractionalKnapsack(items, n, capacity);

    printf("Maximum profit = %.2f\n", maxProfit);

    return 0;
}
