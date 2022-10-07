/*
 *  Simple Caesar cypher algorithm with a little extra to make it like enigma, its a literal extra spin wheel, but digital.
 *  Created by @lekonjak and Caesar, and improved with @simoesusp
 * */
#include<stdio.h>
#include<stdlib.h>

void enigma(int shift2, int enc){
    char *msg = NULL;
    size_t size;
    int i = 0, shift;
    // get message to encode/decode
        printf("Enter the message:");
        size = getline(&msg, &size, stdin);

            printf("Insert the inicial wheel position in latin alphabet:");

        shift = getc(stdin);
        shift = shift%26;
        while( i < (int)size-1 ){
                // encripting message
            enc ? \
                // upper case solution
                ( msg[i] >= 'A' && msg[i] <= 'Z' ) ? msg[i]= ((msg[i]-'A'+ shift)%26 + 'A') : \
                    // lower case solution
                    ( msg[i] >= 'a' && msg[i] <= 'z' ) ? msg[i]= ((msg[i]-'a'+shift)%26 + 'a') : \
                        // non letters ignoring case
                        0 : \
                // decripting message
                ( msg[i] >= 'A' && msg[i] <= 'Z' ) ? msg[i]= ((msg[i]-'A'+(26-shift))%26 + 'A') : \
                    // lower case solution
                    ( msg[i] >= 'a' && msg[i] <= 'z' ) ? msg[i]= ((msg[i]-'a'+(26-shift))%26 + 'a') : \
                        // non letters ignoring case
                        0 ;
            i++;
//            shift = enc ? ((shift -'A' + shift2)%26 + 'A') : ((shift - 'A' + (26-shift2))%26 + 'A');i
//            shift = enc ? ((shift -'A' + shift2)%26 + 'A') : ((shift - 'A' + (26-shift2))%26 + 'A');i
//            shift = enc ? ((shift -'A' + shift2)%26 + 'A') : ((shift - 'A' + (26-shift2))%26 + 'A');i
//            shift = enc ? ((shift -'A' + shift2)%26 + 'A') : ((shift - 'A' + (26-shift2))%26 + 'A');i
//            shift = enc ? ((shift -'A' + shift2)%26 + 'A') : ((shift - 'A' + (26-shift2))%26 + 'A');i
            shift = ((shift + shift2 + 26)%26); 
            
        }
    // print, deallocate memory and return
    printf("%s", msg);
    free(msg);
    return;
}

int main(int argc, char **argv){
        // checking for wrong argument number
    if( argc < 3 ){
        printf("Usage: ./usage arg1 arg2\narg1 implies the operation: e stands for encoding, d for decoding.\narg2 is the shift number.\n");
        return(0);
    }
        // passing arg1
    ( *(argv+1)[0] == 'e' ) ? enigma(atoi(*(argv+2)), 1) : (*(argv+1)[0] == 'd') ? \
                 enigma(atoi(*(argv+2)), 0) : printf("There is no %c operation.\n", *(argv+1)[0]);
    
    printf("Exiting.\n"); 
    return(1);
}
