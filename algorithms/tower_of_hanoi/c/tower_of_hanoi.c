#include <stdio.h>

//Prints the movement
void moveDisk(from_pole, to_pole){
	printf("Moving disk from pole %d to pole %d\n", from_pole, to_pole);	
}

//Recursive implementation for Tower of Hanoi
void tower_of_hanoi(height, from_pole, to_pole, aux){
	if (height > 0){
		tower_of_hanoi(height-1, from_pole, to_pole, aux);
		moveDisk(from_pole, to_pole);
		tower_of_hanoi(height-1, aux, from_pole, to_pole);
	}
}

int main(){
	tower_of_hanoi(3);
}
