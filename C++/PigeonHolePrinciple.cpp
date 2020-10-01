/*

You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.

Input Format
The first line contains the number of test cases T. 
First line of each test case contains an integer N denoting the number of elements.
Second line of each test case contains N integers, a1, a2, a3….aN, where ai denotes the ith element of the array.

Constraints
1<=T<=10
1<=N<=10^5
|ai|<=10^9

Output Format
Output a single integer denoting the number of good sub-arrays.

Sample Input
2
5
1 1 1 1 1
5
5 5 5 5 5

Sample Output
1
15

Explanation
In first test case, there is only one sub-array [1, 1, 1, 1, 1], such that 1+1+1+1+1=5, which is divisible by N=5

*/

#include <iostream>
#include <cstring>

using namespace std;

long a[1000005], freq[1000005];

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(freq, 0, sizeof(freq));
        freq[0] = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum = sum + a[i];
            sum = sum % n;
            sum = (sum + n) % n;
            freq[sum]++;
        }
        long ans = 0;
        for(int i = 0; i < n; i++){
            long m = freq[i];
            ans += (m * (m-1))/2; 
        }
        cout << ans << endl;
    }
	return 0;
}