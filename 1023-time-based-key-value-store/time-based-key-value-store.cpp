class TimeMap {
public:
    map<string,map<int,string>>mpp;
    TimeMap() {
         
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto &finder = mpp[key];
        auto exact = finder.find(timestamp);
        if(exact != finder.end()){
            return mpp[key][timestamp];
        }

       auto it = mpp[key].lower_bound(timestamp);
       if(it == mpp[key].begin()){
        return "";
       }
       it--;
       return it->second;
    } 
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */