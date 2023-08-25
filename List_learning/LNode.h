//
// Created by Lenovo on 2023/6/19.
//

#ifndef DS_LEARNING_LNODE_H
#define DS_LEARNING_LNODE_H

typedef int elementType;
typedef struct LNode{
    elementType data;
    struct LNode* next;
}node, *linkList;

// ��ʼ��
// ���ص���ͷָ��(ͷ���)
/*!
 * @brief ��ʼ�� ----- ͨ�������ķ���ֵ����������
 * @return ͷָ��
 */
node *inittalList(){
    node *p;
    p = new node;   // ͷ���
    p->next = nullptr;
    return p;
}
/*!
 * @brief ��ʼ�� ----- ͨ�����������ݴ�������
 * @param L
 */
void initialList(node* &L){ // �ڵ�ָ�������
    L = new node ;
    L->next = nullptr;
}
/*!
 * @brief ͨ��ָ���ָ��������ָ��
 * @param A ͷ����ָ��
 */
void initialList(node* *A){
    (*A) = new node ;
    (*A) ->next = nullptr;
}
/*!
 * @brief β�巨ʵ������ĳ�ʼ��
 * @param L
 */
void createList(node *&L){
    int i;
    int n; //Ԫ�ؽڵ����������ͷ���
    elementType x; //����Ԫ�ص���ֵ
    node *p, *R; //RΪβ�ڵ��ָ��
    L=new node;  //����ͷ�ڵ㣬��̬����heap�������ڴ棬���һ���ڵ㣨ͷ��㣩
    L->next=NULL;  //ͷ����ָ����Ϊ��
    R=L;  //����βָ�룬�Կձ�ͷ��βָ����ͬ

    std::cout<<"������Ԫ�ؽڵ��������������"<<std::endl;  //����Ԫ�ؽڵ�ĸ���
    std::cin>>n;

    std::cout<<"������Ԫ�����ݣ�������:"<<std::endl;
    for(i=n;i>0;i--)  //β�巨ѭ������ڵ�
    {
        p=new node;  //��̬�����ڴ棬�����½ڵ�
        std:: cin>>x;
        p->data=x;  //д��Ԫ������
        R->next=p;  //ԭ��β�ڵ��nextָ���½ڵ�p
        R=p;        //�޸�βָ�룬ʹ��ָ�����²����Ľڵ㣬������һ���ڵ�
    }
    R->next=NULL;  //β�ڵ��nextָ��Ϊ��
}
/*!
 * @brief ��ӡ���������ݵ���Ϣ
 * @param L ����
 */
