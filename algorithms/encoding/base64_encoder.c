// C implementation of base64 encoder for converting ASCII string format into radix-64 representation.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


static char b64_arr[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'};

int main() {
    char *str = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";
    int in = -1;
    int len = strlen(str);
    int outlen = (int)ceil(len/3.0)*4;
    char *result = (char *)malloc(sizeof(char)*outlen);
    for (int i = 0; i < len; i += 3) {
        int x = 0;
        if(str[i+1] != '\0' && str[i+2] != '\0'){
            x |= (str[i] << 16);
            x |= (str[i+1] << 8);
            x |= (str[i+2]);
            result[++in] = b64_arr[(x >> 18) & (0x3F)];
            result[++in] = b64_arr[(x >> 12) & (0x3F)];
            result[++in] = b64_arr[(x >> 6) & (0x3F)];
            result[++in] = b64_arr[(x) & (0x3F)];
        }
        else if(str[i+1] != '\0'){
            x |= (str[i] << 16);
            x |= (str[i+1] << 8);
            result[++in] = b64_arr[(x >> 18) & (0x3F)];
            result[++in] = b64_arr[(x >> 12) & (0x3F)];
            result[++in] = b64_arr[(x >> 6) & (0x3F)];
            result[++in] = '=';
        }
        else{
            x |= (str[i] << 16);
            result[++in] = b64_arr[(x >> 18) & (0x3F)];
            result[++in] = b64_arr[(x >> 12) & (0x3F)];
            result[++in] = '=';
            result[++in] = '=';
        }
    }
    if(in < outlen) result[++in] = '\0';
    printf("%s\n", result);
    return 0;
}
