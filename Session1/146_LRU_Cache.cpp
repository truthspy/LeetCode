/**
* 花花教我的
*/
class LRUCache{
private:
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> keys;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        else {
            list<pair<int,int>>::iterator iter = mp[key];
            keys.push_front(*iter);
            keys.erase(iter);
            mp[key] = keys.begin();
            return (keys.begin())->second;
        }
        
    }
    
    void set(int key, int value) {
        if(mp.find(key) != mp.end()) {
            list<pair<int,int>>::iterator iter = mp[key];
            keys.push_front(*iter);
            keys.erase(iter);
            (keys.begin())->second = value;
            mp[key] = keys.begin();
        }
        else {
            if(keys.size() == cap) {
                mp.erase(keys.rbegin()->first);
                keys.pop_back();
                keys.push_front(make_pair(key, value));
                mp[key] = keys.begin();
            }
            else {
                keys.push_front(make_pair(key, value));
                mp[key] = keys.begin();
            }
        }
    }
};
