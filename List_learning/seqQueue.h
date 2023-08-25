//
// Created by Lenovo on 2023/6/20.
// 循环队列,front下一个为对头，rear指向队尾元素，牺牲一个存储空间来判断队列是否满还是空
//

#ifndef DS_LEARNING_SEQQUEUE_H
#define DS_LEARNING_SEQQUEUE_H

#include <iostream>
#include "PTNode.h"

#define MaxLen 100
typedef CSNode* elementType;
typedef struct {
    elementType data[MaxLen];
    int front;
    int rear;
}seqQueue;
/*!
 * @brief 初始化循环队列
 * @param Q
 */
void initQueue(seqQueue &Q){
    Q.front = 0;
    Q.rear = 0;
}
bool queueEmpty(seqQueue &Q){
    return (Q.front == Q.rear);
}
bool queueFull(seqQueue &Q){
    return ((Q.rear+1)%MaxLen == Q.front);
}
bool queueFront(seqQueue &Q,elementType &x){
    if(queueEmpty(Q)) return false;
    else{
        x = Q.data[(Q.front+1) % MaxLen];
        return true;
    }
}
bool enQueue(seqQueue &Q,elementType x){
    if((queueFull(Q))){
        return false;
    } else{
        Q.rear = (Q.rear+1)%MaxLen;
        Q.data[Q.rear] = x;
        return true;
    }
}
bool outQueue(seqQueue &Q,elementType &x){
    if(queueEmpty(Q)){
        return false;
    } else{
        Q.front = (Q.front+1) % MaxLen;
        x = Q.data[Q.front];
    }
}
void getLength(seqQueue &Q,int &Len){
    Len = (Q.rear-Q.front+MaxLen) % MaxLen;
}
void QueuePrint(seqQueue &Q){
    int i = Q.front;
    while (i != Q.rear){
        i = (i+1) % MaxLen;
        std::cout<< Q.data[i]<< " ";
    }
    std::cout << std::endl;
}
void createQueue(seqQueue &Q){
    initQueue(Q);
    int i;
    elementType x;
    std::cout << "生成队列元素个数" << std::endl;
    std::cin >> i;
    for (int j = 0; j < i; j++) {
        std::cin >> x ;
        enQueue(Q, x);
    }
}
#endif //DS_LEARNING_SEQQUEUE_H
