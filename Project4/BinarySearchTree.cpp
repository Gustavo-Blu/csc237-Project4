#include <iostream>
#include <string>
#include <queue>
#include "BinarySearchTree.h"

template<typename treeEltType>
BinaryTree<treeEltType>::BinaryTree()
{
	m_Root = nullptr;
}

template <typename treeEltType>
int BinaryTree<treeEltType>::insertToTree(const treeEltType& data)
{
	if (m_Root == nullptr) {
		auto* newNode = new TreeNode<treeEltType>(data);
		m_Root = newNode;
		return 1;
	}

	TreeNode<treeEltType>* curr = m_Root, *parent = m_Root;

	while (curr != nullptr)
	{
		if (curr->m_Info == data)
		{
			curr->m_Count += 1;
			return 0;
		}
		
		if (data > curr->m_Info)
		{
			parent = curr;
			curr = curr->m_Right;
		}
		else
		{
			parent = curr;
			curr = curr->m_Left;
		}
	}


	if (data > parent->m_Info)
	{
		TreeNode<treeEltType>* newNode = new TreeNode<treeEltType>(data);
		parent->m_Right = newNode;
		return 1;
	}
	else
	{
		TreeNode<treeEltType>* newNode = new TreeNode<treeEltType>(data);
		parent->m_Left = newNode;
		return 1;
	}


	return 0;

}

template <typename treeEltType>
treeEltType* BinaryTree<treeEltType>::treeSearch(const treeEltType& data)
{
		TreeNode<treeEltType> * curr = m_Root;

	while (curr && curr->m_Info != data)
	{

		if (curr->m_Info < data)
			curr = curr->m_Right;
		else
			curr = curr->m_Left;
	}

	if (curr)
		return &curr->m_Info;

	return nullptr;
}

template <typename treeEltType>
treeEltType& BinaryTree<treeEltType>::retrieveFromTree(const treeEltType& data)
{
	TreeNode<treeEltType>* curr = m_Root;

	while (curr && curr->m_Info != data)
	{
		if (curr->m_Info < data)
			curr = curr->m_Right;
		else
			curr = curr->m_Left;
	}

		return curr->m_Info;

}

template <typename treeEltType>
void BinaryTree<treeEltType>::deleteFromTree(const treeEltType& data)
{
	TreeNode<treeEltType>* curr = m_Root;

	while (curr && curr->m_Info != data)
	{
		if (curr->m_Info < data)
			curr = curr->m_Right;
		else
			curr = curr->m_Left;
	}

	if (curr)
		curr->m_Count -= 1;
}

template <typename treeEltType>
void BinaryTree<treeEltType>::inorder() const
{
	printInorder(m_Root);
}

template <typename treeEltType>
void BinaryTree<treeEltType>::preorder() const
{
	printPreorder(m_Root);
}

template <typename treeEltType>
void BinaryTree<treeEltType>::postorder() const
{
	printPostorder(m_Root);
}

template <typename treeEltType>
void BinaryTree<treeEltType>::treePrint() const
{
	treePrintHelper(m_Root);
}

template <typename treeEltType>
void BinaryTree<treeEltType>::printInorder(TreeNode<treeEltType>* data) const
{
	if (data == nullptr)
		return;

	printInorder(data->m_Left);
	std::cout << data->m_Info << " " << data->m_Count << std::endl;
	printInorder(data->m_Right);
}

template <typename treeEltType>
void BinaryTree<treeEltType>::printPreorder(TreeNode<treeEltType>* data) const
{
	if (data == nullptr)
		return;

	std::cout << data->m_Info << " " << data->m_Count << std::endl;
	printPreorder(data->m_Left);
	printPreorder(data->m_Right);
}

template <typename treeEltType>
void BinaryTree<treeEltType>::printPostorder(TreeNode<treeEltType>* data) const
{
	if (data == nullptr)
		return;

	printPostorder(data->m_Left);
	printPostorder(data->m_Right);
	std::cout << data->m_Info << " " << data->m_Count << std::endl;
}
template <typename treeEltType>
void BinaryTree<treeEltType>::treePrintHelper(TreeNode<treeEltType>* data) const
{
	std::queue<TreeNode<treeEltType> *> nodes;
	nodes.push(data);

	while (!nodes.empty())
	{
		TreeNode<treeEltType>* curr = nodes.front();
		nodes.pop();

		std::cout << curr->m_Info << " " << curr->m_Count << std::endl;

		if (curr->m_Left)
			nodes.push(curr->m_Left);
		if (curr->m_Right)
			nodes.push(curr->m_Right);
	}
}

template class BinaryTree<int>;
//template class BinaryTree<std::string>;