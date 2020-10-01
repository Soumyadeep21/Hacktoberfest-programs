/*
Code Forces Round #627 A
Yet Another Tetris Problem

time limit per test: 2 seconds
memory limit per test: 256 megabytes
input: standard input
output: standard output
You are given some Tetris field consisting of n columns. The initial height of the i-th column of the field is ai blocks.
On top of these columns you can place only figures of size 2×1 
(i.e. the height of this figure is 2 blocks an the width of this figure is 1 block). Note that you cannot rotate these figures.

Your task is to say if you can clear the whole field by placing such figures.

More formally, the problem can be described like this:

The following process occurs while at least one ai is greater than 0:

You place one figure 2×1 (choose some i from 1 to n and replace ai with ai+2);
then, while all ai are greater than zero, replace each ai with ai−1.
And your task is to determine if it is possible to clear the whole field (i.e. finish the described process),
choosing the places for new figures properly.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤100) — the number of test cases.

The next 2t lines describe test cases. The first line of the test case contains one integer n (1≤n≤100) — 
the number of columns in the Tetris field. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤100),
where ai is the initial height of the i-th column of the Tetris field.

Output
For each test case, print the answer — "YES" (without quotes) if you can clear the whole Tetris field and "NO" otherwise.

Example:

input

4
3
1 1 3
4
1 1 2 1
2
11 11
1
100

output

YES
NO
YES
YES

Note

The first test case of the example field is shown below:

Gray lines are bounds of the Tetris field. Note that the field has no upper bound.

One of the correct answers is to first place the figure in the first column.
Then after the second step of the process, the field becomes [2,0,2].
Then place the figure in the second column and after the second step of the process, the field becomes [0,0,0].

And the second test case of the example field is shown below:

It can be shown that you cannot do anything to end the process.

In the third test case of the example, you first place the figure in the second column after the second step of the process,
the field becomes [0,2]. Then place the figure in the first column and after the second step of the process, the field becomes [0,0].

In the fourth test case of the example, place the figure in the first column,
then the field becomes [102] after the first step of the process,
and then the field becomes [0] after the second step of the process.

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
 
int32_t main()
{
    c_p_c();
    w(t){
        int n;
        cin >> n;
        mk(arr, n+1, int);
        int cnt[2] = {};

        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }

        for(int i = 1; i <= n; i++){
            cnt[arr[i]%2]++;
        }

        if(cnt[0] && cnt[1]){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }

    }
    return 0;
}