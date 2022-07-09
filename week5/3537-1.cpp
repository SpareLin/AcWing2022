/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/4 11:38
* @Description: 
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 7;
int n, l, r, k, arr[MAXN];

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    cin >> k;
    l = 1 << (k - 1), r = (1 << k) - 1;
    if(l > n) {
        cout << "EMPTY";
        return 0;
    }
    for (int i = l; i <= min(n, r); ++i) {
        cout << arr[i] << ' ';
    }
    return 0;
}