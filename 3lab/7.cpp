#include <bits/stdc++.h>

using namespace std;

long long santa(int arr[], long long bag, int n){
    long long t = 0;
    for(int i = 0; i < n; i++){
        t += arr[i] / bag;
        if (arr[i] % bag){
            t++;
        }
    }
    return t;


}


int main(){
    int n, k; 
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long l=0, r=1e15;

    while(l+1 < r){
        long long mid=(l+r)/2;
        long long t = santa(arr, mid, n);
        if(t <= k){
            r=mid;
        } else {
            l=mid;
        }
    }
    cout << r;
    
    



    return 0;
}