//
// Created by Lenovo on 2023/6/21.
// ͨ��������ʵ�ֶ�����
//

#ifndef DS_LEARNING_BTNODE_H
#define DS_LEARNING_BTNODE_H

#include <iostream>

/*!
 * @brief ͨ������������ʵ�ֶ�����
 */
typedef char elementType;
//typedef struct blNode{
//    elementType data;
//    struct blNode* lchild, *rchild;
//}btNode,*BiTree;
/*!
 * @brief ͨ������������ʵ�ֶ�����������˫�׽�㣬���Ӻ��Һ��ӽ��
 */
typedef struct TriTNode{
    elementType data;
    struct TriTNode *lchild, *rchild, *parent;
}TriTNode, *TriTree;
/*!
 * @brief �����������Ľṹ����
 * @param Tag 0��ʾ����ָ�룬1��ʾ����ָ��
 */
typedef struct blNode{
    elementType data;
    int lTag,rTag;  // �����Ǻ���ָ�뻹������ָ�룬�����ڹ����
    struct blNode* lchild, *rchild;
}btNode,*BiTree;
/*!
 * @brief �������
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
 * @brief �������
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
 * @brief �������
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
 * @brief ������������
 * @param T
 * @return �����������
 */
int btHeight(btNode *T){
    if (T == nullptr)
        return 0;
    else
        return (btHeight(T->lchild) > btHeight(T->rchild) ? btHeight(T->lchild) + 1 : btHeight(T->rchild) + 1);
}
/*!
 * @brief �������ϵ��ܽ����
 * @param T
 * @param num �ܽ����
 */
void getNodeNumber(btNode *T, int *num)
{                  //��������������������
    if(T)
    {
        (*num)++;    //���������
        getNodeNumber(T->lchild, num);    //�ۼ����������
        getNodeNumber(T->rchild, num);    //�ۼ����������
    }
}
/*!
 * @brief ���ض�����Ҷ�ӽ����
 * @param T
 * @param num Ҷ����
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
 * @brief ���ض�������Ϊ2�Ľ����
 * @param T
 * @param num ��Ϊ2�Ľ����
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
 * @brief ���ض�������Ϊ1�Ľ����
 * @param T
 * @param num ��Ϊ1�Ľ����
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
 * @brief ������(ǰ��),'/'����û������
 * @return �������Ľ��
 */
btNode * CreatBTree() {
    btNode* p;
    elementType number;
    std::cin >> number;
    if (number == '0')    // elementType == int ����Ϊ0��Ϊchar����Ϊ /
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
 * @brief ��ʼ��
 * @param T
 */
void Init(btNode*& T) {
    T->lchild = nullptr;
    T->rchild = nullptr;
    T->data = 0;
}
/*!
 * @brief �ж϶������Ƿ�Ϊ��
 * @param T
 * @return �շ���true
 */
bool isEmpty(btNode *T)
{
    if(T!=nullptr)
        return false;
    else
        return true;
}

/*!
 * @brief ���ٶ�����
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
 * @brief ����ָ����Ԫ��ֵ�����ؽ�㣬��������
 * @param T ������ָ��
 * @param x ָ����Ԫ��ֵ
 * @return ��������ָ��
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
 * @brief ����ָ��Ԫ�صĽ������
 * @param T
 * @param x
 * @param nLevel ���Ĳ����
 * @param nLevelTemp ���浱������
 * @return ��Ԫ���ڽ���Ϸ���True
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
 * @brief ����ָ��Ԫ�ص�˫�׽�㣬��������
 * @param T
 * @param x ָ����Ԫ��
 * @return ���ڷ���True
 */
btNode* getParent(btNode* T, elementType x){
    btNode* pParent = nullptr;
    if(T->data == x)
    {
        printf("Ŀ����Ϊ����㣬�޸���㡣\n");
        return nullptr;
    }
    if((T->lchild && T->lchild->data==x) || (T->rchild && T->rchild->data==x))
    {
        return T;  //ȡ�ø��ڵ�ָ�룬����
    }
    if (T->lchild)
    {
        pParent = getParent(T->lchild, x);  //�ݹ�����������
        if (pParent != nullptr)
            return pParent;
    }

    if(T->rchild)
        return getParent(T->rchild, x);  //�ݹ�����������

    return nullptr;
}
/*!
 * @brief ����ָ��Ԫ�صĺ��ӽ��
 * @param T
 * @param x ָ����Ԫ��
 * @param pL ���ص����ӽ��
 * @param pR ���ص��Һ��ӽ��
 * @return
 */
int getChildren(btNode *T, elementType x,btNode **pL,btNode **pR)
{
    //pL,pR�ֱ𷵻����Һ��ӽ��ָ��
    btNode *p = nullptr;
    (*pL) = nullptr;
    (*pR) = nullptr;
    if(T == nullptr)
        return 0;       //����������
    p = btSearch(T,x);      //�������x
    if(p == nullptr)
        return 1;       //x��������
    if(p->lchild)
    {
        (*pL) = p->lchild;   //��������ָ��
    }
    if(p->rchild)
        (*pR) = p->rchild;   //�����Һ���ָ��
    return 2;
}
/*!
 * @brief ����ָ��Ԫ�ص��ֵڽ��
 * @param T
 * @param x ָ����Ԫ��
 * @param pL ���ֵ�
 * @param pR ���ֵ�
 * @return ����1 ���ڵ�  ����2 �������� ����3 �������ֵ� ����4 �������ֵ�
 */
int getSibling(btNode *T,elementType x, btNode **pL,btNode **pR)
{
    //pL�������ֵ�ָ�룬pR�������ֵ�ָ��
    btNode *p=nullptr;
    (*pL) = nullptr;
    (*pR) = nullptr;
    if(T == nullptr)
        return 0;   //����
    p = getParent(T,x);
    if(p == nullptr)
    {
        if(T->data == x)
            return 1;   //xΪ�����
        else
            return 2;   //x��������
    }

    if(p->lchild && p->lchild->data == x)
    {
        (*pR) = p->rchild;
        return 3;    //���ֵܿ��ܴ���
    }

    if(p->rchild && p->rchild->data==x)
    {
        (*pL) = p->lchild;
        return 4;   //���ֵܿ��ܴ���
    }
}
/*!
 * @brief ����������
 * @param T ��ǰ����Ľ��
 * @param last ǰһ������Ľ��
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
 * @brief ������ĺ�̽��
 * @param P ����ָ���Ľ��
 * @return ��̽��ָ��
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
        // �������������������
        btNode *temp = P->rchild;
        while (temp->lTag == 0){
            temp = temp->lchild;
        }
        return temp;
    }
}
#endif //DS_LEARNING_BTNODE_H
