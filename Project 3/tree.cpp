/* Theo Rowlett
 * CS202 Winter 21
 * Project 3
 * tree.cpp: code for BST.
 */

#include "tree.h"

using namespace std;


//TREE
Tree::Tree():root(nullptr)
{
}

Tree::~Tree()
{
	if (root)
		delete_tree(root);
}

void Tree::delete_tree(Contact *& curr)
{
	if (curr->go_left())
		delete_tree(curr->go_left());
	if (curr->go_right())
		delete_tree(curr->go_right());
	delete curr;
	curr = nullptr;
}

void Tree::search(String * a_name)
{
	Contact * result = new Contact(*retrieve(a_name));
	result->display();
	delete result;
	result = nullptr;
}

void Tree::remove(String * a_name)
{
	Contact * result = new Contact();
	Contact * hold = new Contact();
	result = retrieve(a_name);
	if (!result->go_left() && !result->go_right())		//Node to be removed is leaf
	{
		if (result == root)
		{
			delete root;
			root = nullptr;
			//delete result;
			//result = nullptr;
		}
		else
		{
			fix_parent(result);
			delete result;
			result = nullptr;
		}
	}
	else if(result->go_left() && !result->go_left())		//Node to be deleted has only left child
	{
		hold = result->go_left();
		*result = *hold;
		result->go_left() = hold->go_left();
		result->go_right() = hold->go_right();
	}
	else
	{
		hold = inorder(result->go_right());
		*result = *hold;
		result->go_left() = hold->go_left();
		result->go_right() = hold->go_right();
	}
	
	delete hold;
	hold = nullptr;
}

bool Tree::insert(Contact & to_insert)
{
	return insert(root,to_insert);
}

bool Tree::insert(Contact *& curr, Contact & to_insert)
{
	if (curr == nullptr)
	{
		curr = new Contact(to_insert);
		return true;
	}
	if (to_insert < *curr)
		return insert(curr->go_left(),to_insert);

	return insert(curr->go_right(),to_insert);
}

void Tree::display()
{
	if (root)
		display(root);
}

void Tree::display(Contact * curr)
{
	if (curr->go_left() == nullptr)
	{
		curr->display();
		if (curr->go_right() != nullptr)
			display(curr->go_right());
	}
	else
	{
		display(curr->go_left());
		curr->display();
		if (curr->go_right() != nullptr)
			display(curr->go_right());
	}
}

Contact * Tree::retrieve(String * a_name)
{
	if (root)
		return retrieve(root,a_name);
	return nullptr;
}

Contact * Tree::retrieve(Contact *& curr, String * a_name)
{
	if (curr)
	{
		if (*curr->return_name() == *a_name)
			return curr;
		if (*curr->return_name() > *a_name)
		{
			if (curr->go_left())
				return retrieve(curr->go_left(),a_name);
		}
		if (*curr->return_name() < *a_name)
		{
			if(curr->go_right())
				return retrieve(curr->go_right(),a_name);
		}
	}
	return nullptr;
}

Contact * Tree::inorder(Contact * curr)
{
	if (curr)
	{
		if (curr->go_left())
			return inorder(curr->go_left());
		else
		{
			Contact * successor = new Contact();
			*successor = *curr;
			if (curr->go_right())
			{
				Contact * hold = new Contact(*curr->go_right());
				hold->go_left() = curr->go_right()->go_left();
				hold->go_right() = curr->go_right()->go_right();
				delete curr;
				curr = nullptr;
				curr = hold;
			}
			else 
			{
				delete curr;
				curr = nullptr;
			}
			return successor;
		}
	}
	return nullptr;
}
void Tree::fix_parent(Contact * to_be_removed)
{
	if (root)
		fix_parent(root,to_be_removed);
}

bool Tree::fix_parent(Contact * curr, Contact * to_be_removed)
{
	if (curr->go_left() == to_be_removed)
	{
		curr->go_left() = nullptr;
		return true;
	}
	if (curr->go_right() == to_be_removed)
	{
		curr->go_right() = nullptr;
		return true;
	}
	if (*curr > *to_be_removed)
		return fix_parent(curr->go_left(),to_be_removed);
	else if (*curr < *to_be_removed)
		return fix_parent(curr->go_right(),to_be_removed);
	return false;
}

