using lit = list<int>::iterator;
#define se second
class FirstUnique {
    map<int, lit> vis;
    list<int> que;

   public:
    FirstUnique(vector<int>& nums) {
        for (int e : nums) add(e);
    }
    int showFirstUnique() {
        if (que.empty()) return -1;
        return que.front();
    }
    void add(int value) {
        auto it = vis.find(value);
        if (it == vis.end()) {
            que.push_back(value);
            vis[value] = prev(que.end());
            return;
        }
        if (it->se == que.end()) return;
        que.erase(it->se);
        it->se = que.end();
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */