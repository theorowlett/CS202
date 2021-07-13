/*
Theo Rowlett
CS202 Project 4
Winter 2021
Photography.java: Abstract class, inherits from Activity. 3 sub classes: Landscape, Portrait, and Event.
 */
package com.company;

abstract class Photography extends Activity {
    protected String camera;
    protected boolean digital;
    protected int number_of_photos;

    public Photography() {
        camera = null;
        digital=false;
        number_of_photos=0;
    }

    protected void setPhotography(){
        String selection;
        System.out.print("What camera was used? ");
        camera = input.nextLine();
        System.out.print("How many photos were taken? ");
        number_of_photos = input.nextInt();
        input.nextLine();
        System.out.print("Is this camera digital (y/n)?" );
        selection = input.nextLine();
        if (selection.equalsIgnoreCase("y")  || selection.equalsIgnoreCase("yes"))
            digital = true;
    }

    protected void display_photography() {
        System.out.print("Camera model: ");
        System.out.println(camera);
        System.out.print("Camera type: ");
        if (digital)
            System.out.println("Digital");
        else
            System.out.println("Film");
        System.out.print("Number of photos taken: ");
        System.out.println(number_of_photos);
    }
}
