/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/7 17:03
* @Description: �㷨������ �����㷨
*/

#include <iostream>

using namespace std;

const int MAXN = 1e5 + 7;
int arr[8] = {4, 6, 8, 7, 9, 7, 2, 3};

/*
 * ��ȷ���ֽ�� ����ѡ q[l] q[r] q[(l + r) / 2] ....
 * �ڵ�����Χ�� ʹ�õ�һ�������е�����С�ڵ���x ����һ�����䶼�Ǵ��ڵ���x
 *  ˼·1������������ a[] b[]
 *  q[l ~ r] �� a[i]<=x �ŵ�a���� ��a[i]>=x �ŵ�b����ȥ
 *  Ȼ��a �Ž� q  b�Ž�q
 *  ˼·2��˫ָ��
 * �۵ݹ鴦���������� �ֱ�����
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

/*  �鲢���� ����
 * ʱ�临�Ӷ� O��N*logN��
 * �� ȷ���ֽ�� mid = (l + r) / 2
 * �� �ȵݹ�����left right ��ߺ��ұ�
 * �� �鲢 �϶�Ϊһ �������������к϶�Ϊһ  ��˫ָ���㷨��
 * */

void Merge_Sort(int q[], int l, int r) {
    if (l >= r) return;  //����ǰ����ֻ��һ������û����

    int mid = (l + r) >> 1; //ȡ�е�

    /*������*/
    Merge_Sort(q, l, mid);
    Merge_Sort(q, mid + 1, r);

    /*�ϲ�������������*/
    int tmp[MAXN];  //��������
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
