/*
Code Forces #630 E
Height All the Same

time limit per test: 2 seconds
memory limit per test: 512 megabytes
input: standard input
output: standard output

Alice has got addicted to a game called Sirtet recently.

In Sirtet, player is given an n×m grid. Initially ai,j cubes are stacked up in the cell (i,j).
Two cells are called adjacent if they share a side. Player can perform the following operations:

stack up one cube in two adjacent cells;
stack up two cubes in one cell.
Cubes mentioned above are identical in height.

Here is an illustration of the game. States on the right are obtained by performing one of the
above operations on the state on the left, and grey cubes are added due to the operation.


Player's goal is to make the height of all cells the same (i.e. so that each cell has the same
number of cubes in it) using above operations.

Alice, however, has found out that on some starting grids she may never reach the goal no matter
what strategy she uses. Thus, she is wondering the number of initial grids such that

L≤ai,j≤R for all 1≤i≤n, 1≤j≤m;
player can reach the goal using above operations.
Please help Alice with it. Notice that the answer might be large, please output the desired
value modulo 998,244,353.

Input
The only line contains four integers n, m, L and R (1≤n,m,L,R≤109, L≤R, n⋅m≥2).

Output
Output one integer, representing the desired answer modulo 998,244,353.

Examples:

input

2 2 1 1

output

1

input

1 2 1 2

output

2

Note

In the first sample, the only initial grid that satisfies the requirements
is a1,1=a2,1=a1,2=a2,2=1. Thus the answer should be 1.

In the second sample, initial grids that satisfy the requirements are a1,1=a1,2=1 and
a1,1=a1,2=2. Thus the answer should be 2.

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
    int n, m, l, r; 
    cin >> n >> m >> l >> r;
 
	int t = r - l + 1;
	int e = r / 2 - (l - 1) / 2;
	int o = t - e;
 
	if ((n * m) & 1)
		cout << pwmd(t, n * m) << '\n';
 
	else {
		int sub = pwmd(e + o, n * m) - pwmd(abs(e - o), n * m);
		sub += mod;
		sub %= mod;
 
		sub = (sub * pwmd(2, mod - 2)) % mod; // x^-1%mod == (x^(mod-2))%mod
 
		int tot = pwmd(t, n * m);
 
		int ans = (tot - sub + mod) % mod;
 
		cout << ans << '\n'; 
	}
    return 0;
}