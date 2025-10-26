class Bank {
public:
    unordered_map<int,long long>mpp;
    Bank(vector<long long>& balance) {
        
        for(int i = 0;i<balance.size();i++){
            mpp[i+1] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 < 1 || account1 > mpp.size() || account2 < 1 || account2 > mpp.size() ){
            return false;
        }
        if(mpp[account1] >= money){
            long long temp = mpp[account1];
            temp = temp - money;
            mpp[account1] = temp;
            long long temp2 = mpp[account2];
            temp2 = temp2 + money;
            mpp[account2] = temp2;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account < 1 || account > mpp.size()){
            return false;
        }
        mpp[account] = mpp[account] + money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account < 1 || account > mpp.size()){
            return false;
        }
        if(mpp[account] >= money){
            long long temp = mpp[account];
            temp = temp - money;
            mpp[account] = temp;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */