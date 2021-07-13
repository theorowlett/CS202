/*
Theo Rowlett
CS202 Winter 2021
Project 5
Comment.java: Comment class, Each node in Tree contains a LLL of comments.
 */
package com.company;

public class Comment extends Utility{
    private String name;
    private String comment;
    private Comment next;

    public Comment() {
        name = null;
        comment = null;
        next = null;
    }

    public Comment getNext() {
        return next;
    }

    public void setNext(Comment is_next) {
            next = is_next;
    }

    public void add_comment() {
        System.out.print("Name: ");
        name = input.nextLine();
        System.out.print("Enter comment: ");
        comment = input.nextLine();
    }

    public void display() {
        System.out.print("Name: ");
        System.out.println(name);
        System.out.println(comment);
    }
}
