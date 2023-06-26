
#include <algorithm>
#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
int main(){
    char a;
    int x;
    deque<int> d;
    while(cin >> a && a != '!'){
        if (a == '*'){
            if (d.size()){
                cout << d.front() + d.back() << "\n";
                d.pop_front();
                if (d.size()) d.pop_back();
            }
            else 
                cout << "error\n";
        }
        else{
            cin >> x;
            if (a == '+') d.push_front(x);
            else  d.push_back(x);
        }
    }
    return 0;
}
 
 