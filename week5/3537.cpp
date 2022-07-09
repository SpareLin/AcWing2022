/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/4 10:37
* @Description: 3537. 树查找 来源：北京邮电大学考研机试题
 * 暴力
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e3 + 7;
vector<int> v[21];
int n, k, arr[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> k;
    int first = 0, index = 0;
    for (int i = 1; i <= k; i++) {
        index += 1 << (i - 1);
        for (int j = first; j < index && j < n; j++) {
            v[i].push_back(arr[j]);
            first++;
        }
    }
    if(1 << k - 1 > n) cout << "EMPTY";
    else for (auto x: v[k]) cout << x << ' ';
    return 0;
}