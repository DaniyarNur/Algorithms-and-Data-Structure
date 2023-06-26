#include <iostream>
#include <stack>
using namespace std;

bool check() {
    string s;
    getline(cin, s);
    stack<char> st;
    for (char i : s) {
        if (st.empty() || st.top() != i)
            st.push(i);
        else
            st.pop();
    }
    return st.empty();
}

int main() {
    bool flag;
    string s;
    // while (true) {
    flag = false;
    if (check())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    // }

    return 0;
}