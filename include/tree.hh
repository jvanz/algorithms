#ifndef _TREE_HH
#define _TREE_HH

#include <functional>
#include <stack>

using namespace std;

namespace jvanz {
namespace tree {

// declarations
template<typename T>
class PreOrderIterator;

/// Binary tree data structure
template<typename T, typename IT = PreOrderIterator<T>>
class TreeNode
{
private:
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode<T>* parent;

public:
	T data;

	TreeNode(T val): data{val}, left{nullptr}, right{nullptr}, parent{nullptr} {};
	// destructor
	~TreeNode()
	{
		if (this->left)
			delete this->left;
		if (this->right)
			delete this->right;
	}

	void set_left(TreeNode<T>* _left)
	{
		this->left = _left;
		_left->parent = this;
	}

	void set_right(TreeNode<T>* _right)
	{
		this->right = _right;
		_right->parent = this;
	}

	TreeNode<T>* get_left()
	{
	       return this->left;
	}

	TreeNode<T>* get_right()
	{
		return this->right;
	}

	IT begin(){
		return IT(this);
	}
	IT end(){
		return IT(nullptr);
	}

	friend IT;
	template<typename I>
	friend void pre_order_iterator(TreeNode<I>* root, function<void(I)> func);
	template<typename I>
	friend void post_order_iterator(TreeNode<I>* root, function<void(I)> func);
	template<typename I>
	friend void in_order_iterator(TreeNode<I>* root, function<void(I)> func);
	template<typename I>
	friend TreeNode<I>* insert(TreeNode<I>* root, I value);
	template<typename I>
	friend int get_height(TreeNode<I>* root);


}; // TreeNode class

/**
 * Iterator class to traverse a binary tree using the pre order algorithm
 */
template<typename T>
class PreOrderIterator
{
	private:
		TreeNode<T>* current;
		TreeNode<T>* last_left;
		TreeNode<T>* last_right;

	void get_next_node(TreeNode<T>* root)
	{
		if (this->current->left && this->last_left != this->current->left) {
			this->current = this->current->left;
		} else if (this->current->right && this->last_right != this->current->right) {
			this->current = this->current->right;
		} else {
			if (this->current->parent == nullptr) {
				this->current = nullptr;
				return;
			}
			if (this->current->parent->left == this->current) {
				this->last_left = this->current;
			} else if (this->current->parent->right == this->current) {
				this->last_right = this->current;
				// pre order. If I'm in the right branch, the
				// left is done.
				this->last_left = this->current->parent->left;
			}
			this->current = this->current->parent;
			this->get_next_node(this->current);
		}
	}

	public:
	PreOrderIterator(TreeNode<T>* _curr): current{_curr}, last_left{nullptr}, last_right{nullptr} {};
	PreOrderIterator(const PreOrderIterator<T>& it): current{it.current}, last_left{it.last_left}, last_right{it.last_right} {};

	PreOrderIterator<T>& operator++()
	{
		this->get_next_node(this->current);
		return *this;
	};

	PreOrderIterator<T>& operator++(int)
	{
		this->operator++();
		return *this;
	};

	bool operator==(const PreOrderIterator<T>& rhs)
	{
		return this->current == rhs.current;
	};

	bool operator!=(const PreOrderIterator<T>& rhs)
	{
		return !this->operator==(rhs);
	};

	TreeNode<T>& operator*()
	{
		return *this->current;
	};

};

template<typename T>
void pre_order_iterator(TreeNode<T>* root, function<void(T)> func)
{
	if (!root)
		return;
	func(root->data);
	pre_order_iterator<T>(root->left, func);
	pre_order_iterator<T>(root->right, func);
}

template<typename T>
void post_order_iterator(TreeNode<T>* root, function<void(T)> func)
{
	if (!root)
		return;
	post_order_iterator<T>(root->left, func);
	post_order_iterator<T>(root->right, func);
	func(root->data);
}

template<typename T>
void in_order_iterator(TreeNode<T>* root, function<void(T)> func)
{
	if (!root)
		return;
	in_order_iterator<T>(root->left, func);
	func(root->data);
	in_order_iterator<T>(root->right, func);
}

template<typename T>
int get_height(TreeNode<T>* root)
{
	if (!root)
		return -1;
	auto lheight = get_height<T>(root->left);
	auto rheight = get_height<T>(root->right);
	return lheight > rheight ? lheight + 1 : rheight + 1;
}

template<typename T>
TreeNode<T>* insert(TreeNode<T>* root, T value)
{
	if (!root)
		return new TreeNode<T>(value);
	if (root->data > value)
		root->left = insert<T>(root->left, value);
	else
		root->right = insert<T>(root->right, value);
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

} } // namespaces

#endif
