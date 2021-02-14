/*
Name : Vasu Kalariya
Roll : PB32
Quick Sort
*/

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int partition(int arr[], int low, int high)
{
	int i, j, temp, pivot;
	pivot = arr[low];
	i = low+1;
	j = high;
	while(1)
	{
		while(i<high && pivot>=arr[i])
		{
			i++;
		}
		while(pivot<arr[j])
		{
			j--;
		}
		if(i<j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else
		{
			temp = arr[low];
			arr[low] = arr[j];
			arr[j] = temp;
			return j;
		}
	}
}

void quicksort(int arr[], int low, int high)
{
	int key;
	if(low<high)
	{
		key = partition(arr, low, high);
		quicksort(arr, low, key-1);
		quicksort(arr, key+1, high);
	}
}

void parallel_quicksort(int arr_parallel[], int n)
{
	double start, end, total;
	int i;
	int key = partition(arr_parallel, 0, n-1);
	start = omp_get_wtime();
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			quicksort(arr_parallel, 0, key-1);
		}

		#pragma omp section
		{
			quicksort(arr_parallel, key+1, n-1);
		}
	}

	end = omp_get_wtime();
	total = end-start;
	printf("Time taken for Parallel Sort: %f seconds\n", total);
}

int main()
{
	int i, n;

        printf("Enter the size of array: ");
		scanf("%d", &n);
		int arr_serial[n], arr_parallel[n];
		for(i=0; i<n; i++)
		{
			arr_serial[i] = rand()%INT_MAX;
			arr_parallel[i] = arr_serial[i];
		}
		clock_t t;
		t = clock();
		quicksort(arr_serial, 0, n-1);
		t = clock()-t;
		double time_taken = ((double)t)/CLOCKS_PER_SEC;
		printf("Time Taken for Sequential Sort: %f seconds\n", time_taken);

		parallel_quicksort(arr_parallel, n);

	return 0;
}

