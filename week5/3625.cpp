/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/5 21:19
* @Description: AcWing 3625. �ݴη�
 * ������
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
        //���b�ĸ�λ��1 ǿ������ת����ֹ���
        if(b and 1) res = res * 1ll * a % p;
        //ʮλ����a * a
        a = a * 1ll * a % p;
        //ȥ����λ
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
