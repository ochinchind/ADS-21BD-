#include <iostream>
#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;


int main(){
    int n, x; cin >> n >> x; 
    int arr[n];
    int sum = 0;
    int arr1[n];
    for(int i =0; i <n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int right=n-1, left=0;

    while(x > 0){
        right = n-1;
        if(arr[right-1] >= arr[right]){
            while(arr[right-1] >= arr[right]){
                if(right == left){
                    break;
                }
                right -= 1;
            }
        }
        sum += arr[right];

        arr[right] = arr[right] -1;
        x -= 1;


    }
    cout << sum;
}

