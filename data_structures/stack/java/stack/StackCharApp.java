/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Dilshan
 */
public class StackCharApp {
    
    public static void main(String ar[]){
        
        StackCharX char1 = new StackCharX(5);
        char1.push('A');
        char1.push('B');
        char1.push('C');
        char1.push('D');
        
        while(!char1.isEmpty()){
            char x = char1.pop();
            System.out.println(x);
            System.out.println();
        }
        
    }
}
