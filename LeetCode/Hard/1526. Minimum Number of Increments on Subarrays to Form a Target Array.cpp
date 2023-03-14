https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for (int i = 1; i < target.size(); i++){
           ans += max(target[i] - target[i-1], 0);
        }
        
        return ans;
    }
};