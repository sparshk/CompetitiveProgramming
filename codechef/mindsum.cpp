#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll digSumC(ll n){
	ll sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	ll t;
	cin>>t;
	while(t-->0){
		ll n,d;
		cin>>n>>d;
		ll arr[10];
		for(ll i=0;i<10;i++)
			arr[i]=-1;
		ll bt[1000000];
		bt[0]=n;
		if(n<10)
			arr[n]=0;

		ll ans;
		if(d%9!=3&&d%9!=6&&d%9!=0){
			for(ll i=0;i<1000000;i++)
			{
				bt[2*i+1]=digSumC(bt[i]);
				if(bt[2*i+1]==1)
				{
					ans=2*i+1;
					break;
				}
				bt[2*i+2]=bt[i]+d;
			}
			arr[1]=floor(log2(ans+1));
		}
		else{
			if(d%9==3||d%9==6){
				ll a;
				if(n%9!=0)
					a=(n%9)-3*(((n-1)%9)/3);
				else
					a=9-3*(((n-1)%9)/3);
				if(bt[0]==a)
				{
					cout<<a<<" "<<0<<endl;
					break;
				}
				for(ll i=0;i<1000000;i++)
				{
					bt[2*i+1]=digSumC(bt[i]);
					if(bt[2*i+1]==a)
					{
						ans=2*i+1;
						break;
					}
					bt[2*i+2]=bt[i]+d;
				}
				arr[a]=floor(log2(ans+1));
			}
			else if(d%9==0){
				ll a;
				if(n%9==0)
					a=9;
				else
					a=n%9;
				if(bt[0]==a)
				{
					cout<<a<<" "<<0<<endl;
					continue;
				}
				for(ll i=0;i<1000000;i++)
				{
					bt[2*i+1]=digSumC(bt[i]);
					if(bt[2*i+1]==a)
					{
						ans=2*i+1;
						break;
					}
					bt[2*i+2]=bt[i]+d;
				}
				arr[a]=floor(log2(ans+1));
			}
		}
		for(ll i=1;i<=9;i++)
		{
			if(arr[i]!=-1){
				cout<<i<<" "<<arr[i]<<endl;
				break;
			}
		}
	}
}