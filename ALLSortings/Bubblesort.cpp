// Analysis Criteria for Sorting Algoritm
// 1 - Time Complexity
// 2 - Space Complexity - Inplace Sorting Algorithm
// 3 - Stability
// 4 - Ineternal SA - ALl the data loaded in the memeory  External SA - All the data is not loaded in the memory
// 5 - Adaptive - Already sorted data takes less time
// 6 - Recursive/Non Recursive SA - Recursive if it uses recursion

/*BUBBLE SORT ->
Passes = n - 1
Worst case time complexity = 0(n^2)*/

// BUBBLE SORT
#include <iostream>
using namespace std;

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubblesort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // For no of passes
    {
        for (int j = 0; j < n - 1 - i; j++) // For no of comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bublesortt(int arr[], int n)
{
    int temp;
    int issorted = 1;
    for (int i = 0; i < n - 1; i++) // For  passes
    {
        issorted = 1;
        cout << "Working on pass number : " << i + 1 << endl;
        for (int j = 0; j < n - i - 1; j++) // For comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {2, 7, 4, 11, 9, 3};
    // int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printarr(arr, n);
    bubblesort(arr, n); // Normal Bubble sort
    printarr(arr, n);
    bublesortt(arr, n); // Optimized Bubble sort
    printarr(arr, n);
    return 0;
}
 