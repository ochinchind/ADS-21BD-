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
        if(i){
            arr[i] += arr[i-1];
        }
    }


    for(int i =0; i<k; i++){
        int mis;
        cin >> mis;

        int l=0,r=n;
        while(l <r){
            int mid = (l+r)/2;
            if(arr[mid] >= mis){
                r=mid;
            } else {
                l =mid+1;
            }

        }
        cout << r+1<< "\n";


    }

    
    
    



    return 0;
}