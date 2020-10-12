#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(char *str1, char *str2) 
{ 
	char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char)); 
	strcpy(temp, str1); 
	strcpy(str1, str2); 
	strcpy(str2, temp); 
	free(temp); 
}   

void  reverse(char *str)
{int i=0;
	for( i=0;i<strlen(str)/2;i++)
	{
		char temp=str[i];
		str[i]=str[strlen(str)-i-1];
		str[strlen(str)-i-1]=temp;
	}
	
}

void add(char a[],char b[],char *temp)
{
	reverse(a); reverse(b);
	long int at,bt;
	at=strlen(a);  bt=strlen(b);
	int val=0,carry=0;
	int i=0;
	while(at>0 && bt>0)
	{
		val=((a[strlen(a)-at]-'0')+(b[strlen(b)-bt]-'0'))%10+carry;
		temp[i++]=val+'0';
	 	carry=((a[strlen(a)-at]-'0')+(b[strlen(b)-bt]-'0'))/10;
	 	at--;  bt--;
	}
	while(at>0)
	{
		if(carry!=0)
		{
			val=(((a[strlen(a)-at]-'0')+carry))%10;
			carry=(((a[strlen(a)-at]-'0')+carry))/10;
			temp[i++]=val+'0';
		}	
	 	else
	 		temp[i++]=(a[strlen(a)-at]-'0')+'0';
	 	at--;
	 }	
	while(bt>0)
	{
		if(carry!=0)
		{
			val=(((b[strlen(b)-bt]-'0')+carry))%10;
			carry=(((b[strlen(b)-bt]-'0')+carry))/10;
			temp[i++]=val+'0';
		}	
	 	else
	 		temp[i++]=(b[strlen(b)-bt]-'0')+'0';
	 	at--;
	 }
	 if(carry!=0)
	 	temp[i++]=carry+'0';
	temp[i]='\0';
	reverse(temp);
}

char * multiply(char a[],char b[]){
    static char mul[1000000];
    char c[1000000];
    char temp[1000000];
    int la,lb;
    int i,j,k=0,x=0,y;
    long int r=0;
    long sum = 0;
    la=strlen(a)-1;
        lb=strlen(b)-1;
   
        for(i=0;i<=la;i++){
                a[i] = a[i] - 48;
        }

        for(i=0;i<=lb;i++){
                b[i] = b[i] - 48;
        }

    for(i=lb;i>=0;i--){
         r=0;
         for(j=la;j>=0;j--){
             temp[k++] = (b[i]*a[j] + r)%10;
             r = (b[i]*a[j]+r)/10;
         }
         temp[k++] = r;
         x++;
         for(y = 0;y<x;y++){
             temp[k++] = 0;
         }
    }
   
    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++){
         sum =0;
         y=0;
         for(j=1;j<=lb+1;j++){
             if(i <= la+j){
                 sum = sum + temp[y+i];
             }
             y += j + la + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--){
         mul[j++]=c[i] + 48;
    }
    reverse(mul);
    mul[strlen(mul)-1]='\0';
    return mul;
}

int main()
{
	char A[1000],B[1000];
	char sum[1000];
	char *product;
	printf("Enter your 1st number : ");
	scanf("%s",A);
	printf("Enter ypur 2nd number : ");
	scanf("%s",B);
	if(strlen(A)<strlen(B))
		swap(A, B);
	add(A,B,sum);
	printf("Sum = %s\n",sum);
	product=multiply(A,B);
	printf("Product = %s\n",product);
	return 0;
}
