#include<stdio.h>
#include<time.h>

int h[1000000];

void heapify(int h[], int n)
{
    int i, k, j, heap, v;
    for(i=n/2; i>=1; i--)
    {
        k=i;
        v=h[k];
        heap = 0;
        while(!heap && (2*k)<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(h[j]<h[j+1])
                {
                    j=j+1;
                }
            }
            if(v>=h[j])
            {
                heap = 1;
            }
            else
            {
                h[k] = h[j];
                k=j;
            }
        }
        h[k]=v;
    }
}

void main()
{
    int i, n, size, t, temp;
    clock_t start, end;
    double total;
    // printf("Enter the number of elements\n");
    // scanf("%d",&n);
    // printf("Enter the elements\n");

    for( t=5000; t<=50000; t=t+5000)
    {
        n=t;
        for(i=1; i<=n; i++)
        {
            h[i] = rand();
        }

        start = clock();
        heapify(h, n);
        for(i=n; i>=1; i--)
        {
            temp = h[1];
            h[1] = h[i];
            h[i] = temp;
            size = i-1;
            heapify(h, size);
        }
        end = clock();

        total = (double)(end-start)/CLOCKS_PER_SEC;
        printf("Time taken for %d items = %lf\n", t, total);
    }


    // printf("Elements heapified :\n");
    // for(i=1; i<=n; i++)
    // {
    //     printf("%d\t",h[i]);
    // }



    // printf("Sorted elements: \n");
    // for(i=1; i<=n; i++)
    // {
    //     printf("%d\t",h[i]);
    // }
}
