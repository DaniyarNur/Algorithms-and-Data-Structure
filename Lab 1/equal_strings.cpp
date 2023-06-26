#include <iostream>
#include <stack>
#include <algorithm> // Include the algorithm header for reverse function
using namespace std;

string check(const string& s) {
    stack<char> st1;
    for (char i : s) {
        if (i != '#')
            st1.push(i);
        else if (!st1.empty())
            st1.pop();
    }
    string result;
    while (!st1.empty()) {
        result.push_back(st1.top());
        st1.pop();
    }
    reverse(result.begin(), result.end()); // Use the reverse function from the algorithm header
    return result;
}

int main() {
    string s, t;
    cin >> s >> t;

    if (check(s) == check(t))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
