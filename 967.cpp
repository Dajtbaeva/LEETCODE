967. Numbers With Same Consecutive Differences
https://leetcode.com/problems/numbers-with-same-consecutive-differences/
Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.
Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

// BFS
class Solution {
public:
    // The idea is to use BFS to try appending 0 - 9 to each number 
    // starting from a single digit 1 - 9 until the number has n digits
    vector<int> numsSameConsecDiff(int n, int k) {
        // push all numbers with single digit to a deque
        deque<int> q{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        // do the following logic n - 1 times
        while (--n > 0) {
            // get the queue size
            int sz = q.size();
            // for each item in the current queue,
            // do the following logic
            for (int i = 0; i < sz; i++) {
                // get the first number from the queue
                int p = q.front();
                // pop it
                q.pop_front();
                // we can potentially add 0 to 9 to the current number p
                for (int j = 0; j < 10; j++) {
                    // we use p % 10 to get the last digit of p
                    // then get the difference with j
                    // since (p % 10) - j can be negative and positive
                    // we use abs to cover both case
                  if (abs((p % 10) - j) == k) {
                    // if the difference is equal to k
                    // we can include digit j 
                    // so multiply the current number by 10 and add j
                    q.push_back(p * 10 + j);
                  }
                }
          }
        }
        // return all numbers in deque, return them in vector<int>
        return vector<int>{q.begin(), q.end()};
    }
};

// DFS
class Solution {
public:
	//To find digits in the current number
    int digits(int x) {
        int count = 0;
        while(x){
			count++;
            x = x/10;
        }
        return count;
    }
    void findNumbers(int cur_digit , int n ,int k, vector<int> &result){
		//Base case
        if(digits(cur_digit ) == n) {
            result.push_back(cur_digit);
            return;
        }
        for(int i=0;i<10;i++) {
           int last_digit = cur_digit  % 10;
           if(abs(last_digit - i) == k) 
           {
               findNumbers((cur_digit *10 + i), n, k, result); 
           } 
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result; 
        for(int i=1;i<10;i++) {
            findNumbers(i, N, K, result);    
        }
        return result; 
    }
};
