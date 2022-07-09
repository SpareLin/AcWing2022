/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/8 9:32
* @Description: 
*/

#include <iostream>

using namespace std;

const int N = 2e5 + 7;
int arr[N], det[N];

int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k ++ ) {
        int n;
        cin >> n;a
        for (int i = 0; i < n; i ++ ) cin >> arr[i];
        for (int i = 0; i < n - 1; i ++ ) det[i] = arr[i + 1] - arr[i];

        int ans = 1, cnt = 1;
        for (int i = 1; i < n - 1; i ++ ) {
            if(det[i] == det[i - 1])
                ans = max(ans, ++cnt);
            else
                cnt = 1;
        }
        cout << "Case #" << k << ": " << ans + 1 << endl;
    }
    return 0;
}
