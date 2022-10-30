#include <iostream>
#include <bits/stdc++.h>
#include <cassert>

using namespace std;

const int N = (int) 1e5 +5;
typedef pair<int,int> pii;

pii a[N];

int n, m;

int main(){
    scanf("%d", &n);
    for(int i =1;i<=n; i++){
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    sort(a+1, a+n+1);
    scanf("%d", &m);

}