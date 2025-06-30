/*
    Title: K Closest Points to the Origin

    Problem Statement:
        - Given a list of points on a 2D plane, return the k closest points to the origin (0, 0).
        - Distance is measured using Euclidean distance (squared to avoid computing square roots).

    Approach:
        - Calculate the squared Euclidean distance of each point.
        - Store each point with its distance in a pair.
        - Sort the list of pairs by distance.
        - Return the first k points from the sorted list.

    Time Complexity:
        - O(n log n), where n is the number of points (due to sorting).

    Space Complexity:
        - O(n), for storing distance pairs and result.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator function to sort based on distance
bool cmp(pair<vector<int>, int> &a, pair<vector<int>, int> &b) {
    return a.second < b.second;
}

// Sort list of points based on their distance
vector<vector<int>> sortedByDistance(vector<pair<vector<int>, int>> &res) {
    sort(res.begin(), res.end(), cmp);

    vector<vector<int>> result;
    for (auto &it : res) {
        result.push_back(it.first);
    }
    return result;
}

// Return k closest points to the origin
vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<pair<vector<int>, int>> disList;

    for (int i = 0; i < points.size(); i++) {
        int x = points[i][0];
        int y = points[i][1];
        int dist = x * x + y * y;
        disList.push_back({points[i], dist});
    }

    vector<vector<int>> sortedPoints = sortedByDistance(disList);

    vector<vector<int>> result(sortedPoints.begin(), sortedPoints.begin() + k);
    return result;
}

// Print helper
void printPoints(const vector<vector<int>> &points) {
    for (auto &p : points) {
        cout << "[" << p[0] << ", " << p[1] << "] ";
    }
    cout << endl;
}

// Main function
int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 4;

    vector<vector<int>> closest = kClosest(points, k);

    cout << k << " Closest Points to Origin: ";
    printPoints(closest);

    return 0;
}
