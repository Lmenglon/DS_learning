//
// Created by Lenovo on 2023/6/20.
//
#include "List_learning/linkedStack.h"
#include <iostream>

using namespace std;
int main (){
    char s[100];
    char *p =s;
    char c;
    cout << "�����ַ�����0������"<<endl;
    while (true){
        cin >> c;
        if (c == '0'){
            *p = '\0';
            break;
        }
        *p = c;
        p++;
    }
    printf("%s�Ľ���ǣ�%s\n", s, JudgeString(s) ? "ƥ��" : "��ƥ��");
    return 0;
}