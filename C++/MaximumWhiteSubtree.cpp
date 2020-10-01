/*
Code Forces #627 F
Maximum White Subtree

time limit per test: 2 seconds
memory limit per test: 256 megabytes
input: standard input
output: standard output

You are given a tree consisting of n vertices. A tree is a connected undirected graph with n−1 edges. 
Each vertex v of this tree has a color assigned to it (av=1 if the vertex v is white and 0 if the vertex v is black).

You have to solve the following problem for each vertex v: what is the maximum difference
between the number of white and the number of black vertices you can obtain if you choose some
subtree of the given tree that contains the vertex v? The subtree of the tree is the connected
subgraph of the given tree. More formally, if you choose the subtree that contains cntw white
vertices and cntb black vertices, you have to maximize cntw−cntb.

Input
The first line of the input contains one integer n (2≤n≤2⋅105) — the number of vertices in the tree.

The second line of the input contains n integers a1,a2,…,an (0≤ai≤1), where ai is the color of the i-th vertex.

Each of the next n−1 lines describes an edge of the tree. Edge i is denoted by two integers ui and vi, 
the labels of vertices it connects (1≤ui,vi≤n,ui≠vi).

It is guaranteed that the given edges form a tree.

Output
Print n integers res1,res2,…,resn, where resi is the maximum possible difference between the number
of white and black vertices in some subtree that contains the vertex i.

Examples:

input

9
0 1 1 1 0 0 0 0 1
1 2
1 3
3 4
3 5
2 6
4 7
6 8
5 9

output

2 2 2 2 2 1 1 0 2 

input

4
0 0 1 0
1 2
1 3
1 4

output

0 -1 1 -1 

Note
The first example is shown below:

The black vertices have bold borders.

In the second example, the best subtree for vertices 2,3 and 4 are vertices 2,3 and 4 correspondingly. 
And the best subtree for the vertex 1 is the subtree consisting of vertices 1 and 3.

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
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int n;
int a[200001];
vi adj[200001];
int dp1[200001];
int dp2[200001];

void dfs1(int nd = 1, int pr = 0){

	dp1[nd] = a[nd] == 1 ? 1 : -1;

	for (auto ch : adj[nd]){

		if (ch == pr)
			continue;

		dfs1(ch, nd);
		dp1[nd] += max(0ll, dp1[ch]);
	}
}

void dfs2(int nd = 1, int pr = 0){

	dp2[nd] = dp1[nd];

	if (pr){
		int val = dp2[pr] - max(0ll, dp1[nd]);
		dp2[nd] += max(0ll, val);
	}

	for (auto ch : adj[nd]){
		if (ch == pr)
			continue;

		dfs2(ch, nd);
	}
}

int32_t main()
{
	c_p_c();
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 0; i < n - 1; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs1();
	dfs2();

	for (int i = 1; i <= n; ++i)
		cout << dp2[i] << ' ';

	return 0;
}