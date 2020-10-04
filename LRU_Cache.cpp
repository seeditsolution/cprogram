class LRUCache {
private:
    int cap;
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            keys.erase(cache[key].second);
            keys.push_front(key);
            cache[key].second = keys.begin();
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            keys.erase(cache[key].second);
            keys.push_front(key);
            cache[key] = {value, keys.begin()};
        }else{
            if(keys.size() == cap){
                cache.erase(keys.back());
                keys.pop_back();
            }    
            keys.push_front(key);
            cache[key] = {value, keys.begin()};
        }
    }
};
