#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    
    sort(arr, arr + n);

    // Initialize the difference between the largest and smallest heights
    int diff = arr[n - 1] - arr[0];

    // Set the smallest and largest values after adjusting heights
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;

    // Ensure smallest is always the minimum and largest is always the maximum
    if (smallest > largest) {
        swap(smallest, largest);
    }

    // Traverse through the array and minimize the difference
    for (int i = 1; i < n - 1; i++) {
        int subtract = arr[i] - k;
        int add = arr[i] + k;

        // Ignore negative heights
        if (subtract < 0) continue;

        // Update smallest and largest values
        int newSmallest = min(smallest, subtract);
        int newLargest = max(largest, add);

        // Update the difference
        diff = min(diff, newLargest - newSmallest);
    }

    return diff;
}

int main() {
    int arr[] = {1, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "Minimum difference: " << getMinDiff(arr, n, k) << endl;

    return 0;
}
