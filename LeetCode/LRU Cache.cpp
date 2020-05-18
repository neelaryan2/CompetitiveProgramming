using pii = pair<int, int>;
using lit = list<pii>::iterator;
using mit = unordered_map<int, lit>::iterator;
#define fi first
#define se second
class LRUCache {
    int cap;
    unordered_map<int, lit> cache;
    list<pii> lru;

   public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        mit it = cache.find(key);
        if (it == cache.end()) return -1;
        pii p = *(it->se);
        lru.erase(it->se);
        lru.push_front(p);
        it->se = lru.begin();
        return p.se;
    }

    void put(int key, int value) {
        mit it = cache.find(key);
        if (it != cache.end()) {
            lru.erase(it->se);
            lru.push_front({key, value});
            it->se = lru.begin();
            return;
        }
        if (lru.size() < cap) {
            lru.push_front({key, value});
            cache[key] = lru.begin();
            return;
        }
        lit old = prev(lru.end());
        cache.erase(old->fi);
        lru.pop_back();
        lru.push_front({key, value});
        cache[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */