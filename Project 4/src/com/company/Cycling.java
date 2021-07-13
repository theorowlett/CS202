/*
Theo Rowlett
CS202 Project 4
Winter 2021
Cycling.java: Contains methods to create and display cycling objects.
 */
package com.company;

public class Cycling extends Exercise{
    private int miles;
    private String type;

    public Cycling(){
        miles = 0;
        type = null;
    }

    public void build()
    {
        setActivity();
        setExercise();
        setCycling();
    }
    private void setCycling() {
        System.out.print("Enter the number of miles cycled: ");
        miles = input.nextInt();
        input.nextLine();
        System.out.print("Enter the type of cycling (ex. gravel/road): ");
        type = input.nextLine();
        //input.nextLine();
    }

    public void display() {
        display_activity();
        display_exercise();
        System.out.print("Type: ");
        System.out.println(type);
        System.out.print("Miles rode: ");
        System.out.println(miles);
    }
}
