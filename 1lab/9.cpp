#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int n, k, sa = 0;
    cin >>n;
    string str;
    cin >> str;
    string s[n];
    for (int i =0; i<n; i++){
        std::string g = std::to_string(i);
        if (str.at(i) == 'K') 
            s[i] = ('K'+g); else
            s[i] = ('S'+g);
    }

    for (int i =0; i < n; i++){
        std::string g = std::to_string(i);
        std::string go = std::to_string(i+1);
        if(s[i] == "K"+g && s[i+1] == "S" + go) 
        s[i+1] = "0"; 
        if(s[i] == "S"+g && s[i+1] == "K" + go) 
        s[i+1] = "0";
        
    }

    for(int i =0; i<n; i++){
        std::string g = std::to_string(i);
        if(s[i] == "K"+g)
        k++;
        if(s[i] == "S"+g)
        sa++;
    }


    if (sa>k) cout << "SAKAYANAGI"; else cout << "KATSURAGI";
    
    return 0;
}
 