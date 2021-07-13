package com.company;

public class Lifestyle extends Photography{
    private String subject;
    private boolean paid;

    public Lifestyle() {
        subject = null;
        paid = false;
    }

    public void build() {
        setActivity();
        setPhotography();
        setLifestyle();
    }

    private void setLifestyle() {
        String selection;
        System.out.print("Subject for this shoot: ");
        subject = input.nextLine();
        System.out.print("Payment received (y/n): ");
        selection = input.nextLine();
        if (selection.equalsIgnoreCase("y") || selection.equalsIgnoreCase("yes"))
            paid = true;
    }

    public void display() {
        display_activity();
        display_photography();
        System.out.print("Subject: ");
        System.out.println(subject);
        System.out.print("Payment status: ");
        if (paid)
            System.out.println("Paid");
        else
            System.out.println("Unpaid");
    }
}
