/*
    Title: Maximum Profit from Stock Prices (Single Transaction)
    Description:
        This program calculates the maximum profit that can be obtained 
        by performing a single buy-sell transaction on given stock prices.
        The approach finds the minimum stock price up to the current day 
        and calculates the maximum profit for every day.

    Input:
        - Array of stock prices (size n)

    Output:
        - The maximum profit that can be obtained with one transaction

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <climits>
using namespace std;

// Function to calculate the maximum profit with a single buy-sell transaction
int maximum_profit(int arr[], int size) {
    int minimum_element = arr[0]; // Track the minimum price seen so far
    int res = 0; // Variable to store the maximum profit

    for (int i = 1; i < size; i++) {
        // Update the minimum element (lowest price so far)
        minimum_element = min(minimum_element, arr[i]);
        
        // Calculate the profit if sold on the current day and update the result
        res = max(res, arr[i] - minimum_element);
    }
    return res;
}

int main() {
    int size;
    // Input: Size of the stock prices array
    cout << "Enter the size of array (number of days): ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid size. Size must be greater than 0.\n";
        return 1;
    }
    // Input: Stock prices
    int arr[size];
    cout << "Enter the stock prices: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    // Output: Maximum profit
    int profit = maximum_profit(arr, size);
    cout << "\nThe maximum profit for the given stock prices is: " << profit << "\n";
    return 0;
}
