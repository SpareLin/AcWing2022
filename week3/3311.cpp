/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/8 9:08
* @Description: 3311. 最长算术  dp 差分 等差数列
*/

#include <iostream>

using namespace std;

const int N = 2e5 + 7;
int arr[N];

int main()
{
    int T;
    cin >> T;
    for (int v = 1; v <= T; v++) {
        int n;
        cin >> n;
        int ans = 2, cnt = 2;
        for (int i = 0; i < n; i ++ ) {
            cin >> arr[i];
        }
        for (int i = 2; i < n; i ++ ) {
            if(arr[i] - arr[i - 1] == arr[i - 1] - arr[i - 2])
                cnt++, ans = max(ans, cnt);
            else
                cnt = 2;
        }
        cout << "Case #" << v << ": " << ans << endl;
    }
    return 0;
}