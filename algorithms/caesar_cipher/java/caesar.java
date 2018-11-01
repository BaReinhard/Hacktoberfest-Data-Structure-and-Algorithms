#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
  char s[100];
  scanf("%[^\n]s", &s);
  int key, index, ciph;
  do {
    scanf("%i", &key);
  }
  while(key < 0 || key > 26);

  for(int i = 0; i < strlen(s); i++) {

    if(isalpha(s[i])) {

      if(isupper(s[i])) {

        index = ((int)(s[i])) - 65;
        ciph = (index + key) % 26;
        printf("%c", (char)(ciph + 65));
      }
       else {

        if(islower(s[i])) {

          index = ((int)(s[i])) - 97;
          ciph = (index + key) % 26;
          printf("%c", (char)(ciph + 97));
        }
      }
    }
     else {

       if(s[i] == " ") {
         printf(" ");
       }
       else {

        printf("%c", (int)s[i]);
       }
     }
  }
}
