59. Spiral Matrix II
https://leetcode.com/problems/spiral-matrix-ii/
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> reslast;
        int arr[n][n];
        int row = 0, col = 0;
        int rowend = n;
        int colend = n;
        int cnt = 1;
        while(row < rowend && col < colend){
            for(int j = col; j < colend; j++){
                arr[row][j] = cnt;
                cnt++;
            }
            row++;
            for(int i = row; i < rowend; i++){
                arr[i][colend - 1] = cnt;
                cnt++;   
            }
            colend--;
            if(row < rowend){
                for(int j = colend-1; j >= col; j--){
                    arr[rowend - 1][j] = cnt;
                    cnt++;
                }
                rowend--;
            }
            if(col < colend){
                for(int i = rowend - 1; i >= row; i--){
                    arr[i][col] = cnt;
                    cnt++;
                }
                col++;
            }
        }
        for(int i = 0; i < n; i++){
            vector<int> tmp;
            for(int j = 0; j < n; j++){
                tmp.push_back(arr[i][j]);
            }
            reslast.push_back(tmp);
        }
        return reslast;
    }
};