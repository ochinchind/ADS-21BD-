#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


int main()
{
    int n, x;
    cin >>n;
    std::list<int> list1;
    for (int i = 0; i<n; i++){
        cin >>x; 
        list1.push_back(x);
    }
    for (auto it = next(list1.begin(), 1); it != list1.end();) {
        it = list1.erase(it);
        if (it != list1.end())
            ++it;
    }
    for (auto it = list1.begin(); it != list1.end(); it++){
        std::cout << *it << "\t";
    }
    return 0;
}
 