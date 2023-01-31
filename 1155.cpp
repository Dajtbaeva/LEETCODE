// not my solution
1155. Number of Dice Rolls With Target Sum
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

We build a dp soution starting from recursion.
Basic idea is simple, we start with N dice rolls, and K as the target sum.

We roll once and get d as the outcome.
So, now we are left with N-1 rolls, and K-d as the target.
We use this recursion to create combine_recursion solution.
Building on that is the combine_tabulate function and reduces the time complexity from O(K^N) to O(K*N*target).

#define mod int(1e9+7)

class Solution 
{
private:
    // Time complexity = O(k^n)
    // Space complexity = O() ??
    int combine_recursive(int n, int k, int target)
    {
        // Reached the target
        if(target==0)
            return 1;

        // Base exit cases
        if((target<0) || (n<=0))
            return 0;
        
        int num_ways=0;
        for(int i=1; i<=k; i++)
            num_ways+= combine_recursive(n-1, k, target-i);
        
        return num_ways;
    }
    
    // Time complexity = O(n*k*target)
    // Space complexity = O(target*n)
    int combine_tabulate(int n, int k, int target)
    {
        long long int table[target+1][n+1];
        memset(table, 0, sizeof(table));
        
        // Initialize the base true conditions. 
        for(int i=1; i<=min(k,target); i++)
            table[i][1]=1;
        
        for(int i=i; i<=target; i++)
        {
            for(int j=1; j<=n; j++)
            {
                for(int ki=1; ki<=k; ki++)
                {
                    if((i-ki)>=0)
                        table[i][j] += table[i-ki][j-1];
                    table[i][j] %= mod;
                }
            }
        }
        
        return table[target][n];
    }
    
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        // If the target is less than what's the least possible outcome reject it
        // Reject if the target is larger than what's possible at max.
        if(n>target)
        //if((n>target) || (n*k<target))
            return 0;
        
        return combine_tabulate(n, k, target);
    }
};