#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >>n;

    int arr[n],arr1[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int k, p;
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> p;
        int sum = 0, cnt = 0;
        for(int j = 0; j <n; j++){
            if (p >= arr[j]){
                cnt = j+1;
                sum += arr[j];
                
            } else break;
            
        }
        cout << cnt<< " " << sum << "\n";


    } 


    return 0;
}