#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
using namespace std;

void findPairsWithLeastDifference(int N, const vector<int>& points) {
    vector<pair<int, int>> pairs;
    int minDiff = INT_MAX;

    for (int i = 1; i < N; i++) {
        int diff = abs(points[i] - points[i - 1]);

        if (diff < minDiff) {
            minDiff = diff;
            pairs.clear();
            pairs.emplace_back(points[i - 1], points[i]);
        } else if (diff == minDiff) {
            pairs.emplace_back(points[i - 1], points[i]);
        }
    }

    for (const auto& pair : pairs) {
        cout << pair.first << " " << pair.second << " ";
    }

    cout << endl;
}

int main() {
    int N;
    cin >> N;

    vector<int> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    findPairsWithLeastDifference(N, points);

    return 0;
}
