//
// Created by Lenovo on 2023/8/21.
// 用邻接矩阵的方式构建图 一个一维数组维护顶点 二维数组维护边
//

#ifndef DS_LEARNING_MGRAPH_H
#define DS_LEARNING_MGRAPH_H

#include <cstdio>
#include <iostream>
#include <mqoai.h>
#include <queue>
typedef char VertexType;    // 顶点的类型
typedef int EdgeType;       // 边上权值的类型
#define MAXVEX 100          // 最大的顶点个数
#define INFINITY 65535      // 表示无穷大，权值无法取到的数

typedef struct {
    VertexType vexs[MAXVEX];    // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];  // 邻接矩阵
    int numNodes,numEdges;  // 分别表示当前的顶点数和边数
}MGraph;

/*!
 * @brief 生成无向图
 * @param G
 */
void CreateMGraph(MGraph *G){
    int i,j,k,w;
    printf("输入顶点数和边数");
    std::cin >> G->numNodes >> G->numEdges;
    for (int i = 0; i < G->numNodes; ++i) {
        std::cin >> G->vexs[i];
    }
    for (int i = 0; i < G->numNodes; ++i) {
        for (int j = 0; j < G->numNodes; ++j) {
            G->arc[i][j] = INFINITY;    // 初始化权
        }
    }
    for (int k = 0; k < G->numEdges; ++k) {
        printf("输入边(vi,vj)的i、j 值和权重w:\n");
        std::cin >> i >> j >> w;
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];    // 无向图对称矩阵
    }
}

// 邻接矩阵 来实现DFS
// 邻接矩阵的深度优化算法
Boolean visited[MAXVEX];
void DFS(MGraph G, int i){
    int j;
    visited[i] = true;
    printf("%c",G.vexs[i]); // 遍历矩阵，对矩阵进行操作
    for (int j = 0; j < G.numNodes; ++j) {  // j、i 表示的是顶点
        if(G.arc[i][j] == 1 && !visited[j])
            DFS(G,j);
    }
}

// 邻接矩阵的深度遍历矩阵
// 这样每一条边都能进行操作
void DFSTraverse(MGraph G){
    for (int i = 0; i < G.numNodes; ++i) {
        visited[i] = false;
    }
    for (int j = 0; j < G.numNodes; ++j) {
        if (!visited[j])
            DFS(G,j);
    }
}

// 邻接矩阵实现广度遍历算法
void BFSTraverse(MGraph G){
    std::queue<int> Q;
    for (int i = 0; i < G.numNodes; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < G.numNodes; ++i) {
        if (!visited[i]){
            visited[i] = true;
            printf("%c",G.vexs[i]);
            Q.push(i);
            while (!Q.empty()){
                int k = Q.front();
                Q.pop();
                for (int j = 0; j < G.numNodes; ++j) {
                    if (G.arc[k][j] == 1 && !visited[j]){
                        visited[j] = true;
                        printf("%c",G.vexs[j]);
                        Q.push(j);
                    }
                }
            }
        }
    }
}
#endif //DS_LEARNING_MGRAPH_H
