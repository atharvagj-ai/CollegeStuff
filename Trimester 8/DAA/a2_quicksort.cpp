#include <bits/stdc++.h>
 
int partition(long long int arr[], long long int low, long long int high)
{
    long long int pivot = arr[high];
    long long int i = low - 1;
    for (long long int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}
 
void quicksort(long long int arr[], long long int low, long long int high)
{
    if (low < high)
    {
        long long int pi = partition(arr, low, high);
 
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
 
int main()
{
    long long int n;
    std::cout << "Enter the no. of elements : ";
    std::cin >> n;
    long long int arr[n];
    for (long long int i = 0; i < n; i++)
        std::cin >> arr[i];
    std::cout << "Array Before sorting "
              << "\n";
    for (long long int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    quicksort(arr, 0, n - 1);
    std::cout << "Array After sorting "
              << "\n";
    for (long long int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
 
    return 0;
}
