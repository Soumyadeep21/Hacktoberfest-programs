#include<stdio.h>
void SecondMax(int *a,int n)
{
	int x,i,j,y;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(*(a+j)>*(a+(j+1)))
			{				
				x=*(a+j);
				*(a+j)=*(a+(j+1));
				*(a+(j+1))=x;
			}
		}
	}
}
void main()
{
	int array[100],n,i;
	printf("Enter the length of array ");
	scanf("%d",&n);
	printf("Enter %d elements ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	SecondMax(array,n);
	printf("Second largest integer in the list of integers is = %d",array[n-2]);
}
