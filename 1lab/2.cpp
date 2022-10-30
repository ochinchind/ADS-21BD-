#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
        
    int n, x, k;
    
    cin >> n;
    int arr[n] ;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }
    int gg[n];
    for (int i = 0; i < n; i++){
        k = arr[i];
        bool og = false;
        for (int j = i-1; j >= 0; j--){
            if (og == true){
                continue;
            }
            if (k >= arr[j]){
                k = arr[j];
                og = true;
            }
        }
        if (og == false){
            gg[i] = -1;
        } else {
            gg[i] = k;
        }
    }
    for (int i = 0; i < n; i++){
        cout << gg[i] << " ";
    }

  }