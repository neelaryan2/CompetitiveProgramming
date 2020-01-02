#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
public:
    stack<int> st_new, st_old;
    void push(int x) {
        st_new.push(x);
    }
    void pop() {
        if (st_old.empty()) {
            while (!st_new.empty())
                st_old.push(st_new.top()), st_new.pop();
        }
        st_old.pop();
    }
    int front() {
        if (st_old.empty()) {
            while (!st_new.empty())
                st_old.push(st_new.top()), st_new.pop();
        }
        return st_old.top();
    }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if (type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    return 0;
}

