#include <iostream>

using namespace std;

void prime_sieve(int *p){

    for(int i = 3; i <= 1000000; i+=2){
        p[i] = 1;
    }

    for(long long i = 3; i <= 1000000; i+=2){
        if(p[i] == 1){
            for(long long j = 2*i; j <= 1000000; j = j + i){
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main(){
    int n;
    cin >> n;
    int p[1000000] = {0};
    prime_sieve(p);

    for(int i = 0; i <= n; i++){
        if(p[i] == 1){
            cout << i << " ";
        }
    }
}