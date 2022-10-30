#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
 
	int n;
    bool og = false;
    cin >> n;
    for (int i = 2; i < n; i++) {
        if(n%i == 0){
            og = true;
            break;
        }
    }
    if (n == 1) {
        cout << "NO";
    } else if (og == true){
        cout << "NO";
    } else {
        cout << "YES";
    }
    
	return 0;
}
 