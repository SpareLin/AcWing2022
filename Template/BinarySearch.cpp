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

bool check(int x);
int binarySearch(int l, int r) {
    int mid = l + r >> 1;

    while(l < r)
    {
        r = mid;
        if(check(mid))
    }
}

//不需要处理边界
double binarySearch(double l, double r, int x) {
    double mid = (l + r) / 2;
    while(r - l >= 1e - 8) {
        if(mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main() {

    return 0;
}
