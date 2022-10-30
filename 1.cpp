#include <deque>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 1e5;
int n;
ll a[N];

void heapify_up(int v){
    while(v != 1 && a[v/2] < a[v]){
        swap(a[v/2], a[v]);
        v = v/2;
    }
}

void heapify_down(int v){
    int mx=v; 
    if(2*v <= n && a[v*2] > a[mx]){
        mx = v*2;
    }
    if(2*v+1 <= n && a[v*2+1] > a[mx]){
        mx = v*2+1;
    }
    if(mx != v){
    swap(a[v], a[mx]);
    heapify_down(mx);
    }
}

void insert(ll x){
    a[++n] = x;
    heapify_up(n);

}

ll pop_top1(){
    ll root = a[1];
    swap(a[1], a[n--]);
    heapify_down(1);
    return root;
}


int main(){

    insert(543);
    insert(3245);
    insert(1234);
    insert(436);
    insert(634);
    while(true){
        cout << pop_top1() << " ";
        if (a[1] == 0){break;}
    }



    return 0;
}