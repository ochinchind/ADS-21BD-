#include <iostream>
#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;


int main(){
    int n; cin >> n; 
    int arr[n];
    int sum, x = 0;
    int arr1[n];
    for(int i =0; i <n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int right=n-1, left=0;

    while(right > left){

        if(arr[right] == arr[right-1]){
            
            n -=2;
            right -= 2;
        } else if(arr[right] > arr[right-1]){
            arr[right-1] = arr[right] - arr[right-1];
            n=n-1;
            right = right - 1;
        }
        sort(arr, arr+n);

    }
    if (n == 0){
        cout << 0;
    } else {
        cout << arr[0];
    }

}

