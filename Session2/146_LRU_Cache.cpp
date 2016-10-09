class LRUCache{
private:
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> myList;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        auto it = mp[key];
        int val = (*it).second;
        myList.push_front(make_pair(key, val));
        myList.erase(it);
        mp[key] = myList.begin();
        return val;
    }
    
    void set(int key, int value) {
        if(mp.find(key) == mp.end()) {
            if(myList.size() == size) {
                mp.erase(myList.back().first);
                myList.pop_back();
            }
        }
        else {
            myList.erase(mp[key]);
        }
        myList.push_front(make_pair(key, value));
        mp[key] = myList.begin();
    }
};
