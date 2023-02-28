https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

class TreeAncestor {
public:
    int par[25][50005] = {};
    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 0; (1 << i) < n; i++) {
            for (int j = 0; j < n; j++) {
                par[i][j] = -1;
            }
        }
        for (int i = 0; i < n; i++) {
           par[0][i] = parent[i]; 
        }
        for (int i = 1; (1 << i) <= n; i++) {
            for (int j = 0; j < n; j++) {
                if (par[i-1][j] != -1) {
                    par[i][j] = par[i-1][par[i-1][j]];    
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int cnt = 0;
        for (int j = log2(k); j >= 0; j--) {
            if (cnt + pow(2, j) <= k) {
                cnt += pow(2, j);
                node = par[j][node];
                if (node == -1) {
                    return -1;
                }
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */