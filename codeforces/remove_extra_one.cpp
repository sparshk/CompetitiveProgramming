#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	ll n;
	cin>>n;
	ll arr[n+1];
	for(ll i=1;i<=n;i++)
		cin>>arr[i];
	ll mx[n+1];
	ll cnt[n+1]={0};
	set<ll> app;
	app.insert(arr[1]);
	ll ma=arr[1];
	for(ll i=2;i<=n;i++){
		set<ll>::iterator it=app.upper_bound(arr[i]);
		if(arr[i]>ma){
			ma=arr[i];
		}
		else if((*it)==ma)
		{
			//cout<<(*it)<<endl;
			cnt[ma]+=1;
		}
		app.insert(arr[i]);
		//cout<<arr[i]<<" "<<ma<<endl;
		mx[arr[i]]=ma;
	}
	ll ans=n,freq=0;
	for(ll i=1;i<=n;i++)
	{
		if(cnt[i]>freq){
			freq=cnt[i];
			ans=i;
		}
	}
	if(n==1)
		cout<<1<<endl;
	else if(freq==0&&arr[1]!=1)
		cout<<1<<endl;
	else if(freq==0&&arr[1]==1)
	{
		if(arr[2]==2)
			cout<<1<<endl;
		else
			cout<<2<<endl;
	}
	else if(freq==1&&arr[1]==1)
	{
		for(ll i=1;i<=n;i++)
		{
			if(cnt[mx[i]]==1)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	else if(freq==1&&arr[1]!=1)
		cout<<1<<endl;
	else
		cout<<ans<<endl;

	//cout<<mx[2]<<endl;
	/*if(n==1&&arr[1]==1)
		cout<<1<<endl;
	else if(freq==0&&arr[1]!=1)
		cout<<1<<endl;
	else if(freq==0&&arr[1]==1)
	{
		for(ll i=1;i<ma;i++){
			if(mx[i]==ma)
			{
				cout<<i<<endl;
				break;
			}
		}

	}
	else if(ans==n&&freq==1&&arr[1]==n)
		cout<<1<<endl;
	else if(freq==1){
		ll x=ans;
		for(ll i=1;i<x;i++)
		{
			if(cnt[mx[i]]==ans)
			{
				ans=i;
				break;
			}

		}
		cout<<ans<<endl;
	}
	else
		cout<<ans<<endl;*/
}