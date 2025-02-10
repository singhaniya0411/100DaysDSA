/*
    Title: H-Index Calculation (Sorting Approach)
    Description:
        - This program calculates the **H-Index** of a researcher based on citation counts.
        - **H-Index Definition**: A researcher has an H-Index of `h` if they have at least `h` papers with `h` or more citations.

    Approach:
        - Sort the citation array in **descending order**.
        - Traverse the sorted array and find the maximum `h` where `citations[h] ≥ h`.

    Time Complexity:
        - **O(n log n)** (Due to sorting)

    Space Complexity:
        - **O(1)** (No extra space used apart from variables)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Custom comparator function for sorting in descending order
bool comp(int a, int b)
{
    return a > b;
}

// Function to compute the H-Index using sorting
int highest_citation_index(int arr[], int size)
{
    // Step 1: Sort the array in descending order
    sort(arr, arr + size, comp);

    // Step 2: Find the highest index where citation count ≥ index
    int idx = 0;
    while (idx < size && arr[idx] > idx)
    {
        idx++;
    }

    return idx; // The computed H-Index
}

int main()
{
    int size;

    // Input: Get the number of papers
    cout << "Enter the number of papers: ";
    cin >> size;

    int arr[size];

    // Input: Get the citation count for each paper
    cout << "Enter the citation counts: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Compute the H-Index
    int h_index = highest_citation_index(arr, size);

    // Output the result
    cout << "The H-Index of the researcher is: " << h_index << endl;

    return 0;
}
