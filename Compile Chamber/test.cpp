const int K = 26;
const int def = -1;
int root = 0;
struct Vertex {
    int nxt[K], go[K];
    bool leaf = false;
    int par = def, link = def;
    char pch = '$';
    Vertex(int par = def, char ch = '$') : par(par), pch(ch) {
        fill(begin(nxt), end(nxt), def);
        fill(begin(go), end(go), def);
    }
};
vector<Vertex> trie(1);
void add_string(int v = root, string const& s) {
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].nxt[c] == def) {
            trie[v].nxt[c] = trie.size();
            trie.emplace_back(v, ch);
        }
        v = trie[v].nxt[c];
    }
    trie[v].leaf = true;
}
int go(int v, char ch);
int get_link(int v) {
    if (trie[v].link != def)
        return trie[v].link;
    if (v == root || trie[v].par == root)
        trie[v].link = root;
    else
        trie[v].link = go(get_link(trie[v].par), trie[v].pch);
    return trie[v].link;
}
int go(int v, char ch) {
    int c = ch - 'a';
    if (trie[v].go[c] != def)
        return trie[v].go[c];
    if (trie[v].nxt[c] != def)
        trie[v].go[c] = trie[v].nxt[c];
    else if (v == root)
        trie[v].go[c] = root;
    else
        trie[v].go[c] = go(get_link(v), ch);
    return trie[v].go[c];
}
void dfs(int v) {
    for (int i = 0; i < K; i++) {
        if (trie[v].nxt[i] == def) continue;
        dfs(trie[v].nxt[i]);
    }
}