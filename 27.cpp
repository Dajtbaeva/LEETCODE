// Remove Element
// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).

class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        vector<int> res;
        res = nums;
        nums.clear();
        for(int i = 0; i < res.size(); i++){
            if(res[i] != val) nums.push_back(res[i]);
        }
        sort(nums.begin(), nums.end());
        return nums.size();
    }
};

// int[] nums = [...]; // Input array
// int val = ...; // Value to remove
// int[] expectedNums = [...]; // The expected answer with correct length.
//                             // It is sorted with no values equaling val.

// int k = removeElement(nums, val); // Calls your implementation

// assert k == expectedNums.length;
// sort(nums, 0, k); // Sort the first k elements of nums
// for (int i = 0; i < actualLength; i++) {
//     assert nums[i] == expectedNums[i];
// }