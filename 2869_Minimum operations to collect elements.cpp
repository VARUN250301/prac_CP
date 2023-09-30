class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        int count = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            count++;
            if(nums[i] <= k) s.insert(nums[i]);
            if(s.size() == k) break;
        }
        return count;
    }
};