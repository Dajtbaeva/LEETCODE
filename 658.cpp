658. Find K Closest Elements
https://leetcode.com/problems/find-k-closest-elements/

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>win(k,0);
        deque<int>q;
        int sumi = 0;
        for(int i = 0; i < k; ++i){
            q.push_back(arr[i]);
            sumi += (abs(arr[i] - x));
        }
        int mn=sumi;
        for(int i = k; i < arr.size(); ++i){
            sumi -=(abs(arr[i - k] - x));
            sumi +=(abs(arr[i] - x));
            if(sumi < mn){
                mn = sumi;
                q.pop_front();
                q.push_back(arr[i]);
            }
        }
        int i = 0;
        while(!q.empty()){
            win[i++] = q.front();
            q.pop_front();
        }
        return win;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        priority_queue<int> pq;
        map<int, vector<int>> mp;
        
        int diff = 0;
        for (int i : arr) {
            diff = abs(i-x);
            
            if (mp.find(diff) != mp.end())
                mp[diff].push_back(i);
            else
                mp.insert(pair<int, vector<int>>(diff, {i}));
        }
        
        
        // USING PQ
//         for (auto pair:mp){
//             for (int i : pair.second){
//                 if (k >=1 ){
//                     pq.push(-i);     // To treat the priority queue as min heap instead of max heap
//                     k-=1;
//                 }
//                 else
//                     break;
//             }
//             if (k < 1)
//                 break;
//         }
        
//         while (!pq.empty()){
//             result.push_back(-pq.top());
//             pq.pop();
//         }
        
        // WITHOUT USING PQ
        
         for (auto pair:mp){
            for (int i : pair.second){
                if (k >=1 ){
                    result.push_back(i);
                    k-=1;
                }
                else
                    break;
            }
            if (k < 1)
                break;
        }
        
        sort(result.begin(),result.end());
       
        return result;
    }
};


class Solution
{
public:
    vector<int> findClosestElements(vector<int> &a, int k, int x)
    {
        int n = a.size(), idx = lower_bound(a.begin(), a.end(), x) - a.begin();
        int i = idx - 1, j = idx;
        for(int time = 1; time <= k; time++)
        {
            int left = i >= 0 ? abs(a[i] - x) : INT_MAX;
            int right = j < n ? abs(a[j] - x) : INT_MAX;
            if (left <= right)
                i--;
            else
                j++;
        }
        return vector<int>(a.begin() + i + 1, a.begin() + j);
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>win(k,0);
        deque<int>q;
        int sum=0;
        for(int i=0;i<k;++i)
        {
            q.push_back(arr[i]);
            sum+=(abs(arr[i]-x));
        }
        int mn=sum;
        for(int i=k;i<arr.size();++i)
        {
            sum-=(abs(arr[i-k]-x));
            sum+=(abs(arr[i]-x));
            if(sum<mn)
            {
                mn=sum;
                q.pop_front();
                q.push_back(arr[i]);
            }
        }
        int i=0;
        while(!q.empty())
        {
            win[i++]=q.front();
            q.pop_front();
        }
        return win;
    }
};