void listPrint(node *L){
    node *p = L;
    while (p->next != nullptr){
        p = p->next;
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}
/*!
 * @brief ��������ĳ���
 * @param L ����
 * @return ������
 */
int listLength(node *L){
    int len = 0;
//    node *p = L->next;  // ��һ��Ԫ��
//    while (p!= nullptr){
//        len ++;
//        p = p->next;
//    }
    node *p = L;    // ͷ���
    while (p->next!= nullptr){
        len ++;
        p = p->next;
    }
    return len;
}
/*!
 * @brief ͨ������������������
 * @param L ����
 * @param len ����
 */
void listLength(node *L,int &len){
    len = 0;
    node *p = L;    // ͷ���
    while (p->next!= nullptr){
        len ++;
        p = p->next;
    }
}
/*!
 * @brief ͨ��ָ������������ĳ���
 * @param L ����
 * @param len ����
 */
void listLength(node *L,int *len){
    (*len) = 0;
    node *p = L;    // ͷ���
    while (p->next!= nullptr){
        (*len) ++;
        p = p->next;
    }
}
/*!
 * @brief ����ָ��λ�õĽ��     �ڵ��1��ʼ����
 * @param L �����ͷ���
 * @param i ָ����λ��
 * @return ����ָ��λ�õĽڵ�,����nullptr ��������
 */
node* getElement(node *L,int i){
    node *p = L->next;
    int j = 1;
    while ((j!= i)&&(p != nullptr)){
        p = p->next;
        j++;
    }
    return p;
}
/*!
 * @brief ����ָ��Ԫ���������еĵ�һ��λ�õĽ���λ��
 * @param L �����ͷ���
 * @param x ָ����Ԫ��
 * @param j ����λ��(��1��ʼ)
 * @return ������Ԫ�صĽ��
 */
node* listLocate(node *L,elementType x,int *j){
    node *p = L->next;
    while ((p->data != x) && p != nullptr){
        (*j)++;
        p = p->next;
    }
    if (p == nullptr){
        (*j) = 0;
    }
    return p;
}
/*!
 * @brief ��ָ����λ�ô�����ֵ�õ�Ԫ��(��1��ʼ)
 * @param L �����ͷ���
 * @param i ָ����λ��
 * @param x ָ����Ԫ��
 * @return ��ȷ���뷵��true
 */
bool listInsert(node* L,int i,elementType x){
    node* p = L;node *s ;
    int j = 0;
    while ((p!= nullptr) && (j!= i-1)){ // ���Ǵ�����β��������������
        p = p->next;
        j++;
    }
    if (p == nullptr) {
//        std::cout << "��Ŵ���"<< std::endl;
        return false;
    }
    else{
        s = new node ;
        s->data = x;
        s->next = p->next;
        p->next = s;
        return true;
    }
}
/*!
 * @brief ɾ��ָ��λ�õĽ�� ��1��ʼ
 * @param L ����ͷ���
 * @param i ָ����λ��
 * @return ɾ���ɹ�����1
 */
bool listDelete(node *L,int i){
    node *p =L;int j = 0;
    while ((j != i-1) && (p!= nullptr)){
        p = p->next;
        j++;
    }
    if (p == nullptr || p ->next == nullptr){   //���ɾ���������һ������һ��λ��ʱ,p���ǿ�ָ��,p����һ�����ǿ�ָ��
        return false;
    } else{
        node *temp = p->next;
        p->next = p->next->next;
        delete temp;    // ����ɾ���Ľ��Ŀռ�
        return true;
    }
}
/*!
 * @brief ����β�巨���½�����,ͨ���������������������������
 * @param L �����ͷ���
 */
void createListR(node* &L){
    L = new node ;
    node *R = L;
    elementType x;
    std::cin  >> x;
    while (x!= 9999){   // �������ſ���
        node *temp = new node ;
        temp->data = x;
        R->next = temp;
        R = temp;
        std::cin >> x;
    }
    R->next = nullptr;
}
/*!
 * @brief ͷ�巨�½�����
 * @param L �����ͷ���
 */
void createListH(node* &L){
    L = new node ;
    L->next = nullptr;
    elementType x;
    std::cin >> x;
    while (x != 9999){  // �������ſ���
        node *temp = new node ;
        temp->data = x;
        temp->next = L->next;
        L->next = temp;
        std::cin >>x;
    }
}
/*!
 * @brief ���������
 * @param L �����ͷ���
 */
void destroyList(node* &L){
    node *p,*pTemp;
    p = L;
    while (p){
        pTemp = p->next;
        delete p;
        p = pTemp;
    }
    L = nullptr;
}
/*!
 * @brief �ж������ǲ��ǵ�����
 * @param L
 * @return ��������true
 */
bool Judge(node *L){
    node *P = L->next;
    while (P->next != nullptr){
        if (P->data <=P->next->data){
            P = P->next;
        } else return false;
    }
    return true;
}
/*!
 * @brief ��һ��Ԫ�ز��뵽������������
 * @param L �����ͷ���
 * @param x �����Ԫ��
 */
void setInsert(node* L,elementType x){
    node *p = L;
    while ((p->next != nullptr) && p->next->data <= x){  // ��p -> next��ָ���������Ԫ��,��Ϊ��ʹָ���βʱ,p��������
        p = p->next;
    }
    node *temp = new node ;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}
/*!
 * @brief ��A�����Ƶ�B����,���ı�˳��
 * @param A ����A
 * @param B ����B
 */
void listCopy(node *A,node* &B){
    node *pa = A->next;
    B = new node ;
    node *Rb = B;
    while (pa != nullptr){
        node *temp = new node;
        temp->data = pa->data;
        Rb->next = temp;
        Rb = temp;
        pa = pa->next;
    }
    Rb->next = nullptr;
}
/*!
 * @brief ���������������������󽻼�
 * @param A ����A
 * @param B ����B
 * @param C ��������C
 */
void insertSet(node *A,node *B,node *&C){
    node *pa = A->next ,*pb = B->next;
    C = new node ;
    C->next = nullptr;
    node *Rc = C;
    while ((pa!= nullptr) && (pb != nullptr)){
        if (pa->data < pb->data){
            pa = pa->next;
        } else if(pb->data < pa->data){
            pb = pb->next;
        }else{
            node *temp = new node ;
            temp->data = pa->data;
            Rc->next = temp;
            Rc = temp;
            pa = pa->next;
            pb = pb->next;
        }
        Rc->next = nullptr;
    }
}
/*!
 * @brief ��ͷָ�������͵�ת��
 * @param L
 */
void reverse(node *& L){
    linkList p,u;
    p = L->next;
    u = L->next->next;
    while (u != nullptr){
        linkList temp = u;
        u = u->next;
        temp->next = p;
        p = temp;
    }
    L->next->next = nullptr;
    L->next = p;
}
// ----------------------------------------------------------------- //
// ѭ������
// βָ�����һ������ͷָ��
// ----------------------------------------------------------------- //
/*!
 * @brief ͨ��β�巨���ɵ�ѭ������
 * @return ����βָ��
 */
node *createCircleListR(){
    elementType x;
    node *R = new node ;
    node *p;
    R ->next = R;   // ���ɿյ�ѭ������

    std::cin >> x;
    while (x!= 9999){
        p = new node ;
        p->data = x;
        p->next = R->next;  // �µ�β���ָ��ͷ���
        R->next= p;
        R = p;
        std::cin >> x;
    }
    p = nullptr;
    return R;   // ����βָ��
}
/*!
 * @brief �ͷŴ�βָ��ĵ�ѭ��
 * @param R βָ��
 */
void destroyCircleList(node* R){
    node *p,*pTemp;
    p = R->next;
    R->next = nullptr;  // ��ɵ�����
    while (p){
        pTemp = p->next;
        delete (p);
        p = pTemp;
    }
    R = nullptr;
}
void CircleListPrint(node *L){
    node *temp = L->next->next;
    while (temp != L->next){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
void mergeCircleList(node *&A, node *&B){
    node *temp = A->next;
    A->next = B->next->next;
    delete B->next;
    B->next = temp;
    A = B;
}
#endif //DS_LEARNING_LNODE_H
