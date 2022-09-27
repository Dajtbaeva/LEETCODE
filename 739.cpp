739. Daily Temperatures

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();     
        if(st.empty()){
            ans[i] = 0;
            st.push(i);
            }else{
                ans[i] = st.top()-i;
                st.push(i);
            } 
        }
        return ans;
    }
};