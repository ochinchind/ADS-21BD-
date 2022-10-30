
#include <bits/stdc++.h>


using namespace std;


int main() {
    string expr;
    cin >> expr;
    
    stack<char> temp;
    for (int i = 0; i < expr.length(); i++) {
        if (temp.empty()) {

            temp.push(expr[i]);
        }
        else if (temp.top() == expr[i]) {

            temp.pop();
        }
        else {
            temp.push(expr[i]);
        }
    }


    if (temp.empty()){
        cout << "YES";
    } else {
        cout << "NO";
    }


    

    
  }