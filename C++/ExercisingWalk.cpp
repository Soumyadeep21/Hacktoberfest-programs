/*
Code Forces #630 A
Exercising Walk

time limit per test: 2 seconds
memory limit per test: 512 megabytes
input: standard input
output: standard output
Alice has a cute cat. To keep her cat fit, Alice wants to design an exercising walk for her cat!

Initially, Alice's cat is located in a cell (x,y) of an infinite grid.
According to Alice's theory, cat needs to move:

exactly a steps left: from (u,v) to (u−1,v);
exactly b steps right: from (u,v) to (u+1,v);
exactly c steps down: from (u,v) to (u,v−1);
exactly d steps up: from (u,v) to (u,v+1).

Note that the moves can be performed in an arbitrary order.
For example, if the cat has to move 1 step left, 3 steps right and 2 steps down,
then the walk right, down, left, right, right, down is valid.

Alice, however, is worrying that her cat might get lost if it moves far away from her.
So she hopes that her cat is always in the area [x1,x2]×[y1,y2],
i.e. for every cat's position (u,v) of a walk x1≤u≤x2 and y1≤v≤y2 holds.

Also, note that the cat can visit the same cell multiple times.

Can you help Alice find out if there exists a walk satisfying her wishes?

Formally, the walk should contain exactly a+b+c+d unit moves (a to the left, b to the right,
c to the down, d to the up). Alice can do the moves in any order. Her current position (u,v)
should always satisfy the constraints: x1≤u≤x2, y1≤v≤y2. The staring point is (x,y).

You are required to answer t test cases independently.

Input
The first line contains a single integer t (1≤t≤103) — the number of testcases.

The first line of each test case contains four integers a, b, c, d (0≤a,b,c,d≤108, a+b+c+d≥1).

The second line of the test case contains six integers x, y, x1, y1, x2, y2 (−108≤x1≤x≤x2≤108, −108≤y1≤y≤y2≤108).

Output
For each test case, output "YES" in a separate line, if there exists a walk satisfying her wishes.
Otherwise, output "NO" in a separate line.

You can print each letter in any case (upper or lower).

Example:

input

6
3 2 2 2
0 0 -2 -2 2 2
3 1 4 1
0 0 -1 -1 1 1
1 1 1 1
1 1 1 1 1 1
0 0 0 1
0 0 0 0 0 1
5 1 1 1
0 0 -100 -100 0 100
1 1 5 1
0 0 -100 -100 100 0

output

Yes
No
No
Yes
Yes
Yes

Note:

In the first test case, one valid exercising walk is
(0,0) → (−1,0) → (−2,0) → (−2,1) → (−2,2) → (−1,2) → (0,2) → (0,1) → (0,0) → (−1,0)

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
	w(t){
        
		int l, r, d, u; 
        cin >> l >> r >> d >> u;
		int x, y, xl, yd, xr, yu; 
        cin >> x >> y >> xl >> yd >> xr >> yu;
 
		int ans = 1;
 
		if (r - l > xr - x || l - r > x - xl)
			ans = 0;
 
		if (u - d > yu - y || d - u > y - yd)
			ans = 0;
 
		if (xl == xr && (l + r) > 0)
			ans = 0;
 
		if (yd == yu && (d + u) > 0)
			ans = 0;
 
		if (ans == 1)
			cout << "Yes\n";
 
		else
			cout << "No\n";
	}
	return 0;
}