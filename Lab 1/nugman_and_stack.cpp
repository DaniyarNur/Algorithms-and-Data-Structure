#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int arr[n];
    stack<int> st;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() > arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans = -1;
        } else {
            ans = st.top();
        }

        st.push(arr[i]);
        cout << ans << " ";
    }

    return 0;
}
