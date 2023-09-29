class Solution {
public:
    int findNoOfSetBits(int i){
        vector<int> binary;
        while(i != 0){
            int rem = i%2;
            binary.push_back(rem);
            i /= 2;
        }
        int setBits = 0;
        for(int i: binary) if(i== 1) setBits++;
        return setBits;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int val = findNoOfSetBits(i);
           
            if(val == k) ans += nums[i];
        }
        return ans;
    }
};