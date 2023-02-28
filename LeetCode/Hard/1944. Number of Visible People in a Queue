https://leetcode.com/problems/number-of-visible-people-in-a-queue/

class Solution {
public:

    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> ans;
        st.push(heights[heights.size()-1]);
        ans.push_back(0);
        for (int i = heights.size()-2; i >= 0; i--){
            int cnt = 0;
            while(st.size() && heights[i] > st.top()){
                cnt++;
                st.pop();
            }   
            if (st.size()) {
                cnt++;
            }
            st.push(heights[i]);
            ans.push_back(cnt); 
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};