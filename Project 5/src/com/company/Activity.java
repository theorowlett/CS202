/*
Theo Rowlett
CS202 Project 4
Winter 2021
Activity.java: Abstract base class for all activity classes. Has 2 sub classes: Exercise and Photography.
 */
package com.company;

import org.w3c.dom.ls.LSInput;

import java.sql.SQLOutput;

abstract class Activity extends Utility{
    protected String name;
    protected int start_time;
    protected int end_time;

    public Activity() {
        name = null;
        start_time = 0;
        end_time = 0;
    }

    public int compare_string(String to_compare) {
        return name.compareTo(to_compare);
    }

    public int compare_name(Activity to_compare) {
        return name.compareTo(to_compare.name);
    }

    protected void setActivity() {
        System.out.print("What is the name of this activity: ");
        name= input.nextLine();
        setStart_time();
        setEnd_time();
        input.nextLine();
    }
    abstract void display();
    abstract void build();

    private void setStart_time() {
        System.out.print("Enter the start time (in HHMM format): ");
        start_time = input.nextInt();
    }

    private void setEnd_time() {
        System.out.print("Enter the end time (in HHMM format): ");
        end_time=input.nextInt();

    }
    protected void display_activity() {
        if (name!=null)
        {
            System.out.print("Activity name: ");
            System.out.println(name);
        }
        if (start_time!=0)
        {
            System.out.print("Begins: ");
            System.out.print(start_time);
        }
        if (end_time!=0)
        {
            System.out.print(" Ends: ");
            System.out.println(end_time);
        }
    }
}
