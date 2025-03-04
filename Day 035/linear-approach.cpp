#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Finds the k-th smallest element in two sorted arrays using the merge approach.
 * 
 * @param arr1 First sorted array.
 * @param arr2 Second sorted array.
 * @param size1 Size of the first array.
 * @param size2 Size of the second array.
 * @param k The k-th position to find.
 * @return The k-th smallest element.
 */
int find_k_th(vector<int> &arr1, vector<int> &arr2, int size1, int size2, int k) {
    int x = 0, y = 0;

    // Merge until we reach the k-th element
    while (--k > 0) {
        if (x < size1 && (y >= size2 || arr1[x] < arr2[y])) {
            x++;  // Move pointer in arr1
        } else {
            y++;  // Move pointer in arr2
        }
    }

    // Return the k-th smallest element
    return (x < size1 && (y >= size2 || arr1[x] < arr2[y])) ? arr1[x] : arr2[y];
}

int main() {
    int size1, size2, k;
    cout << "Enter the size of both arrays: ";
    cin >> size1 >> size2;

    vector<int> arr1(size1), arr2(size2);

    cout << "Enter elements of first sorted array: ";
    for (int &num : arr1) cin >> num;

    cout << "Enter elements of second sorted array: ";
    for (int &num : arr2) cin >> num;

    cout << "Enter the value of k: ";
    cin >> k;

    if (k > 0 && k <= size1 + size2) {
        cout << k << "-th smallest element from these two arrays is: "
             << find_k_th(arr1, arr2, size1, size2, k) << endl;
    } else {
        cout << "Invalid value of k!" << endl;
    }

    return 0;
}
