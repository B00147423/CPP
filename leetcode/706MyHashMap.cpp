#include <unordered_map>
class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        if(mp.count(key)){
            return mp[key];
        }else
        {
            return -1;
        }
    }
    
    void remove(int key) {
        mp.erase(key);
    }

private:
    std::unordered_map<int, int> mp;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */