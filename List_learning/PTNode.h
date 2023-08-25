//
// Created by Lenovo on 2023/6/23.
// 森林
// 孩子兄弟链的存储结构
//

#ifndef DS_LEARNING_PTNODE_H
#define DS_LEARNING_PTNODE_H

#include <iostream>
#include "seqQueue.h"
typedef int elementType ;

/*!
 * @brief 将森林转化为二叉树存储。
 */
typedef struct CSNode{
    elementType data;
    struct CSNode *fistChild,*nextSibling;  // 左孩子和第一个右边的兄弟结点
}csNode,*csTree;

/*!
 * @brief 森林的先序遍历
 * @param T
 */
void preOrder(csNode *T){
    if(T != nullptr){
        // 森林的先序遍历就是 二叉树的先序遍历
        std::cout << T->data << " ";
        preOrder(T->fistChild);
        preOrder(T->nextSibling);
    }
}

void postOrder(csNode *T){
    if (T != nullptr){
        // 森林的后序遍历就是 二叉树的中序遍历
        // 找下结点的对应关系就知道了
        postOrder(T->fistChild);
        std::cout << T->data << " ";
        postOrder(T->nextSibling);
    }
}
/*!
 * @brief森林的层次遍历
 * @param T
 */
 /*
void LevelOrder(csNode *T){
    csNode *P = T;
    csNode *K;
    seqQueue seqQueue1;
    //创建队列来存储同一层的结点数据
    initQueue(seqQueue1);
    while (P){
        K = P;
        //依次访问所有的结点
        enQueue(seqQueue1,K);
        while (!queueEmpty(seqQueue1)){
            outQueue(seqQueue1,K);
            std::cout << K->data << " ";
            if (K->fistChild){
                //如果存在有下一层的存起来放最后
                K = K->fistChild;
                enQueue(seqQueue1,K);
                while (K->nextSibling){
                    // 把同一层的依次存起来
                    K = K->nextSibling ;
                    enQueue(seqQueue1,K);
                }
            }
        }
        P = P->nextSibling;//最顶层的结点
    }
}*/
#endif //DS_LEARNING_PTNODE_H
