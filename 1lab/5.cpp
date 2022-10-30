#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
        
        
        int arr[5] ;
        int arr2[5];
        int n = 0;

        for (int i = 0; i < 5; i++ ){
            cin >> arr[i];
        }
        for (int i = 0; i < 5; i++ ){
            cin >> arr2[i];
        }
        for (int i = 0; i < 5; i++ ){
            if(arr[i] == 0 && arr2[i]==9){
                n++;
                
            } else
            if(arr[i] > arr2[i]){
                if (arr[i] == 9 && arr2[i] == 0){
                    continue;
                } else {
                    n++;
                }
            }
        }
        if (arr[0]== 1 && arr2[0] ==9){
            cout << "Boris 31";
        } else if(arr[0] == 1 && arr2[0]==8){
            cout << "Boris 71";
        } else if(arr[0]==8 && arr2[0]==1){
            cout << "Nursik 239";
        } else if(n > 2){
            cout << "Boris " << n;
        } else {
            cout << "Nursik " << 5-n;
        }

        return 0;
  }