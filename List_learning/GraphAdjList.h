//
// Created by Lenovo on 2023/8/21.
// 通过邻接表来实现即数组加链表。数组维护顶点，链表维护边
//

#ifndef DS_LEARNING_GRAPHADJLIST_H
#define DS_LEARNING_GRAPHADJLIST_H
#include <cstdio>
#include <iostream>
#include <mqoai.h>
#include "seqQueue.h"
typedef char VertexType;    // 顶点的类型
typedef int EdgeType;       // 边上权值的类型
#define MAXVEX 100          // 最大的顶点个数
#define INFINITY 65535      // 表示无穷大，权值无法取到的数

typedef struct EdgeNode{    // 边表结点
    int adjvex;     // 存储该节点对应的下标
    EdgeType info;  // 存储权值
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{  // 顶点表结点
    VertexType data;    // 顶点信息
    EdgeNode *firstedge;    // 边表的头指针
}VertexNode,AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numNodes,numEdges;  // 当前顶点数和边数
}GraphAdjList;

void CreateALGraph(GraphAdjList *G){
    int i, j;
    EdgeNode *e;
    printf("输入顶点数和边数\n");
    std::cin >> G->numNodes >> G->numEdges;
    for (int i = 0; i < G->numNodes; ++i) {
        std::cin >> G->adjList[i].data;
        G->adjList[i].firstedge = nullptr;
    }
    for (int k = 0; k < G->numEdges; ++k) {
        printf("输入边(vi,vj)上的顶点序号：\n");
        std::cin >> i >> j;
        e = new EdgeNode ;
        e->adjvex = j;
        // 头插法
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        // 无向表 两边都要插
        e = new EdgeNode ;
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }

}

// 邻接表 来实现DFS
// 邻接表的深度优化算法
Boolean visited[MAXVEX];
void DFS(GraphAdjList *GL,int i){
    EdgeNode *p;
    visited[i] = true;
    printf("%c",GL->adjList[i].data);
    p = GL->adjList[i].firstedge;
    while (p){
        if(!visited[p->adjvex])
            DFS(GL,p->adjvex);
        p = p->next;
    }
}

// 邻接表的深度遍历操作
void DFSTraverse(GraphAdjList *GL){
    for (int i = 0; i < GL->numNodes; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < GL->numNodes; ++i) {
        if (!visited[i])
            DFS(GL,i);
    }
}


// 邻接表，实现广度遍历算法
void BFSTraverse(GraphAdjList *GL){
    for (int i = 0; i < GL->numNodes; ++i) {
        visited[i] = false;
    }
    EdgeNode *p;
    seqQueue Q;
    initQueue(Q);
    for (int i = 0; i < GL->numNodes; ++i) {
        if (!visited[i]){
            visited[i] = true;
            printf("%c",GL->adjList[i].data);
            enQueue(Q,i);
            while (!queueEmpty(Q)){
                int k;
                outQueue(Q,k);
                p = GL->adjList[k].firstedge;
                while (p){
                    if (!visited[p->adjvex]){
                        visited[p->adjvex] = true;
                        printf("%c",GL->adjList[i].data);
                        enQueue(Q,j);
                    }
                    p = p->next;
                }
            }
        }
    }
}








#endif //DS_LEARNING_GRAPHADJLIST_H
