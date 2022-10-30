#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
        
        
        string str1,str2, s, s2;
        cin >> s;
        cin >> s2;
        for(int i = 0; i<s.length(); i++) {
            char x;
            x = s.at(i);
            if (x == '#') {
                s.erase(s.begin() + i - 1, s.begin() + i + 1);
                i-=2;
            } 
        }
        for(int i = 0; i<s2.length(); i++) {
            char x;
            x = s2.at(i);
            if (x == '#') {
                s2.erase(s2.begin() + i - 1, s2.begin() + i + 1);
                i-=2;
            }
        }

        if (s == s2){
            cout << "Yes";
        } else {
            cout << "No";
        }
        return 0;
  }