//
// Created by Lenovo on 2023/6/24.
//
#include "List_learning/linkQueue.h"
#include <iostream>

using namespace std;
int main(){
    linkQueue seqQueue1;
    cout << "��ʼ��\n";
    initQueue(seqQueue1);
    cout << "<2>�ж��Ƿ�ӿ�\n";
    cout <<"ԭ����\n";
    QueuePrint(seqQueue1);
    printf(queueEmpty(seqQueue1)?"��\n":"�ǿ�\n");
    printf("<3>���\n"
           "���ݣ�4��7��8��12��20��50\n");
    int data[6] = {4,7,8,12,20,50};
    initQueue(seqQueue1);
    for (int i : data) {
        enQueue(seqQueue1,i);
    }

    cout << "<4>����\n";
    elementType  x;
    outQueue(seqQueue1,x);
    cout << "����Ԫ��ֵ" << x << endl;
    cout << "<5>ȡ��ͷԪ��\n";
    queueFront(seqQueue1,x);
    cout <<"��ͷԪ��\n" << x << endl;
    cout << "<6>��ǰ������Ԫ�ظ���\n";
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