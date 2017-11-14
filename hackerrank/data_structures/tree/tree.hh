#ifndef _TREE_HH
#define _TREE_HH

#include <functional>
#include <stack>

using namespace std;

namespace jvanz {
namespace tree {

/// Binary tree data structure
// TODO add template support
class TreeNode
{
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) : data{val}, left{nullptr}, right{nullptr} {};

	class iterator : public std::iterator<std::forward_iterator_tag, TreeNode>
	{
		private:
			stack<TreeNode*> st;
		public:
			iterator(TreeNode* n)
			{ 
				st.push(n);
			};

			iterator(const iterator& poi) : st(poi.st) { };

			iterator& operator++()
			{ 
				auto top = this->st.top();
				this->st.pop();
				if (top->right)
					this->st.push(top->right);
				if (top->left)
					this->st.push(top->left);
				return *this; 
			};

			iterator operator++(int)
			{ 
				iterator tmp(*this);
				operator++(); 
				return tmp;
			};

			bool operator==(const iterator& rhs) const
			{
				return this->st.size() > 0 && rhs.st.size() > 0
					&& this->st.top() == rhs.st.top();
			};

			bool operator!=(const iterator& rhs) const
			{
				return this->st.size() > 0 && rhs.st.size() > 0
					&& this->st.top() != rhs.st.top();
			};

			TreeNode& operator*()
			{ 
				return *(this->st.top());
			};

	}; // iterator class


	// TreeNode methods
	iterator begin() { return iterator(this); };
	iterator end() { return iterator(nullptr); };

}; // TreeNode class

void pre_order_iterator(TreeNode* root, function<void(int)> func)
{
	if (!root)
		return;
	func(root->data);
	pre_order_iterator(root->left, func);
	pre_order_iterator(root->right, func);
}

void post_order_iterator(TreeNode* root, function<void(int)> func)
{
	if (!root)
		return;
	post_order_iterator(root->left, func);
	post_order_iterator(root->right, func);
	func(root->data);
}

void in_order_iterator(TreeNode* root, function<void(int)> func)
{
	if (!root)
		return;
	in_order_iterator(root->left, func);
	func(root->data);
	in_order_iterator(root->right, func);
}

int get_height(TreeNode* root)
{
	if (!root)
		return -1;
	auto lheight = get_height(root->left);
	auto rheight = get_height(root->right);
	return lheight > rheight ? lheight + 1 : rheight + 1;
}

} } // namespaces

#endif
