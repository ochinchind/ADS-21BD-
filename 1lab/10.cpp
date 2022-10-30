
#include <bits/stdc++.h>

using namespace std;


int main() {
        
        char n; 
        deque<int> deque1;
        int k;
        vector <string> v;
        while (cin >> n){
            if (n == '!') break;
            if (n == '+'){
                cin >> k;
                deque1.push_front(k);
            } else if(n == '-'){
                cin >> k;
                deque1.push_back(k);
            } else if (n == '*'){
                if (deque1.size() <=0){
                    cout << "error" << "\n";
                } else if (deque1.size() == 1) {
                    cout << deque1.front()+deque1.back() << "\n";
                    deque1.pop_back();
                    }
                    else {
                cout << deque1.front() + deque1.back() << "\n";
                deque1.pop_front();
                deque1.pop_back();
                }
            }
        }

        return 0;
  }