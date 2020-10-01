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
    int n, m;
    cin >> n >> m;

    vector<vi> edges(m);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    vi dis(n + 1, inf);

    dis[1] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int u, v, w;
            u = edges[j][0];
            v = edges[j][1];
            w = edges[j][2];

            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
            }
        }        
    }

    for(int j = 0; j < m; j++){
        int u, v, w;
        u = edges[j][0];
        v = edges[j][1];
        w = edges[j][2];

        if(dis[v] > dis[u] + w){
            cout << "Negative Cycle Detected";
            return 0;
        }
    }

    for(int k = 1; k <= n; k++){
        cout << k << " ----> " << dis[k] << '\n';
    }

}