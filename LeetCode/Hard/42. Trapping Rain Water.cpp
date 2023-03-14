https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int max_left[height.size()] = {};
        int max_right[height.size()] = {};
        
        max_left[0] = height[0];
        for (int i = 1; i < height.size(); i++){
            max_left[i] = max(max_left[i-1], height[i]);
        }
        max_right[height.size()-1] = height[height.size()-1];
        for (int i = height.size() - 2; i >= 0; i--){
            max_right[i] = max(max_right[i+1], height[i]);
        }
        int ans = 0;
        for (int i = 1; i < height.size() - 1; i++){
            ans = ans + max(min(max_left[i-1], max_right[i+1]) - height[i], 0);
        }
        
        return ans;
    }
};