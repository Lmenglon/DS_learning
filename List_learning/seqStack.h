//
// Created by Lenovo on 2023/6/20.
// 通过顺序表来实现栈
//

#ifndef DS_LEARNING_SEQSTACK_H
#define DS_LEARNING_SEQSTACK_H

#include <iostream>

#define MaxLen 100
typedef int elementType;

typedef struct {
    elementType data[MaxLen];
    int top ;
}seqStack;
/*!
 * @brief 初始化栈
 * @param S 栈的指针
 */
void initStack(seqStack *S){
    S->top = -1;
}
/*!
 * @brief 判断栈是否为空
 * @param S 栈
 * @return 空返回True
 */
bool stackEmpty(seqStack S){
    return (S.top == -1);
}
/*!
 * @brief 判断栈满
 * @param S
 * @return 栈满返回True
 */
bool stackFull(seqStack S){
    return (S.top == MaxLen -1);
}
/*!
 * @brief 返回栈顶元素
 * @param S
 * @param x 栈顶元素
 */
void stackTop(seqStack *S,elementType &x){
    if(stackEmpty(*S)) std::cout << "栈空" << std::endl;
    else x = S->data[S->top];
}
/*!
 * @brief 指定的元素入栈
 * @param S
 * @param x 指定的元素
 */
void pushStack(seqStack *S,elementType x){
    if (stackFull(*S)) std::cout << "栈满" << std::endl;
    else{
        S->top ++;
        S->data[S->top] = x;
    }
}
void popStack(seqStack *S,elementType &x){
    if (stackEmpty(*S)) std::cout << "栈空" 
}
#endif //DS_LEARNING_SEQSTACK_H
