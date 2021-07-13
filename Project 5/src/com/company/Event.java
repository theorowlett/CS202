/*
Theo Rowlett
CS202 Project 4
Winter 2021
Event.java: Contains methods to create and display Event objects.
 */
package com.company;

public class Event extends Photography{
    private String location;
    private boolean paid;

    Event() {
        location = null;
        paid = false;
    }

    public void build(){
        setActivity();
        setPhotography();
        setEvent();
    }

    private void setEvent(){
        String selection;
        System.out.print("Location for this shoot: ");
        location = input.nextLine();
        System.out.print("Payment received (y/n): ");
        selection = input.nextLine();
        if (selection.equalsIgnoreCase("y") || selection.equalsIgnoreCase("yes"))
            paid = true;
    }

    public void display() {
        display_activity();
        display_photography();
        System.out.print("Location: ");
        System.out.println(location);
        System.out.print("Payment status: ");
        if (paid)
            System.out.println("Paid");
        else
            System.out.println("Unpaid");
    }

}
