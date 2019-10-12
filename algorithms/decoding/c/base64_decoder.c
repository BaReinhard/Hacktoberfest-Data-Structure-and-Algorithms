// C implementation of base64 decoder for converting radix-64 representation into ASCII string format
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

int val(char x){
    for (int i = 0; i < 64; ++i){
        if(x == b64_arr[i]) return i;
    }
    return -1;
}

int main() {
    char *str = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";
    int in = -1;
    int len = strlen(str);
    int outlen = (int)ceil(len/4.0)*3;
    char *result = (char *)malloc(sizeof(char)*outlen);
    for (int i = 0; i < len; i += 4) {
        int x = 0;
        if(str[i+2] != '=' && str[i+3] != '='){
            x |= (val(str[i]) << 18);
            x |= (val(str[i+1]) << 12);
            x |= (val(str[i+2]) << 6);
            x |= (val(str[i+3]));
            result[++in] = (x >> 16) & (0xFF);
            result[++in] = (x >> 8) & (0xFF);
            result[++in] = (x) & (0xFF);
        }
        else if(str[i+2] != '='){
            x |= (val(str[i]) << 18);
            x |= (val(str[i+1]) << 12);
            x |= (val(str[i+2]) << 6);
            result[++in] = (x >> 16) & (0xFF);
            result[++in] = (x >> 8) & (0xFF);
        }
        else{
            x |= (val(str[i]) << 18);
            x |= (val(str[i+1]) << 12);
            result[++in] = (x >> 16) & (0xFF);
        }
    }
    if(in < outlen) result[++in] = '\0';
    printf("%s\n", result);
    return 0;
}
