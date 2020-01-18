#pragma once

#include <functional>

using namespace std;

namespace jvanz {
namespace tree {

// declarations
template <typename T>
class PreOrderIterator;

/// Binary tree data structure
template <typename T>
class TreeNode {
       private:
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode<T>* parent;
	T data;

       public:
	TreeNode() : left{nullptr}, right{nullptr}, parent{nullptr} {};

	explicit TreeNode(const T& val)
	    : left{nullptr}, right{nullptr}, parent{nullptr}, data{val} {};

	TreeNode(const TreeNode<T>& other)
	    : left{other.left},
	      right{other.right},
	      parent{other.parent},
	      data{other.data} {};  // copy constructor

	TreeNode(TreeNode<T>&& other)
	    : left{move(other.left)},
	      right{move(other.right)},
	      parent{move(other.parent)},
	      data{move(other.data)} {}  // move constructor

	TreeNode<T>& operator=(const TreeNode<T>& other) {
		this->left = other.left;
		this->right = other.right;
		this->parent = other.parent;
		this->data = other.data;
		return *this;
	}  // copy assignment

	TreeNode<T>& operator=(const TreeNode<T>&& other) {
		this->left = move(other.left);
		this->right = move(other.right);
		this->parent = move(other.parent);
		this->data = move(other.data);
		return *this;

	}  // move assignment

	// destructor
	~TreeNode() {
		if (this->left)
			delete this->left;
		this->left = nullptr;
		if (this->right)
			delete this->right;
		this->right = nullptr;
		this->parent = nullptr;
	}

	void set_left(TreeNode<T>* _left) {
		this->left = _left;
		_left->parent = this;
	}

	void set_right(TreeNode<T>* _right) {
		this->right = _right;
		_right->parent = this;
	}

	TreeNode<T>* get_left() const { return this->left; }
	TreeNode<T>* get_right() const { return this->right; }
	T get() const { return this->data; }
	void set(T&& _data) { this->data = move(_data); }

	PreOrderIterator<T> begin() { return PreOrderIterator<T>(this); }
	PreOrderIterator<T> end() { return PreOrderIterator<T>(nullptr); }

	friend class PreOrderIterator<T>;
	template <typename I>
	friend void pre_order_iterator(TreeNode<I>* root,
				       function<void(I)> func);
	template <typename I>
	friend void post_order_iterator(TreeNode<I>* root,
					function<void(I)> func);
	template <typename I>
	friend void in_order_iterator(TreeNode<I>* root,
				      function<void(I)> func);
	template <typename I>
	friend TreeNode<I>* insert(TreeNode<I>* root, I value);
	template <typename I>
	friend int get_height(TreeNode<I>* root);
	template <typename I>
	friend void insert(
	    TreeNode<I>* root,
	    TreeNode<I>* children,
	    function<int(TreeNode<I>* root, TreeNode<I>* child)> compare);

};  // namespace tree

/**
 * Iterator class to traverse a binary tree using the pre order algorithm
 */
template <typename T>
class PreOrderIterator {
       private:
	TreeNode<T>* current;
	TreeNode<T>* last_left;
	TreeNode<T>* last_right;

	void get_next_node() {
		if (this->current->left &&
		    this->last_left != this->current->left) {
			this->current = this->current->left;
		} else if (this->current->right &&
			   this->last_right != this->current->right) {
			this->current = this->current->right;
		} else {
			if (this->current->parent == nullptr) {
				this->current = nullptr;
				return;
			}
			if (this->current->parent->left == this->current) {
				this->last_left = this->current;
			} else if (this->current->parent->right ==
				   this->current) {
				this->last_right = this->current;
				// pre order. If I'm in the right branch, the
				// left is done.
				this->last_left = this->current->parent->left;
			}
			this->current = this->current->parent;
			this->get_next_node();
		}
	}

       public:
	PreOrderIterator(TreeNode<T>* _curr)
	    : current{_curr}, last_left{nullptr}, last_right{nullptr} {};
	PreOrderIterator(const PreOrderIterator<T>& it)
	    : current{it.current},
	      last_left{it.last_left},
	      last_right{it.last_right} {};

	PreOrderIterator& operator++() {
		this->get_next_node();
		return *this;
	};

	PreOrderIterator& operator++(int) {
		this->operator++();
		return *this;
	};

	bool operator==(const PreOrderIterator& rhs) {
		return this->current == rhs.current;
	};

	bool operator!=(const PreOrderIterator& rhs) {
		return !this->operator==(rhs);
	};

	TreeNode<T>& operator*() { return *this->current; };
};

template <typename T>
void pre_order_iterator(TreeNode<T>* root, function<void(T)> func) {
	if (!root)
		return;
	func(root->get());
	pre_order_iterator<T>(root->left, func);
	pre_order_iterator<T>(root->right, func);
}

template <typename T>
void post_order_iterator(TreeNode<T>* root, function<void(T)> func) {
	if (!root)
		return;
	post_order_iterator<T>(root->left, func);
	post_order_iterator<T>(root->right, func);
	func(root->get());
}

template <typename T>
void in_order_iterator(TreeNode<T>* root, function<void(T)> func) {
	if (!root)
		return;
	in_order_iterator<T>(root->left, func);
	func(root->get());
	in_order_iterator<T>(root->right, func);
}

template <typename T>
int get_height(TreeNode<T>* root) {
	if (!root)
		return -1;
	auto lheight = get_height<T>(root->left);
	auto rheight = get_height<T>(root->right);
	return lheight > rheight ? lheight + 1 : rheight + 1;
}

template <typename T>
TreeNode<T>* insert(TreeNode<T>* root, T value) {
	if (!root)
		return new TreeNode<T>(value);
	if (root->get() > value)
		root->left = insert<T>(root->left, value);
	else
		root->right = insert<T>(root->right, value);
	return root;
}

template <typename T>
class HuffmanNode {
	T data;
	HuffmanNode<T>* left;
	HuffmanNode<T>* right;

       public:
	HuffmanNode(T _data,
		    HuffmanNode<T>* _left = nullptr,
		    HuffmanNode<T>* _right = nullptr)
	    : data{_data}, left{_left}, right{_right} {};
	template <typename P, P internalval>
	friend std::string decode_huffman(const HuffmanNode<P>* root,
					  const std::string& s);
};

template <typename T, T internalval>
std::string decode_huffman(const HuffmanNode<T>* root, const std::string& s) {
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
		if (node->data != internalval) {
			result += node->data;
			node = root;
		}
	}
	return result;
}
template <typename I>
void insert(TreeNode<I>* root,
	    TreeNode<I>* children,
	    function<int(TreeNode<I>* root, TreeNode<I>* child)> compare) {
	if (root == nullptr || children == nullptr)
		return;

	auto position = compare(root, children);
	if (position < 0) {
		if (root->get_left() == nullptr)
			root->set_left(children);
		else
			insert(root->get_left(), children, compare);
		return;
	}

	if (root->get_right() == nullptr) {
		root->set_right(children);
		return;
	}
	insert(root->get_right(), children, compare);
}

template <typename T>
void vertical_traversal(TreeNode<T>* root,
			function<void(TreeNode<T>*, int)> func,
			int distance = 0) {
	if (!root)
		return;

	func(root, distance);
	vertical_traversal<T>(root->get_left(), func, distance - 1);
	vertical_traversal<T>(root->get_right(), func, distance + 1);
}

}  // namespace tree
}  // namespace jvanz
