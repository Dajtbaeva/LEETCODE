#include <bits/stdc++.h>

using namespace std;

int main(){
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(x3 <= x2 && x3 >= x1 && y3 <= y1 && y3 >= y2) cout << "yes";
    else cout << "no";
}