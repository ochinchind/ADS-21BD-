#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;





int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
                       
    long long left = 0, right =1e16, mid, a, sum;
    while (left <= right){
        mid = left + (right - left)/2;
        a = 1;
        sum = 0;
        for(int i = 0; i <n; i++){
            if(mid < sum + arr[i]){
                sum = 0; 
                a++;
            }
            if(mid < arr[i]){
                a = k+ 1;
            }
            sum += arr[i];
        }
        if (k < a){
            left = mid +1;
        } else {
            right = mid-1;
        }



    }
    cout << left;


    
    return 0;
}
 