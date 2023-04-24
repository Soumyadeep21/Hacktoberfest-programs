/*
Code Forces #627 D
Pair of Topics

time limit per test: 2 seconds
memory limit per test: 256 megabytes
input: standard input
output: standard output

The next lecture in a high school requires two topics to be discussed.
The i-th topic is interesting by ai units for the teacher and by bi units for the students.

The pair of topics i and j (i<j) is called good if ai+aj>bi+bj (i.e. it is more interesting for the teacher).

Your task is to find the number of good pairs of topics.

Input
The first line of the input contains one integer n (2≤n≤2⋅105) — the number of topics.

The second line of the input contains n integers a1,a2,…,an (1≤ai≤109),
where ai is the interestingness of the i-th topic for the teacher.

The third line of the input contains n integers b1,b2,…,bn (1≤bi≤109),
where bi is the interestingness of the i-th topic for the students.

Output
Print one integer — the number of good pairs of topic.

Examples:

input

5
4 8 2 6 2
4 5 4 1 3

output

7

input

4
1 3 2 4
1 3 2 4

output

0

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
    int n;
    cin >> n;
    mk(a, n, int);
    mk(b, n, int);
    mk(c, n, int);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    for(int i = 0; i < n; i++){
        c[i] = b[i] - a[i];
    }

    sort(c, c+n);

    int ans = 0;

    for(int i = 0; i < n; i++){
        auto it = lower_bound(c+i+1, c+n, -c[i]);
        int id = it - c;
        ans += id - (i+1);
    }

    cout << ans << '\n';

    return 0;
}