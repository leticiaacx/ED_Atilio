#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "SparseMatrix.h"
#include "Node.h"

//Letícia Pinheiro 509955
// Lucas Mauricio Braga 512257

SparseMatriz* readSparseMatriz(std::string nome_do_arquivo) {
    int i, j;
    double valor = 1.0;
    std::string leit;
    std::ifstream f;
    SparseMatriz *lst;
    try {
        f.open(nome_do_arquivo);
        if(f.fail()) {
            throw std::invalid_argument("cant open a file '" + nome_do_arquivo + "'");
        }

        std::getline(f,leit);
        std::stringstream ss(leit);
        ss >> i >> j;
        lst = new SparseMatriz(i,j);
        while(std::getline(f,leit)) {
            std::stringstream ss(leit);
            ss >> i >> j >> leit;
            valor = std::stod(leit);
            lst->insert(i,j,valor);
        }
        f.close();
    } catch(std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return nullptr;
    }
    return lst;
}

SparseMatriz* sum(SparseMatriz* A, SparseMatriz *B) {
    Node *auxNode_1, *auxNode_2;
    int i, j;
    double a;

    if(A->getRow() > B->getRow()) i = A->getRow();
    else i = B->getRow();
    if(A->getColumn() > B->getColumn()) j = A->getColumn();
    else j = B->getColumn();

    SparseMatriz *C = new SparseMatriz(i,j);
    for(int m = 1; m <= i; m++) {
        for(int n = 1; n <= j; n++) {
            a = 0;
            try {
                if(A->getRow() >= m && A->getColumn() >= n) a += A->get(m,n);
                if(B->getRow() >= m && B->getColumn() >= n) a += B->get(m,n);
                C->insert(m,n,a);
            }
            catch(std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
                return nullptr;
            }
        }
    }

    return C;
}

SparseMatriz *multiply(SparseMatriz *A, SparseMatriz *B) {
    if(A->getColumn() != B->getRow()) {
        std::cout << "Error: different values for row and column" << std::endl;
        return nullptr;
    }
    double value;
    SparseMatriz *C = new SparseMatriz(A->getRow(),B->getColumn());

    for(int i = 1; i <= A->getRow(); i++) {
        for(int j = 1; j <= B->getColumn(); j++) {
            value = 0;
            try {
                for(int k = 1; k <= A->getColumn(); k++) {
                    value += A->get(i,k)*B->get(k,j);
                }
                C->insert(i,j,value);
            }
            catch(std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
                return nullptr;
            }
        }
    }

    return C;
}

int main(void) {
    std::vector<SparseMatriz* > matriz;

    std::cout << "digite 'help' para saber os comandos" << std::endl;
    while(true) {
        std::string cmd;
        std::getline(std::cin,cmd);
        std::stringstream ss{cmd};
        std::vector<std::string> tokens;
        std::string buffer;

        std::cout<< "$" << ss.str() << std::endl;

        while(ss >> buffer) {
            tokens.push_back(buffer);
        }

        if(tokens[0] == "exit") {
            for(int i = 0; i < matriz.size(); i++) {
                std::cout << "Matrix [" << (i) << "] destruida!" << std::endl;
                delete matriz[i];
            }
            matriz.clear();
            break;
        }
        else if(tokens[0] == "create") {
            SparseMatriz *lst = readSparseMatriz(tokens[1]);
            if(lst != nullptr) {
                matriz.push_back(lst);
                std::cout << "Matrix [" << (matriz.size()-1) << "] criada!" << std::endl;
            }
        }
        else if(tokens[0] == "sum") {
            int i = std::stoi(tokens[1]);
            int j = std::stoi(tokens[2]);
            if(i > matriz.size()-1 || j > matriz.size()-1) {
                std::cout << "matriz(es) inexistente(s)" << std::endl;
            }
            else {
                SparseMatriz *lst = sum(matriz[i], matriz[j]);
                if(lst != nullptr) {
                    matriz.push_back(lst);
                    std::cout << "Matrix [" << (matriz.size()-1) << "] criada!" << std::endl;
                }
            }
        }
        else if(tokens[0] == "multiply") {
            int i = std::stoi(tokens[1]);
            int j = std::stoi(tokens[2]);
            if(i > matriz.size()-1 || j > matriz.size()-1) {
                std::cout << "matriz(es) inexistente(s)" << std::endl;
            }
            else {
                SparseMatriz *lst = multiply(matriz[j], matriz[i]);
                if(lst != nullptr) {
                    matriz.push_back(lst);
                    std::cout << "Matrix [" << (matriz.size()-1) << "] criada!" << std::endl;
                }
            }
        }
        else if(tokens[0] == "print") {
            int i = std::stoi(tokens[1]);
            if(i > matriz.size()-1) {
                std::cout << "matriz inexistente" << std::endl;
            }
            else {
                std::cout << "Matriz [" << i << "]" << std::endl; 
                matriz[i]->print();
            }
        }
        else if(tokens[0] == "show") {
            std::cout << "existem " << matriz.size() << " matrizes" << std::endl; 
        }
        else if(tokens[0] == "help") {
            std::cout << "- create: criar uma nova matriz" << std::endl;
            std::cout << "$create file.txt" << std::endl;
            std::cout << std::endl;
            std::cout << "- sum: somar duas matrizes 'n' e 'm'" << std::endl;
            std::cout << "$sum [n] [m]" << std::endl;
            std::cout << std::endl;
            std::cout << "- multiply: multiplicar duas matrizes 'n' e 'm'" << std::endl;
            std::cout << "$multiply [n] [m]" << std::endl;
            std::cout << std::endl;
            std::cout << "- print: escrever na tela a matriz 'n' " << std::endl;
            std::cout << "$print [n]" << std::endl;
            std::cout << std::endl;
            std::cout << "- show: mostrar quantas matrizes existem" << std::endl;
            std::cout << "$show" << std::endl;
            std::cout << std::endl;
            std::cout << "- exit: sair do programa" << std::endl;
            std::cout << "$exit" << std::endl;
            std::cout << "- fim dos comandos -" << std::endl;
        }
        else {
            std::cout << "comando inexistente" << std::endl;
        }
    }
    return 0;
}