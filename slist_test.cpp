#include <iostream>
#include "List_learning/list.h"

using namespace std;

int main (){
    slist L1,L2,L3;
    int data1[10] = {1,3,6,10,15,16,17,18,19,20};
    int data2[14] = {1,2,3,4,5,6,7,8,9,10,18,19,20,30};
    int data3[8] = {2,4,5,7,8,9,12,22};
    int data4[10] = {1,2,3,4,5,6,7,8,9,10};
    int data[5] = {};

    cout << "��һ��\n"
            "��һ�����Ա�Ԫ��Ϊ ��1��3��6��10��15��16��17��18��19��20��\n"
            "�ڶ������Ա�Ԫ��Ϊ ��1��2��3��4��5��6��7��8��9��10��18��20��30��"<< endl;
    for (int i = 0; i < 10; ++i) {
        L1.data[i] = data1[i];
    }
    L1.listLen = 10;
    for (int i = 0; i < 14; ++i) {
        L2.data[i] = data2[i];
    }
    L2.listLen = 14;
    cout << "L1:ԭ���ݣ�"<< endl;
    printList(&L1);
    cout << "L2:ԭ���ݣ�"<< endl;
    printList(&L2);
    mergeList(&L1,&L2,&L3);
    cout << "L3:���ݣ�"<< endl;
    printList(&L3);


    cout << "�ڶ���\n"
            "��һ�����Ա�Ԫ��Ϊ ��1��3��6��10��15��16��17��18��19��20��\n"
            "�ڶ������Ա�Ԫ��Ϊ ��2��4��5��7��8��9��12��22��"<< endl;
    for (int i = 0; i < 10; ++i) {
        L1.data[i] = data1[i];
    }
    L1.listLen = 10;
    for (int i = 0; i < 8; ++i) {
        L2.data[i] = data3[i];
    }
    L2.listLen = 8;
    cout << "L1:ԭ���ݣ�"<< endl;
    printList(&L1);
    cout << "L2:ԭ���ݣ�"<< endl;
    printList(&L2);
    mergeList(&L1,&L2,&L3);
    cout << "L3:���ݣ�"<< endl;
    printList(&L3);

    cout << "������\n"
            "��һ�����Ա�Ԫ��Ϊ ����\n"
            "�ڶ������Ա�Ԫ��Ϊ ��1��2��3��4��5��6��7��8��9��10��"<< endl;
    initialList(&L1);
    for (int i = 0; i < 10; ++i) {
        L2.data[i] = data4[i];
    }
    L2.listLen = 10;
    cout << "L1:ԭ���ݣ�"<< endl;
    printList(&L1);
    cout << "L2:ԭ���ݣ�"<< endl;
    printList(&L2);
    mergeList(&L1,&L2,&L3);
    cout << "L3:���ݣ�"<< endl;
    printList(&L3);
    return 0;
}
