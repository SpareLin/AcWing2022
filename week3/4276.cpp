/*
* @Author: Spare Lin
* @Project: AcWing2022
* @Date: 2022/6/29 11:12
* @Description: AcWing 4276. �ó�C ��Դ��PAT�׼�����1164
*/

#include <iostream>

using namespace std;

char g[26][7][6]; //���뵥�� 26��7*5�ľ���
bool is_first = true;//�ж��Ƿ��ǵ�һ��

void output(string word) {  //���ÿ������
    if (word.empty()) return;   //����Ϊ�� ����Ҫ���

    if(is_first) is_first = false; //����ǵ�һ��������������� �����������
    else cout << '\n';

    char str[7][60] = {0};
    for (int i = 0; i < word.size(); ++i) {
        //��ӡ����ÿ����ĸ�� 7*5����
        for (int j = 0; j < 7; ++j) {
            for (int k = 0; k < 5; ++k) {
                //������з��ڵ�j��  ��Ӧ��Ϊi * 6 + k
                str[j][i * 6 + k] = g[word[i] - 'A'][j][k];
            }
        }
    }
    //�ӵڶ�������ʼ���' '��ÿ���������ʼ��ǰһ��λ�� �� i * 6 - 1
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
    cin.get();  //���ջ���
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
    output(str); //�����ܻ�ʣ��һ������
    return 0;
}