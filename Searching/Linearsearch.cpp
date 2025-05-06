// for both sorted and unsorted data
// time complexity - 0(n)

#include <iostream>
using namespace std;

void linearsearch(int arr[], int n)
{
    int key;
    cout << "Enter element to search : ";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index " << i + 1 << endl;
        }
    }
}
    int main()
    {

        int arr[] = {2, 3, 6, 9, 6, 8};
        int n = sizeof(arr) / sizeof(arr[0]);
        linearsearch(arr, n);
    }