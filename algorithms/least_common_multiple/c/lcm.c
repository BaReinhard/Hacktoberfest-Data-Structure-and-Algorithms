#include <stdio.h>
#include <math.h>

int gcd(int x, int y){
	int r;
	x = abs(x);
	y = abs(y);
	if (x < y)
		return gcd(y,x);
	else {
		do {
			r = x % y;
			x = y;
			y = r;
		
		} while (r != 0);
		return x;
	}
}

int lcm(int x, y){
	int d = gcd(x,y);
	if (d == 0)
		return 0;
	else
		return ((a*b) / d);
}
