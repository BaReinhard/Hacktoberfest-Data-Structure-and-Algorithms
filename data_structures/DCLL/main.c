#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int printmenu() {
	int choice;
	printf("1. insert\n"\
		"2. remove \n"\
		"3. append \n"\
		"4. length \n"\
		"5. insert after \n"\
		"6. delete whole list\n"\
		"7. reverse\n"\
		"8. sort\n"\
		"9.exit \n");
	scanf("%d", &choice);	
	return choice;
}
int main() {
	list p;
	int choice;
	int pos;
	char str[128], *s;

	init(&p);	
	while(1) {
		traverse(&p);
		printf("Length = %d \n", length(&p));
		choice = printmenu();
		switch(choice) {
		case 1: /*insert */ 
			printf("Enter the value and pos\n");
			scanf("%s%d", str, &pos);
			insert(&p, str, pos);
			break;
		case 2: /*remove*/
			printf("Enter the pos \n");
			scanf("%d", &pos);
			s = remov(&p, pos);
			if(s) {
				printf("Returned val = %s \n", s);
				free(s);
			}
			break;
		case 3: /*append */
			printf("Enter the val \n");
			scanf("%s", str);
			append(&p, str);
			break;
		case 4: /*length*/
			printf("Length = %d \n", length(&p));
			break;
		case 5: /*insert after */
			break;
		case 6: /*delete whole */
			break;
		case 7: /*reverse*/
			reverse(&p);
			break;
		case 8: /*reverse*/
			sort(&p);
			break;
		case 9: /*exit */
			exit(0);
			break;
		}	
	}
	return 0;
}
