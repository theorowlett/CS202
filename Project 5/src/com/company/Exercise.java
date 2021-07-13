/*
Theo Rowlett
CS202 Project 4
Winter 2021
Exercise.java: abstract class, inherits from Activity. Has 3 subclasses: Hiking, Cycling, Running.
 */
package com.company;

abstract class Exercise extends Activity {
    protected String weather;
    protected int temperature;
    protected int difficulty;

    public Exercise() {
        weather = null;
        temperature = 0;
        difficulty = 0;
    }
    protected void setExercise() {

        setTemperature();
        setWeather();
        setDifficulty();
    }
    private void setWeather(){
        System.out.print("Enter the weather conditions (ex. Rainy): ");
        weather = input.nextLine();
    }

    private void setTemperature(){
        System.out.print("Enter the temperature during the event: ");
        temperature = input.nextInt();
        input.nextLine();

    }
    private void setDifficulty(){
        System.out.print("Enter the Difficulty of exercise on a scale of 1-10: ");
        difficulty = input.nextInt();
        input.nextLine();
    }

    protected void display_exercise() {
        if (weather != null) {
            System.out.print("Weather: ");
            System.out.println(weather);
        }
        System.out.print("Temperature (F): ");
        System.out.println(temperature);
        System.out.print("Difficulty Rating (1-10): ");
        System.out.println(difficulty);
    }
}
