/*
    Title: 
        Maximum Profit from Stock Prices
    Description:
        This program calculates the maximum profit that can be obtained 
        by performing multiple buy-sell transactions on given stock prices.
        The approach assumes you can buy and sell on the same day and 
        there are no restrictions on the number of transactions.

    Input:
        - Size of the array (n)
        - Array of stock prices (n integers)

    Output:
        - The sequence of stock prices
        - The maximum profit that can be obtained

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Function to calculate the maximum profit
int maximum_profit(int arr[], int size) {
    int max_profit = 0;
    for (int i = 0; i < size - 1; i++) {
        // Add the profit for every upward slope
        if (arr[i] <= arr[i + 1]) {
            max_profit += arr[i + 1] - arr[i];
        }
    }
    cout << "\nMaximum profit for given stock price is: ";
    return max_profit;
}

// Helper function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        cout << ((i == size - 1) ? "\n" : " , ");
    }
}

int main() {
    int size;

    // Input: Size of the array
    cout << "Enter the size of array: ";
    cin >> size;

    // Input: Stock prices
    int arr[size];
    cout << "Enter the elements of array (stock prices): ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Output: Stock prices
    cout << "The price of stocks are: ";
    printArray(arr, size);

    // Calculate and display the maximum profit
    cout << maximum_profit(arr, size) << "\n";

    return 0;
}
