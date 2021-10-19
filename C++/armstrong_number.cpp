#include<iostream>
#include<math.h>

using namespace std;

int  main(){
    int n;
    cout<<"Enter the Number you want to check"<<endl;
    cin>>n;
    int temp=n;
    int num , sum=0;
    while(n!=0){
        num=n%10;
        sum=sum+pow(num , 3);
        n=n/10;
        }
        if(sum==temp){
            cout<<"It is an armstrong number";
        }
        else{
            cout<<"It is not an armstrong number";
        }
}