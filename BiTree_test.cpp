//
// Created by Lenovo on 2023/6/21.
//
#include "List_learning/btNode.h"
#include <iostream>

using namespace std;
int main(){
    btNode *btNode1,*btNode2;
    printf("<8>��������һ��Ԫ��x�����������еĲ�Ρ�������ʱ������Ӧ��ʾ��Ϣ��\n"
           "\tʵ��������ݻ���Ҫ��\n"
           "��һ�����ݣ� bt261.btr\n"
           "�ڶ������ݣ� bt21.btr\n");
    cout << "��һ�����ݣ� bt261.btr\n";
    const char *fileName = "E:\\Clion\\Project\\DS_learning\\BTdata\\bt261.btr";
    createBTree(fileName,btNode1);
    int num = 0;
    elementType x;
    cout << "����һ��Ԫ��x\n";
    cin >> x;
    getNodeLevel(btNode1,x,&num,1);
    if (num == 0){
        printf("bt261������������%c\n",x);
    } else{
        printf("bt261��������Ԫ��%c�Ĳ����%d��\n",x,num);
    }

    cout << "�ڶ������ݣ� bt21.btr\n";
    fileName = "E:\\Clion\\Project\\DS_learning\\BTdata\\bt21.btr";
    createBTree(fileName,btNode1);
    cout << "����һ��Ԫ��x\n";
    cin >> x;
    getNodeLevel(btNode1,x,&num,0);
    if (num == 0){
        printf("bt21������������%c\n",x);
    } else{
        printf("bt21��������Ԫ��%c�Ĳ����%d��\n",x,num);
    }

    printf("<9>������������ÿ���������Һ���ָ���ֵ����������������Ϊ����������������Ϊ����������\n"
           "\tʵ��������ݻ���Ҫ��\n"
           "��һ�����ݣ� full4.btr\n"
           "�ڶ������ݣ� bt21.btr\n");
    printf("��һ�����ݣ� full4.btr\n");
    fileName = "E:\\Clion\\Project\\DS_learning\\BTdata\\full4.btr";
    createBTree(fileName,btNode1);
    exchage(btNode1);
    cout << "������������������\n";
    PreOrder(btNode1);
    cout << "\n";
    printf("�ڶ������ݣ� bt21.btr\n");
    fileName = "E:\\Clion\\Project\\DS_learning\\BTdata\\bt21.btr";
    createBTree(fileName,btNode1);
    exchage(btNode1);
    cout << "������������������\n";
    PreOrder(btNode1);
    return 0;
}