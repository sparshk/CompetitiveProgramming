#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long int  ll;
typedef long double  ld;
#define pii pair<ll,ll> 
#define pic pair<ll,char>
#define vi vector< ll > 
#define vvi vector< vi > 
#define vpi vector< pii > 
#define vvpi vector< vpi > 
#define st  set <ll, greater <ll> >
#define mst  multiset <ll, greater <ll> >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mapp  unordered_map <ll, ll>
#define ppii pair< pii, pii > 
#define test(t) ll t;cin>>t;while(t--)
#define inarr(n) ll arr[n];for(ll i=0;i<n;i++)cin>>arr[i];
#define ingra(m) vvi arr(100005);for(ll i=0;i<m;i++){ll u,v;cin>>u>>v;arr[u].pb(v);arr[v].pb(u);}
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res;}
vvi arr(1000001);
ll val[1000001];
ll lca[1000001][25];
ll ans[1000001];
ll n;
void dfs(ll u,ll par,ll prev,ll done)
{
    ans[u] = ans[par];
    if(val[u]>prev)
    {
        ans[u]++;
        prev = val[u];
    }
    else
        val[u] = prev;
    lca[u][1] = par;
    for(auto v:arr[u])
    {
        if(v!=par)
        {
            dfs(v,u,prev,ans[u]);
        }
    }
}
int main()
{
  fast;
  test(t)
  {
    arr.clear();
    cin>>n;
    ll i,j;
    for(i=0;i<=n;i++)
        arr[i].clear(),val[i] = 0,ans[i] = 0;
    for(i=1;i<=n;i++)
        cin>>val[i];
    for(i=2;i<=n;i++)
    {
        ll k;
        cin>>k;
        arr[i].pb(k);
        arr[k].pb(i);
    }
    for(i=0;i<25;i++)
    {
        for(j=0;j<=n;j++)
            lca[j][i] = 0;
    }
    for(i=0;i<=n;i++)
    {
        lca[i][0] = i;
    }
    dfs(1,0,0,0);
    for(j=2;j<25;j++)
    {
        for(i=0;i<=n;i++)
        {
            lca[i][j] = lca[lca[i][j-1]][j-1];
        }
    }
    ll q;
    cin>>q;
    ll pr = 0;
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        ll u = pr^a;
        ll w = pr^b;
        ll v = u;
        for(i=24;i>=0;i--)
        {
            if(val[lca[u][i]]>w)
                u = lca[u][i];
        }
        if(u==v)
        {
            if(val[u]>w)
                pr = 1;
            else
                pr = 0;
        }
        else
            pr = ans[v]-ans[u]+1;
        // cout<<u<<"\n"
        cout<<pr<<"\n";
    }


  }
}