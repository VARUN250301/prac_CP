class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       int n = nums.size();
       int k = INT_MIN;
       stack<int> st;
       for(int i = n - 1; i >= 0; i--){
           if(nums[i] < k) return true;
           else{
               while(!st.empty() and nums[i] > st.top()){
                   k = st.top();
                   st.pop();
               }
           }
           st.push(nums[i]);
       } 
       return false;
    }
};

//TLE Recursion
class Solution {
public:
    bool ans = false;
    void rec(vector<int>& v,vector<int>& ss, int i){
    if(ss.size() == 3){
        if(ss[0] < ss[1] and ss[0] < ss[2] and ss[1] > ss[2]) ans = true;
        return;
    }
    if(i >= v.size()) return;
    ss.push_back(v[i]);
    rec(v, ss, i + 1);
    ss.pop_back();
    rec(v, ss, i + 1);
    
}
    bool find132pattern(vector<int>& nums) {
        vector<int> ss;
        rec(nums, ss, 0);
        return ans;
    }
};