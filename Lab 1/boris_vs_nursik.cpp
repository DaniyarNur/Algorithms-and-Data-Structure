#include <iostream>
#include <queue>
using namespace std;

int main() {
    int x, ans = 0;
    queue<int> b;
    queue<int> n;
    // while (true) {
    for (int i = 0; i < 5; i++) {
        cin >> x;
        b.push(x);
    }
    for (int j = 0; j < 5; j++) {
        cin >> x;
        n.push(x);
    }

    while (!b.empty() && !n.empty() && ans < 1000000) {
        ans++;
        int bb = b.front(), nn = n.front();
        b.pop();
        n.pop();
        if ((bb > nn || nn - bb == 9) && nn - bb != -9) {
            b.push(bb);
            b.push(nn);
        } else {
            n.push(bb);
            n.push(nn);
        }
    }
    if (ans == 1000000)
        cout << "blin nichya" << endl;
    else if (n.empty())
        cout << "Boris " << ans << endl;
    else
        cout << "Nursik " << ans << endl;
    // }
    return 0;
}
