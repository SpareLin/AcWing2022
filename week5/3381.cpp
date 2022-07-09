/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/7 22:08
* @Description: 3381. 手机键盘 来源：清华大学考研机试题
*/

#include <iostream>
#include <unordered_map>

using namespace std;

typedef pair<int, int> PII;
unordered_map<char, PII> mp;
string s[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main() {
    for (int i = 2; i <= 9; ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            mp[s[i][j]] = {i, j + 1};
        }
    }
    string str;
    while (cin >> str) {
        int ans = 0;
        char a = str[0], b;
        ans += mp[a].second;
        for (int i = 1; i < str.size(); ++i) {
            b = str[i];
            if (mp[b].first == mp[a].first) ans += 2; // 在同一个按键上
            ans += mp[b].second;
            a = b;
        }
        cout << ans << '\n';
    }
    return 0;
}