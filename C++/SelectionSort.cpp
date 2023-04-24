#include <iostream>

using namespace std;

void selectionSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_index = i;
        for(int j = i + 1; j <= n - 1; j++){
            if(a[j] < a[min_index]){
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
    

}

int main(){
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    selectionSort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
}