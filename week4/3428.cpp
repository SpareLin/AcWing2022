/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/29 17:11
* @Description: 3428. 放苹果 来源：北京大学考研机试题
*/


#include <iostream>

using namespace std;

int n, m;

//暴力深搜  类似于求全排列
//只搜递增序列 所以保证没有重复搜

int dfs(int u, int sum, int last) {
    if(u == n) {    //剪枝
        if(sum == 0) return 1;
        return 0;
    }
    int res = 0;
    for (int i = last; i <= sum; ++i) {
        res += dfs(u + 1, sum - i, i);
    }
    return res;
}

//递归
/*f(m,n)表示m个相同苹果n个相同盘子，每个盘子可以为空的方案总数
 *边界状态： f(m,1) = f(n,0) = 1
 *状态转移方程
 * m < n时  返回f(m,m)。
 * m >=n 时 返回f(m,n-1) + f(m-n,n)。
 * */
int f(int m, int n) {
    if(n == 1 || m == 0) {  //盘子数为1 or 苹果数为0 只有一种方法
        return 1;
    }
    if(m < n) { //苹果数小于盘子数
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