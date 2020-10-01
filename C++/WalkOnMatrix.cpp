/*
Code Forces #630 D
Walk on Matrix

time limit per test: 2 seconds
memory limit per test: 512 megabytes
input: standard input
output: standard output

Bob is playing a game named "Walk on Matrix".

In this game, player is given an n×m matrix A=(ai,j), i.e. the element in the i-th row
in the j-th column is ai,j. Initially, player is located at position (1,1) with score a1,1.

To reach the goal, position (n,m), player can move right or down, i.e. move from (x,y) 
to (x,y+1) or (x+1,y), as long as player is still on the matrix.

However, each move changes player's score to the bitwise AND of the current score and the value at the position he moves to.

Bob can't wait to find out the maximum score he can get using the tool he recently learnt  — dynamic programming.
Here is his algorithm for this problem.

However, he suddenly realize that the algorithm above fails to output the maximum score for some matrix A.
Thus, for any given non-negative integer k, he wants to find out an n×m matrix A=(ai,j) such that

1≤n,m≤500 (as Bob hates large matrix);
0≤ai,j≤3⋅105 for all 1≤i≤n,1≤j≤m (as Bob hates large numbers);
the difference between the maximum score he can get and the output of his algorithm is exactly k.
It can be shown that for any given integer k such that 0≤k≤105, there exists a matrix satisfying the above constraints.

Please help him with it!

Input
The only line of the input contains one single integer k (0≤k≤105).

Output
Output two integers n, m (1≤n,m≤500) in the first line, representing the size of the matrix.

Then output n lines with m integers in each line, ai,j in the (i+1)-th row, j-th column.

Examples:

input

0

output

1 1
300000

input

1

output

3 4
7 3 3 1
4 8 3 6
7 7 7 3

Note
In the first example, the maximum score Bob can achieve is 300000, while the output of his algorithm is 300000.

In the second example, the maximum score Bob can achieve is 7&3&3&3&7&3=3, while the output of his algorithm is 2.

*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
int32_t main()
{
    FIO;
    int k; 
    cin >> k;
 
	if (!k){
		cout << 1 << ' ' << 1 << '\n' << 100 << '\n';
    } else {
		cout << 3 << ' ' << 3 << '\n';
		int all_one = (1 << 18) - 1;
		int pw17 = 1 << 17;
 
		cout << all_one << ' ' << all_one << ' ' << pw17 << '\n';
		cout << all_one << ' ' << k << ' ' << pw17 + k << '\n';
		cout << pw17 << ' ' << pw17 + k << ' ' << k << '\n';
	}
    return 0;
}