#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);

    int w[32][32];
    printf("\nEnter the weight matrix(999 for infinity):\n");

    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&w[i][j]);
        }
    }

    int d[32][32];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            d[i][j]=w[i][j];

        }
    }

    int k;
    for(k=0;k<n;k++){
        for(j=0;j<n;j++){
            for(i=0;i<n;i++){
                d[i][j]=fmin(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    
    printf("\nAnswer:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d\t",d[i][j]);
        printf("\n");
    }
    return 0;
}
