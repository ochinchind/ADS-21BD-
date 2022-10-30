#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int n, k, max, c, cnt1, cnt2 ;
    cnt2 = -1;
    cin >>n;
    std::list<int> list1;
    std::list<int> list2;
    for (int i =0; i<n; i++){
        cin >>k;
        list1.push_back(k);
    }
    for (auto it = list1.begin(); it != list1.end(); it++){
        cnt1=0;
        for (auto iter = list1.begin(); iter != list1.end(); iter++){
        if(*it == *iter){
            cnt1++;
        }
    }
    if (cnt1>cnt2){
            cnt2=cnt1;
            max = *it;
        }
    }
    for (auto it = list1.begin(); it != list1.end(); it++){
        cnt1=0;
        for (auto iter = list1.begin(); iter != list1.end(); iter++){
        if(*it == *iter){
            cnt1++;
        }
    }
    if (cnt1==cnt2){
            list2.push_back(*it);
        }
    }
    list2.sort();
    list2.unique();
    for (auto it = list2.crbegin(); it != list2.crend(); ++it){
        cout << *it << " ";
    }
    return 0;
}
 