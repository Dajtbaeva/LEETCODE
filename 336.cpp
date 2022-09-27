336. Palindrome Pairs
https://leetcode.com/problems/palindrome-pairs/
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

class Solution {
public:
    static bool pali(string t, int i){
        if(i == t.size()) return true;
        if(t[i] != t[t.size() - i - 1]) return false;
        return pali(t, i + 1);
    }
    
    vector<vector<int>> palindromePairs(vector<string>& v) {
        vector<vector<int> > res;
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v.size(); j++){
                if(i != j){
                    vector<int> w;
                    string t = v[i] + v[j];
                    if(pali(t, 0)){
                        w.push_back(i);
                        w.push_back(j);
                    }
                    if(!w.empty()) res.push_back(w);
                }
            }
        }
        return res;
    }
};

struct TrieNode{
    TrieNode *child[26]={};
    int curIndex=-1;
    vector<int> wordIndex;
};
    
class Solution{
    bool isPalindrome(string &s, int i, int j){
        while (i < j){
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    TrieNode *root;
    void insert(string &s, int index){
        TrieNode *cur = root;
        for (int i = s.size() - 1; i >= 0; i--){
            int c = s[i] - 'a';
            if (cur->child[c] == nullptr)
                cur->child[c] = new TrieNode();
            if (isPalindrome(s, 0, i))
                cur->wordIndex.push_back(index);
            cur = cur->child[c];
        }
        cur->wordIndex.push_back(index);
        cur->curIndex = index;
    }
public:
    vector<vector<int>> palindromePairs(vector<string> &words){
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++){
            TrieNode *cur = root;
            string &s = words[i];
            for (int j = 0; j < s.size(); j++){
                if (cur->curIndex != -1 && cur->curIndex != i && isPalindrome(s, j, s.size() - 1))
                ans.push_back({i, cur->curIndex});
                cur = cur->child[s[j] - 'a'];
                if (cur == nullptr)
                    break;
            }
            if (cur == nullptr)
                continue;
            for (int j : cur->wordIndex){
                if (i == j)
                    continue;
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};

class Solution {
public:
    static bool pali(string word){
        int i = 0;
        int j = word.size() - 1;
        while (i < j) {
            if (word[i] != word[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& v) {
        vector<vector<int> > res;
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v.size(); j++){
                if(i != j && pali(v[i] + v[j])) res.push_back({i, j});
            }
        }
        return res;
    }
};
Time Complexity: O(n^2 * m)
Space Complexity: O(1)
