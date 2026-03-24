/*
🚗 Carpooling Problem

There is a car that starts from a point and travels only towards the east in a straight line. The car has some vacant seats.

You are given an integer T (number of trips) and a 2D array trips, where each trip is represented as:
trips[i] = [numPassengers, from, to]

📌 The car moves only in one direction (east), and locations are given as distances from the starting point.
🎯 Task

Return the maximum number of passengers present in the car at any time, i.e., the minimum capacity required to complete all trips.

📥 Input Format
First line: Integer T (number of trips)
Next T lines: Each line contains 3 integers:
numPassengers from to
2
2 1 5
3 3 7

📤 Output Format
Return a single integer:
Maximum capacity required
5

🔒 Constraints
1 ≤ T ≤ 10^5
1 ≤ numPassengers ≤ 100
0 ≤ from < to ≤ 1000
*/
#include <bits/stdc++.h>
using namespace std;
int findMaxCapacity(int T, vector<vector<int>>& trips) {
    int maxDistance = INT_MIN;

    for (auto &trip : trips)
        maxDistance = max(maxDistance, trip[2]);

    vector<int> prefix(maxDistance + 2, 0);

    for (int i = 0; i < T; i++) {
        prefix[trips[i][1]] += trips[i][0];
        prefix[trips[i][2]] -= trips[i][0]; // passengers leave at 'to'
    }

    for (int i = 1; i < prefix.size(); i++)
        prefix[i] += prefix[i - 1];

    int maxCapacity = 0;

    for (int i = 0; i < prefix.size(); i++)
        maxCapacity = max(maxCapacity, prefix[i]);

    return maxCapacity;
}
int main(){
    int T;
    cin >> T;

    vector<vector<int>> trips(T, vector<int>(3));

    for (int i = 0; i < T; i++) {
        cin >> trips[i][0] >> trips[i][1] >> trips[i][2];
    }

    int maxCapacity = findMaxCapacity(T, trips);
    cout << maxCapacity;
    return 0;
}