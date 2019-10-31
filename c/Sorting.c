#include <stdio>
using namespace std;

void sorting(int *hp)
{
    int box;
    for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
                if(hp[i]>hp[j])
                {
                    box=hp[i];
                    hp[i]=hp[j];
                    hp[j]=box;
                }
        }
    return;
}

// Driver program
int main()
{
    int a[5];
    //input
    for(int i=0;i<5;i++)
        scanf("%d",&a[i]);
        
    //sorting fun
    sorting(a);     //default sending as reference

    for(int i=0;i<5;i++)
        printf("%d",a[i]); 

    return 0;
}
