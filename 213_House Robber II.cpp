//Recursive Solution (void function)
class Solution {
public:
    void rec(vector<int>& arr, int i, int& pickFirstMax, int& sum){
        if(i >= arr.size()){
            pickFirstMax = max(pickFirstMax, sum);
            return;
        }
        sum += arr[i];
        rec(arr, i + 2, pickFirstMax, sum);

        sum -= arr[i];
        rec(arr, i + 1, pickFirstMax, sum);
        
    }
    int rob(vector<int>& nums) {
        vector<int> v;
        for(int i = 0; i < nums.size() - 1; i++) v.push_back(nums[i]);
        int pickFirstMax = nums[0], sum = nums[0];
        rec(v, 2, pickFirstMax, sum);
        int doNotPick = 0;
        sum = 0;
        rec(nums, 1, doNotPick, sum);

        return max(pickFirstMax, doNotPick);
    }
};
//Recursive Solution(int function)
class Solution {
public:
    int rec(vector<int>& arr, int i){
        if(i >= arr.size()){
            return 0;
        }
        int pick = arr[i] + rec(arr, i + 2);

        int notPick = 0 + rec(arr, i + 1);

        return max(pick, notPick);
        
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> v;
        for(int i = 0; i < nums.size() - 1; i++) v.push_back(nums[i]);
        int takeFirst = rec(v, 0);
        int doNotTakeFirst = rec(nums, 1);
        return max(takeFirst, doNotTakeFirst);
    }
};
//DP solution(Recursive DP)
class Solution {
public:
    int rec(vector<int>& arr, int i, vector<int>& dp){
        if(i >= arr.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        int pick = arr[i] + rec(arr, i + 2, dp);

        int notPick = 0 + rec(arr, i + 1, dp);

        return dp[i] = max(pick, notPick);
        
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> v;
        for(int i = 0; i < nums.size() - 1; i++) v.push_back(nums[i]);

        vector<int> dpT(v.size(), -1);
     
        int takeFirst = rec(v, 0, dpT);

        vector<int> dpNT(nums.size(), -1);

        int doNotTakeFirst = rec(nums, 1, dpNT);
        
        return max(takeFirst, doNotTakeFirst);
    }
};
