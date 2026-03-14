class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mpp;
    int n;
    LRUCache(int capacity) {
      n = capacity;
    }
    
    int get(int key) {
        int ans = -1;
      if(mpp.count(key)){
         ans = mpp[key].second;
         auto it = mpp[key].first;
         dll.erase(it);
         dll.push_front(key);
         mpp[key].first = dll.begin();
      }
      return ans;
    }
    
    void put(int key, int value) {
        if(mpp.count(key)){
         mpp[key].second = value;
         auto it = mpp[key].first;
         dll.erase(it);
         dll.push_front(key);
         mpp[key].first = dll.begin();
      }
      else{
         if(dll.size() == n){
            int k = dll.back();
            mpp.erase(k);
            dll.pop_back();
            dll.push_front(key);
            mpp[key].first = dll.begin();
            mpp[key].second = value;
         }
         else{
            dll.push_front(key);
            mpp[key].first = dll.begin();
            mpp[key].second = value;
         }
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