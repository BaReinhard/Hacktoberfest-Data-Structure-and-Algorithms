package algorithms.closest.java;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/*
This algorithm searches through a list of integers and finds the distance between
the two closest element. It then prints this integer.
 */
public class Closest {
    public static void main(String[] args) {
        //get input
        Scanner sc = new Scanner(System.in).useDelimiter(" ");
        ArrayList<Integer> input = new ArrayList<>();
        //add input to ArrayList
        while (sc.hasNextInt()) {
            input.add(sc.nextInt());
        }
        //sort the list
        Collections.sort(input);
        //initialize closest values, with the first two elements in the list
        int closest = input.get(1)-input.get(0);
        //check all elements in the list
        for(int i = 2; i < input.size(); i++) {
            //change closest if we find two elements with a shorter distance.
            closest = Math.min(closest, input.get(i)-input.get(i-1));
        }
        //print the shortest distance
        System.out.println(closest);
    }
}
