//
// Created by Lenovo on 2023/6/21.
// 广义表的结构定义
// 取表头是取表的第一个元素
// 取表尾是去掉表头组成的子表
//

#ifndef DS_LEARNING_GLNODE_H
#define DS_LEARNING_GLNODE_H
typedef char elementType;
/*!
 * @brief 广义表，原子结点不包含表尾的指针
 */
 /*
typedef struct glNode{
    int tag;// tag == 1 为子表的结点  tag == 0 为子表的原子结点 存放数据
    union {     // 是将两个东西写在一块内存上，因为下面的数据只能存在一个
        elementType data;   // 存放原子结点时，存放数据
        struct {
            struct glNode* hp,*tp;  // 存放子表结点时，存放子表，表包含表头和表尾。
        }ptr;
    };
}glNode;
*/
 /*!
  * @brief 广义表的拓展表，将表尾指针作为公共区间使用
  */
typedef struct glNode {
    int tag;// tag == 1 为子表的结点  tag == 0 为子表的原子结点 存放数据
    struct glNode *next;    //将表尾指针作为公共的空间
    union {     // 是将两个东西写在一块内存上，因为下面的数据只能存在一个
        elementType data;   // 存放原子结点时，存放数据
        struct glNode* hp;  // 表头指针
    };
}glNode;
#endif //DS_LEARNING_GLNODE_H
