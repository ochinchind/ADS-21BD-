#include <bits/stdc++.h>

using namespace std;

int binSearch(int arr[], int n, int target){
    int l =0;

    while(l <= n){
        int mid = (l+n)/2;
        if (arr[mid] == target){
            return mid;
        } else if(arr[mid] > target) {
            n = mid -1;
        } else{
            l = mid+1;
        }
    }
    return -1;

}


int main(){
    int n, k; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    int a=binSearch(arr, n-1, k);
    if(a==-1){
        cout <<"No";
    } else cout<<"Yes";


    


    return 0;
}