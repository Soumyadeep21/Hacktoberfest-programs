#include <stdio.h>
#include <stdlib.h>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct term
{
	int coeff;
	int exp;
};
struct polynomial
{
	int n;
	struct term *terms;
};
void create(struct polynomial *p)
{ 
	printf("No of terms:");
	scanf("%d",&p->n);
	p->terms=(struct term*)malloc(p->n*sizeof(struct term));
 
	printf("Enter terms\n");
	int i;
	for( i=0;i<p->n;i++)
	scanf("%d%d",&p->terms[i].coeff,&p->terms[i].exp);
}
 
void display(struct polynomial p)
{
	int i;
	for(i=0;i<p.n;i++)
	printf("%dx^%d+",p.terms[i].coeff,p.terms[i].exp);
	printf("\n");
}
 
struct polynomial *add(struct polynomial *p1,struct polynomial *p2 )
{
	struct polynomial *sum;
	sum=(struct polynomial*)malloc(sizeof(struct polynomial));
	sum->terms=(struct term*)malloc((p1->n+p2->n)*sizeof(struct term));
	int i,j,k;
	i=k=j=0;
	while(i<p1->n && j<p2->n)
	{
		if(p1->terms[i].exp>p2->terms[j].exp)
		sum->terms[k++]=p1->terms[i++];
		else if(p1->terms[i].exp<p2->terms[j].exp)
		sum->terms[k++]=p2->terms[j++];
		else
		{
			sum->terms[k].exp=p1->terms[i].exp;
			sum->terms[k++].coeff=p1->terms[i++].coeff+p2->terms[j++].coeff;
		}
 
 
	}
	for(;i<p1->n;i++)sum->terms[k++]=p1->terms[i];
		for(;j<p2->n;j++)sum->terms[k++]=p2->terms[j];
 
		sum->n=k;
		return sum;
}
int main() {
 
	struct polynomial p1,p2,*p3;
	create(&p1);
	create(&p2);
	p3=add(&p1,&p2);
	printf("\n");
	display(p1);
	printf("\n");
	display(p2);
	printf("\n");
	display(*p3);
 
	return 0;
	getch();
}
