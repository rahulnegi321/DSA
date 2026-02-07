class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mpp;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    void makerecent(int key){
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first = dll.begin();
        return;
    }

    int get(int key) {
        if(!mpp.count(key)){
            return -1;
        }
        makerecent(key);
        return mpp[key].second;
    }
    
    void put(int key, int value) {
        if(mpp.count(key)){
            makerecent(key);
            mpp[key].second = value;
            return;
        }
        dll.push_front(key);
        mpp[key].first = dll.begin();
        mpp[key].second = value;
        n--;
        if(n < 0){
            int to_delete = dll.back();
            mpp.erase(to_delete);
            dll.pop_back();
            n++;
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */