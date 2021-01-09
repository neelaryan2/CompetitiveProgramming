#include <list>
using lit = list<int>::iterator;
map<int, lit> loc;
map<int, int> cache;
list<int> vals;
int n;
LRUCache::LRUCache(int capacity) {
    loc.clear();
    cache.clear();
    vals.clear();
    n = capacity;
}
int LRUCache::get(int key) {
    auto lc = loc.find(key);
    if (lc == loc.end()) return -1;
    lit it = lc->second;
    int val = cache[*it];
    vals.erase(it);
    vals.push_back(key);
    lc->second = prev(vals.end());
    return val;
}
void LRUCache::set(int key, int value) {
    auto lc = loc.find(key);
    if (lc == loc.end()) {
        if (vals.size() == n) {
            int old = *vals.begin();
            loc.erase(old);
            cache.erase(old);
            vals.pop_front();
        }
        vals.push_back(key);
        cache[key] = value;
        loc[key] = prev(vals.end());
        return;
    }
    cache[key] = value;
    LRUCache::get(key);
}
