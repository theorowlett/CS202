/*
Theo Rowlett
CS202 Project 4
Winter 2021
Hiking.java: Contains methods to create and display Hiking objects.
 */
package com.company;

public class Hiking extends Exercise{
    protected String location;

    public Hiking(){
        location = null;
    }

    public void build() {
        setActivity();
        setExercise();
        location = setLocation();
    }

    private String setLocation() {
        System.out.print("Enter the location: ");
        location = input.nextLine();
        return location;
    }

    public void display() {
        display_activity();
        display_exercise();

        if (location != null) {
            System.out.print("Location: ");
            System.out.println(location);
        }
    }
}
