#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int getNearest(int x, int y, int target) {
   if (target - x >= y - target)
      return y;
   else
      return x;
}
int getNearestElement(int arr[], int n, int target) {
   if (target <= arr[0])
      return arr[0];
   if (target >= arr[n - 1])
      return arr[n - 1];
   int left = 0, right = n, mid = 0;
   while (left < right) {
      mid = (left + right) / 2;
      if (arr[mid] == target)
         return arr[mid];
      if (target < arr[mid]) {
         if (mid > 0 && target > arr[mid - 1])
            return getNearest(arr[mid - 1], arr[mid], target);
            right = mid;
      } else {
         if (mid < n - 1 && target < arr[mid + 1])
            return getNearest(arr[mid], arr[mid + 1], target);
         left = mid + 1;
      }
   }
   return arr[mid];
}

int main()
{
    int n, k, g, key;
    cin >>n;
    int arr[n], arr2[n], arr3[n];
    for (int i =0; i<n; i++){
        cin >> arr[i];
    }
    cin >> k;
    for (int i =0; i<n; i++){
        arr2[i] = arr[i] - k;
    }
    for (int i =0; i<n; i++){
        arr3[i] = arr2[i];
    }
    sort(arr2, arr2+n);
    int near = getNearestElement(arr2, n, 0);
    for(int i =0; i<n; i++){
        if((arr3[i] == near) || (arr3[i] == k-near-k) ){
            key = i;
            break;
        }
    }
    cout << key;
    
    
    return 0;
}
 