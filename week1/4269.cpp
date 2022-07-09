/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/28 13:57
* @Description: AcWing 4269. 校庆 来源：PAT甲级真题1157
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> hash_mp;

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string str;
    while(n--) {
        cin >> str;
        hash_mp[str] = 1;
    }
    int m, ans = 0, flag = 0;
    cin >> m;
    string res = "999999999999999999", res2 = "999999999999999999";
    while(m--) {
        cin >> str;
        if(res2.substr(6, 8) > str.substr(6, 8)) res2 = str;
        if(hash_mp.count(str)) {
            ans++;
            if(res.substr(6, 8) > str.substr(6, 8)) res = str;
        }
    }
    if(!ans) {
        cout << ans << '\n' << res2;
    }
    else {
        cout << ans << '\n' << res;
    }
    return 0;
}