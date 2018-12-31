#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	ll t;
	cin>>t;
	while(t-->0){
		ll k;
		cin>>k;
		ll ans=192+(k-1)*250;
		cout<<ans<<endl;
	}
}