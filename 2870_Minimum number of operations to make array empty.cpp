class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        map<int, int> m;
        for(int i: nums) m[i]++;
        for(auto r: m){
            if(r.second == 1) return -1;
            else if(r.second % 3 == 2){
                ans += r.second / 3;
                ans += 1;
            }
            else if(r.second % 3 == 0) ans += r.second / 3;
            else if(r.second % 3 == 1){
                if(r.second == 4) ans += 2;
                else{
                    int val = r.second - 4;
                    ans += val /3;
                    ans += 2;
                }
            }
            
            
        }
        return ans;
    }
};