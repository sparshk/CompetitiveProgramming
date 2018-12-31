#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t-->0){
		ll n,q;
		cin>>n>>q;
		vector<ll> v;
		for(ll i=0;i<n;i++){
			ll ele;
			cin>>ele;
			v.push_back(ele);
	    }
		sort(v.begin(),v.end());
		map<ll,ll> m;
		while(q-->0){
			ll x;
			cin>>x;
			map<ll,ll>::iterator it=m.find(x);
			if(m.find(x)!=m.end()){
				cout<<it->second<<endl;
				continue;
			}
			ll start=lower_bound(v.begin(),v.end(),x)-v.begin();
			ll end=upper_bound(v.begin(),v.end(),x)-v.begin();
			ll count=0;
			//cout<<start<<" "<<end<<endl;
			if(start==end){
				count=n-start;
				ll temp=start;
				start=start-1;
				if(start==-1){
					if(n==1){
						cout<<0<<endl;
						m.insert({x,0ll});
					}
					else{
						cout<<n<<endl;
						m.insert({x,n});
					}
				}
				else{
					while(x-v[start]<=(temp-1)){
						count+=1;
						temp=temp-(x-v[start])-1;
						start-=1;
					}
					cout<<count<<endl;
					m.insert({x,count});
				}
			}
			else if(start!=(end)){
				count=n-start;
				//cout<<count<<endl;
				ll temp=start;
				start=start-1;
				if(start==-1){
					if(n==1){
						cout<<1<<endl;
						m.insert({x,1ll});
					}
					else{
						cout<<n<<endl;
						m.insert({x,n});
					}
				}
				else{
					while((x-v[start])<=(temp-1)){
						//cout<<temp<<" "<<v[start]<<endl;
						count+=1;
						temp=temp-(x-v[start])-1;
						start-=1;
						
					}
					cout<<count<<endl;
					m.insert({x,count});
				}

			}
		}

	}
}



