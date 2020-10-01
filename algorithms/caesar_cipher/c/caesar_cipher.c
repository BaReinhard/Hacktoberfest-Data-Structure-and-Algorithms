#include<stdio.h>
 
int main(){
    char message[1000], ch;
    int i, key;
    
    printf("Message : ");
    gets(message);
    printf("Enter key : ");
    scanf("%d", &key);
    
    for(i=0; message[i]!='\0';i++){
        ch=message[i];
        
        if(ch>='a' && ch<='z'){
            ch=ch+key;
            if(ch>'z'){
                ch=ch-'z'+'a'-1;
            }
            message[i] = ch;
        }
        else if(ch>='A' && ch<='Z'){
            ch=ch+key;
            if(ch>'Z'){
                ch=ch-'Z'+'A'-1;
            }
            message[i] = ch;
        }
    }
    
    printf("\n\nEncrypted message: %s", message);
    
    return 0;
}