class Solution {
    int tmax[400005];
public:
    void update(int k, int left, int right, int pos, int val){
        if (pos < left || pos > right) return;
        if (left == right) {
            tmax[k] = val;
            return;
        }
        int m = (left + right) / 2;
        update(2 * k, left, m, pos, val);
        update(2 * k + 1, m + 1, right, pos, val);
        tmax[k] = max(tmax[2*k], tmax[2*k+1]);
    }
    
    int query(int k, int left, int right, int L, int R) {
        if (L > right || R < left) return 0;
        if (L <= left && right <= R) return tmax[k];
        int m = (left + right) / 2;
        return max(query(2*k, left, m, L, R), query(2*k+1, m + 1, right, L, R));
    }
    
    int lengthOfLIS(vector<int>& a, int k) {
        int ans = 0;
        int n = 1e5+5;
        a.insert(a.begin(), 1e9);
        for (int i = 1; i < a.size(); i++) {
            int val = query(1, 1, n, a[i] - k, a[i] - 1);
            update(1, 1, n, a[i], val + 1);
            ans = max(ans, val + 1);
        }
        return ans;
    }
};