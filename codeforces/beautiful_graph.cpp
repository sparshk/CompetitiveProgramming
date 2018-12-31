#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353
ll power(ll x, unsigned ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
bool isBipartite(vector<ll> arr[],ll n,ll color[],ll cnt[])
{
	color[n]=1;
	cnt[1]+=1;
	queue<ll> q;
	q.push(n);
	while(q.empty()!=true){
		ll u=q.front();
		//cout<<u<<endl;
		q.pop();
		for(ll i=0;i<arr[u].size();i++){
			//cout<<u<<" "<<arr[u][i]<<endl;
			if(color[arr[u][i]]==-1){
				color[arr[u][i]]=1-color[u];
				cnt[1-color[u]]+=1;
				q.push(arr[u][i]);
			}
			else if(color[arr[u][i]]==color[u])
				return false;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	ll t;
	cin>>t;
	while(t-->0){
		ll n,m;
		cin>>n>>m;
		vector<ll> arr[n+1];
		for(ll i=0;i<m;i++)
		{
			ll x,y;
			cin>>x>>y;
			arr[x].push_back(y);
			arr[y].push_back(x);
		}
		ll ans=1;
		ll color[n+1];
		bool flag=true;
		for(ll i=0;i<=n;i++)
			color[i]=-1;
		for(ll i=1;i<=n;i++){
			ll cur=0;
			ll cnt[2]={0};
			if(color[i]!=-1)
				continue;
			else{
				if(isBipartite(arr,i,color,cnt)==true)
					{
						//cout<<cnt[1]<<" "<<cnt[0]<<endl;

						cur=(power(2,cnt[1],mod)+power(2,cnt[0],mod))%mod;

					}
				else
				{
					flag=false;
					break;
				}
			}
			ans=((ans%mod)*(cur%mod))%mod;

		}
		if(flag==true)
			cout<<ans<<endl;
		else
			cout<<"0"<<endl;

	}

}