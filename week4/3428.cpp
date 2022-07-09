/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/29 17:11
* @Description: 3428. ��ƻ�� ��Դ��������ѧ���л�����
*/


#include <iostream>

using namespace std;

int n, m;

//��������  ��������ȫ����
//ֻ�ѵ������� ���Ա�֤û���ظ���

int dfs(int u, int sum, int last) {
    if(u == n) {    //��֦
        if(sum == 0) return 1;
        return 0;
    }
    int res = 0;
    for (int i = last; i <= sum; ++i) {
        res += dfs(u + 1, sum - i, i);
    }
    return res;
}

//�ݹ�
/*f(m,n)��ʾm����ͬƻ��n����ͬ���ӣ�ÿ�����ӿ���Ϊ�յķ�������
 *�߽�״̬�� f(m,1) = f(n,0) = 1
 *״̬ת�Ʒ���
 * m < nʱ  ����f(m,m)��
 * m >=n ʱ ����f(m,n-1) + f(m-n,n)��
 * */
int f(int m, int n) {
    if(n == 1 || m == 0) {  //������Ϊ1 or ƻ����Ϊ0 ֻ��һ�ַ���
        return 1;
    }
    if(m < n) { //ƻ����С��������
        return f(m, m);
    }
    else {
        return f(m, n - 1) + f(m - n, n);
    }
}

int main() {
    while (cin >> m >> n) {
        //cout << dfs(0, m, 0) << '\n';
        cout << f(m, n) << '\n';
    }
    return 0;
}