/*

Given an integer n, write a function that returns count of trailing zeroes in n!.
Input Format
A single integer N.

Constraints
1 <= N <= 10^9

Output Format
A single integer denoting the count of trailing zeroes in N!

Sample Input
5

Sample Output
1

Explanation
Factorial of 5 is 120 which has one trailing 0.

*/

#include <iostream>

using namespace std;

int findZeroes(int n){
    int ans = 0;
    int p = 5;
    while((n/p) > 0){
        ans = ans + (n/p);
        p = p*5;
    }
    return ans;
}

int main(){
    long long int n;
    cin >> n;
    cout << findZeroes(n) << endl;
    return 0;
}