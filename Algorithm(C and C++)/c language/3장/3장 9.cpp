#include<stdio.h>

int main() 
{
	 int light_speed = 3e+4;
	 int distance = 1496e+5;

	 double time;

	 time = distance / light_speed;

	 time /= 60.0;

	 printf("%lf", time);

}