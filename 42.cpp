42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1, ans = 0, mx = 0, mi = 0;
        while (i <= j) {
            mi = min(height[i], height[j]);
            mx = max(mx, mi);
            ans += mx - mi;
            if (height[i] < height[j]) i++;
            else j--;
        }
        return ans;   
    }
};


int trap(vector<int>& height)
{
    if(height.empty())
        return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}


// Time Complexity: O(N)
// Space Complexity: O(N)
// where N is the length of height
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        // dp1[i]: the max height of bar from the left till position i
        // dp2[i]: the max height of bar from the right till position i
        vector<int> dp1(n), dp2(n);
        // let's build dp1 first
        dp1[0] = height[0];
        // for each position i, 
        // if the current height is greater than the max height, then dp1[i] will be height[i]
        // else dp1[i] will be taking the previous result, i.e. dp1[i - 1]
        for (int i = 1; i < n; i++) dp1[i] = max(dp1[i - 1], height[i]);
        // build dp2 in a similar way
        dp2[n - 1] = height[n - 1];
        // for each position i, 
        // if the current height is greater than the max height, 
        // then dp2[i] will be height[i]
        // else dp2[i] will be taking the previous result, i.e. dp2[i + 1]
        for (int i = n - 2; i >= 0; i--) dp2[i] = max(dp2[i + 1], height[i]);
        // then iterate the heights and take the minimum of dp1[i] and dp2[i]
        // why minimum? because that is the max height a bar can hold. (water will overflow)
        // then we substract height[i] from the min
        // if min(dp1[i], dp2[i]) is 2 and height[i] is 2, then no water is being trapped
        // if min(dp1[i], dp2[i]) is 2 and height[i] is 0, then 2 units of water are being trapped
        for (int i = 1; i < n - 1; i++) ans += min(dp1[i], dp2[i]) - height[i];
        return ans;
    }
};

Two Pointers
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
    public int trap(int[] height) {
        int i = 0, j = height.length - 1, ans = 0, mx = 0, mi = 0;
        // two pointers 
        // pointer i from the left
        // pointer j from the right
        while (i <= j) {
            // take the min height 
            mi = Math.min(height[i], height[j]);
            // find the max min height
            mx = Math.max(mx, mi);
            // the units of water being tapped is the diffence between max height and min height
            ans += mx - mi;
            // move the pointer i if height[i] is smaller
            if (height[i] < height[j]) i++;
            // else move pointer j
            else j--;
        }
        return ans;
    }
}