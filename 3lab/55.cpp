#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, k; 
    cin >> n >> k;
    int a[n][5], b[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> a[i][j];
        }
        sort(a[i], a[i] + 4);
        reverse(a[i], a[i] + 4);
        b[i] = a[i][0];
    }
    sort(b, b + n);
    int t = 0, t1 = 0;
    for(int i = 0; i < n; i++){
        if(k != t){
            t1 = b[i];
            t++;
        }else{
            break;
        }
    }
    cout << t1;

}