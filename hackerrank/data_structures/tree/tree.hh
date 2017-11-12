#ifndef _TREE_HH
#define _TREE_HH

#include <iostream>

using namespace std;

namespace jvanz {
namespace tree {

/// Binary tree data structure
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
			TreeNode* p;
			friend class const_iterator;
		public:
			iterator(TreeNode* n) : p(n) { };
			iterator(const iterator& poi) : p(poi.p) { };

			iterator& operator++()
			{ 
				cout << "operator++" << endl;
				if (this->p->left)
					this->p = p->left;
				else if (p->right)
					this->p = p->right;
				else
					this->p = nullptr;
				return *this; 
			};

			iterator operator++(int)
			{ 
				cout << "operator++(int)" << endl;
				iterator tmp(*this);
				operator++(); 
				return tmp;
			};
			bool operator==(const iterator& rhs) const
			{
				cout << "operator==" << endl;
				return this->p==rhs.p;
			};
			bool operator!=(const iterator& rhs) const
			{
				cout << "operator!=" << endl;
				return this->p!=rhs.p;
			};
			TreeNode& operator*()
			{ 
				cout << "operator*" << endl;
				return *(this->p); 
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
	iterator end() { return nullptr; };
	//const_iterator begin() { return const_iterator(this); };
	//const_iterator end() { return nullptr; };

}; // TreeNode class

} } // namespaces

#endif
