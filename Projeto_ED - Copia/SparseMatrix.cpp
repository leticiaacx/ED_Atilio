#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Node.h"
#include "SparseMatrix.h"

//Letícia Pinheiro 509955
// Lucas Mauricio Braga 512257

/**
 * Construtor da classe SparseMatriz
 */
SparseMatriz::SparseMatriz(int m, int n) {
    if(m < 0 || n < 0) {
        throw std::runtime_error( "Invalid value of dimensions" );
    }
    Node *newNode, *aux_node;
    n_row = m;
    n_column = n;
    m_head = new Node(0,0,nullptr,nullptr,0);
    
    aux_node = m_head;
    for(int i = 1; i <= m; i++) {
        newNode = new Node(i,0,nullptr,nullptr,0);
        aux_node->nodeRow = newNode;
        newNode->nodeColumn = newNode;
        aux_node = aux_node->nodeRow;
    }
    aux_node->nodeRow = m_head;

    aux_node = m_head;
    for(int j = 1; j <= n; j++) {
        newNode = new Node(0,j,nullptr,nullptr,0);
        aux_node->nodeColumn = newNode;
        newNode->nodeRow = newNode;
        aux_node = aux_node->nodeColumn;
    }
    aux_node->nodeColumn = m_head;
}

SparseMatriz::~SparseMatriz() { // destrutor
    Node *aux_node, *delete_node;

    aux_node = m_head->nodeColumn;
    while(aux_node != m_head) {
        delete_node = aux_node;
        aux_node = aux_node->nodeColumn;
        delete delete_node;
    }

    aux_node = m_head->nodeRow;
    while(aux_node != m_head) {
        delete_node = aux_node;
        aux_node = aux_node->nodeRow;
        delete delete_node;
    }

    delete aux_node;
}

bool SparseMatriz::verify(int i, int j) { // verificador
    if(i < 0 || j < 0 || i > getRow() || j > getColumn()) {
        throw std::invalid_argument( "valores negativos recebidos" );
        return false;
    }
    if(i > getRow() || j > getColumn()) {
        throw std::invalid_argument( "valores maiores que aceitos" );
        return false;
    }
    return true;
}

void SparseMatriz::DeleteNode(int i, int j) { // deletar node
    Node *aux_node, *delete_node = nullptr;
    int flag = 0;

    aux_node = m_head;
    while(aux_node->row != i) { aux_node = aux_node->nodeRow; }
    aux_node = aux_node->nodeColumn;
    while(aux_node->column != 0) {
        if(aux_node->nodeColumn->column == j) {
            aux_node->nodeColumn = aux_node->nodeColumn->nodeColumn;
            flag = 1;
            break;
        }
        aux_node = aux_node->nodeColumn;
    }
    
    if(flag == 1) {
        while(aux_node->nodeRow->row != i) { aux_node = aux_node->nodeRow; }
        delete_node = aux_node->nodeRow;
        aux_node->nodeRow = aux_node->nodeRow->nodeRow;
        delete delete_node;
        std::cout << "no deletado" << std::endl;
    }
}

void SparseMatriz::insert(int i, int j, double value) { // inserir na matriz
    if(i < 0 || j < 0 || i > getRow() || j > getColumn()) {
        throw std::invalid_argument( "Invalid value" );
    }
    DeleteNode(i,j);
    if(value != 0)
    {
        Node *aux_node, *newNode;
        newNode = new Node(i,j,nullptr,nullptr,value);

        aux_node = m_head;
        while(aux_node->column != j){ aux_node = aux_node->nodeColumn; }
        if(aux_node == aux_node->nodeRow) {
            newNode->nodeRow = aux_node;
            aux_node->nodeRow = newNode;
        }
        else {
            while(aux_node->nodeRow->row != 0) {
                if(aux_node->nodeRow->row > i && aux_node->row < i) {
                    newNode->nodeRow = aux_node->nodeRow;
                    aux_node->nodeRow = newNode;
                    break;
                }
                aux_node = aux_node->nodeRow;
            }
            if(aux_node->nodeRow->row == 0) {
                newNode->nodeRow = aux_node->nodeRow;
                aux_node->nodeRow = newNode;
            }
        }

        aux_node = m_head;
        while(aux_node->row != i){ aux_node = aux_node->nodeRow; }
        if(aux_node == aux_node->nodeColumn) {
            newNode->nodeColumn = aux_node;
            aux_node->nodeColumn = newNode;
        }
        else {
            while(aux_node->nodeColumn->column != 0) {
                if(aux_node->nodeColumn->column > j && aux_node->column < j) {
                    newNode->nodeColumn = aux_node->nodeColumn;
                    aux_node->nodeColumn = newNode;
                }
                aux_node = aux_node->nodeColumn;
            }
            if(aux_node->nodeColumn->column == 0) {
                newNode->nodeColumn = aux_node->nodeColumn;
                aux_node->nodeColumn = newNode;
            }
        }
    }
    
}

/**
 * Função get
 * recebe: posições i e j da matriz
 * return: Um double caso exista um nó na posição i e j, ou 0
 * caso não exista
 */
double SparseMatriz::get(int i, int j) {
    if(i < 0 || j < 0 || i > getRow() || j > getColumn()) {
        throw std::invalid_argument( "Invalid value" );
    }
    Node *aux_node_1;
    aux_node_1 = m_head;

    while(aux_node_1->row != i) { aux_node_1 = aux_node_1->nodeRow; }

    aux_node_1 = aux_node_1->nodeColumn;
    while(aux_node_1->column != 0) {
        if(aux_node_1->column == j) {
            return aux_node_1->value;
        }
        aux_node_1 = aux_node_1->nodeColumn;
    }

    return 0;
}

/**
 * Função getRow
 * Recebe:
 * Return: n_row
 * Descrição: irá retorar um inteiro referente ao número de linhas da matriz
 */
int SparseMatriz::getRow() {
    return n_row;
}

/**
 * Função getColumn
 * Recebe:
 * Return: n_column
 * Descrição: irá retorar um inteiro referente ao número de colunas da matriz.
 */
int SparseMatriz::getColumn() {
    return n_column;
}

/**
 * Função print
 * Recebe: 
 * Return:
 * Descrição: essa função irá imprimir toda a matriz (m x n) com ajuda de dois
 * nodes, um deles (pos_node) irá percorrer toda a coluna (0,j) enquanto o 
 * aux_node irá percorrer as linhas (i,j) imprimindo o valor do nó i,j caso 
 * ele exista e 0.0 caso não exista.
 */
void SparseMatriz::print() {
    Node *pos_node, *aux_node;

    pos_node = m_head->nodeColumn;
    while(pos_node != m_head) {
        aux_node = pos_node->nodeRow;
        std::cout << "[ ";
        for(int i = 1; i <= n_row; i++) {
            if(aux_node->row == i) {
                std::cout << std::fixed << std::setprecision(1) << aux_node->value << " ";
                aux_node = aux_node->nodeRow;
            }
            else {
                std::cout << "0.0 ";
            }
        }
        std::cout << "]" << std::endl;
        pos_node = pos_node->nodeColumn;
    }
}