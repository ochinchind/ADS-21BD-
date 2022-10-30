#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >>n;
    cin >> k;
    deque<string> deque1;
    string str;
    for (int i = 0; i<n; i++){
        cin >> str;
        deque1.push_back(str);
    }

    for (int i = 0; i <k; i++){
        str = deque1.front();
        deque1.push_back(str);
        deque1.pop_front();
    }
    for (auto it = deque1.begin(); it != deque1.end(); ++it)
        cout << *it << " ";
    cout << endl;
    
    return 0;
}
 