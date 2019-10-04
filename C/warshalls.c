#include<Stdio.h>
#define size 21

void main()
{
    int a[size][size], i, j, k, n;
    printf("Enter the order of matrix\n");
    scanf("%d",&n);
    printf("Enter the elements in the matrix\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);

    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(a[i][j]==1 || (a[i][k]==1 && a[k][j]==1))
                {
                    a[i][j]=1;
                }
            }
        }
    }

    printf("Tranisitve closure : \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
