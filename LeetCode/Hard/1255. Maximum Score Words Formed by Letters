https://leetcode.com/problems/maximum-score-words-formed-by-letters/

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<int, bool> selectedWords;
        map<char, int> mLetters;
        for (int i = 0; i < letters.size(); i++){
            mLetters[letters[i]] += 1;
        }
        int maxScore = 0;
        Try(0, words, letters, score, mLetters, selectedWords, maxScore);
        
        return maxScore;
    }
    
    int Score(vector<string>& words, vector<int>& score, map<char, int>& mLetters, map<int, bool>& selectedWords){
        map<char, int> usedLetters;
        int ret = 0;
        for (int i = 0; i < words.size(); i++){
            if (selectedWords[i] == 1){
                 for (int j = 0; j < words[i].size(); j++){
                     ret += score[words[i][j] - 'a'];
                     usedLetters[words[i][j]] += 1;
                     if (usedLetters[words[i][j]] > mLetters[words[i][j]]) {
                         return 0;
                     }
                 }
            }
        }
        return ret;
    }
    
    void Try(int i, vector<string>& words, vector<char>& letters, vector<int>& score, map<char, int>& mLetters, map<int, bool>& selectedWords, int &maxScore){
        for (int j = 0; j <= 1; j++){
            selectedWords[i] = j;
            if (i == words.size()-1){
                maxScore = max(maxScore, Score(words, score, mLetters, selectedWords));
            } else {
                Try(i + 1, words, letters, score, mLetters, selectedWords, maxScore);
            }
        }
    }
    
};