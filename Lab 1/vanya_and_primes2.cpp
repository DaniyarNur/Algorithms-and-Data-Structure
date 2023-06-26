#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    vector<int> vv;
    bool p[1000001];
    for (int i = 2; i <= 1000000; i++)
        p[i] = true;

    for (int i = 2; i * i <= 1000000; i++) {
        if (p[i]) {
            for (int j = i * i; j <= 1000000; j += i)
                p[j] = false;
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        if (p[i])
            v.push_back(i);
    }

    for (int i = 1; i <= v.size(); i++) {
        if (p[i])
            vv.push_back(v[i - 1]);
    }

    cout << vv[n - 1] << endl;

    return 0;
}
