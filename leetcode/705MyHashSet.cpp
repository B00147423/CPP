#include <unordered_set>
class MyHashSet {

private:

    std::unordered_set<int> mySet;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        mySet.insert(key);
    }
    
    void remove(int key) {
        mySet.erase(key);
    }
    
    bool contains(int key) {
        return mySet.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */