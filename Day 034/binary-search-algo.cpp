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

    Author: Vishal
*/

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm> // For max_element()
using namespace std;

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


int findPages(int arr[], int size, int k) {
    if (k > size) return -1; // If students > books, return impossible case

    int low = *max_element(arr, arr + size); // Max pages (minimum limit)
    int high = reduce(arr,arr+size);
    int result = -1;
    
    while(low<=high){
        int mid=(low+high)/2;
        if(check(arr,k,mid,size)){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
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
