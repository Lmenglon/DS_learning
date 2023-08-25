//
// Created by Lenovo on 2023/6/13.
// 顺序表学习
//

#ifndef DS_LEARNING_LIST_H
#define DS_LEARNING_LIST_H

//#include <wsman.h>

// 定义一个数据类型为int
typedef int elementType;
# define maxLen 100 // 定义顺序表的最长长度为100
typedef struct slist{
    elementType data[maxLen];
    int listLen;
}seqlist;


void error(const char *string);

/*!
 * @brief 初始化链表
 */
void initialList(seqlist *L){
    L ->listLen = 0;
}

/*!
 * @brief 返回顺序表的长度
 * @param L 顺序表
 * @return 整数
 */
int listLen(seqlist *L){
    return L ->listLen;
}
void printList(seqlist *L){
    for (int i = 0; i < L->listLen; ++i) {
        std::cout << L->data[i] << " ";
    }
    std::cout << std::endl;
}
/*!
 * @brief 返回第几位的顺序表的值，从1开始
 * @param L 顺序表
 * @param i 第几位，
 * @param x 返回的值
 */
void getElement(seqlist *L,int i , elementType & x){
    if(i < 1 || i > L->listLen){
        std::cout << "超出范围";
//        error("超出范围");
    }
    else{
        x = L->data[i-1];
    };
}

/*!
 * @brief 返回指定值的第一个位置，不存在返回0，第一个位置为1
 * @param L 顺序表
 * @param x 指定的值
 * @return  返回的位置
 */
int listLocate(seqlist *L,elementType x){
    int i;  // 记录是否值的位置
    for (i = 0;i < L->listLen;i++) {
        if(L->data[i] == x){
            return i+1;
        }
    }
    return 0;
}

/*!
 * @brief 在指定的位置插入指定的值
 * @param L 顺序表
 * @param x 指定的值
 * @param i 指定的位置
 * @return 0 顺序表已满 1 序号错误 2 插入成功
 */
int listInsert(seqlist *L,elementType x,int i){
    if(L->listLen == maxLen) {
        std::cout << "顺序表已满"<< std::endl;
        return 0;
    }
    else if(i < 1 || i > L->listLen+1) {
        std::cout << "序号错误" << std::endl;
        return 1;
    }
    else{
        // 后移
        for (int j = L->listLen-1; j >= i-1; --j) {
            L->data[j+1] = L->data[j];
        }
        L->data[i-1] = x;
        L->listLen ++;
        return 2;
    }
}

/*!
 * @brief 删除指定位置的元素
 * @param L 顺序表
 * @param i 指定的位置
 * @return 0 空表 1 序号不正确 2 删除成功
 */
int listDelete(seqlist *L,int i){
    int j;
    if (L->listLen == 0) { std::cout << "空表"<<std::endl;return 0; }  // 空表
    else if(i < 1||i> L->listLen) { std::cout << "序号不正确"<<std::endl;return 1; } // 序号不正确
    else{
        for (j = i; j < L->listLen; j++) {
            L->data[j-1] = L->data[j];
        }
        L->listLen --;
        return 2;
    }
}
/*!
 * @brief  求两个链表的并集
 * @param L1 一个链表
 * @param L2 另一个链表
 * @param newlist 生成的新链表
 */
void listMerge(seqlist *L1,seqlist *L2,seqlist * newlist){
    // 先将L1 的元素都写到 newlist中
    elementType x;
    for (int i = 1; i <= L1->listLen; ++i) {
        getElement(L1,i,x);
        listInsert(newlist,x,newlist->listLen+1);
    }
    for (int i = 1; i <= L2->listLen ; ++i) {
        getElement(L2,i,x);
        if(!listLocate(newlist,x)){
            listInsert(newlist,x,newlist->listLen+1);
        }
    }
}
/*!
 * @brief 递增排列的顺序表中插入指定的元素
 * @param L 顺序表指针
 * @param x 指定的元素
 */
void insert(seqlist *L,elementType x){
    int i = 0;
    if (L->listLen == maxLen) std::cout << "表满了";
    else{
        while (i<L->listLen && x > L->data[i]){
            i++;
        }
        listInsert(L,x,i+1);
    }
}
/*!
 * @brief 判断A是否是B的子集
 * @param A 集合A
 * @param B 集合B
 * @return 子集TRUE
 */
bool subset(seqlist *A,seqlist *B){
    for (int i = 0; i < A->listLen; ++i) {
        elementType x= A->data[i];
//        方法一   通过判断位置间接实现
        if (!listLocate(B,x)){
            return false;
        }
//      ---------------------------
//      方法二     直接实现
//        int j;
//        for ( j= 0; j < B->listLen; ++j) {
//            if (x == B->data[j]){
//                break;
//            }
//        }
//        if(j == B->listLen) return false;
    }
    return true;
}
/*!
 * @brief 对两个递增的顺序表检测 A是不是B的子集
 * @param A 集合A
 * @param B 集合B
 * @return 子集True
 */
bool OrderedListSubset(seqlist*A,seqlist*B){
    int ia,ib;
    ia = 0;
    ib = 0;
    while (ia < A ->listLen && ib < B->listLen){
        if (A->data[ia] == B->data[ib]){
            ia++,ib++;
        } else if (A->data[ia] > B->data[ib]){
            ib++;
        } else return false;
    }
    if (ia == A->listLen) return true;
    else return false;
}

/*!
 * @brief 将两个递增的顺序表公共元素合并成一个顺序表
 * @param A 顺序表A
 * @param B 顺序表B
 * @param newList 合并后的顺序表
 */
void mergeList(seqlist *A, seqlist *B, seqlist *newList){
    int ia = 0,ib = 0,in = 1;
    initialList(newList);
    elementType x,y;
    while (ia < A->listLen && ib < B->listLen){
        x = A->data[ia];
        y = B->data[ib];
        if (x < y){
            ia++;
        }
        else if (x == y){
            listInsert(newList,x,in);
            ia++,in++,ib++;
        } else {
            ib++;
        }
    }
}



#endif //DS_LEARNING_LIST_H
