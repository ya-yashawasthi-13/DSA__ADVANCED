// for sorted data
// tome complexity - 0(log n)

#include <iostream>
using namespace std;

void binarysearch(int arr[], int n)
{
    int key;
    cout << "Enter element to search : ";
    cin >> key;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            cout << "Element found at index " << mid + 1 << endl;
            break;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}

int main()
{
    int arr[] = {2, 3, 5, 6, 7, 9, 10, 12, 17, 33, 44, 66, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    binarysearch(arr, n);
}
