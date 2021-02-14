#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
#include<unistd.h>


void sequential_sum(int *a, int *b, int *c, int n){
    clock_t start, end;
    start = clock();
        for(int i=0; i<n; i++){
            c[i] = a[i] + b[i];
        }

    /*for(int i=0; i<n; i++){
        printf("%d ", c[i]);
    }
    */
    end = clock();

    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\t\tTime Taken for parallel computation : %f \n", time_taken);

   
}

void parallel_sum(int *a, int *b, int *c, int n){
    clock_t start, end;
    start = clock();
    #pragma omp parallel
    {
        #pragma omp for
        for(int i=0; i<n; i++){
            c[i] = a[i] + b[i];
        }
    }

    // for(int i=0; i<n; i++){
    //     printf("%d ", c[i]);
    // }
    end = clock();

    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\t\tTime Taken for serial computation : %f \n", time_taken);

   
}

int main(){
    int *a, *b, *c, *d;

    int n = 1000000;
    int total_thread = 4;

    a = (int *) malloc(sizeof(int)*n);
    b = (int *) malloc(sizeof(int)*n);
    c = (int *) malloc(sizeof(int)*n);
    d = (int *) malloc(sizeof(int)*n);
    
    for(int i=0; i<n; i++){
        a[i] = rand();
    }
    for(int i=0; i<n; i++){
        b[i] = rand();
    }
    
    /* printf("\nFirst Array : ");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    printf("\n");
    printf("\nSecond Array : ");
    for(int i=0; i<n; i++){
        printf("%d ", b[i]);
    }
    */
    printf("\n");
    
    printf("\n  Serial : ");
    parallel_sum(a, b, c, n);
    printf("\nParallel :");
    sequential_sum(a, b, c, n);

}