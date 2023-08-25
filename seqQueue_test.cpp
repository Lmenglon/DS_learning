//
// Created by Lenovo on 2023/6/20.
//
#include "List_learning/seqQueue.h"
#include <iostream>

using namespace std;
int main(){
    seqQueue seqQueue1;
    cout << "初始化\n";
    initQueue(seqQueue1);
    cout << "<2>判断是否队空\n";
    cout <<"原队列\n";
    QueuePrint(seqQueue1);
    printf(queueEmpty(seqQueue1)?"空\n":"非空\n");
    cout << "<3>判断是否队满。\n";
    cout << "第一组数据：入队n个元素，判断队满\n";
    int n = 10;
    cout << "n = 10\n";
    initQueue(seqQueue1);
    for (int i = 1 ; i < n; ++i) {
        enQueue(seqQueue1,i);
    }
    printf(queueFull(seqQueue1)?"满\n":"没满\n");
    cout << "用循环方式将1到99，99个元素入队，判队满\n";
    initQueue(seqQueue1);
    for (int i = 1 ; i < 100; ++i) {
        enQueue(seqQueue1,i);
    }
    printf(queueFull(seqQueue1)?"满\n":"没满\n");
    int data[6] = {4,7,8,12,20,50};
    initQueue(seqQueue1);
    for (int i : data) {
        enQueue(seqQueue1,i);
    }

    cout << "出队\n";
    elementType  x;
    outQueue(seqQueue1,x);
    cout << "出队元素值" << x << endl;
    cout << "取队头元素\n";
    queueFront(seqQueue1,x);
    cout <<"队头元素\n" << x << endl;
    cout << "求当前队列中元素个数\n";
    int len = 0;
    cout <<"当前队列\n";
    QueuePrint(seqQueue1);
    getLength(seqQueue1,len);
    printf("当前队列中元素个数:%d\n",len);
    printf("<8>编写算法实现\n"
           "①初始化空循环队列；\n"
           "②当键盘输入奇数时，此奇数入队；\n"
           "③当键盘输入偶数时，队头出队；\n"
           "④当键盘输入0时，算法退出；\n"
           "⑤每当键盘输入后，输出当前队列中的所有元素。\n");
    demo(seqQueue1);
    return 0;
}