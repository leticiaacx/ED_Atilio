#ifndef NODE_H
#define NODE_H

// Letícia Pinheiro 509955
//  Lucas Mauricio Braga 512257

using Item = double;

struct Node
{
    Node *nodeRow;
    Node *nodeColumn;
    int column;
    int row;
    Item value;

    Node(int row, int column, Node *nextRow, Node *nextColumn, const Item& value) 
    {
        this->row = row;
        this->column = column;
        nodeRow = nextRow;
        nodeColumn = nextColumn;
        this->value = value;
    }

};

#endif
