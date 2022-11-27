#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int sumi = 0;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(i == j || i + j == n - 1) continue;
            else sumi += a[i][j];
        }
    }
    cout << sumi;
}