//Theo Rowlett
//tree.h
//CS202 Project 3
//tree.h: header file for BST tree

#ifndef TREE
#define TREE

#include "string.h"
#include "contact.h"

class Tree
{
	public:
		Tree();
		//Tree(const Tree & to_copy);
		~Tree();

		bool insert(Contact & to_insert);
		bool insert(Contact *& curr, Contact & to_insert);

		void delete_tree(Contact *& curr);
		void search(String * a_name);
		void remove(String * a_name);
		void display();
		void display(Contact * curr);
	private:
		Contact * root;
		
		Contact * retrieve(String * a_name);
		Contact * retrieve(Contact *& curr, String * a_name);
		Contact * inorder(Contact * curr);
		void fix_parent(Contact * to_be_removed);
		bool fix_parent(Contact * curr, Contact * to_be_removed);
};

#endif
