//
// Created by Lenovo on 2023/6/21.
//
#include "List_learning/btNode.h"
#include <iostream>

using namespace std;
int main(){
    btNode *btNode1,*btNode2;
    printf("<8>键盘输入一个元素x，求其在树中的层次。不存在时给出相应提示信息。\n"
           "\t实验测试数据基本要求：\n"
           "第一组数据： bt261.btr\n"
           "第二组数据： bt21.btr\n");
    cout << "第一组数据： bt261.btr\n";
    const char *fileName = "E:\\Clion\\Project\\DS_learning\\BTdata\\bt261.btr";
    createBTree(fileName,btNode1);
    int num = 0;
    elementType x;
    cout << "输入一个元素x\n";
    cin >> x;
    getNodeLevel(btNode1,x,&num,1);
    if (num == 0){
        printf("bt261二叉树不存在%c\n",x);
    } else{
        printf("bt261二叉树中元素%c的层次数%d：\n",x,num);
    }

    cout << "第二组数据： bt21.btr\n";
    fileName = "E:\\Clion\\Project\\DS_learning\\BTdata\\bt21.btr";
    createBTree(fileName,btNode1);
    cout << "输入一个元素x\n";
    cin >> x;
    getNodeLevel(btNode1,x,&num,0);
    if (num == 0){
        printf("bt21二叉树不存在%c\n",x);
    } else{
        printf("bt21二叉树中元素%c的层次数%d：\n",x,num);
    }

    printf("<9>交换二叉树中每个结点的左右孩子指针的值。（即：左子树变为右子树，右子树变为左子树）。\n"
           "\t实验测试数据基本要求：\n"
           "第一组数据： full4.btr\n"
           "第二组数据： bt21.btr\n");
    printf("第一组数据： full4.btr\n");
    fileName = "E:\\Clion\\Project\\DS_learning\\BTdata\\full4.btr";
    createBTree(fileName,btNode1);
    exchage(btNode1);
    cout << "交换后的树的先序遍历\n";
    PreOrder(btNode1);
    cout << "\n";
    printf("第二组数据： bt21.btr\n");
    fileName = "E:\\Clion\\Project\\DS_learning\\BTdata\\bt21.btr";
    createBTree(fileName,btNode1);
    exchage(btNode1);
    cout << "交换后的树的先序遍历\n";
    PreOrder(btNode1);
    return 0;
}