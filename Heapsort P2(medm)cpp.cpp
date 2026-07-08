#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Heapify Function
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort Function
void heapSort(vector<int>& arr, int n)
{
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // One by one extract elements
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";

    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    // Heap Sort
    heapSort(arr, n);

    // Print Sorted Array
    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Fastest
    cout << "\nFastest: " << arr[0];

    // Slowest
    cout << "\nSlowest: " << arr[n - 1];

    // Average
    double average = sum / n;
    cout << fixed << setprecision(2);
    cout << "\nAverage: " << average;

    // Count Faster Than Average
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < average)
        {
            count++;
        }
    }

    cout << "\nCases Faster Than Average: " << count;

    // Percentage
    double percentage = (count * 100.0) / n;

    cout << "\nPercentage: " << percentage << "%";

    return 0;
}