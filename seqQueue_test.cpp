//
// Created by Lenovo on 2023/6/20.
//
#include "List_learning/seqQueue.h"
#include <iostream>

using namespace std;
int main(){
    seqQueue seqQueue1;
    cout << "��ʼ��\n";
    initQueue(seqQueue1);
    cout << "<2>�ж��Ƿ�ӿ�\n";
    cout <<"ԭ����\n";
    QueuePrint(seqQueue1);
    printf(queueEmpty(seqQueue1)?"��\n":"�ǿ�\n");
    cout << "<3>�ж��Ƿ������\n";
    cout << "��һ�����ݣ����n��Ԫ�أ��ж϶���\n";
    int n = 10;
    cout << "n = 10\n";
    initQueue(seqQueue1);
    for (int i = 1 ; i < n; ++i) {
        enQueue(seqQueue1,i);
    }
    printf(queueFull(seqQueue1)?"��\n":"û��\n");
    cout << "��ѭ����ʽ��1��99��99��Ԫ����ӣ��ж���\n";
    initQueue(seqQueue1);
    for (int i = 1 ; i < 100; ++i) {
        enQueue(seqQueue1,i);
    }
    printf(queueFull(seqQueue1)?"��\n":"û��\n");
    int data[6] = {4,7,8,12,20,50};
    initQueue(seqQueue1);
    for (int i : data) {
        enQueue(seqQueue1,i);
    }

    cout << "����\n";
    elementType  x;
    outQueue(seqQueue1,x);
    cout << "����Ԫ��ֵ" << x << endl;
    cout << "ȡ��ͷԪ��\n";
    queueFront(seqQueue1,x);
    cout <<"��ͷԪ��\n" << x << endl;
    cout << "��ǰ������Ԫ�ظ���\n";
    int len = 0;
    cout <<"��ǰ����\n";
    QueuePrint(seqQueue1);
    getLength(seqQueue1,len);
    printf("��ǰ������Ԫ�ظ���:%d\n",len);
    printf("<8>��д�㷨ʵ��\n"
           "�ٳ�ʼ����ѭ�����У�\n"
           "�ڵ�������������ʱ����������ӣ�\n"
           "�۵���������ż��ʱ����ͷ���ӣ�\n"
           "�ܵ���������0ʱ���㷨�˳���\n"
           "��ÿ����������������ǰ�����е�����Ԫ�ء�\n");
    demo(seqQueue1);
    return 0;
}