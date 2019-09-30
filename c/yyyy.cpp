#include<stdio.h>
int fun(unsigned int n)
{
	if(n==0||n==1)
	return n;
	
	if(n%5!=0)
	return 0;
	
	return fun(n/5);
}
