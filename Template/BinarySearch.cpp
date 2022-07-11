/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/8 22:22
* @Description: 二分查找
*/

#include <iostream>

using namespace std;

/* 二分不局限于单调性 本质是 整个区间一分为二, 一半满足一半不满足 可以寻找边界点
 * ① mid = l + r >> 1
 *  if(check(mid)) true [mid, r] l = mid;
 *                 false [l, mid - 1] l
 * ② mid =
 * */

bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
//浮点数二分算法模板
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}

int main() {

    return 0;
}
