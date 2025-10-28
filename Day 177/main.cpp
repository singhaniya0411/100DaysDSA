/*.
    Title: Minimum Days to Make M Bouquets

    Problem Statement:
        - You are given an array `arr[]` where `arr[i]` represents the day on which the i-th flower blooms.
        - You need to make exactly `m` bouquets.
        - Each bouquet requires exactly `k` consecutive flowers that have bloomed on or before a certain day.
        - Find the **minimum number of days** required to make `m` bouquets.
        - If it is not possible to make `m` bouquets, return -1.

    Approach:
        1. Use **Binary Search** on the range of days:
            - Low = 0 (earliest possible day)
            - High = max(arr) (latest blooming day)
        2. For each day (mid), check if it’s possible to make `m` bouquets:
            - Traverse the array:
                - Count consecutive bloomed flowers (arr[i] <= mid).
                - Whenever a flower is not bloomed, add `count / k` to bouquets and reset count.
            - If total bouquets ≥ m → possible → try smaller day (move left).
              Else → increase day (move right).
        3. Return the smallest valid day.

    Example:
        Input:
            arr = [1, 10, 3, 10, 2]
            m = 3, k = 1

        Process:
            - Day 3 → Flowers that bloom: [1, _, 3, _, 2]
              Bouquets = 3 ✅
            - Day 2 → Bouquets = 2 ❌
            → Minimum days = 3

        Output:
            ✅ Minimum days required to make 3 bouquets = 3

    Time Complexity:
        - O(N log M), where N = number of flowers, M = max bloom day.

    Space Complexity:
        - O(1), no extra space used.

    Applications:
        - Scheduling problems, production line optimization, resource allocation.

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

// Helper function: Checks if we can make m bouquets in 'days' days
bool check(vector<int> &arr, int k, int m, int days) {
    int bouquet = 0, cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= days) {
            cnt++;
        } else {
            bouquet += cnt / k;
            cnt = 0;
        }
    }
    bouquet += cnt / k;
    return bouquet >= m;
}

// Main function: Finds minimum days required
int minDaysBloom(vector<int> &arr, int k, int m) {
    if ((long long)m * k > arr.size()) return -1; // Not enough flowers

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int res = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(arr, k, m, mid)) {
            res = mid;
            high = mid - 1; // Try to find a smaller valid day
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    cout << "Minimum number of days to make " << m 
         << " bouquets is : " << minDaysBloom(arr, k, m) << "\n";

    return 0;
}
