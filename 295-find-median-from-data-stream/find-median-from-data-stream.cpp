class MedianFinder {
public:
    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int>>q2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
           q1.push(num);
           q2.push(q1.top());
           q1.pop();
           if(q2.size() > q1.size()){
            q1.push(q2.top());
            q2.pop();
           }
    }
    
    double findMedian() {
        double ans = 0;
        if(q1.size() > q2.size()){
            ans = q1.top();
        }
        else{
            ans = ((double)q1.top() + (double)q2.top())/2;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */