/*
Theo Rowlett
CS202 Winter 2021
Project 5
Tree.java: Red-black sorted BST of nodes. Contains code to add, sort, display, and search within the tree. Tree is sorted
    by the activity name.
 */
package com.company;

public class Tree extends Utility{
    private Node root;

    public Tree() {
        root = null;
    }

    private void leftRotate(Node x) {
        Node y = x.go_right();
        x.set_right(y.go_left());
        if (y.go_left() != null)
            y.go_left().set_parent(x);
        y.set_parent(x.go_parent());        //So we don't lose the tree above
        if (x.go_parent() == null)
            root = y;
        else if (x ==x.go_parent().go_left())
            x.go_parent().set_left(y);
        else
            x.go_parent().set_right(y);
        y.set_left(x);
        x.set_parent(y);
    }

    private void rightRotate(Node x) {
        if (x == null)
            return;
        Node y = x.go_left();
        x.set_left(y.go_right());
        if (y.go_right() != null)
            y.go_right().set_parent(x);
        y.set_parent(x.go_parent());
        if (x.go_parent() == null)
            root = y;
        else if (x == x.go_parent().go_right())
            x.go_parent().set_right(y);
        else
            x.go_parent().set_left(y);
        y.set_right(x);
        x.set_parent(y);
    }

    public void insert(Activity to_add) {
        int compare_val = 0;
        Node node = new Node(to_add);
        //Base case.
        if (root == null) {
            root = node;
            root.set_black();
            return;
        }
        compare_val = root.compare_name(to_add);

        if (compare_val <= 0) {
            insert(to_add,root.go_right(),root,1);
        }
        else
            insert(to_add,root.go_left(),root,0);
    }

    private void insert(Activity to_add, Node dest, Node par, int rorl) {
        int compare_val;
        if (dest==null)
        {
            dest = new Node(to_add);
            dest.set_parent(par);
            if (rorl == 1)
                par.set_right(dest);
            else
                par.set_left(dest);
            balance(dest);
            return;
        }
        compare_val = dest.compare_name(to_add);
        if (compare_val <=0) {
            insert(to_add,dest.go_right(),dest,1);
        }
        else
            insert(to_add,dest.go_left(),dest,0);
    }

    public void search(String to_search) {
        String selection;
        Node hold;
        if (root == null)
            return;
        hold = search(to_search,root);
        hold.display();
        System.out.println("Would you like to add a comment (y/n)?");
        selection = input.nextLine();
        if (selection.equalsIgnoreCase("y") || selection.equalsIgnoreCase("yes"))
            hold.add_comment();
        return;
    }

    private Node search(String to_search,Node curr) {
        int compare_val;
        compare_val = curr.compare_name(to_search);
        if (compare_val == 0)
            return curr;
        else if (compare_val <0) {
            return search(to_search,curr.go_right());
        }
        else
            return search(to_search,curr.go_left());
    }

    public void display() {
        if (root==null) {
            System.out.println("Nothing saved yet!");
            return;
        }

        display(root);
    }

    private void display(Node node) {
        if (node == null)
            return;
        display(node.go_left());
        node.display();
        System.out.println();
        display(node.go_right());
    }

    public void remove_all() {
        root = null;
    }

    protected void balance(Node child) {
        Node uncle;
        while (child.go_parent() != null && child.go_parent().is_red()) {
            if (child.go_parent().go_parent() != null && child.go_parent() == child.go_parent().go_parent().go_left()) {
                uncle = child.go_parent().go_parent().go_right();
                if (uncle != null && uncle.is_red()) {
                    child.go_parent().set_black();              //Parent is now black
                    uncle.set_black();                          //Uncle is now black
                    child.go_parent().go_parent().set_red();    //Grandpa is now red
                    child = child.go_parent().go_parent();      //Fry is now his own Grandpa.
                }
                else if (child==child.go_parent().go_right()) {
                    child = child.go_parent();
                    leftRotate(child);
                }
                if (child.go_parent() != null) {
                    child.go_parent().set_black();
                    child.go_parent().go_parent().set_red();
                    rightRotate(child.go_parent().go_parent());
                }
            }
            else if (child.go_parent().go_parent() != null) {
                uncle = child.go_parent().go_parent().go_left();
                if (uncle != null && uncle.is_red()) {
                    child.go_parent().set_black();              //Parent is now black
                    uncle.set_black();                          //Uncle is now black
                    child.go_parent().go_parent().set_red();    //Grandpa is now red
                    child = child.go_parent().go_parent();      //https://youtu.be/Ns7JIzrIB9c
                }
                else if (child==child.go_parent().go_left()) {
                    child = child.go_parent();
                    rightRotate(child);
                }
                if (child.go_parent() != null) {
                    child.go_parent().set_black();
                    child.go_parent().go_parent().set_red();
                    leftRotate(child.go_parent().go_parent());
                }
            }
        }
        root.set_black();
    }
}
