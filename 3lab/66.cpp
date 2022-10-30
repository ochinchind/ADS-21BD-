#include<bits/stdc++.h>

using namespace std;
int main(){
    int n, m; 
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    for(int i = 0; i < m; i++){
        int p;
        cin >> p;
        int sum = 0, j = 0;
        for(j = 0; j < n; j++){
            if(p >= a[j])
            sum += a[j];
            else
            break;
        }
        cout << j << ' ' << sum << "\n";
    }
    

}