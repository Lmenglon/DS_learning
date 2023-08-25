//
// Created by Lenovo on 2023/6/19.
//
#include <iostream>
#include "List_learning/LNode.h"
using namespace std;

int main(){
    linkList L1,L2,L3;
    int data1[10] = {1,3,6,10,15,16,17,18,19,20};
    int data2[14] = {1,2,3,4,5,6,7,8,9,10,18,19,20,30};
    int data3[8] = {2,4,5,7,8,9,12,22};
    int data4[10] = {1,2,3,4,5,6,7,8,9,10};
    int data[5] = {};

    cout << "第一组\n"
            "第一个线性表元素为 （1，3，6，10，15，16，17，18，19，20）\n"
            "第二个线性表元素为 （1，2，3，4，5，6，7，8，9，10，18，20，30）"<< endl;
    createList(L1,data1,10);
    createList(L2,data2,14);
    cout << "L1:原数据："<< endl;
    listPrint(L1);
    cout << "L2:原数据："<< endl;
    listPrint(L2);
    insertSet(L1,L2,L3);
    cout << "L3:数据："<< endl;
    listPrint(L3);


    cout << "第二组\n"
            "第一个线性表元素为 （1，3，6，10，15，16，17，18，19，20）\n"
            "第二个线性表元素为 （2，4，5，7，8，9，12，22）"<< endl;
    createList(L1,data1,10);
    createList(L2,data3,8);
    cout << "L1:原数据："<< endl;
    listPrint(L1);
    cout << "L2:原数据："<< endl;
    listPrint(L2);
    insertSet(L1,L2,L3);
    cout << "L3:数据："<< endl;
    listPrint(L3);

    cout << "第三组\n"
            "第一个线性表元素为 （）\n"
            "第二个线性表元素为 （1，2，3，4，5，6，7，8，9，10）"<< endl;
    initialList(L1);
    createList(L2,data4,10);
    cout << "L1:原数据："<< endl;
    listPrint(L1);
    cout << "L2:原数据："<< endl;
    listPrint(L2);
    insertSet(L1,L2,L3);
    cout << "L3:数据："<< endl;
    listPrint(L3);
    return 0;
}