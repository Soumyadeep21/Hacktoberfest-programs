#include <iostream>

using namespace std;

void insertionSort(int a[], int n){
    int i,j,key;
    for (i = 1; i < n; i++) 
    {  
        key = a[i];  
        j = i - 1;
        while (j >= 0 && a[j] > key) 
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = key;  
    }  
}

int main(){
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    insertionSort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
} 