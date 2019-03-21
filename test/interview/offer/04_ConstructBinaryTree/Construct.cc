 ///
 /// @file    Construct.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-10 20:52:15
 ///
 
//分析：
//1.我们现根据前序遍历序列的第一个确定根，然后在中序遍历的序列中找到
//根的位置，根左边的就是其左子树，右边就是其右子树
//2.构建根和左右子树
//3.递归进行1和2

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
 
struct BinaryTreeNode
{
	int _data;
	BinaryTreeNode * _left;
	BinaryTreeNode * _right;

	BinaryTreeNode(int x)
	: _data(x)
	, _left(nullptr)
	, _right(nullptr)
	{}

	static void PreOrder(BinaryTreeNode * root)
	{
		if(root == nullptr)
		{
			return ;
		}
		cout << root->_data;
		PreOrder(root->_left);
		PreOrder(root->_right);
	}

	static void InOrder(BinaryTreeNode * root)
	{
		if(root == nullptr)
		{
			return ;
		}
		InOrder(root->_left);
		cout << root->_data;
		InOrder(root->_right);
	}
};

class Solution
{
public:
	struct BinaryTreeNode * ConstructBinaryTree(vector<int>pre, vector<int> in)
	{
		//前序遍历的长度跟中序遍历的长度应该相同
		if(pre.size() != in.size()) {
			cout << "the length of PRE and IN should be same" << endl;
			return nullptr;
		}

		//长度不能为0
		int size = pre.size();
		if(size == 0) {
			cout << "it's a null tree" << endl;
			return nullptr;
		}

		int length = pre.size();
		cout << endl << "the length of your tree = " << length << endl;
		int value = pre[0]; //前序遍历的第一个节点是根节点
		BinaryTreeNode * root = new BinaryTreeNode(value);
		
		cout << "the root is " << root->_data << endl;
		//在中序遍历中查找到根的位置
		int rootIndex = 0;
		for(rootIndex = 0; rootIndex < length; rootIndex++)
		{
			if(in[rootIndex] == value)
			{
				cout << "find the root at " << rootIndex << endl;
				break;
			}
		}

		if(rootIndex >= length)
		{
			cout << "can't find root" << endl;
			return nullptr;
		}
		//区分左子树和右子树
		//中序遍历中，根左边的就是左子树，右边的就是右子树
		//前序遍历中，根后面是先遍历左子树，然后是右子树
		
		//首先确定左右子树的长度，从中序遍历in中确定
		int leftlength = rootIndex;
		int rightlength = length - 1 - rootIndex;
		cout << "leftlength = " <<  leftlength 
			 << "\nrightlength = " << rightlength << endl;
		vector<int> preLeft(leftlength), inLeft(leftlength);
		vector<int> preRight(rightlength), inRight(rightlength);
		for(int i = 0; i < length; ++i){
			if(i < rootIndex) {
				//前序遍历的第一个是根节点，根后面的(leftlength = rootIndex) - 1个节点是左子树，因此是i+1
				preLeft[i] = pre[i + 1];
				inLeft[i] = in[i];
				cout << preLeft[i] << inLeft[i] << " ";
			}else if(i > rootIndex)
			{
				preRight[i - rootIndex -1] = pre[i];
				inRight[i - rootIndex - 1] = in[i];
				cout << preRight[i - rootIndex -1] << inRight[i - rootIndex - 1] << " ";
			}
		}
		cout << endl;

		cout << "the left tree" << endl;
		for(int i = 0; i < leftlength; ++i)
		{
			cout << preLeft[i] << inLeft[i] << " ";
		}
		cout << endl;

		cout << "the right tree" << endl;
		for(int i = 0; i < rightlength; ++i)
		{
			cout << preRight[i] << inRight[i] << " ";
		}
		cout << endl;

		root->_left = ConstructBinaryTree(preLeft, inLeft);
		root->_right= ConstructBinaryTree(preRight, inRight);

		return root;
	}
};

int main()
{
	int pre[] = {1, 2, 4, 7, 3, 5, 7, 8};
	int in[] = {4, 7, 2, 1, 5, 3, 8, 7};

	vector<int> preOrder(pre, pre + 8);
	vector<int> inOrder(in, in + 8);

	Solution solu;
	BinaryTreeNode * root = solu.ConstructBinaryTree(preOrder, inOrder);
	
	cout << "PreOrder" << endl;
	BinaryTreeNode::PreOrder(root);
	cout << endl;

	cout << "InOrder" << endl;
	BinaryTreeNode::InOrder(root);
	cout << endl;

	return 0;
}
