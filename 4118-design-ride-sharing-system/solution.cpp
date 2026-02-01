class RideSharingSystem {
public:
    queue<int> rider;
    queue<int> driver;
    unordered_set<int> result;
    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        result.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!rider.empty()&& !result.count(rider.front())){
            rider.pop();
        }
        if(rider.empty()||driver.empty()) return {-1,-1};
        int r=rider.front(); rider.pop();
        int d= driver.front(); driver.pop();
        return {d,r};
    }
    
    void cancelRider(int riderId) {
        // bool flag=false;
        // queue<int> temp;
        // for(auto &it: result){
        //     if(it.first==riderId){
        //         flag=true;
        //     }
        // }
        // if(!flag){
        //     while(!rider.empty()){
        //         int cur= rider.front();
        //         rider.pop();
        //         if(cur==riderId){
        //             continue;
        //         }
        //         temp.push(cur);
        //     }
        //     rider=temp;
        // }
        result.erase(riderId);
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
