/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/7/1 11:46
* @Description: 4278. ��� ��Դ��PAT�׼�����1166
*/

#include <iostream>

using namespace std;

const int MAXN = 210;
int n, m, k;
bool g[MAXN][MAXN]; //�ڽӾ���
int arr[MAXN];    //��Ϣ��

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }

    cin >> k;   //k������

    for (int i = 1; i <= k; ++i) {
        int l;  //l������
        cin >> l;
        for (int j = 0; j < l; ++j) {
            cin >> arr[j];
        }
        //��������޷��������е���������֮�䶼��ֱ�����ѹ�ϵ������� Area X needs help.
        bool flag = false;   //�ж��Ƿ�����
        for (int j = 0; j < l - 1; ++j) {
            for (int k = j + 1; k < l; ++k) {
                if (!g[arr[j]][arr[k]])  //���arr[j] arr[k]��������
                    flag = true;
            }
        }
        if (flag) {
            cout << "Area " << i << " needs help.\n";
            continue;
        }

        flag = false;   //�ܷ��Ÿ����������һ������Ϣ
        int id; //���ŵ��˵ı��
        for (int j = 1; j <= n; ++j) {
            bool f = true;
            for (int k = 0; k < l; ++k) {
                if (!g[j][arr[k]]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                flag = true, id = j;
                break;
            }
        }
        if (flag) cout << "Area " << i << " may invite more people, such as " << id << ".\n";
        else cout << "Area " << i << " is OK.\n";
    }
    return 0;
}