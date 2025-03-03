/*
    Title: Allocate Minimum Number of Pages (Brute Force Approach)
    
    Problem Statement:
        - Given an array representing pages in 'N' books and 'K' students,
          allocate books to minimize the **maximum number of pages** a student gets.
        - A student must read **contiguous books**.

    Approach:
        1. **Iterate through possible maximum page limits** from max(arr) to sum(arr).
        2. **Use a helper function (`check`) to verify if books can be allocated under a given limit.**
        3. **Return the first possible maximum pages that satisfy the condition.**

    Time Complexity: **O(N²)** (since we check every page limit from max to sum).
    Space Complexity: **O(1)** (No extra space used).

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm> // For max_element()
using namespace std;

/**
 * @brief Checks if we can assign books such that no student gets more than 'pageLimit' pages.
 * 
 * @param arr Array of books with pages.
 * @param k Number of students.
 * @param pageLimit Maximum pages allowed per student.
 * @param size Number of books.
 * @return true if books can be allocated within the limit, false otherwise.
 */
bool check(int arr[], int k, int pageLimit, int size) {
    int count = 1;  // Number of students assigned
    int pageSum = 0;

    for (int i = 0; i < size; i++) {
        if (pageSum + arr[i] > pageLimit) {
            count++;       // Assign next student
            pageSum = arr[i];

            if (count > k) { // If students exceed 'K', return false
                return false;
            }
        } else {
            pageSum += arr[i];
        }
    }
    return true;
}

/**
 * @brief Finds the minimum maximum pages a student has to read (Brute Force).
 * 
 * @param arr Array of books with pages.
 * @param size Number of books.
 * @param k Number of students.
 * @return Minimum possible maximum pages.
 */
int findPages(int arr[], int size, int k) {
    if (k > size) return -1; // If students > books, return impossible case

    int minPageLimit = *max_element(arr, arr + size); // Max pages (minimum limit)
    
    // Calculate the sum of all elements manually (instead of accumulate)
    int maxPageLimit = 0;
    for (int i = 0; i < size; i++) {
        maxPageLimit += arr[i];
    }

    // Brute Force: Check all possible maximum limits
    for (int i = minPageLimit; i <= maxPageLimit; i++) {
        if (check(arr, k, i, size)) {
            return i; // Return the first valid answer
        }
    }

    return -1; // No valid assignment found
}

int main() {
    int size;
    cout << "Enter the number of books: ";
    cin >> size;
    int arr[size];

    // Taking input for pages in each book
    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the number of students: ";
    cin >> k;

    // Finding and displaying the minimum max pages
    int result = findPages(arr, size, k);
    if (result == -1) {
        cout << "Not possible to allocate books!" << endl;
    } else {
        cout << "Minimum possible maximum pages: " << result << endl;
    }
    return 0;
}
