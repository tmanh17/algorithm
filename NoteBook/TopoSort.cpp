class Solution {
    vector<int> radj[405];
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        vector<int> rowOrder;
        vector<int> colOrder;
        if (!topoSort(k, r, rowOrder) || !topoSort(k, c, colOrder)) {
            return {};
        }
        vector<int> row(k + 1, 0);
        vector<int> col(k + 1, 0);
        for (int i = 0; i < k; i++) {
            row[rowOrder[i]] = i;
            col[colOrder[i]] = i;
        }
        
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++) {
            ans[row[i]][col[i]] = i;
        }
        return ans;
    }
    
    bool topoSort(int k, vector<vector<int>> v, vector<int>& order) {
        vector<int> adj[405];
        int indeg[405] = {};
        
        for (int i = 0; i < v.size(); i++) {
            adj[v[i][0]].push_back(v[i][1]);
            indeg[v[i][1]]++;
        }
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indeg[i] == 0) q.push(i);
        }
        while(q.size()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return k == order.size();
    }
};