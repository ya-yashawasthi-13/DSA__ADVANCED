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

void insertionsort(int arr[], int n)
{
    int key = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[5] = {6, 8, 11, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    insertionsort(arr, n);
    print(arr, n);
    return 0;
}