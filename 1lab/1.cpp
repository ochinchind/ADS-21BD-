
#include <bits/stdc++.h>


using namespace std;


int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++){
        deque<int> deque1;
        for (int j = arr[i]; j > 0; j--){
            deque1.push_front(j);
            for (int h = 0; h < j; h++){
                k = deque1.back();
                deque1.push_front(k);
                deque1.pop_back();
            }
        }
        for (auto it = deque1.begin(); it != deque1.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }


    
  }