#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
#include<unistd.h>


void sequential(int arr[], int n){
    int isSorted = 1;
    clock_t start, end;

    start = clock();

    while(isSorted != 0){
        isSorted = 0;

        for(int i=0; i<n-2; i+=2){
            if(arr[i] > arr[i+2]){
                int temp = arr[i];
                arr[i] = arr[i+2];
                arr[i+2] = temp;
                isSorted = 1;
            }
        }

        for(int i=1; i<n-2; i+=2){
            if(arr[i] > arr[i+2]){
                int temp = arr[i];
                arr[i] = arr[i+2];
                arr[i+2] = temp;
                isSorted = 1;
            }
        }
    }
    end = clock();

    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time required for sequential sorting for %d Items : %f \n", n, time_taken);
    // for(int i=0; i<n; i++)
        // printf("%d ", arr[i]);
}




void parallel_sorting(int arr[], int n){
     int isSorted = 1;
    clock_t start, end;

    start = clock();
    while(isSorted != 0){
        isSorted = 0;
        #pragma omp parallel
        {
            #pragma omp for
            for(int i=0; i<n-2; i+=2){
                if(arr[i] > arr[i+2]){
                    int temp = arr[i];
                    arr[i] = arr[i+2];
                    arr[i+2] = temp;
                    isSorted = 1;
                }
            }
        }
        #pragma omp parallel
        {
            #pragma omp for
            for(int i=1; i<n-2; i+=2){
            if(arr[i] > arr[i+2]){
                int temp = arr[i];
                    arr[i] = arr[i+2];
                    arr[i+2] = temp;
                    isSorted = 1;
            }
        }
        }
    }
    end = clock();

    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time required for Parallel Sorting for %d Items : %f \n", n, time_taken);
    // for(int i=0; i<n; i++)
        // printf("%d ", arr[i]);
}

int main(){
    int arr[10000],arr1[10000];
    
    for(int i=0; i<10000; i++){
        arr[i] = rand();
    }
    for(int i=0; i<10000; i++){
        arr1[i] = rand();
    }
    parallel_sorting(arr1, 10000);

    sequential(arr, 10000);


return 0;
}


// OUTPUT
// C:\Users\Shradha\Downloads>gcc odd_even_sort.c
// C:\Users\Shradha\Downloads>a
// Time required for Parallel Sorting for 10000 Items : 0.269000
// Time required for sequential sorting for 10000 Items : 0.263000