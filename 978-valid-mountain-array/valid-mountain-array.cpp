class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3){
            return false;
        }
        if(arr.size() == 3){
            if(arr[1] > arr[0] && arr[1] > arr[2]){
                return true;
            }
            else{
                return false;
            }
        }

        int maxi = -1;
        int n = arr.size();
        for(int i = 0;i<arr.size();i++){
            maxi = max(arr[i],maxi);
            if(arr[i] == maxi && (i == n-1)){
                return false;
            } 
        }
        if(maxi == arr[0]){
            return false;
        }
        int count = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] == maxi){
                count ++;
                if(count > 1){
                    return false;
                }
            }
        }
        int i = 0;
        while(i+1< n && arr[i] < arr[i+1]){
            i++;
        }
        if(arr[i] == arr[i+1]){
            return false;
        }
        if(arr[i] != maxi){
            return false;
        }
        while(i+1 < n && arr[i] > arr[i+1]){
            i++;
        }
        if(i != n-1){
            return false;
        }
        return true;
    }
};