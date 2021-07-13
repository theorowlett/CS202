/*
Theo Rowlett
Winter 2021
CS202 Project 5
Node.java: Node for tree. Each node contains a parent, left, and right node for the tree as well as color data for
    sorting in the tree, an Activity object, and a linear linked list of comments for the node/activity.
 */

package com.company;

public class Node extends Utility{
    private Activity activity;
    private Node parent;
    private Node left;
    private Node right;
    private int color;
    private Comment head;

    public Node() {
        activity = null;
        parent = null;
        left = null;
        right = null;
        color = 0;      //1. Red, 0. Black
        head = null;
    }

    public Node(Activity to_add) {
        activity = to_add;
        parent = null;
        left = null;
        right = null;
        color = 1;
        head = null;
    }

    public Node go_left() {
        return left;
    }

    public Node go_right() {
        return right;
    }

    public Node go_parent() {
        return parent;
    }

    public boolean is_red() {
        if (color == 1)
            return true;
        return false;
    }

    public void set_black() {
        color = 0;
    }

    public void set_red() {
        color = 1;
    }

    public void set_left(Node to_left) {
        left = to_left;
    }

    public void set_right(Node to_right) {
        right = to_right;
    }

    public void set_parent(Node to_parent) {
        parent = to_parent;
    }

    public int compare_name(Activity to_compare) {
        return activity.compare_name(to_compare);
    }

    public int compare_name(String to_compare) {
        return activity.compare_string(to_compare);
    }

    public void display() {
        activity.display();
        if (head != null) {
            System.out.println("--------Comments--------");
            display_comment(head);
        }
        System.out.println();
    }

    public void add_comment() {
        if (head == null) {
            head = new Comment();
            head.add_comment();
        }
        else head.setNext(add_comment(head.getNext()));
    }

    private Comment add_comment(Comment curr) {
        if (curr != null) {
            curr.setNext(add_comment(curr.getNext()));
        }
        else {
            curr = new Comment();
            curr.add_comment();
        }
        return curr;
    }

    private void display_comment(Comment curr) {
        if (curr == null)
            return;
        curr.display();
        display_comment(curr.getNext());
    }
}
