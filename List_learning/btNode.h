//
// Created by Lenovo on 2023/6/21.
// 通过链表来实现二叉树
//

#ifndef DS_LEARNING_BTNODE_H
#define DS_LEARNING_BTNODE_H

#include <iostream>

/*!
 * @brief 通过二叉链表来实现二叉树
 */
typedef char elementType;
//typedef struct blNode{
//    elementType data;
//    struct blNode* lchild, *rchild;
//}btNode,*BiTree;
/*!
 * @brief 通过三叉链表来实现二叉树，包含双亲结点，左孩子和右孩子结点
 */
typedef struct TriTNode{
    elementType data;
    struct TriTNode *lchild, *rchild, *parent;
}TriTNode, *TriTree;
/*!
 * @brief 线索二叉树的结构定义
 * @param Tag 0表示孩子指针，1表示线索指针
 */
typedef struct blNode{
    elementType data;
    int lTag,rTag;  // 区分是孩子指针还是线索指针，类似于广义表
    struct blNode* lchild, *rchild;
}btNode,*BiTree;
/*!
 * @brief 先序遍历
 * @param T
 */
void PreOrder(btNode *T){
    if(T){
        std::cout<< T->data;
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
/*!
 * @brief 中序遍历
 * @param T
 */
void InOrder(btNode *T){
    if(T){
        InOrder(T->lchild);
        std::cout<< T->data;
        InOrder(T->rchild);
    }
}
/*!
 * @brief 后序遍历
 * @param T
 */
void PostOrder(btNode *T){
    if(T){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        std::cout<< T->data;
    }
}
/*!
 * @brief 求二叉数的深度
 * @param T
 * @return 二叉树的深度
 */
int btHeight(btNode *T){
    if (T == nullptr)
        return 0;
    else
        return (btHeight(T->lchild) > btHeight(T->rchild) ? btHeight(T->lchild) + 1 : btHeight(T->rchild) + 1);
}
/*!
 * @brief 返回树上的总结点数
 * @param T
 * @param num 总结点数
 */
void getNodeNumber(btNode *T, int *num)
{                  //改造先序遍历计数结点数
    if(T)
    {
        (*num)++;    //计数根结点
        getNodeNumber(T->lchild, num);    //累计左子树结点
        getNodeNumber(T->rchild, num);    //累计右子树结点
    }
}
/*!
 * @brief 返回二叉树叶子结点数
 * @param T
 * @param num 叶子数
 */
void getLeafNumber(btNode *T,int* num)
{
    if(T)
    {
        if(T->lchild==nullptr && T->rchild==nullptr)
            (*num)++;
        getLeafNumber(T->lchild, num);
        getLeafNumber(T->rchild, num);
    }
}
/*!
 * @brief 返回二叉树度为2的结点数
 * @param T
 * @param num 度为2的结点数
 */
void get2DegreeNumber(btNode *T,int* num)
{
    if(T)
    {
        if(T->lchild && T->rchild)
            (*num)++;
        get2DegreeNumber(T->lchild, num);
        get2DegreeNumber(T->rchild, num);
    }
}
/*!
 * @brief 返回二叉树度为1的结点数
 * @param T
 * @param num 度为1的结点数
 */
void get1DegreeNumber(btNode *T,int* num)
{
    if(T)
    {
        if((T->lchild && T->rchild == nullptr) || (T->lchild == nullptr && T->rchild))
            (*num)++;
        get1DegreeNumber(T->lchild, num);
        get1DegreeNumber(T->rchild, num);
    }
}
/*!
 * @brief 创建树(前序),'/'代表没右子树
 * @return 二叉树的结点
 */
btNode * CreatBTree() {
    btNode* p;
    elementType number;
    std::cin >> number;
    if (number == '0')    // elementType == int 结束为0，为char结束为 /
        p = nullptr;
    else {
        p = new btNode;
        p->data = number;
        p->lchild = CreatBTree();
        p->rchild = CreatBTree();
    }
    return p;
}
/*!
 * @brief 初始化
 * @param T
 */
void Init(btNode*& T) {
    T->lchild = nullptr;
    T->rchild = nullptr;
    T->data = 0;
}
/*!
 * @brief 判断二叉树是否为空
 * @param T
 * @return 空返回true
 */
bool isEmpty(btNode *T)
{
    if(T!=nullptr)
        return false;
    else
        return true;
}

/*!
 * @brief 销毁二叉树
 * @param T
 */
void destroyBt(btNode *T)
{
    if(T)
    {
        destroyBt(T->lchild);
        destroyBt(T->rchild);
        delete T;
    }
}
/*!
 * @brief 搜索指定的元素值，返回结点，中序搜索
 * @param T 二叉树指针
 * @param x 指定的元素值
 * @return 搜索到的指针
 */
btNode *btSearch(btNode *T,elementType x){
    btNode *temp = nullptr;
    if (T){
        if (T->data == x){
            return T;
        } else{
            temp = btSearch(T->lchild,x);
            if (temp != nullptr){
                return temp;
            }
            return btSearch(T->rchild,x);
        }
    }
    return nullptr;
}
/*!
 * @brief 返回指定元素的结点层次数
 * @param T
 * @param x
 * @param nLevel 结点的层次数
 * @param nLevelTemp 保存当层层次数
 * @return 该元素在结点上返回True
 */
bool getNodeLevel(btNode *T, elementType x, int* nLevel, int nLevelTemp){
    if (!T){
        *nLevel = 0;
        return false;
    }
    if (T->data == x){
        *nLevel = nLevelTemp;
        return true;
    }
    if (getNodeLevel(T->lchild,x,nLevel,nLevelTemp+1)){
        *nLevel = nLevelTemp;
        return true;
    }
    if (getNodeLevel(T->rchild,x,nLevel,nLevelTemp+1)){
        *nLevel = nLevelTemp;
        return true;
    }
    return false;
}
/*!
 * @brief 返回指定元素的双亲结点，中序搜索
 * @param T
 * @param x 指定的元素
 * @return 存在返回True
 */
btNode* getParent(btNode* T, elementType x){
    btNode* pParent = nullptr;
    if(T->data == x)
    {
        printf("目标结点为根结点，无父结点。\n");
        return nullptr;
    }
    if((T->lchild && T->lchild->data==x) || (T->rchild && T->rchild->data==x))
    {
        return T;  //取得父节点指针，返回
    }
    if (T->lchild)
    {
        pParent = getParent(T->lchild, x);  //递归搜索左子树
        if (pParent != nullptr)
            return pParent;
    }

    if(T->rchild)
        return getParent(T->rchild, x);  //递归搜索右子树

    return nullptr;
}
/*!
 * @brief 返回指定元素的孩子结点
 * @param T
 * @param x 指定的元素
 * @param pL 返回的左孩子结点
 * @param pR 返回的右孩子结点
 * @return
 */
int getChildren(btNode *T, elementType x,btNode **pL,btNode **pR)
{
    //pL,pR分别返回左右孩子结点指针
    btNode *p = nullptr;
    (*pL) = nullptr;
    (*pR) = nullptr;
    if(T == nullptr)
        return 0;       //空树，返回
    p = btSearch(T,x);      //搜索结点x
    if(p == nullptr)
        return 1;       //x不在树上
    if(p->lchild)
    {
        (*pL) = p->lchild;   //返回左孩子指针
    }
    if(p->rchild)
        (*pR) = p->rchild;   //返回右孩子指针
    return 2;
}
/*!
 * @brief 返回指定元素的兄第结点
 * @param T
 * @param x 指定的元素
 * @param pL 左兄弟
 * @param pR 右兄弟
 * @return 返回1 根节点  返回2 不在树上 返回3 存在右兄弟 返回4 存在左兄弟
 */
int getSibling(btNode *T,elementType x, btNode **pL,btNode **pR)
{
    //pL返回左兄弟指针，pR返回右兄弟指针
    btNode *p=nullptr;
    (*pL) = nullptr;
    (*pR) = nullptr;
    if(T == nullptr)
        return 0;   //空树
    p = getParent(T,x);
    if(p == nullptr)
    {
        if(T->data == x)
            return 1;   //x为根结点
        else
            return 2;   //x不在树上
    }

    if(p->lchild && p->lchild->data == x)
    {
        (*pR) = p->rchild;
        return 3;    //右兄弟可能存在
    }

    if(p->rchild && p->rchild->data==x)
    {
        (*pL) = p->lchild;
        return 4;   //左兄弟可能存在
    }
}
/*!
 * @brief 先序线索化
 * @param T 当前处理的结点
 * @param last 前一个处理的结点
 */
void PreThreading(btNode *T,btNode *last){
    btNode  *lp,*rp;
    if(T != nullptr){
        lp = T->lchild;
        rp = T->rchild;
        if (lp ==  nullptr && last != nullptr){
            T->lchild = last;
            T->lTag = 1;
        }
        if (last != nullptr && last->rchild == nullptr){
            last->rchild = T;
            last->rTag = 1;
        }
        last = T;
        PreThreading(lp,last);
        PreThreading(rp,last);
    }
}
/*!
 * @brief 求先序的后继结点
 * @param P 先序指定的结点
 * @return 后继结点指针
 */
btNode *PreSuc(btNode *P){
    if (P->lTag == 0)
        return P->lchild;
    else
        return P->rchild;
}
btNode *InSuc(btNode *P){
    if (P->lTag == 0)
        return P->lchild;
    else{
        // 返回右子树下面的左孩子
        btNode *temp = P->rchild;
        while (temp->lTag == 0){
            temp = temp->lchild;
        }
        return temp;
    }
}
#endif //DS_LEARNING_BTNODE_H
