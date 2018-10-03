<?php
// php program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
function SieveOfEratosthenes($n)
{
    // Create a boolean array "prime[0..n]"
    // and initialize all entries it as true.
    // A value in prime[i] will finally be
    // false if i is Not a prime, else true.
    $prime = array_fill(0, $n+1, true);

    for ($p = 2; $p*$p <= $n; $p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if ($prime[$p] == true)
        {

            // Update all multiples of p
            for ($i = $p*2; $i <= $n; $i += $p)
                $prime[$i] = false;
        }
    }

    // Print all prime numbers
    for ($p = 2; $p <= $n; $p++)
        if ($prime[$p])
            echo $p." ";
}

  // Driver Program to test above function
  $n = 30;
  echo "Following are the prime numbers smaller than or equal to " .$n."\n" ;
  SieveOfEratosthenes($n);
?>
