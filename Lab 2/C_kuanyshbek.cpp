#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> ll;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ll.push_back(num);
    }

    int i = 0;
    for (auto it = ll.begin(); it != ll.end(); ++it) {
        if (i % 2 == 0) {
            cout << *it << " ";
        }
        i++;
    }

    return 0;
}
