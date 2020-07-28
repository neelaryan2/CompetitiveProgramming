#include <bitset>
const int B = 31, ALPH = 2;
const vector<int> def(ALPH, -1);
vector<vector<int>> t;
void add(int num) {
    bitset<B> s(num);
    int v = 0;
    for (int i = B - 1; i >= 0; i--) {
        int c = s[i];
        if (t[v][c] == -1) {
            t[v][c] = t.size();
            t.push_back(def);
        }
        v = t[v][c];
    }
}
int query(int num) {
    bitset<B> s(num);
    int v = 0, ans = 0;
    for (int i = B - 1; i >= 0; i--) {
        int c = s[i];
        if (t[v][c] != -1) {
            v = t[v][c];
        } else {
            ans ^= (1 << i);
            v = t[v][c ^ 1];
        }
    }
    return ans;
}
int trie(vector<int>& A) {
    t.clear();
    t.assign(1, def);
    int n = A.size(), ans = INT_MAX;
    add(A[0]);
    for (int i = 1; i < n; i++) {
        ans = min(ans, query(A[i]));
        add(A[i]);
    }
    return ans;
}
int Solution::findMinXor(vector<int> &A) {
    // return trie(A);
    int n = A.size(), ans = INT_MAX;
    sort(A.begin(), A.end());
    for (int i = 1; i < n; i++)
        ans = min(ans, A[i] ^ A[i - 1]);
    return ans;
}
