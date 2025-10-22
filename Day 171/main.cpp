/*
    Title: Form the Largest Number from an Array of Integers.

    Problem Statement:
        - Given an array of non-negative integers, arrange them such that they form the largest possible number.
        - The result should be returned as a string because the formed number can be very large.

    Approach:
        1. Convert all integers in the array into strings.
        2. Sort the string numbers using a custom comparator:
              Compare concatenations (a + b) and (b + a).
              - If (a + b) > (b + a), 'a' should come before 'b'.
        3. After sorting, concatenate all the numbers to form the largest number.
        4. Handle edge cases like all elements being zero — return "0" in that case.

    Example:
        Input:
            arr = {45, 3, 9, 867, 4, 90}

        Process:
            - Convert to strings: {"45", "3", "9", "867", "4", "90"}
            - Sort using rule (a+b) > (b+a)
              Sorted result: {"9", "90", "867", "45", "4", "3"}
            - Concatenate: "9908674543"

        Output:
            ✅ Largest number formed = "9908674543"

    Dry Run:
        arr = {10, 2}
        Strings: {"10", "2"}
        Compare: ("210" > "102") → "2" comes first
        Result: "210"

    Time Complexity:
        - Sorting: O(N log N) comparisons, each taking up to O(K) (K = average string length)
        - Overall: O(N log N * K)

    Space Complexity:
        - O(N) for storing string representations.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

bool myComp(string &a, string &b) {
    return (a + b) > (b + a);
}

string largestNumber(vector<int>& arr) {
    vector<string> numbers;
    
    for (int x : arr) {
        numbers.push_back(to_string(x));
    }
    
    sort(numbers.begin(), numbers.end(), myComp);
    
    if (numbers[0] == "0") {
        return "0";
    }
    
    string res;
    for (string ele : numbers) {
        res += ele;
    }
    
    return res;
}

int main() {
    vector<int> arr = {45, 3, 9, 867, 4, 90};
    cout << "Largest number that can be formed from the given array is " << largestNumber(arr);
    return 0;
}







