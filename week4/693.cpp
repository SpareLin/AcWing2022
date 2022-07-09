/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/29 17:19
* @Description: AcWing 693. 行程排序
 * 来源：Google Kickstart2014 Round D Problem C
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
        //val 用于寻找行程的起点 val[i] == 1
        while (n--) {
            string source, destin;
            cin >> source >> destin;
            mp.emplace(source, destin);    //哈希表映射起点终点
            val[source]++;
            val[destin]--;
            places.push_back(source);   //存储去过的地方
        }
        string start; //行程起点
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