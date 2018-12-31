#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 200005
ll n,m;
ll A[5000005],B[5000005];
vector<pair<ll,ll>> adj[MAX];
ll cycle_idx;
ll cycle[MAX];
ll color[MAX];
ll tree_root[MAX];
ll total[MAX];
ll direct_cyc[MAX];
ll par[MAX];
ll subtree[MAX];
ll ans[5000005];
void dfs_subtree(ll u, ll p, ll root){
	subtree[u]=1;
	tree_root[u]=root;
	for(auto it : adj[u]){
		ll v=it.first;
		if(v==p)
			continue;
		if(!cycle[u]||cycle[u]!=cycle[v]){
			dfs_subtree(v,u,root);
			subtree[u]+=subtree[v];
		}
	}
}
void dfs_cycle(ll u, ll p){
	if(color[u]==2)
		return;
	if(color[u]==1){
		cycle_idx++;
		ll cur=p;
		cycle[cur]=cycle_idx;
		while(cur!=u){
			cur=par[cur];
			cycle[cur]=cycle_idx;
		}
		return;
	}
	par[u]=p;
	color[u]=1;
	for(auto x:adj[u]){
		ll v=x.first;
		if(v==par[u])
			continue;
		dfs_cycle(v,u);
	}
	color[u]=2;
}
void dfs2(ll u, ll p){
	for(auto it : adj[u]){
		ll v=it.first, idx=it.second;
		if(v==p)
			continue;
		if(!cycle[u]||cycle[u]!=cycle[v]){
			dfs2(v,u);
			ll tr=tree_root[u];
			ll non_cycle_cnt=(subtree[tr]-subtree[v])*subtree[v];
			ll cycle_cnt=(total[tr]-direct_cyc[v])*subtree[v];
			cycle_cnt+=(subtree[tr]-subtree[v])*direct_cyc[v];
			ans[idx]=cycle_cnt+non_cycle_cnt;
			direct_cyc[u]+=direct_cyc[v];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t-->0){
		cin>>n>>m;
		for(ll i=1;i<=n;i++){
			adj[i].clear();
			cycle[i]=0;
			color[i]=0;
			tree_root[i]=0;
			total[i]=0;
			direct_cyc[i]=0;
		}
		for(ll i=1;i<=m;i++){
			cin>>A[i]>>B[i];
			adj[A[i]].push_back({B[i],i});
			adj[B[i]].push_back({A[i],i});
		}
		cycle_idx=0;
		for(ll i=1;i<=n;i++){
			dfs_cycle(i,0);
		}
		for(ll i=1;i<=n;i++){
			if(!tree_root[i])
				dfs_subtree(i,0,i);
		}
		for(ll i=1;i<=m;i++){
			if(cycle[A[i]]&& cycle[A[i]]==cycle[B[i]]){
				ans[i]=subtree[tree_root[A[i]]]*subtree[tree_root[B[i]]];
				direct_cyc[A[i]]+=subtree[tree_root[B[i]]];
				direct_cyc[B[i]]+=subtree[tree_root[A[i]]];
				total[tree_root[A[i]]]+=subtree[tree_root[B[i]]];
				total[tree_root[B[i]]]+=subtree[tree_root[A[i]]];
			}
		}
		for(ll i=1;i<=n;i++){
			if(tree_root[i]==i)
				dfs2(i,0);
		}

		for(ll i=1;i<=m;i++)
			cout<<ans[i]<<"\n";
	}
}