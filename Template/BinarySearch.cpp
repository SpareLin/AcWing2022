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

bool check(int x) {/* ... */} // ���x�Ƿ�����ĳ������

// ����[l, r]�����ֳ�[l, mid]��[mid + 1, r]ʱʹ�ã�
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()�ж�mid�Ƿ���������
        else l = mid + 1;
    }
    return l;
}
// ����[l, r]�����ֳ�[l, mid - 1]��[mid, r]ʱʹ�ã�
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
//�����������㷨ģ��
bool check(double x) {/* ... */} // ���x�Ƿ�����ĳ������

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps ��ʾ���ȣ�ȡ������Ŀ�Ծ��ȵ�Ҫ��
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
