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

// 初始化
// 返回的是头指针(头结点)
/*!
 * @brief 初始化 ----- 通过函数的返回值来传递链表
 * @return 头指针
 */
node *inittalList(){
    node *p;
    p = new node;   // 头结点
    p->next = nullptr;
    return p;
}
/*!
 * @brief 初始化 ----- 通过引用来传递创建链表
 * @param L
 */
void initialList(node* &L){ // 节点指针的引用
    L = new node ;
    L->next = nullptr;
}
/*!
 * @brief 通过指针的指针来传递指针
 * @param A 头结点的指针
 */
void initialList(node* *A){
    (*A) = new node ;
    (*A) ->next = nullptr;
}
/*!
 * @brief 尾插法实现链表的初始化
 * @param L
 */
void createList(node *&L){
    int i;
    int n; //元素节点个数，不含头结点
    elementType x; //数据元素的数值
    node *p, *R; //R为尾节点的指针
    L=new node;  //产生头节点，动态的在heap上申请内存，存放一个节点（头结点）
    L->next=NULL;  //头结点的指针域为空
    R=L;  //设置尾指针，对空表头、尾指针相同

    std::cout<<"请输入元素节点个数（整数）："<<std::endl;  //控制元素节点的个数
    std::cin>>n;

    std::cout<<"请输入元素数据（整数）:"<<std::endl;
    for(i=n;i>0;i--)  //尾插法循环插入节点
    {
        p=new node;  //动态申请内存，产生新节点
        std:: cin>>x;
        p->data=x;  //写入元素数据
        R->next=p;  //原来尾节点的next指向新节点p
        R=p;        //修改尾指针，使得指向最新产生的节点，即后移一个节点
    }
    R->next=NULL;  //尾节点的next指针为空
}
/*!
 * @brief 打印链表中数据的信息
 * @param L 链表
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
 * @brief 返回链表的长度
 * @param L 链表
 * @return 链表长度
 */
int listLength(node *L){
    int len = 0;
//    node *p = L->next;  // 第一个元素
//    while (p!= nullptr){
//        len ++;
//        p = p->next;
//    }
    node *p = L;    // 头结点
    while (p->next!= nullptr){
        len ++;
        p = p->next;
    }
    return len;
}
/*!
 * @brief 通过引用来返回链表长度
 * @param L 链表
 * @param len 长度
 */
void listLength(node *L,int &len){
    len = 0;
    node *p = L;    // 头结点
    while (p->next!= nullptr){
        len ++;
        p = p->next;
    }
}
/*!
 * @brief 通过指针来返回链表的长度
 * @param L 链表
 * @param len 长度
 */
void listLength(node *L,int *len){
    (*len) = 0;
    node *p = L;    // 头结点
    while (p->next!= nullptr){
        (*len) ++;
        p = p->next;
    }
}
/*!
 * @brief 返回指定位置的结点     节点从1开始计数
 * @param L 链表的头结点
 * @param i 指定的位置
 * @return 返回指定位置的节点,返回nullptr 即不存在
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
 * @brief 返回指定元素再链表中的第一个位置的结点和位置
 * @param L 链表的头结点
 * @param x 指定的元素
 * @param j 结点的位置(从1开始)
 * @return 包含该元素的结点
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
 * @brief 在指定的位置处插入值得的元素(从1开始)
 * @param L 链表的头结点
 * @param i 指定的位置
 * @param x 指定的元素
 * @return 正确插入返回true
 */
bool listInsert(node* L,int i,elementType x){
    node* p = L;node *s ;
    int j = 0;
    while ((p!= nullptr) && (j!= i-1)){ // 这是存在了尾结点才能在最后插入
        p = p->next;
        j++;
    }
    if (p == nullptr) {
//        std::cout << "序号错误"<< std::endl;
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
 * @brief 删除指定位置的结点 从1开始
 * @param L 链表头结点
 * @param i 指定的位置
 * @return 删除成功返回1
 */
bool listDelete(node *L,int i){
    node *p =L;int j = 0;
    while ((j != i-1) && (p!= nullptr)){
        p = p->next;
        j++;
    }
    if (p == nullptr || p ->next == nullptr){   //如果删除的是最后一个结点后一个位置时,p不是空指针,p的下一个才是空指针
        return false;
    } else{
        node *temp = p->next;
        p->next = p->next->next;
        delete temp;    // 回收删除的结点的空间
        return true;
    }
}
/*!
 * @brief 利用尾插法来新建链表,通过特殊符号来控制链表的输入结束
 * @param L 链表的头结点
 */
void createListR(node* &L){
    L = new node ;
    node *R = L;
    elementType x;
    std::cin  >> x;
    while (x!= 9999){   // 结束符号控制
        node *temp = new node ;
        temp->data = x;
        R->next = temp;
        R = temp;
        std::cin >> x;
    }
    R->next = nullptr;
}
/*!
 * @brief 头插法新建链表
 * @param L 链表的头结点
 */
void createListH(node* &L){
    L = new node ;
    L->next = nullptr;
    elementType x;
    std::cin >> x;
    while (x != 9999){  // 结束符号控制
        node *temp = new node ;
        temp->data = x;
        temp->next = L->next;
        L->next = temp;
        std::cin >>x;
    }
}
/*!
 * @brief 链表的销毁
 * @param L 链表的头结点
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
 * @brief 判断链表是不是递增的
 * @param L
 * @return 递增返回true
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
 * @brief 将一个元素插入到递增的链表中
 * @param L 链表的头结点
 * @param x 插入的元素
 */
void setInsert(node* L,elementType x){
    node *p = L;
    while ((p->next != nullptr) && p->next->data <= x){  // 用p -> next来指向各个结点的元素,是为了使指向表尾时,p在链表中
        p = p->next;
    }
    node *temp = new node ;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}
/*!
 * @brief 将A链表复制到B链表,不改变顺序
 * @param A 链表A
 * @param B 链表B
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
 * @brief 对两个单调递增的链表求交集
 * @param A 链表A
 * @param B 链表B
 * @param C 交集链表C
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
 * @brief 带头指针的链表就地转置
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
// 循环链表
// 尾指针的下一个就是头指针
// ----------------------------------------------------------------- //
/*!
 * @brief 通过尾插法生成单循环链表
 * @return 返回尾指针
 */
node *createCircleListR(){
    elementType x;
    node *R = new node ;
    node *p;
    R ->next = R;   // 构成空单循环链表

    std::cin >> x;
    while (x!= 9999){
        p = new node ;
        p->data = x;
        p->next = R->next;  // 新的尾结点指向头结点
        R->next= p;
        R = p;
        std::cin >> x;
    }
    p = nullptr;
    return R;   // 返回尾指针
}
/*!
 * @brief 释放带尾指针的单循环
 * @param R 尾指针
 */
void destroyCircleList(node* R){
    node *p,*pTemp;
    p = R->next;
    R->next = nullptr;  // 变成单链表
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
