/*
Theo Rowlett
CS202 Project 4
Winter 2021
Running.java: Contains methods to create and display Running objects.
 */
package com.company;

public class Running extends Exercise{
    private int miles;
    private boolean treadmill;

    public Running() {
        miles = 0;
        treadmill = false;
    }

    public void build() {
        setActivity();
        setExercise();
        setRunning();
    }

    public void display() {
        display_activity();
        display_exercise();
        System.out.print("Number of miles ran: ");
        System.out.println(miles);
        if (treadmill = true)
            System.out.println("Ran on treadmill.");
        else
            System.out.println("Not ran on treadmill.");
    }

    private void setRunning() {
        String readin;
        System.out.print("Enter the distance, in whole miles, ran: ");
        miles = input.nextInt();
        input.nextLine();
        System.out.print("Was this on a treadmill(y/n)? ");
        readin = input.nextLine();
        if (readin.equalsIgnoreCase("y") || readin.equalsIgnoreCase("yes"))
            treadmill = true;
    }
}
