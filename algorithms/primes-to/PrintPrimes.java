/**
* A simple program that prints prime numbers up to an input n.
* @author makeroflight
*/

import java.util.Scanner;

public class PrintPrimes {

  /**
  * isPrime
  *
  * Checks first if the input is not even or of the form 6n+1 or 6n-1.
  * If it fails either case the number is not prime, so the function
  * returns false immediately.
  *
  * Otherwise it checks every odd number from 3 up to the square root of
  * the input for divisibility.
  *
  * @param n is the input
  * @return prime is true if prime, and false if not prime.
  */

  public static boolean isPrime(long n) {

    boolean prime = true;

    if(n > 3 && n % 2 == 0)
      prime = false;
    if(n > 3 && ((n + 3) % 6 == 0 || (n - 3) % 6 == 0))
      prime = false;

    for(long i = 3; i <= Math.sqrt(n) && prime; i += 2) {
      if ( n % i == 0)
        prime = false;
      }
    return prime;
  }

  public static void main(String[] args) {
    long n;

    Scanner input = new Scanner(System.in);
    System.out.println("Enter an integer for the program to find primes " +
                "up to: ");
    n = input.nextLong();
    for (int i = 1; i < n; ++i) {
      if (isPrime(i))
        System.out.print(i + ", ");
    }
    System.out.print("\n");
  }
}
