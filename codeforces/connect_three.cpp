#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool sortbysec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	vector<pair<ll,ll>> v;
	for(ll i=0;i<3;i++)
	{
		ll x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end(),sortbysec);
	ll ans=0;
	if(v[1].first<=v[2].first&&v[0].first>=v[2].first)
	{
		ans=v[2].second-v[0].second+v[2].first-v[1].first-1+v[0].first-v[2].first-1;
		cout<<ans+3<<endl;
		for(ll i=0;i<=(v[2].second-v[0].second);i++)
			cout<<v[2].first<<" "<<v[2].second-i<<endl;
		for(ll i=1;i<=v[2].first-v[1].first;i++)
			cout<<v[2].first-i<<" "<<v[1].second<<endl;
		for(ll i=1;i<=v[0].first-v[2].first;i++)
			cout<<v[2].first+i<<" "<<v[0].second<<endl;
	}
	else if(v[1].first>=v[2].first&&v[0].first<=v[2].first)
	{
		ans=v[2].second-v[0].second+v[1].first-v[2].first-1+v[2].first-v[0].first-1;
		cout<<ans+3<<endl;
		for(ll i=0;i<=(v[2].second-v[0].second);i++)
			cout<<v[2].first<<" "<<v[2].second-i<<endl;
		for(ll i=1;i<=v[2].first-v[0].first;i++)
			cout<<v[2].first-i<<" "<<v[0].second<<endl;
		for(ll i=1;i<=v[1].first-v[2].first;i++)
			cout<<v[2].first+i<<" "<<v[1].second<<endl;
		//cout<<ans<<endl;
	}
	else if(v[1].first<=v[2].first&&v[0].first<=v[2].first)
	{
		if(v[0].first<=v[1].first){
			ans=v[2].second-v[1].second+v[2].first-v[1].first-1+v[1].second-v[0].second+v[1].first-v[0].first-1;
			cout<<ans+3<<endl;
			for(ll i=0;i<=v[2].second-v[1].second;i++)
				cout<<v[2].first<<" "<<v[2].second-i<<endl;
			for(ll i=1;i<=v[2].first-v[1].first;i++)
				cout<<v[2].first-i<<" "<<v[1].second<<endl;
			for(ll i=1;i<=v[1].second-v[0].second;i++)
				cout<<v[1].first<<" "<<v[1].second-i<<endl;
			for(ll i=1;i<=v[1].first-v[0].first;i++)
				cout<<v[1].first-i<<" "<<v[0].second<<endl;

		}
		else{
			ans=v[2].second-v[1].second+v[2].first-v[1].first-1+v[1].second-v[0].second-1;
			cout<<ans+3<<endl;
			for(ll i=0;i<=v[2].second-v[1].second;i++)
				cout<<v[2].first<<" "<<v[2].second-i<<endl;
			for(ll i=1;i<=v[2].first-v[1].first;i++)
				cout<<v[2].first-i<<" "<<v[1].second<<endl;
			for(ll i=1;i<=v[1].second-v[0].second;i++)
				cout<<v[0].first<<" "<<v[1].second-i<<endl;
			
		}
	}
	else if(v[1].first>=v[2].first&&v[0].first>=v[2].first)
	{
		if(v[0].first>=v[1].first){
			ans=v[2].second-v[1].second+v[1].first-v[2].first-1+v[1].second-v[0].second+v[0].first-v[1].first-1;
			cout<<ans+3<<endl;
			for(ll i=0;i<=v[2].second-v[1].second;i++)
				cout<<v[2].first<<" "<<v[2].second-i<<endl;
			for(ll i=1;i<=v[1].first-v[2].first;i++)
				cout<<v[2].first+i<<" "<<v[1].second<<endl;
			for(ll i=1;i<=v[1].second-v[0].second;i++)
				cout<<v[1].first<<" "<<v[1].second-i<<endl;
			for(ll i=1;i<=v[0].first-v[1].first;i++)
				cout<<v[1].first+i<<" "<<v[0].second<<endl;
		}
		else{
			ans=v[2].second-v[1].second+v[1].first-v[2].first-1+v[1].second-v[0].second-1;
			cout<<ans+3<<endl;
			for(ll i=0;i<=v[2].second-v[1].second;i++)
				cout<<v[2].first<<" "<<v[2].second-i<<endl;
			for(ll i=1;i<=v[1].first-v[2].first;i++)
				cout<<v[2].first+i<<" "<<v[1].second<<endl;
			for(ll i=1;i<=v[1].second-v[0].second;i++)
				cout<<v[0].first<<" "<<v[1].second-i<<endl;
		}
	}
}