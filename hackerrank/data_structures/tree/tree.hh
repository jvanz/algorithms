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

TreeNode* insert(TreeNode* root, int value)
{
	if (!root)
		return new TreeNode(value);
	if (root->data > value)
		root->left = insert(root->left, value);
	else
		root->right = insert(root->right, value);
	return root;
}

template<typename T>
class HuffmanNode
{
	T data;
	HuffmanNode<T>* left;
	HuffmanNode<T>* right;
	public:
	HuffmanNode(T _data, HuffmanNode<T>* _left=nullptr, HuffmanNode<T>* _right=nullptr):
		data{_data}, left{_left}, right{_right} { };
	template<typename P, P internalval>
	friend std::string decode_huffman( const HuffmanNode<P>* root, const std::string& s);
};

template<typename T, T internalval>
std::string decode_huffman( const HuffmanNode<T>* root, const std::string& s)
{
	std::string result = "";
	auto node = root;
	for (auto c : s) {
		if (c == '0')
			node = node->left;
		else if (c == '1')
			node = node->right;
		else
			throw "Invalid value";
		// leaf node? If so, get the char and restart the process
		if (node->data != internalval){
			result += node->data;
			node = root;
		}
	}
	return result;
}

/// Swap node in the given tree
void swap_node(TreeNode& root)
{
	// TODO
}

} } // namespaces

#endif
