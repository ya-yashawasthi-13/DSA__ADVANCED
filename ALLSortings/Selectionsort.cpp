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

void selectionsort(int arr[], int n)
{
    int indexmin = 0, temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        indexmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexmin])
            {
                indexmin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexmin];
        arr[indexmin] = temp;
    }
}

int main()
{
    int arr[5] = {5, 8, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    selectionsort(arr, n);
    print(arr, n);
    return 0;
}