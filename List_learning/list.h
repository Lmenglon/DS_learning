//
// Created by Lenovo on 2023/6/13.
// ˳���ѧϰ
//

#ifndef DS_LEARNING_LIST_H
#define DS_LEARNING_LIST_H

//#include <wsman.h>

// ����һ����������Ϊint
typedef int elementType;
# define maxLen 100 // ����˳���������Ϊ100
typedef struct slist{
    elementType data[maxLen];
    int listLen;
}seqlist;


void error(const char *string);

/*!
 * @brief ��ʼ������
 */
void initialList(seqlist *L){
    L ->listLen = 0;
}

/*!
 * @brief ����˳���ĳ���
 * @param L ˳���
 * @return ����
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
 * @brief ���صڼ�λ��˳����ֵ����1��ʼ
 * @param L ˳���
 * @param i �ڼ�λ��
 * @param x ���ص�ֵ
 */
void getElement(seqlist *L,int i , elementType & x){
    if(i < 1 || i > L->listLen){
        std::cout << "������Χ";
//        error("������Χ");
    }
    else{
        x = L->data[i-1];
    };
}

/*!
 * @brief ����ָ��ֵ�ĵ�һ��λ�ã������ڷ���0����һ��λ��Ϊ1
 * @param L ˳���
 * @param x ָ����ֵ
 * @return  ���ص�λ��
 */
int listLocate(seqlist *L,elementType x){
    int i;  // ��¼�Ƿ�ֵ��λ��
    for (i = 0;i < L->listLen;i++) {
        if(L->data[i] == x){
            return i+1;
        }
    }
    return 0;
}

/*!
 * @brief ��ָ����λ�ò���ָ����ֵ
 * @param L ˳���
 * @param x ָ����ֵ
 * @param i ָ����λ��
 * @return 0 ˳������� 1 ��Ŵ��� 2 ����ɹ�
 */
int listInsert(seqlist *L,elementType x,int i){
    if(L->listLen == maxLen) {
        std::cout << "˳�������"<< std::endl;
        return 0;
    }
    else if(i < 1 || i > L->listLen+1) {
        std::cout << "��Ŵ���" << std::endl;
        return 1;
    }
    else{
        // ����
        for (int j = L->listLen-1; j >= i-1; --j) {
            L->data[j+1] = L->data[j];
        }
        L->data[i-1] = x;
        L->listLen ++;
        return 2;
    }
}

/*!
 * @brief ɾ��ָ��λ�õ�Ԫ��
 * @param L ˳���
 * @param i ָ����λ��
 * @return 0 �ձ� 1 ��Ų���ȷ 2 ɾ���ɹ�
 */
int listDelete(seqlist *L,int i){
    int j;
    if (L->listLen == 0) { std::cout << "�ձ�"<<std::endl;return 0; }  // �ձ�
    else if(i < 1||i> L->listLen) { std::cout << "��Ų���ȷ"<<std::endl;return 1; } // ��Ų���ȷ
    else{
        for (j = i; j < L->listLen; j++) {
            L->data[j-1] = L->data[j];
        }
        L->listLen --;
        return 2;
    }
}
/*!
 * @brief  ����������Ĳ���
 * @param L1 һ������
 * @param L2 ��һ������
 * @param newlist ���ɵ�������
 */
void listMerge(seqlist *L1,seqlist *L2,seqlist * newlist){
    // �Ƚ�L1 ��Ԫ�ض�д�� newlist��
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
 * @brief �������е�˳����в���ָ����Ԫ��
 * @param L ˳���ָ��
 * @param x ָ����Ԫ��
 */
void insert(seqlist *L,elementType x){
    int i = 0;
    if (L->listLen == maxLen) std::cout << "������";
    else{
        while (i<L->listLen && x > L->data[i]){
            i++;
        }
        listInsert(L,x,i+1);
    }
}
/*!
 * @brief �ж�A�Ƿ���B���Ӽ�
 * @param A ����A
 * @param B ����B
 * @return �Ӽ�TRUE
 */
bool subset(seqlist *A,seqlist *B){
    for (int i = 0; i < A->listLen; ++i) {
        elementType x= A->data[i];
//        ����һ   ͨ���ж�λ�ü��ʵ��
        if (!listLocate(B,x)){
            return false;
        }
//      ---------------------------
//      ������     ֱ��ʵ��
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
 * @brief ������������˳����� A�ǲ���B���Ӽ�
 * @param A ����A
 * @param B ����B
 * @return �Ӽ�True
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
 * @brief ������������˳�����Ԫ�غϲ���һ��˳���
 * @param A ˳���A
 * @param B ˳���B
 * @param newList �ϲ����˳���
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
