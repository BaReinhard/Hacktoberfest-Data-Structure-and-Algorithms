// There are numerous occassions when you have to find perfect squares between two numbers. And many a times in 
// competetive questions the range is tending to order of 10000000000. 
// Computing squares and then checking them individually is a highly inefficient but common approach.

// A better approach is to computer squareRoot of the limits and then check squareRoots of the numbers are lying in the 
// range or not. This is NOT obviously the most optimized solution but it works like charm and is a lot easier to 
// understand why it works and how it works.

// The even simpler way would be to use the floor() method from Java to make this algorithm even more efficient.

//Basic info about floor()
//Returns the largest (closest to positive infinity) double value that is less than or equal to the argument and is equal to a mathematical integer. 
//Special cases:
//If the argument value is already equal to a mathematical integer, then the result is the same as the argument.
//If the argument is NaN or an infinity or positive zero or negative zero, then the result is the same as the argument.

//Code for this algorithm in java, a and b are the limits, t number of cases:

while(t-- > 0){
    int a = scan.nextInt();
    int b = scan.nextInt();
    System.out.println((int) Math.floor(Math.sqrt(b)) - (int) Math.ceil(Math.sqrt(a)) + 1);
}
