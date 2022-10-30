#include <bits/stdc++.h>
using namespace std;


long long getTime(vector<long long> &bags, long long size) {
    long long ans = 0;
    for(auto i : bags) { // (auto i : bags) = (int i = 0; i < bags.size(); i ++)
        ans += i/size;
        if(i%size)
            ans++;
    }
    return ans;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> bags(n);


    for(auto &i: bags) 
        cin >> i;

    long long left = 0, right = 1e18+123;
    while(left + 1 < right) {
        long long mid = (left+right)/2;
        long long time = getTime(bags, mid);
        if(time <= m)
            right = mid;
        else
            left = mid;
    }
    cout << right;
    return 0;
}