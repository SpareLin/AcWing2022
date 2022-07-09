/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/7 17:03
* @Description: 算法基础课 排序算法
*/

#include <iostream>

using namespace std;

const int MAXN = 1e5 + 7;
int arr[8] = {4, 6, 8, 7, 9, 7, 2, 3};

/*
 * ①确定分界点 可以选 q[l] q[r] q[(l + r) / 2] ....
 * ②调整范围： 使得第一个区间中的数都小于等于x 另外一个区间都是大于等于x
 *  思路1、开两个数组 a[] b[]
 *  q[l ~ r] 若 a[i]<=x 放到a里面 若a[i]>=x 放到b里面去
 *  然后a 放进 q  b放进q
 *  思路2、双指针
 * ③递归处理：左右两段 分别排序
 */
void quick_Sort(int q[], int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_Sort(q, l, j);
    quick_Sort(q, j + 1, r);
}

/*  归并排序 分治
 * 时间复杂度 O（N*logN）
 * ① 确定分解点 mid = (l + r) / 2
 * ② 先递归排序left right 左边和右边
 * ③ 归并 合二为一 将两个有序序列合二为一  （双指针算法）
 * */

void Merge_Sort(int q[], int l, int r) {
    if (l >= r) return;  //若当前区间只有一个数或没有数

    int mid = (l + r) >> 1; //取中点

    /*先排序*/
    Merge_Sort(q, l, mid);
    Merge_Sort(q, mid + 1, r);

    /*合并两个有序序列*/
    int tmp[MAXN];  //辅助数组
    int k = l, i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }

    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];

    for (i = l; i <= r; i++) {
        q[i] = tmp[i];
    }
}

int main() {
    //quick_Sort(arr, 0, 7);
    Merge_Sort(arr, 0, 7);
    for (auto x: arr) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
