//
// Created by Lenovo on 2023/6/20.
//
#include "List_learning/seqStack.h"
#include <iostream>

using namespace std;
void Dec2X(int N){
    seqStack S;int Mod;
    elementType x;
    initStack(&S);
    while (N!=0){
        Mod = N % 16;
        x = '0'+Mod;
        if (Mod >9){
            x = 'A' + Mod -10;
        }
        pushStack(&S,x);
        N = N/16;
    }
    cout << "ת����İ˽�������";
    while(!stackEmpty(S)){
        popStack(&S,x);
        cout << x;
    }
    cout << endl;
}
int main(){
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