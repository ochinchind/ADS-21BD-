#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int binSearch(int arr[], int a, int target){
    int l = 0, length = a - 1, max = a, sum= 0;
    while(l<=length){
        int mid = l + (length -l)/2;
        if(arr[mid]>target){
            length = mid -1 ; 
            max = mid;
        } else l = mid + 1;
    }
    return max;

}



int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n], a, b;
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i =0; i <k; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int cnt =0;
        int first=binSearch(arr, n, r1) - binSearch(arr, n, l1-1), second = binSearch(arr, n, r2) - binSearch(arr, n, l2-1);
        if(l2 <= l1 and r2 >= r1){
            cout << second << "\n";
            continue;
        }
        else if(l1 <= l2 and r1 >= r2){
            cout << first << "\n";
            continue;
        }
        else if(l1 < r2 and r1 >= r2)cnt = binSearch(arr, n, r2) - binSearch(arr, n, l1-1);
        else if(l2 < r1 and r2 >= r1)cnt = binSearch(arr, n, r1) - binSearch(arr, n, l2-1);
        cout << first + second - cnt << "\n";
    }


    return 0;
}
 