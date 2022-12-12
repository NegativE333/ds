                                                                           // Code for quick sort
#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)                                               // Function for swapping the array elements                          
        {
            int temp;
            temp = *a;
            *a = *b;
            *b = temp;
        }

int Partition(int a[], int lowerIndex, int upperIndex)                   // Partitioning of the array
        {
            int pivot, index, i;
            index = lowerIndex;
            pivot = upperIndex;
            for (i = lowerIndex; i < upperIndex; i++)
            {
                    if (a[i] < a[pivot])
                    {
                        swap(&a[i], &a[index]);
                        index++;
                    }
            }
            swap(&a[pivot], &a[index]);
            return index;
    }

int QuickSort(int a[], int lowerIndex, int upperIndex)              
    {
            int pindex;
            if (lowerIndex < upperIndex)
            {
                pindex = Partition(a, lowerIndex, upperIndex);
                QuickSort(a, lowerIndex, pindex - 1);                             // Recursively calling function
                QuickSort(a, pindex + 1, upperIndex);
            }
            return 0;
    }
int main()
    {
        int n, i;
      printf("\nEnter the number of data elements to be sorted: ");        // Taking size of array as input
      scanf("%d", &n);
        int arr[n];
            for (i = 0; i < n; i++)
                {
                    printf("Enter elements %d: ", i);
                    scanf("%d", &arr[i]);
                }
        QuickSort(arr, 0, n - 1);
        printf("\nSorted Data ");
        for (i = 0; i < n; i++)
            printf(" %d", arr[i]);
        return 0;
    }
