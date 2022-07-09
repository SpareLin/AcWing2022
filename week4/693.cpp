/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/29 17:19
* @Description: AcWing 693. �г�����
 * ��Դ��Google Kickstart2014 Round D Problem C
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> places;
unordered_map<string, string> mp;
unordered_map<string, int> val;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        places.clear(), mp.clear(), val.clear();
        //val ����Ѱ���г̵���� val[i] == 1
        while (n--) {
            string source, destin;
            cin >> source >> destin;
            mp.emplace(source, destin);    //��ϣ��ӳ������յ�
            val[source]++;
            val[destin]--;
            places.push_back(source);   //�洢ȥ���ĵط�
        }
        string start; //�г����
        for (auto &x : places) {
            if(val[x] == 1) {
                start = x;
                break;
            }
        }
        cout << "Case #" << i + 1 << ": ";
        while(!mp[start].empty()) {
            cout << start << '-' << mp[start] << ' ';
            start = mp[start];
        }
        cout << '\n';
    }
    return 0;
}