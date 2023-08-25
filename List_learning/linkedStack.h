//
// Created by Lenovo on 2023/6/20.
// 不带头指针
//

#ifndef DS_LEARNING_LINKEDSTACK_H
#define DS_LEARNING_LINKEDSTACK_H

typedef int elementType ;
typedef struct IsNode{
    elementType data;
    struct IsNode *next;
}sNode,*linkedStack;
/*!
 * @brief 初始化链表
 * @param top 栈的头指针
 */
void initialStack(sNode *&top){
    top = nullptr;
}
/*!
 * @brief 指定的元素入栈
 * @param top
 * @param x 指定的元素
 */
void pushStack(sNode *& top,elementType x){
    sNode *s;
    s = new sNode ;
    s->data = x;
    s->next = top;
    top = s;
}
bool popStack(sNode*& top, elementType&x){
    sNode *temp;
    if(top == nullptr) return false;
    else{
        x = top->data;
        temp = top;
        top = top->next;
        delete temp;
        return true;
    }
}
#endif //DS_LEARNING_LINKEDSTACK_H
