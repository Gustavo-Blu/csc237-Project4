// File: TreeTest.cpp
// Driver for Binary Tree ADT

#include <iostream>
#include <string>
#include "BinarySearchTree.h"

typedef BinaryTree<int> IntTree;

char getChoice(std::string ok);
// Insert Value to Search Tree
void addToTree(IntTree& TheTree);
// Remove Value from Search Tree
void removeFromTree(IntTree& TheTree);

int main()
{
	IntTree Tree;
	int entry, * result;
	char Choice;
	do {
		std::cout << "Select: A)dd    R)emove     P)rint     T)ree Print     Q)uit\n";
		Choice = getChoice("ARPTQ");
		switch (Choice) {
		case 'A':
			addToTree(Tree);
			break;
		case 'P':
			std::cout << "The Tree:" << std::endl;
			Tree.inorder();
			break;
		case 'R':
			removeFromTree(Tree);
			break;
		case 'T':
			std::cout << "The tree, as it appears (sort of)..\n";
			Tree.treePrint();
		}
	} while (Choice != 'Q');
}

char getChoice(std::string ok)
{
	char ch = ' ';
	do ch = toupper(std::cin.get()); while (ok.find(ch) == std::string::npos);
	std::cin.get(); // eat CR
	return(toupper(ch));
}

// Insert Value to Search Tree
void addToTree(IntTree& TheTree)
{
	int entry;
	std::cout << " Enter an Integer >";
	std::cin >> entry;
	TheTree.insertToTree(entry);
}

// Remove Value from Search Tree
void removeFromTree(IntTree& TheTree)
{
	int entry, * result;
	std::cout << "Value to Delete? >";
	std::cin >> entry;
	result = TheTree.treeSearch(entry);
	if (!result)
		std::cout << entry << " Not Found\n";
	else
		TheTree.deleteFromTree(entry);
}