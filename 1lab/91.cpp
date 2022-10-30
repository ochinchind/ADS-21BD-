#include <bits/stdc++.h> 
using namespace std; 
int main (){ 
    int n; cin >> n; 
    string str; 
    cin >> str; 
    deque <int> s; 
    deque <int> k; 
    for (int i = 0; i < str.size(); i++){ 
        if (str[i] == 'S'){ 
            s.push_back(i); 
        } else { 
            k.push_back(i); 
        } 
    } 
    while(!k.empty() and !s.empty()){ 
        int i = s.front(); 
        int j = k.front(); 
        if (i < j){ 
            k.pop_front(); 
            s.push_back(i + n); 
            s.pop_front(); 
        } else if (j < i) { 
            s.pop_front(); 
            k.push_back(j + n); 
            k.pop_front(); 
        } 
    } 
    if (k.empty()){ 
        cout << "SAKAYANAGI"; 
    } else cout << "KATSURAGI";  
}