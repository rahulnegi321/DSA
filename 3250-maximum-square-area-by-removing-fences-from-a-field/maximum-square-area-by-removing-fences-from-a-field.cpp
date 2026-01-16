class Solution {
public:
    int M = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        vFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(n);
        unordered_set<int>st;
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        for(int i = 0;i<hFences.size();i++){
            for(int j = i+1;j<hFences.size();j++){
                int temp = hFences[j] - hFences[i];
                st.insert(temp);
            }
        }
        long long ans = -1;
        for(int i = 0;i<vFences.size();i++){
            for(int j = i+1;j<vFences.size();j++){
                long long temp = vFences[j]-vFences[i];
                if(st.count(temp)){
                    ans = max(ans,temp);
                }
            }
        }
        if(ans == -1){
            return -1;
        }
        return (int)((ans*ans)%M);
    }
};