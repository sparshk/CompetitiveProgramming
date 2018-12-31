#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll> m;
ll coins(ll n){
	if(m[n])
		return m[n];
	if(n<12){
		m[n]=n;
		return m[n];
	}
	else
		m[n]=max((coins(n/2)+coins(n/3)+coins(n/4)),n);
 
	return m[n];
 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	ll n;
	while(cin>>n){
		ll ans=coins(n);
		cout<<ans<<endl;
	}
} 