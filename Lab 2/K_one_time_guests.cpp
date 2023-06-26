#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void printFirstNonRepeatingChars(int N, const string& stream) {
    queue<char> q;
    unordered_map<char, int> count;

    for (char c : stream) {
        count[c]++;
        q.push(c);

        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }

    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string stream;
        cin.ignore();
        getline(cin, stream);

        printFirstNonRepeatingChars(N, stream);
    }

    return 0;
}
