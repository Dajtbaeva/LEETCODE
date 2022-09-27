1996. The Number of Weak Characters in the Game
https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

Input: properties = [[1,5],[10,4],[4,3]]

[[5,5],[6,3],[3,6]]
6, 3 
class Solution {
public:
    static bool comp(vector<int> &v1, vector<int> &v2){
        if(v1[0] == v2[0]) return v1[1] > v2[1];
        else return v1[0] < v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int res = 0;
        int n = a.size();
        sort(a.begin(), a.end(), comp);
        int maxi = a[n - 1][1];
        for(int i = n - 2; i >= 0; i--){
            if(a[i][1] < maxi) res++;
            maxi = max(maxi, a[i][1]);
        }
        return res;
    }
};



























































class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int res = 0;
        for(int i = 0; i < properties.size(); i++){
            int f, s = properties[i][0], properties[i][1];
            for(int j = 0; j < properties.size(); j++){
                if(i != j && properties[j][0] > f && properties[j][1] > s) res++;
            }
        }
    }
};

class Solution {
public:
    // the idea is to
    // 1. rearrange the order of attack in ascending order
    // 2. count weak characters (those defenses less than the current maximum defense)
    // 3. update the maximum defense
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        // the final answer to be returned
        int weakCharacters = 0;
        // record maximum defense. since 1 <= defense_i <= 10 ^ 5
        // we can set the init value to x where x < 1
        int maxDefense = 0;
        // use a hash map to map the attack and defense with greater<int> as a key_compare
        map<int, vector<int>, greater<int>> m;
        for(auto x : p) m[x[0]].push_back(x[1]);
        // for each attack
        for(auto x : m) {
            // we count the number of weak characters 
            // and add it to `weakCharacters`
            weakCharacters += count_if(x.second.begin(), x.second.end(), [&](int curDefense){ return curDefense < maxDefense;});
            // then update `maxDefense` which is the maximum value in current defenses
            maxDefense = max(maxDefense, *max_element(x.second.begin(), x.second.end()));
        }
        return weakCharacters;
    }
};


class Solution {
public:
    
    static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        
        int n = arr.size();
        
        // sort the arr
        
        sort(arr.begin(), arr.end(), compare);
        
        int count = 0;
        
        // max_defence will keep track of maximum defence from last
        
        int max_defence = arr[n - 1][1];
        
        for(int i = n - 2; i >= 0; i--)
        {
		    // if curr_defence is less than max_defence
			
            if(arr[i][1] < max_defence)
            {
                count++;
            }
            
            // update max_defence
            
            max_defence = max(max_defence, arr[i][1]);
        }
        
        return count;
    }
};


class Solution {
public:
    static bool sortcol(const vector<int>& v1,const vector<int>& v2)
    {
        if(v1[0]!=v2[0])
            return v1[0] < v2[0];
        return v1[1]>v2[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        sort(properties.begin(),properties.end(),sortcol);
        int maxdefence=INT_MIN;
        int ans=0;
        int n=properties.size();
        for(int i=n-1;i>=0;i--)
        {
            if(properties[i][1]<maxdefence)
            {
                ans++;
            }
            maxdefence=max(maxdefence,properties[i][1]);
        }
        return ans;
    }
};
