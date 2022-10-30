#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,k;
    cin >>n>>k;

    int arr[n],arr1[n];

    for(int i = 0; i < n; i++){
        for(int j=0; j<4; j++){
            cin >> arr[j];
        }
        sort(arr, arr + 4);
        arr1[i] = arr[3];

    }

    sort(arr1, arr1 + n);

    int b = arr1[k-1];
    cout << b;


    return 0;
}