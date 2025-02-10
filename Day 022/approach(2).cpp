/*
    Title: H-Index Calculation (O(n) Algorithm)
    Description:
        - This program computes the **H-Index** in **O(n) time**.
        - Uses a **frequency array** instead of sorting.

    Approach:
        - Build a frequency array `freq[]` to count citations.
        - Iterate from `size` down to 0 to accumulate citations and find `h`.

    Time Complexity:
        - O(n), as we only traverse the array twice.

    Space Complexity:
        - O(n), due to the frequency array.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to compute H-Index in O(n) time
int compute_h_index(int arr[], int size)
{
    vector<int> freq(size + 1, 0); // Frequency array of size (size + 1)

    // Step 1: Populate frequency array
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= size)
        {
            freq[size]++; // Count all citations ≥ size as size
        }
        else
        {
            freq[arr[i]]++; // Count exact citations
        }
    }

    // Step 2: Find H-Index
    int count = 0; // Total papers counted
    for (int h = size; h >= 0; h--)
    {                     // Traverse from high to low
        count += freq[h]; // Accumulate paper count
        if (count >= h)
            return h; // Condition for H-Index met
    }

    return 0; // Edge case, should never reach
}

int main()
{
    int size;
    cout << "Enter the size of the citation array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the citation array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int h_index = compute_h_index(arr, size);
    cout << "The H-Index of this array: " << h_index << endl;

    return 0;
}
