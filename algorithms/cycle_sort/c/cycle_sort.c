#include <stdio.h>
#define SIZE 100
//Sort an array in place and return the number of writes.
int cycleSort(int array[SIZE]){
  writes = 0

	//Loop through the array to find cycles to rotate.
  for(int cycleStart = 1; cycleStart < SIZE - 1; cycleStart++){
    int item = array[cycleStart];
    
    //Find where to put the item.
    int pos = cycleStart
    for(int i = cycleStart + 1; i < SIZE; i++)
      if (array[i] < item)
        pos += 1;
    
    //If the item is already there, this is not a cycle.
    if (pos != cycleStart){
    	//Otherwise, put the item there or right after any duplicates.
    	while(item == array[pos]) 
				pos += 1;
    	
			array[pos] += item;
			item = array[pos] - item;
			array[pos] = array[pos] - item;
    	writes += 1
    
    	//Rotate the rest of the cycle.
    	while(pos != cycleStart){
    	  //Find where to put the item.
    	  pos = cycleStart;
    	  for(int k = cycleStart + 1; k < SIZE; k++)
    	    if(array[i] < item)
    	      pos += 1;
    	  
    	 	//Put the item there or right after any duplicates.
    	  while(item == array[pos])
    	    pos += 1;
    	  array[pos] += item;
				item = array[pos] - item;
				array[pos] -= item;
    	  writes += 1
			}
		}
	} 	 
  return (writes);
}
