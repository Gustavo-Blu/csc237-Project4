#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BinaryTree<int>* temp = new BinaryTree<int>();
    temp->insertToTree(1);
    temp->insertToTree(2);
    temp->insertToTree(3);
    temp->insertToTree(4);
    temp->insertToTree(5);

    temp->insertToTree(5);
    temp->insertToTree(5);
    temp->insertToTree(5);
    temp->insertToTree(5);

    if (temp->treeSearch(5))
        std::cout << "it was there\n";


    std::cout << temp->retrieveFromTree(5) << std::endl;

    temp->inorder();

    //std::cout << "Hello World!\n" << << std::endl;
}

