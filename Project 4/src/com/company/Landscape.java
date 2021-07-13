/*
Theo Rowlett
CS202 Project 4
Winter 2021
Landscape.java: Contains methods to create and display Landscape objects.
 */
package com.company;

public class Landscape extends Photography{
    private String location;
    Landscape() {
        location = null;
    }

    public void build() {
        setActivity();
        setPhotography();
        setLandscape();
    }

    private void setLandscape() {
        System.out.print("Location for this shoot: ");
        location = input.nextLine();
    }

    public void display() {
        display_activity();
        display_photography();
        System.out.print("Location: ");
        System.out.println(location);
        System.out.println();
    }

}
