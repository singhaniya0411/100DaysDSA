/*
    Title: Find Majority Elements in an Array Using Hash Map
    Description:
        This program finds all the majority elements in an array using an unordered map (hash map).
        A majority element is an element that appears more than n/3 times in the array, 
        where n is the size of the array. The program counts the occurrences of each element 
        and then identifies elements that meet the majority condition.

    Input:
        - Size of the array (n)
        - Array elements (n integers)

    Output:
        - The majority elements in the array (if any)
        - If no majority element exists, the output will be empty

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<unordered_map>
using namespace std;

// Function to find and print majority elements using a hash map
void find_majority(int arr[], int n) {
    unordered_map<int, int> occurence; // Hash map to store element counts
    // Count occurrences of each element
    for (int i = 0; i < n; i++) {
        if (occurence.find(arr[i]) != occurence.end()) {
            occurence[arr[i]] += 1; // Increment the count if element is already present
        } else {
            occurence.insert({arr[i], 1}); // Otherwise, initialize count to 1
        }
    }

    // Print majority elements (appears more than n/3 times)
    cout << "\n\nThe majority elements in entered array: ";
    for (const auto& pair : occurence) {
        if (pair.second > (n / 3)) { // Majority condition
            cout << pair.first << " "; // Print majority element
        }
    }
}

// Helper function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << " , "; // Separate elements with commas
        }
    }
    cout << "\n\n";
}

int main() {
    int size;

    // Input: Size of the array
    cout << "\nEnter the size of array: ";
    cin >> size;

    // Input: Array elements
    int arr[size];
    cout << "\nEnter the elements of array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Output: Array elements
    cout << "\nArray: ";
    printArray(arr, size);

    // Output: Majority elements
    find_majority(arr, size);
    cout << "\n";

    return 0;
}
