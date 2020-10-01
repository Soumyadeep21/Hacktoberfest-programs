/*
Code Forces #630 C
K-Complete Word

time limit per test: 2 seconds
memory limit per test: 512 megabytes
input: standard input
output: standard output

Word s of length n is called k-complete if

s is a palindrome, i.e. si=sn+1−i for all 1≤i≤n;
s has a period of k, i.e. si=sk+i for all 1≤i≤n−k.
For example, "abaaba" is a 3-complete word, while "abccba" is not.

Bob is given a word s of length n consisting of only lowercase Latin letters and an integer k,
such that n is divisible by k. He wants to convert s to any k-complete word.

To do this Bob can choose some i (1≤i≤n) and replace the letter at position i with some other lowercase Latin letter.

So now Bob wants to know the minimum number of letters he has to replace to convert s to any k-complete word.

Note that Bob can do zero changes if the word s is already k-complete.

You are required to answer t test cases independently.

Input
The first line contains a single integer t (1≤t≤105) — the number of test cases.

The first line of each test case contains two integers n and k (1≤k<n≤2⋅105, n is divisible by k).

The second line of each test case contains a word s of length n.

It is guaranteed that word s only contains lowercase Latin letters. And it is guaranteed that the sum of 
n over all test cases will not exceed 2⋅105.

Output
For each test case, output one integer, representing the minimum number of characters he has to replace to 
convert s to any k-complete word.

Example:

input

4
6 2
abaaba
6 3
abaaba
36 9
hippopotomonstrosesquippedaliophobia
21 7
wudixiaoxingxingheclp

output

2
0
23
16

Note
In the first test case, one optimal solution is aaaaaa.

In the second test case, the given word itself is k-complete.

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
		int n, k;
        cin >> n >> k;
		string s;
        cin >> s;
 
		int ans = 0;
 
		for (int i = 0; i < k / 2; ++i)s{
			int cnt[26] = {}; 
			for (int st = 0; st + k - 1 < n; st += k){
				int i1 = st + i;
				int i2 = st + (k - 1 - i);
 
				cnt[s[i1] - 'a']++;
				cnt[s[i2] - 'a']++;
			}
 
			int req = 2 * (n / k);
			int mx = *max_element(cnt, cnt + 26); 
			ans += req - mx;
		} 
 
		if (k & 1){
			int cnt[26] = {}; 
			for (int i = k / 2; i < n; i += k){
				cnt[s[i] - 'a']++;
			}
 
			int req = n / k;
			int mx = *max_element(cnt, cnt + 26); 
			ans += req - mx;
		}
 
		cout << ans << '\n'; 
	}
    return 0;
}