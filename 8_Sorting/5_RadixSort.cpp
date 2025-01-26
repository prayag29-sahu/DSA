#include <iostream>
using namespace std;

// Function to get the maximum value in an array
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Function to perform counting sort based on a specific digit
void countingSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains the actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main function to implement radix sort
void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead of
    // passing the digit number, exp is passed. exp is 10^i
    // where i is the current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
