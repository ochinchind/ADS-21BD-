#include<iostream>
#include<algorithm>
using namespace std;
int binarySearchL(int a[], int l, int r, int x, int t){
    if(x > a[t]){
        return -1;
    }else if(x <= a[0]){
        return 0;
    }
    if(l <= r){
        int s = l + (r - l) / 2; 
        if(a[s] == x){
            return s;
        }else if(a[s] < x && x < a[s + 1]){
            return s + 1;
        }else if(a[s - 1] < x && x < a[s]){
            return s;
        }
        else if(a[s] > x){
            return binarySearchL( a, l, s - 1, x, t);
        }
        return binarySearchL( a, s + 1, r, x, t);
    }
    return -1;
}
int binarySearchR(int a[], int l, int r, int x, int t){
    if(x >= a[t]){
        return t;
    }else if(x < a[0]){
        return -1;
    }
    if(l <= r){
        int s = l + (r - l) / 2;
        if(a[s] == x){
            return s;
        }else if(a[s] < x && x < a[s + 1]){
            return s;
        }else if(a[s - 1] < x && x < a[s]){
            return s - 1;
        }else if(a[s] > x){
            return binarySearchR( a, l, s - 1, x, t);
        }
        return binarySearchR( a, s + 1, r, x, t);
    }
    return -1;
}
int main(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);
    for(int i = 0; i < k; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1 = binarySearchL(a, 0, n - 1, l1, n - 1);
        r1 = binarySearchR(a, 0, n - 1, r1, n - 1);
        l2 = binarySearchL(a, 0, n - 1, l2, n - 1);
        r2 = binarySearchR(a, 0, n - 1, r2, n - 1);
        if(l1 == -1 && r1 == -1){
            l1 = -1; r1 = -1;
        }
        if(l2 == -1 && r2 == -1){
            l2 = -1; r2 = -1;
        }
        if(l1 == -1 && l2 == -1){
            cout << 0 << "\n";
        }else if(l1 == -1 && l2 != -1){
            cout << r2 - l2 + 1 << "\n";
        }else if(l1 != -1 && l2 == -1){
            cout << r1 - l1 + 1 << "\n";
        }else{
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
    

}