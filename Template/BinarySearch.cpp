/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/8 22:22
* @Description: ���ֲ���
*/



#include <iostream>

using namespace std;

/* ���ֲ������ڵ����� ������ ��������һ��Ϊ��, һ������һ�벻���� ����Ѱ�ұ߽��
 * �� mid = l + r >> 1
 *  if(check(mid)) true [mid, r] l = mid;
 *                 false [l, mid - 1] l
 * �� mid =
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

//����Ҫ����߽�
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
