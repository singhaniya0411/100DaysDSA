/*
    Title: Allocate Minimum Number of Pages (Binary Search Approach)
    
    Problem Statement:
        - Given an array representing pages in 'N' books and 'K' students,
          allocate books to minimize the **maximum number of pages** a student gets.
        - A student must read **contiguous books**.

    Approach:
        1. **Use Binary Search on the minimum maximum pages possible**.
        2. **Set `low = max(arr)`, `high = sum(arr)`, and find the minimum `mid` that works**.
        3. **Use a helper function (`check`) to verify if books can be allocated under `mid` pages**.
        4. **Optimize `high` to find the smallest valid solution**.

    Time Complexity: **O(N log M)** (binary search over `M = sum(arr) - max(arr)`).
    Space Complexity: **O(1)** (No extra space used).

    Author: Vishal
*/

#include <iostream>
#include <algorithm>  // max_element
#include <numeric>    // accumulate
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
 * @brief Finds the minimum maximum pages a student has to read (Binary Search Approach).
 * 
 * @param arr Array of books with pages.
 * @param size Number of books.
 * @param k Number of students.
 * @return Minimum possible maximum pages.
 */
int findPages(int arr[], int size, int k) {
    if (k > size) return -1; // If students > books, return impossible case

    int low = *max_element(arr, arr + size); // The minimum limit is the max single book size
    int high = accumulate(arr, arr + size, 0); // The maximum limit is the sum of all books
    int result = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(arr, k, mid, size)) {
            result = mid; // Store potential answer
            high = mid - 1; // Try for a better minimum
        } else {
            low = mid + 1; // Increase the limit
        }
    }
    
    return result;
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
