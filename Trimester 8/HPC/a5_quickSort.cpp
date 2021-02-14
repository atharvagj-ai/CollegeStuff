#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[100], int l, int r){
    int piv= arr[l];
    int i = l, j = r;
    while(i<j){
        while(arr[i]<=piv)
            i++;
        while(arr[j] > piv)
            j--;
        if(i < j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void sequential_quickSort(int arr[100], int l, int r){
    int p;
    if(l<r){
        p = partition(arr, l, r);
            sequential_quickSort(arr, l, p-1);
            sequential_quickSort(arr, p+1, r);
    }
    
}

void quickSort(int arr[100], int l, int r){
    int p;
    if(l<r){
        p = partition(arr, l, r);
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                quickSort(arr, l, p-1);
            }
            #pragma omp section
            {
                quickSort(arr, p+1, r);
            }
        }
    }
    
}

int main(){
    int arr[1000], arr2[1000], n;
    cin>>n;
    // cout<<"Enter the size of array"<<endl;
    // cin>>n;
    // cout<<"Enter the Elements"<<endl;
    // for(int i=0; i<n; i++)
    //     cin>>arr[i];
    for(int i=0; i<n; i++){
        arr[i] = 0;
        arr2[i] = 0;
    }
    for(int i=0; i<n; i++){
        arr[i] = rand();
        arr2[i] = rand();
    }

    cout<<"Sorted Array"<<endl;
    clock_t start, end, start1, end1;

    //Sequential
    cout<<"Sequential :";
    start1 = clock();  
    sequential_quickSort(arr2, 0, n-1);

    end1 = clock();
    double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
    cout<<"Executing Time "<<time_taken1<<setprecision(7)<<endl;
    
    for(int i=0; i<n; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    // Parallel
    cout<<"Parallel :";
    start = clock();  
    quickSort(arr, 0, n-1);

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout<<"Executing Time "<<time_taken<<setprecision(5)<<endl;
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
