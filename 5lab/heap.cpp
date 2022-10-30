#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

const int N = (int)1e5 + 7;

void heapify_up(int *a , int &n, int v){
    while (v != 1 && a[v] > a[v/2]){
        swap(a[v], a[v/2]);
        heapify_up(a, n, v/2);
    }


}

void heapify_down(int *a, int&n, int v){
    int mx = v;
    if(2*v <= n && a[mx] < a[2*v]) mx = 2*v;
    if(2*v+1 <=n && a[mx]<a[2*v+1]) mx = 2*v+1;
    if(mx == v)
    return;
    swap(a[mx], a[v]);
    heapify_down(a, n, mx);

}

void push(int *a, int &n, int x){
    n++;
    a[n] = x;
    heapify_up(a, n, n);

}
void pop(int *a, int &n, int key){
    swap(a[1], a[n]);
    n--;
    heapify_down(a, n, n);

}
int top(int *a, int &n, int key){
    return a[1];

}

int a[N], n;

void print (int *a,int n, int v, int tab=0){
    for(int i =0; i < tab; i++ )
    printf("\t");
    printf("%d\n", a[v]);
    if(2*v <=n ) print (a, n, 2*v, tab+1);
    if (2*v+1 <= n) print(a, n, 2*v+1, tab +1);

}


int main(){
    int n = 0;
    push(a, n, 2);
    push(a, n, 5);
    push(a, n, 3);
    push(a, n, 4);
    push(a, n, 1);


    print(a, n, 1);
    pop(a,n,1);
    print(a, n, 1);

    return 0;
}