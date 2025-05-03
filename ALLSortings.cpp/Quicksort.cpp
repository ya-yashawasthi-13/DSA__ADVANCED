#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    // swap arr[low] and arr[j]
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int arr[], int low, int high)
{
    int partitionindex; // Index of the pivot after partition

    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        quicksort(arr, low, partitionindex - 1);  // sort left subarray
        quicksort(arr, partitionindex + 1, high); // sort right subarray
    }
}

int main()
{
    int arr[] = {5, 3, 7, 1, 5, 9, 2, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    quicksort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}

// 3, 5, 2, 13, 12, 3, 2, 13, 45
// 3, 2, 2, 13i, 12, 3j, 5, 13, 45
// 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3