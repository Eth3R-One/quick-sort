#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
    int i, j, temp;
    int pivot = arr[high];
    for (i = low - 1, j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            ++i;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[high];
    arr[high] = arr[++i];
    arr[i] = temp;

    return i;
}

void quick_sort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int p = partition(arr, low, high);
    quick_sort(arr, low, p - 1);
    quick_sort(arr, p + 1, high);
}

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    cout << "Before :" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    quick_sort(arr, 0, 7);
    cout << "\nAfter :" << endl;

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}