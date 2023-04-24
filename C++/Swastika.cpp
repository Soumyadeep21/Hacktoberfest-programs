/*

Take as input N, an odd number (>=5) . Print the following pattern as given below for N = 7.

*  ****
*  *
*  *
*******
   *  *
   *  *
****  *

Input Format
Enter value of N ( >=5 )

Constraints
5 <= N <= 99

Output Format
Print the required pattern.

Sample Input
7

Sample Output
*  ****
*  *
*  *
*******
   *  *
   *  *
****  *

Explanation
Catch the pattern for the corresponding input and print it accordingly.

*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    //First Component
    cout << "*";
    for(int i = 1; i <= (n-3)/2; i++){
        cout << " ";
    }
    for(int i = 1; i <= (n+1)/2; i++){
        cout << "*";
    }
    cout << endl;

    //Second Component
    for(int i = 1; i <= (n-3)/2; i++){
        cout << "*";
        for(int j = 1; j <= (n-3)/2; j++){
            cout << " ";
        }
        cout << "*" << endl;
    }

    //Third Component
    for(int i = 1; i <= n; i++){
        cout << "*";
    }
    cout << endl;

    //Fourth Component
    for(int i = 1; i <= (n-3)/2; i++){
        for (int j = 1; j <= ((n-3)/2)+1; j++){
            cout << " ";
        }
        cout << "*";
        for(int k = 1; k <= (n-3)/2; k++){
            cout << " ";
        }
        cout << "*" << endl;        
    }

    //Fifth Component
    for(int i = 1; i <= (n+1)/2; i++){
        cout << "*";
    }
    for(int i = 1; i <= (n-3)/2; i++){
        cout << " ";
    }
    cout << "*" << endl;

    return 0;
}