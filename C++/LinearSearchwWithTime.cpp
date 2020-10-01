#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>

int arr[10000];
int searchElement = 0;

void generateArray(){
    for(int i = 0; i < 10000; i++){
        arr[i] =  rand() % 1000000;
    }
    searchElement = arr[8000];

}

void LinearSearch(int ele){
    for(int i = 0; i < 10000; i++){
        if(ele == arr[i]){
            std::cout << "Element Found" << std::endl;
        }
    }    
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    generateArray();
    LinearSearch(searchElement);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = finish - start;
    std::cout << "Elapsed Time: " << elapsed.count() << " milliseconds" << std::endl;
    return 0;
}