#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int arr[], int n, int x){
    int l = 0, r = n-1;
    int large = n, sum = 0;
    while(l <= r){
        int m = l + (r-l)/2;
        if(arr[m] > x){
            r = m-1;
            large = m;
        }else l = m+1;
    }
    return large;
}
int answer(int a[], int n, int l1, int r1, int l2, int r2){
    int cnt = 0, d  = 0;
    int first = binarySearch(a, n, r1) - binarySearch(a, n, l1-1);
    int second = binarySearch(a, n, r2) - binarySearch(a, n, l2-1);
    if(l2 <= l1 and r2 >= r1)return second;
    else if(l1 <= l2 and r1 >= r2)return first;
    else if(l1 < r2 and r1 >= r2)d = binarySearch(a, n, r2) - binarySearch(a, n, l1-1);
    else if(l2 < r1 and r2 >= r1)d = binarySearch(a, n, r1) - binarySearch(a, n, l2-1);
    return first + second - d;
}
int main(){
    int n,  q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 0; i < q; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << answer(arr, n, l1, r1, l2, r2) << endl;
    }
}