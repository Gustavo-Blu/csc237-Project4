#ifndef TREE_H
#define TREE_H

template <typename treeEltType> class BinaryTree;

template <typename eltType> class TreeNode
{
	eltType m_Info;
	TreeNode<eltType>* m_Left, * m_Right;
	int m_Count;

	TreeNode(const eltType& data, TreeNode<eltType>* left = nullptr, TreeNode<eltType>* right = nullptr, int counter = 1) : m_Info(data), m_Left(left), m_Right(right), m_Count(counter) {}


	friend class BinaryTree<eltType>;
};

template <typename treeEltType> class BinaryTree
{
public:
	// Constructor
	BinaryTree();

	// Place Element into Tree
	// Returns 1 if inserted, 0 if Data already in tree
	int insertToTree(const treeEltType& data);

	// Search for Element in Tree
	// Assumes == is defined for treeEltType
	// Returns pointer to data, or NULL, according to success
	treeEltType* treeSearch(const treeEltType& data);

	// Retrieve Element from Tree (leaving Tree Intact)
	// Precondition: Item is in Tree
	treeEltType& retrieveFromTree(const treeEltType& data);

	// Remove an Element from the tree
	// Pre: Element is in the Tree
	void deleteFromTree(const treeEltType& data);

	// Display Tree using InOrder Traversal
	void inorder() const;

	// Display Tree using PreOrder Traversal
	void preorder() const;

	// Display Tree using PostOrder Traversal
	void postorder() const;

	// Breadth first print
	void treePrint() const;

private:

	TreeNode<treeEltType>* m_Root;

	// Display Tree using InOrder Traversal
	void printInorder(TreeNode<treeEltType>* data) const;

	// Display Tree using PreOrder Traversal
	void printPreorder() const;

	// Display Tree using PostOrder Traversal
	void printPostorder() const;

	void treePrintHelper(TreeNode<treeEltType>*) const;
};



















#endif // !TREE_H
