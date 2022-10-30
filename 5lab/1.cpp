#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 500;

int n;
ll a[N];

void heapify_up(int v){
    while (v != 1 && a[v/2] > a[v]){
        swap(a[v/2], a[v]);
        v = v/2;
    }
}

void heapify_down(int v){
    int mx = v;
    if (2*v <= n && a[2*v] < a[mx])
        mx = 2*v;
    if (2*v+1 <= n && a[2*v+1] < a[mx])
        mx = 2*v+1;
    if (mx != v){
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

void print (int n, int v, int tab=0){
    for(int i =0; i < tab; i++ )
    printf("\t");
    printf("%d\n", a[v]);
    if(2*v <=n ) print (n, 2*v, tab+1);
    if (2*v+1 <= n) print(n, 2*v+1, tab +1);

}

void build(){
    for (int i = 1; i <= n; i++)
        heapify_up(i);
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build();
    ll sum;

    while (n > 1){
        ll a = pop_top1();
        ll b = pop_top1();
        sum += a + b;
        insert(a + b);
    }

    cout << sum;

    return 0;
}