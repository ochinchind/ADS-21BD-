
#include<iostream>
#include<algorithm>
using namespace std;

int binSearch1(int a[], int l, int r, int l1, int n){
    if(l1 > a[n]){
        return -1;
    } else if(l1 <= a[0]){
        return 0;
    }
    if(l <= r){
        int mid = l + (r-l) / 2;
        if (a[mid]==l1){
            return mid;
        } else if (a[mid] < l1 && l1 < a[mid + 1]){
            return mid +1;
        } else if (l1 < a[mid] &&  a[mid - 1] < l1 ){
            return mid;
        }
        else if (a[mid] > l1){
            return binSearch1(a, l, mid-1, l1, n);
        }
        return binSearch1(a, mid+1, r, l1, n);

    }
    return -1;


}

int binSearch2(int a[], int l, int r, int r1, int n){
    if(r1 >= a[n]){
        return n;
    } else if (r1 < a[0]){
        return -1;
    }
    if (l <= r){
        int mid = l + (r-l) /2;
        if(a[mid] == r1){
            return mid;
        } else if(a[mid] < r1 && r1 < a[mid+1]){
            return mid ;
        } else if(r1 < a[mid] && a[mid -1] < r1){
            return mid -1;
        } else if(a[mid] > r1){
            return binSearch2(a, l, mid-1, r1, n);
        } 
        return binSearch2(a, mid +1, r, r1, n);


    }
    return -1;


}




int main(){
    int n, k; 
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i =0; i <k; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1 = binSearch1(arr, 0, n -1, l1, n-1);
        r1 = binSearch2(arr, 0, n-1, r1, n-1);
        l2 = binSearch1(arr, 0, n -1, l2, n-1);
        r2 = binSearch2(arr, 0, n-1, r2, n-1);
        if(l1 == -1 && r1 == -1){
            l1 = -1; 
            r1 = -1;
        }
        if(l2 == -1 && r2 == -1){
            l2 = -1; 
            r2 = -1;
        }
        if(l1 == -1 && l2 == -1){
            cout << 0 << "\n";
        } else if(l1 == -1 && l2 !=-1){
            cout << r2 - l2 + 1 << "\n";
        } else if(l1 != -1 && l2 == -1){
            cout << r1 - l1 + 1<< "\n";
        } else {
            if(l1 <= l2 && l2 <= r1){
                if(l1 <= r2 && r2 <= r1){
                    cout << r1 - l1 + 1 << "\n";
                }else{
                    cout << r2 - l1 + 1 << "\n";
                }
            }else if(l2 <= l1 && l1 <= r2){
                if(l2 <= r1 && r1 <= r2){
                    cout << r2 - l2 + 1 << "\n";
                }else{
                    cout << r1 - l2 + 1 << "\n";
                }
            }else{
                cout << r1 - l1 + 2 + r2 - l2 << "\n";
            }



        }



    }






    return 0;
}
