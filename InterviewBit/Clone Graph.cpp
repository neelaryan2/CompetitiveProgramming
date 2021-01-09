/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#define node UndirectedGraphNode
map<node*, node*> vis;
void dfs(node* v, node* clone) {
    vis[v] = clone;
    for (node* u : v->neighbors) {
        auto it = vis.find(u);
        if (it != vis.end()) {
            (clone->neighbors).push_back(it->second);
            continue;
        }
        node *c = new node(u->label);
        (clone->neighbors).push_back(c);
        dfs(u, c);
    }
}
node *Solution::cloneGraph(node *v) {
    vis.clear();
    node *clone = new node(v->label);
    vis[v] = clone;
    dfs(v, clone);
    return clone;
}
