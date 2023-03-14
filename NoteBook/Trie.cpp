class Solution {
    unordered_map<string, int> m;
public:
    
    struct Node{
        int cnt = 0;
        Node *c[26];

        Node(){
            int cnt = 0;
            for (int i = 'a'; i <= 'z'; i++) c[i-'a'] = NULL;
        }
    };
    
    struct Trie {
        Node *pHead;
	    Trie(){pHead = new Node();}
        
        void insert(string s) {
            Node *c = pHead;
            for (int i = 0; i < s.size(); i++) {
                if (c -> c[s[i] -'a'] == NULL) c -> c[s[i] -'a'] = new Node();
                c = c -> c[s[i] - 'a'];
                // cout << c -> cnt << endl;
                c -> cnt++;    
            }
        }
        
        int get(string s) {
            int ret = 0;
            Node* c = pHead;
            for (int i = 0; i < s.size(); i++) {
                if (c -> c[s[i] - 'a'] != NULL) {
                    c = c -> c[s[i] - 'a'];
                    ret += c ->cnt;
                }
            }
                
            return ret;
        }
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie trie;
        for (string s: words) trie.insert(s);
        for (string s: words) {
            ans.push_back(trie.get(s));
        }
        return ans;
    }
};