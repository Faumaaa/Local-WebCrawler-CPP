#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <list>
#include <unordered_map>
using namespace std;

template<typename K, typename V>
class LRUCache {
public:
    LRUCache(size_t capacity) : capacity(capacity) {}

    bool get(const K& key, V& value) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            return false;
        }
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        value = it->second->second;
        return true;
    }

    void put(const K& key, const V& value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            cacheList.erase(it->second);
            cacheMap.erase(it);
        }
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
        if (cacheMap.size() > capacity) {
            auto last = cacheList.end();
            last--;
            cacheMap.erase(last->first);
            cacheList.pop_back();
        }
    }

private:
    size_t capacity;
    list<pair<K, V>> cacheList;
    unordered_map<K, typename list<pair<K, V>>::iterator> cacheMap;
};

#endif
