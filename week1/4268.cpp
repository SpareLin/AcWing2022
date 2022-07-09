/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/28 13:55
* @Description: AcWing 4268. 性感素数 来源：PAT甲级真题1156
*/

#include <iostream>
#include <cmath>
using namespace std;

int prime(int x) {
    if(x < 2) return 0;
    else {
        for (int i = 2; i <= sqrt(x); ++i) {
            if(x % i == 0)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    if(prime(n) && (prime(n + 6) || prime(n - 6))) {
        cout << "Yes" << '\n';
        if(prime(n - 6)) cout << n - 6 << '\n';
        if(prime(n + 6) && !prime(n - 6)) cout << n + 6 << '\n';
    }
    else {
        cout << "No" << '\n';
        while(1) {
            n++;
            if(prime(n) && (prime(n + 6) || prime(n - 6))) {
                cout << n << '\n';
                break;
            }
        }
    }
    return 0;
}