#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int K = 2;
struct Vertex {
    Vertex *nxt[K], *par, *link;
    char pch = '$';
    int id, tol;
    Vertex(Vertex* par = NULL, char ch = '$') : par(par), pch(ch) {
        memset(nxt, 0, sizeof nxt);
        // for (int i = 0; i < K; i++) {
        //     nxt[i] = NULL;
        // }
        id = tol = -1;
    }
};
template <class node>
struct suffix_trie {
    node* root;
    suffix_trie() {
        root = new node();
    }
    node* add_string(string const& s, int i) {
        node* v = root;
        for (char ch : s) {
            int c = ch - 'a';
            if (v->nxt[c] == NULL)
                v->nxt[c] = new node(v, ch);
            v = v->nxt[c];
        }
        v->id = i;
        return v;
    }
    node* get_link(node* v) {
        if (v->link != NULL) return v->link;
        if (v == root || v->par == root)
            v->link = root;
        else
            v->link = go(get_link(v->par), v->pch);
        return v->link;
    }
    node* go(node* v, char ch) {
        int c = ch - 'a';
        if (v->nxt[c] != NULL) return v->nxt[c];
        if (v == root)
            v->nxt[c] = root;
        else
            v->nxt[c] = go(get_link(v), ch);
        return v->nxt[c];
    }
    int get_tol(node* v) {
        if (v->tol != -1) return v->tol;
        v->tol = 0;
        if (v != root && v->par != root) {
            v->tol = get_tol(v->par) | get_tol(get_link(v));
            v->tol |= (get_link(v)->id != -1) | ((v->par)->id != -1);
        }
        return v->tol;
    }
};
suffix_trie<Vertex> t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set<int> ans;
    vector<Vertex*> vec;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vec.pb(t.add_string(s, i));
    }
    for (auto v : vec) {
        if (!t.get_tol(v))
            ans.insert(v->id);
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << i + 1 << ' ';
    cout << '\n';
}
