class RideSharingSystem {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>rider;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>driver;
    int r = 0;
    int d = 0; 
    unordered_map<int,int>cancel;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        r++;
        rider.push({r,riderId});
    }
    
    void addDriver(int driverId) {
        driver.push({d,driverId});
        d++;
    }
    
    vector<int> matchDriverWithRider() {
        if(driver.size() == 0 || rider.size() == 0){
            return {-1,-1};
        }
        int did = driver.top().second;
        int t = driver.top().first;
        driver.pop();
        while(rider.size()){
            int rid = rider.top().second;
            int time = rider.top().first;
            rider.pop();
            if(cancel.count(rid)){
                if(cancel[rid] >= time){
                    continue;
                }
                return {did,rid};
            }
            else{
                return {did,rid};
            }
        }
        driver.push({t,did});
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        cancel[riderId] = r;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */