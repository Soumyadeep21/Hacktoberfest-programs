/*
Google Kickstart 2020 Round A - Plates

Dr. Patel has N stacks of plates. Each stack contains K plates.
Each plate has a positive beauty value, describing how beautiful it looks.

Dr. Patel would like to take exactly P plates to use for dinner tonight.
If he would like to take a plate in a stack, he must also take all of the plates above it in that stack as well.

Help Dr. Patel pick the P plates that would maximize the total sum of beauty values.

Input
The first line of the input gives the number of test cases, T. T test cases follow.
Each test case begins with a line containing the three integers N, K and P. Then, N lines follow.
The i-th line contains K integers, describing the beauty values of each stack of plates from top to bottom.

Output
For each test case, output one line containing Case #x: y, where x is the test case number 
(starting from 1) and y is the maximum total sum of beauty values that Dr. Patel could pick.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ K ≤ 30.
1 ≤ P ≤ N * K.
The beauty values are between 1 and 100, inclusive.

Test set 1
1 ≤ N ≤ 3.

Test set 2
1 ≤ N ≤ 50.

Sample

Input
 
2
2 4 5
10 10 100 30
80 50 10 50
3 2 3
80 80
15 50
20 10

Output

Case #1: 250
Case #2: 180

  
In Sample Case #1, Dr. Patel needs to pick P = 5 plates:
He can pick the top 3 plates from the first stack (10 + 10 + 100 = 120).
He can pick the top 2 plates from the second stack (80 + 50 = 130) .
In total, the sum of beauty values is 250.

In Sample Case #2, Dr. Patel needs to pick P = 3 plates:
He can pick the top 2 plates from the first stack (80 + 80 = 160).
He can pick no plates from the second stack.
He can pick the top plate from the third stack (20).
In total, the sum of beauty values is 180.

Note: Unlike previous editions, in Kick Start 2020, all test sets are visible verdict test sets,
meaning you receive instant feedback upon submission.

Analysis
From the constraints, we can see that regardless of the test set, 1 ≤ K ≤ 100. i.e., 1 ≤ P ≤ 100*N.

Test set 1
For this test set, we see that 1 ≤ N ≤ 3. So, we can check for every possible combination of taken plates
across all stacks and output the maximum sum. For example, if N = 3 and for any given values of K and P,
generate all possible triples (S1, S2, S3) such that S1+S2+S3 = P and 0 ≤ Si ≤ K. 
Note: Si is the number of plates picked from the i-th stack.
This can be done via recursion and the total time complexity is O(KN) which abides by the time limits.

Test set 2
The solution we had for test set 1 doesn't scale given that N now is at most 100. 
In order to tackle this test set, we use Dynamic Programming along with some precomputation.

First, let's consider an intermediate state dp[i][j] which denotes the maximum sum that can be obtained using
the first i stacks when we need to pick j plates in total. Therefore, dp[N][P] would give us the maximum sum
using the first N stacks if we need to pick P plates in total. In order to compute dp[][] efficiently, we need
to be able to efficiently answer the question: What is the sum of the first x plates from stack i? 
We can precompute this once for all N stacks. Let sum[i][x] denote the sum of first x plates from stack i.

Next, we iterate over the stacks and try to answer the question: What is the maximum sum if we had to pick
j plates in total using the i stacks we've seen so far? This would give us dp[i][j]. However, we need to also
decide, among those j plates, how many come from the i-th stack? i.e., Let's say we pick x plates from the i-th
stack, then dp[i][j] = max(dp[i][j], sum[i][x]+dp[i-1][j-x]). Therefore, in order to pick j plates in total from 
i stacks, we can pick anywhere between [0, 1, ..., j] plates from the i-th stack and [j, j-1, ..., 0] plates from
the previous i-1 stacks respectively. Also, we need to do this for all values of 1 ≤ j ≤ P.

The flow would look like:
for i [1, N]:
 for j [0, P]:
  dp[i][j] := 0
   for x [0, min(j, K)]:
    dp[i][j] = max(dp[i][j], sum[i][x]+dp[i-1][j-x])

If we observe closely, this is similar to the 0-1 Knapsack Problem with some added complexity. 
To conclude, the overall time complexity would be O(N*P*K).

*/
#include <bits/stdc++.h>
using namespace std;

#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int             long long

const int N = 51;
const int P = 51 * 30;
int cache[N][P];

int n, k, p;
int a[N][31];
int pref[N][31];

int rec(int idx, int taken){

    if(taken == p)
        return 0;
    
    if(idx > n || taken > p)
        return -1e9;

    if(cache[idx][taken] != -1)
        return cache[idx][taken];

    int ans = -1e9;

    for(int i = 0;i <= k; i++){
        ans = max(ans, pref[idx][i] + rec(idx + 1, taken + i));
    }

    return cache[idx][taken] = ans;
}

int32_t main(){

    FIO;
    int t;
    cin >> t;
    int tc = 0;
    while(t--){
        tc++;
        
        cin >> n >> k >> p;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                cin >> a[i][j];
                pref[i][j] = pref[i][j - 1] + a[i][j];
            }
        }
        memset(cache, -1, sizeof(cache));
        int ans = rec(1, 0);
        cout << "Case #" << tc << ": " << ans << '\n';
    }
    return 0;   
}