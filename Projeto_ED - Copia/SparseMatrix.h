#ifndef SPMATRIZ_H
#define SPMATRIZ_H
#include <string>
#include "Node.h"

//Letícia Pinheiro 509955
// Lucas Mauricio Braga 512257

class SparseMatriz
{
private:
    Node *m_head {nullptr};
    int n_row {0};
    int n_column {0};
public:
    SparseMatriz(int m, int n);
    ~SparseMatriz();
    bool verify(int i, int j);
    void DeleteNode(int i, int j);
    void insert(int i, int j, double value);
    void addMatriz(SparseMatriz *A);
    double get(int i, int j);
    int getRow();
    int getColumn();
    void print();
};

#endif
