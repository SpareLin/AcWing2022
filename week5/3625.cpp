/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/5 21:19
* @Description: AcWing 3625. 幂次方
 * 快速幂
*/
/*
 * 3^1 = 3
 * 3^2 = 9
 * 3^4 = 81
 *
 */
#include <iostream>
using namespace std;

typedef long long LL;
const int mod = 233333;

int power(LL a, LL b, LL p) {
    int ans = 1 % p;
    for ( ; b ; b >>=  1) {
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

int fast_power(int a, int b, int p) {
    LL res = 1 % p;
    while(b != 0) {
        //如果b的个位是1 强制类型转换防止溢出
        if(b and 1) res = res * 1ll * a % p;
        //十位就是a * a
        a = a * 1ll * a % p;
        //去掉个位
        b >>= 1;
    }
    return res;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << power(x, n, mod) << '\n';
    cout << fast_power(x, n, mod) << '\n';
    return 0;
}
