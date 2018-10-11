int main (int argc, const char * argv[])
{  
    int i, j, n = 150, P[151] = { 0, 1 }, prime = 1;  
      
    for ( i = 2; i <= n; ++i ) {  
        P[i] = prime;  
        for ( j = 2; j < i ; ++j ) {  
            if ( i % j == 0 )  
                P[i] = 0;  
        }  
    }  
    printf("Print prime numbers results:\n\n");  
    for (i = 2; i <= n ; ++i) {  
        if ( P[i] != 0 )   
            printf("%i\n", i);  
    }  
      
    printf(" \n");  
    printf("Print prime numbers original program #results:\n\n");  
    //Original program referenced. 
    int p, d, isPrime;  
    for ( p = 2; p <= 150; ++p ) {   
        isPrime = 1;  
        for ( d = 2; d < p; ++d )   
            if ( p % d == 0 )  
                isPrime = 0;  
        if ( isPrime != 0 )   
            NSLog (@"%i ", p);  
    }  
    return 0;  
}  