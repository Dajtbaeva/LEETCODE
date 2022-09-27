54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = 0, col = 0;
        int rowend = matrix.size();
        int colend = matrix[0].size();
        while(row < rowend && col < colend){
            for(int j = col; j < colend; j++)res.push_back(matrix[row][j]);
            row++;
            for(int i = row; i < rowend; i++)res.push_back(matrix[i][colend-1]);
            colend--;
            if(row < rowend){
                for(int j = colend-1; j >= col; j--)res.push_back(matrix[rowend - 1][j]);
                rowend--;
            }
            if(col < colend){
                for(int i = rowend - 1; i >= row; i--)res.push_back(matrix[i][col]);
                col++;
            }
        }
        return res;
    }
};