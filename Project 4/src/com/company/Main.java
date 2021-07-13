/*
Theo Rowlett
CS202 Project 4
Winter 2021
Main.java: Contains UI and initializes array of Activity Lists.
 */
package com.company;
import java.util.Scanner;

public class Main{
    public static int selection;
    protected static Scanner input = new Scanner(System.in).useDelimiter("\n");


    public static void main(String[] args) {
        Tree tree;
        tree = new Tree();
        String search;
        System.out.println("Welcome to Program 5 for CS202!");
        do {
            selection = Menu();

            switch (selection) {
                case 1:
                    selection = Select_Activity();
                    if (selection!=0){
                        switch (selection) {
                            case 1 -> {
                                Activity hike = new Hiking();
                                hike.build();
                                //hike.display();
                                tree.insert(hike);
                            }
                            case 2 -> {
                                Activity cycle = new Cycling();
                                cycle.build();
                                cycle.display();
                                tree.insert(cycle);
                            }
                            case 3 -> {
                                Activity run = new Running();
                                run.build();
                                run.display();
                                tree.insert(run);
                            }
                            case 4 -> {
                                Activity landscape = new Landscape();
                                landscape.build();
                                landscape.display();
                                tree.insert(landscape);
                            }
                            case 5 ->  {
                                Activity lifestyle = new Lifestyle();
                                lifestyle.build();
                                lifestyle.display();
                                tree.insert(lifestyle);
                            }
                            case 6 -> {
                                Activity event = new Event();
                                event.build();
                                event.display();
                                tree.insert(event);
                            }
                            default -> System.out.println("Invalid selection");
                        }
                    }
                    else
                        selection = 1;
                    break;
                case 2:
                    tree.display();
                    break;
                case 3:
                    input.nextLine();
                    System.out.print("Activity you would like to search for: ");
                    search = input.nextLine();
                    if (search != null)
                        tree.search(search);
                    break;
                case 4:
                    tree.remove_all();
                    break;
                case 0:
                    break;
                default:
                    System.out.println("Invalid selection.");
                    break;
            }
        } while (selection != 0);

        System.out.println("Goodbye!");
    }

    public static int Menu()
    {
        System.out.println("Make a selection from the menu.");
        System.out.println("1. Add an activity.");
        System.out.println("2. Display all activities");
        System.out.println("3. Search for/add comment to activity");
        System.out.println("4. Remove everything");
        System.out.println("0. Exit the application.");
        return input.nextInt();
    }
    public static int Select_Activity() {
        System.out.println("Select an activity from the menu.");
        System.out.println("1. Hiking");
        System.out.println("2. Cycling");
        System.out.println("3. Running");
        System.out.println("4. Landscape photography");
        System.out.println("5. Lifestyle photography");
        System.out.println("6. Event photography");
        System.out.println("0. Cancel adding an activity.");
        return input.nextInt();
    }


}
