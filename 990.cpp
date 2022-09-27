990. Satisfiability of Equality Equations
https://leetcode.com/problems/satisfiability-of-equality-equations/
Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.


class Solution {
    unordered_map<char,char> par;
public:
	// Function for finding parent of variable
    char parent(char c){
        if(par[c]==c) return c;
        return par[c]=parent(par[c]);
    }
	
    // Function for doing union
    void unite(char a,char b){
        par[a]=b;
    }
    
    bool equationsPossible(vector<string>& equations) {
		// Making every variable parent of itself
        for(int i=0;i<26;i++) par['a'+i] = i+'a';
		
		// First pass
        for(auto &eqn : equations){
            char a = eqn[0];
            char b = eqn[3];
            
            if(eqn[1] == '='){
                char parA = parent(a);
                char parB = parent(b);
				
				// If parents of both variables are different, do union
                if(parA != parB)
					unite(parA,parB);
            }
        }
		
		// Second pass
        for(auto &eqn : equations){
            char a = eqn[0];
            char b = eqn[3];
            
            if(eqn[1] == '!'){
                char parA = parent(a);
                char parB = parent(b);
				
				// If parents of both variables are same, means contradiction
                if(parA == parB)
					return false;
            }
        }
		
		// If all equations are satisfied
        return true;
    }
};
