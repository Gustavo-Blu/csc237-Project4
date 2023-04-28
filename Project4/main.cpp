#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BinaryTree<int>* temp = new BinaryTree<int>();
    temp->insertToTree(3);
    temp->insertToTree(1);
    temp->insertToTree(2);
    temp->insertToTree(5);
    temp->insertToTree(4);

    temp->insertToTree(5);
    temp->insertToTree(5);
    temp->insertToTree(5);
    temp->insertToTree(5);

    if (temp->treeSearch(5))
        std::cout << "it was there\n";


    std::cout << temp->retrieveFromTree(5) << std::endl;

    temp->deleteFromTree(5);

    std::cout << "this is preorder\n";
    temp->preorder();

    std::cout << "this is inorder\n";
    temp->inorder();

    std::cout << "this is postorder\n";
    temp->postorder();

	std::cout << "this is breadth first search\n";
	temp->treePrint();
    //std::cout << "Hello World!\n" << << std::endl;
}

