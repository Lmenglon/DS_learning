//
// Created by Lenovo on 2023/6/20.
//

#ifndef DS_LEARNING_LINKQUEUE_H
#define DS_LEARNING_LINKQUEUE_H
typedef int elementType;
typedef struct LNode{
    elementType data;
    struct LNode* next;
}node;
typedef struct IQueue{
    node *front,*rear;
}linkQueue;


#endif //DS_LEARNING_LINKQUEUE_H
