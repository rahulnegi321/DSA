class ExamTracker {
public:
    map<int, long long> mpp;
    long long pre = 0;
    ExamTracker() {

    }

    void record(int time, int score) {
        pre = pre + score;
         mpp[time] = pre;
          }

    long long totalScore(int startTime, int endTime) {
        long long total = 0;
        long long total_end = 0;
        auto end_it = mpp.upper_bound(endTime);
        if(end_it != mpp.begin()){
            total_end = prev(end_it)->second;
        }
        auto start_it = mpp.lower_bound(startTime);
        long long total_start = 0;
        if(start_it != mpp.begin()){
           total_start = prev(start_it)->second;
        }
        return total_end-total_start;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */