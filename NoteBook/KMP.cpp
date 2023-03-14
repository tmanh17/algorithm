class Solution {
    int match[100005] = {};
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        string S = s + "#" + t;
        for (int i = 1; i < S.size(); i++){
            int prev = match[i-1];
            while(prev > 0 && S[i] != S[prev]) {
                prev = match[prev-1];
            }
            if (S[i] == S[prev]) {
                prev++;
            }
            match[i] = prev;
        }
        return t.substr(0, s.size() - match[S.size()-1]) + s;
    }
};