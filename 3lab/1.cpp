#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;





int main()
{
    int n, k, g, key;
    bool found;
    cin >>n;
    int arr[n];
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cin >> k >> g;
    int arr1[k][g];
    for(int i = 0; i < k; i++){
        for(int j = 0; j<g; j++){
            cin >> arr1[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        found = false;
        for(int row = 0; row < k; row++){
            if(found ==true){
                break;
            }
            if((row+2)%2==0){
                for(int col = g-1; col >=0;col--){
                    if(arr1[row][col]==arr[i]){
                        found =true;
                        cout << row << " "<<col<<"\n";
                    }
                    if(arr1[row][col]>arr[i]){
                        break;
                    }
                }
            } else {
                for(int col = 0; col <g; col++){
                    if(arr1[row][col] == arr[i]){
                        found = true;
                        cout << row<< " "<< col<<"\n";
                    }
                    if(arr1[row][col]>arr[i]){
                        break;
                    }
                }
            }
            
        }
        
        if(found==false){
            cout << "-1"<<"\n";
        }


    }
    
    return 0;
}
 