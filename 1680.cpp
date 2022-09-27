class Solution {
public:
    int length(int n){
        return log2(n) + 1; // length of binary representation of a n number
        
    }
    int concatenatedBinary(int n) {
        long ans = 0; // even tho return type is int.
        int mod = 1e9 + 7;
        
        for(int i=1;i<=n;i++){
            int len = length(i);
            ans = ((ans << len) % mod + i) % mod; // left shift the ans and then add the i number init,(concatenate)
        }
        
        
        
        return ans % mod;
    }
};

class Solution {
public:
    string bin(int n){
        string res = "";
        while(n > 0){
            res = char((n % 2) + 48) + res;
            n /= 2;
        }
        return res;
    } 
    int concatenatedBinary(int n) {
        string s = "";
        int long long m = pow(10, 9) + 7;
        for(int i = 1; i <= n; i++){
            s += bin(i);
        }
        int ans = 0, j = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            int a = s[i] - 48;
            ans += (a * pow(2, j));
            j++;
        }
        return ans % m;
    }
};

class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9+7, length = 0;
        for (int i = 1; i <= n; ++i) {
            
            if ((i & (i - 1)) == 0) length++;
            ans = ((ans << length) + i) % mod;
        }
        return ans;
    }
};
