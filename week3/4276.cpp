/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/29 11:12
* @Description: AcWing 4276. 擅长C 来源：PAT甲级真题1164
*/

#include <iostream>

using namespace std;

char g[26][7][6]; //输入单词 26个7*5的矩阵
bool is_first = true;//判断是否是第一行

void output(string word) {  //输出每个单词
    if (word.empty()) return;   //单词为空 不需要输出

    if(is_first) is_first = false; //如果是第一个单词则不输出换行 否则输出换行
    else cout << '\n';

    char str[7][60] = {0};
    for (int i = 0; i < word.size(); ++i) {
        //打印单词每个字母的 7*5矩阵
        for (int j = 0; j < 7; ++j) {
            for (int k = 0; k < 5; ++k) {
                //矩阵的行放在第j行  列应该为i * 6 + k
                str[j][i * 6 + k] = g[word[i] - 'A'][j][k];
            }
        }
    }
    //从第二个矩阵开始填充' '在每个矩阵的起始列前一个位置 即 i * 6 - 1
    for (int i = 1; i < word.size(); ++i) {
        for (int j = 0; j < 7; ++j) {
            str[j][i * 6 - 1] = ' ';
        }
    }
    for (int i = 0; i < 7; ++i) {
        cout << str[i] << '\n';
    }
}

int main() {
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 7; ++j) {
            for (int k = 0; k < 5; ++k) {
                cin >> g[i][j][k];
            }
        }
    }
    cin.get();  //吸收换行
    string word, str;
    getline(cin, word);
    for (auto &x: word) {
        if (isupper(x)) {
            str += x;
        } else {
            output(str);
            str.clear();
        }
    }
    output(str); //最后可能还剩下一个单词
    return 0;
}