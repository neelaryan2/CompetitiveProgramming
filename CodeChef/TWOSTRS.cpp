#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

const int K = 26;
struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int b = 0;
    ll tot = -1;
    Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};
vector<Vertex> t;
void add_string(string const& s, int b) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].b = b;
}
int go(int v, char ch);
int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}
int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = (v == 0) ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}
ll get_sum(int v) {
    if (v == 0) return 0;
    if (t[v].tot != -1)
        return t[v].tot;
    t[v].tot = t[v].b + get_sum(get_link(v));
    return t[v].tot;
}
void dfs(int v = 0) {
    ll tmp = get_sum(v);
    tmp = get_link(v);
    for (int i = 0; i < K; i++) {
        if (t[v].next[i] == -1) continue;
        dfs(t[v].next[i]);
    }
}
void solve() {
    t.clear();
    t.resize(1);
    string a, b;
    cin >> a >> b;
    string rb = b;
    reverse(all(rb));
    int N, mx = -1;
    cin >> N;
    int root = 0;
    int n = a.size(), m = b.size();
    vector<ll> havea(n + 1, 0), haveb(m + 1, 0);
    vector<int> mxa(n + 1, 0), mxb(m + 1, 0);
    vector<pair<string, int>> vec(N);
    for (int _ = 0; _ < N; _++) {
        string cur;
        int beauty;
        cin >> cur >> beauty;
        vec[_] = {cur, beauty};
        string rcur = cur;
        reverse(all(rcur));
        int l = cur.size();
        add_string(cur, beauty);
        mx = max(mx, l);
        string s1 = cur + "#" + a;
        string s2 = rcur + "#" + rb;
        vector<int> lps(l + n + 1, 0);
        vector<int> blps(l + m + 1, 0);
        for (int i = 1; i < l + n + 1; i++) {
            int j = lps[i - 1];
            while (j > 0 && s1[i] != s1[j])
                j = lps[j - 1];
            if (s1[i] == s1[j]) j++;
            lps[i] = j;
            if (i <= l) continue;
            int& res = mxa[i - l];
            if (j == l) {
                havea[i - l] += beauty;
                res = max(res, lps[l - 1]);
            } else
                res = max(res, j);
        }
        for (int i = 1; i < l + m + 1; i++) {
            int j = blps[i - 1];
            while (j > 0 && s2[i] != s2[j])
                j = blps[j - 1];
            if (s2[i] == s2[j]) j++;
            blps[i] = j;
            if (i <= l) continue;
            int& res = mxb[i - l];
            if (j == l) {
                haveb[i - l] += beauty;
                res = max(res, blps[l - 1]);
            } else
                res = max(res, j);
        }
    }
    dfs();
    t[root].tot = 0;
    for (int i = 1; i <= n; i++)
        havea[i] += havea[i - 1];
    for (int i = 1; i <= m; i++)
        haveb[i] += haveb[i - 1];
    ll ans = -1;
    for (int i = 0; i <= n; i++) {
        ll& res = havea[i];
        int lef = max(i - mx + 1, 0);
        for (int k = i - 1; k >= lef; k--) {
            int len = i - k;
            int u = root;
            bool exist = true;
            for (int tu = k; tu < i; tu++) {
                int cur = a[tu] - 'a';
                if (t[u].next[cur] == -1) {
                    exist = false;
                    break;
                }
                u = t[u].next[cur];
            }
            if (!exist) continue;
            int righ = min(i + mx - len, n);
            for (int tu = i; tu < righ; tu++) {
                int cur = a[tu] - 'a';
                if (t[u].next[cur] == -1) break;
                u = t[u].next[cur];
                res += t[u].b;
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        ll& res = haveb[i];
        int lef = max(m - i - mx + 1, 0);
        for (int k = m - i - 1; k >= lef; k--) {
            int len = m - i - k;
            int u = root;
            bool exist = true;
            for (int tu = k; tu < m - i; tu++) {
                int cur = b[tu] - 'a';
                if (t[u].next[cur] == -1) {
                    exist = false;
                    break;
                }
                u = t[u].next[cur];
            }
            if (!exist) continue;
            int righ = min(m + mx - len - i, m);
            for (int tu = m - i; tu < righ; tu++) {
                int cur = b[tu] - 'a';
                if (t[u].next[cur] == -1) break;
                u = t[u].next[cur];
                res += t[u].b;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int la = mxa[i], lb = mxb[j];
            ll curr = havea[i - la] + haveb[j - lb];
            int v = 0;
            lb = m - j + lb;
            for (int k = i - la; k < i; k++) {
                v = go(v, a[k]);
                curr += t[v].tot;
            }
            for (int k = m - j; k < lb; k++) {
                v = go(v, b[k]);
                curr += t[v].tot;
            }
            ans = max(ans, curr);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
