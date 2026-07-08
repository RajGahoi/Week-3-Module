#include <iostream>
#include <vector>
using namespace std;

// Partition for Descending Order
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] > pivot)   // Descending Order
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Recursive Quick Sort
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";

    long long totalSum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        totalSum += arr[i];
    }

    // Sort in Descending Order
    quickSort(arr, 0, n - 1);

    // Print Sorted Array
    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Top 5 Values
    cout << "\nTop 5: ";

    long long top5Sum = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
        top5Sum += arr[i];
    }

    double top5Average = top5Sum / 5.0;

    cout << "\nAverage of Top 5: " << top5Average;

    // Overall Average
    double overallAverage = totalSum / (double)n;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > overallAverage)
        {
            count++;
        }
    }

    cout << "\nValues Above Overall Average: " << count;

    return 0;
}