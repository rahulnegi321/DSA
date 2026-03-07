class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       unordered_map<int,int>even;
       unordered_map<int,int>odd;

       int n = nums.size();
       if(n == 1){
        return 0;
       }
       if(n == 2){
         return nums[0] == nums[1] ? 1 : 0;
       }
    //    if(n == 3){
    //      if(nums[0] == nums[1] == nums[2]){
    //         return 1;
    //      }
    //      if(nums[0] == nums[2] && nums[1] != nums[2]){
    //         return 0;
    //      }
    //      if((nums[0] == nums[1] && nums[2] != nums[1])
    //    }
       for(int i = 0;i<nums.size();i=i+2){
          even[nums[i]]++;
          if(i+1 < nums.size()){
            odd[nums[i+1]]++;
          }
       }

       int first = 0;
       int count1 = 0;
       int count2 = 0;
       int second = 0;
       priority_queue<pair<int,int>>start;
       priority_queue<pair<int,int>>start2;
    
       for(auto it : even){
          start.push({it.second,it.first});
        
       }
       for(auto it: odd){
           start2.push({it.second,it.first});
          
       }
       start2.push({0,0});
       start.push({0,0});
       first = start.top().second;
       count1 = start.top().first;
       start.pop();
       second = start2.top().second;
       count2 = start2.top().first;
       start2.pop();
       if(first == second){
         int temp = start.top().first;
         int temp2 = start2.top().first;
         if(count1 - temp > count2- temp2){
            count2 = temp2;
         }
         else{
            count1 = temp;
         }
       }
       return n-(count1+count2);
    }
};