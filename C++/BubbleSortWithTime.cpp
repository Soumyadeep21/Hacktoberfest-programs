#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>

void bubbleSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                std::swap(a[j], a[j+1]);
            }
        }
    }
}

int arr[10000];

void generateArray(){
    for(int i = 0; i < 10000; i++){
        arr[i] =  rand() % 1000000;
    }
}

int main(){
    generateArray();
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr, 10000);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = finish - start;
    std::cout << "Elapsed Time: " << elapsed.count() << " milliseconds" << std::endl;
    return 0;
}