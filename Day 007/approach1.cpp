/*
    Title: Maximum Profit from Stock Prices
    Description:
        This program calculates the maximum profit that can be achieved by buying and selling stocks
        on given days. The user provides an array representing stock prices on different days.
        The program identifies all possible buy-sell transactions to maximize profit using a greedy approach.

    Input:
        - The size of the array (n)
        - Array elements (n integers representing stock prices)

    Output:
        - The original stock prices array
        - Maximum profit achievable from multiple transactions

    Author: Vishal Singhaniya
*/

#include<iostream>
using namespace std;

// Function to calculate maximum profit from stock prices
int maximum_profit(int arr[], int size) {
    int local_maxima = arr[0]; // Highest price for selling
    int local_minima = arr[0]; // Lowest price for buying
    int i = 0; // Index to traverse the array
    int max_profit = 0; // Accumulated profit

    while (i < size - 1) {
        // Find local minima (buy point)
        while (i < size - 1 && arr[i] > arr[i + 1]) {
            i++;
        }
        local_minima = arr[i];
        cout << "\nBuy at: " << local_minima;

        // Find local maxima (sell point)
        while (i < size - 1 && arr[i] < arr[i + 1]) {
            i++;
        }
        local_maxima = arr[i];
        cout << " | Sell at: " << local_maxima<<"\n";

        // Add profit from this transaction to the total profit
        max_profit += (local_maxima - local_minima);
    }
    cout<<"Maximum profit can be made of : ";
    return max_profit;
}

// Helper function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << " , ";
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of array (stock prices): ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "The price of stocks are: ";
    printArray(arr, size);

    // Calculate and display the maximum profit
    cout<< maximum_profit(arr, size) << "\n";
    return 0;
}
