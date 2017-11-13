#ifndef _TREE_HH
#define _TREE_HH

#include <iostream>
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

	//class const_iterator : public std::iterator<std::forward_iterator_tag, TreeNode>
	//{
		//private:
			//TreeNode* p;
		//public:
			//iterator(TreeNode* n) : p(n) { };
			//iterator(const iterator& poi) : p(poi.p) { };

			//iterator& operator++()
			//{ 
				//if (this->p->left)
					//this->p = p->left;
				//else if (p->right)
					//this->p = p->right;
				//return *this; 
			//};

			//iterator operator++(int)
			//{ 
				//iterator tmp(*this);
				//operator++(); 
				//return tmp;
			//};
			//bool operator==(const iterator& rhs) const
			//{
				//return this->p==rhs.p;
			//};
			//bool operator!=(const iterator& rhs) const
			//{
				//return this->p!=rhs.p;
			//};
			//TreeNode& operator*()
			//{ 
				//return *(this->p); 
			//};
	//};

	// TreeNode methods
	iterator begin() { return iterator(this); };
	iterator end() { return iterator(nullptr); };

}; // TreeNode class

} } // namespaces

#endif
