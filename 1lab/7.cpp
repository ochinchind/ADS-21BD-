
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int n ,chk;
    cin >> n;
    std::vector< int > arr,arr2;
    for(int i=0; i <10000; i++){
        for (int j=2; j<i;j++){
            if(i%j==0){
                chk++;
                break;
            }
        }
        if(chk==0 && i!=1)
            arr.push_back(i);
        chk = 0;
    }
    for (int i=0; i<arr.size(); i++){
        for (int j=2; j<i;j++){
            if(i%j==0){
                chk++;
                break;
            }
        }
        for (int j=2; j<i;j++){
            if(arr[i]%j==0){
                chk++;
                break;
            }
        }
        if (chk==0 && i!=1 )
            arr2.push_back(arr[i]);
        chk = 0;
    }
    cout << arr2[n];
    
    return 0;
}
 