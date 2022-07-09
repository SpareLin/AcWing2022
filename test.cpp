
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e5 + 7;
int arr[N];

LL merge_sort(int q[], int l, int r) {
    if(l >= r) return ;

    int mid = l + r >> 1;

    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    int tmp[N];
    int k = l, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(q[i] < q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    for (int i = l; i <= r; i++) q[i] = tmp[i];
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    while(q--) {
        int k;
        cin >> k;
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(arr[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if(arr[l] != k) cout << "-1 -1\n";
        else {
            cout << l << ' ';
            while(l < r) {
                int mid = l + r + 1 >> 1;
                if(arr[mid] <= k) l = mid;
                else r = mid - 1;
            }
            cout << r;
        }
    }

    return 0;
}