#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> idx[100002];
/*ll count_min_in_range(ll arr[],ll low,ll high,ll x,ll count){
	if(low==high){
        if(arr[low]<x)
            return 1;
        else
            return 0;
    }
    ll mid=(low+high)/2;
    count=count_min_in_range(arr,low,mid,x,count)+count_min_in_range(arr,mid+1,high,x,count);
    return count;
}*/
ll getMid(ll s, ll e) 
{
	return s + (e - s) / 2;
}

ll MaxUtil(ll* st, ll ss, ll se, ll l, 
			ll r, ll node)
{
	if (l <= ss && r >= se)
		return st[node];
	if (se < l || ss > r)
		return -1;
	ll mid = getMid(ss, se);
	
	return max(MaxUtil(st, ss, mid, l, r, 
					2 * node + 1),
			MaxUtil(st, mid + 1, se, l, 
					r, 2 * node + 2));
}

void updateValue(ll arr[], ll* st, ll ss, ll se, 
				ll index, ll value, ll node)
{
	if (ss == se) 
	{ 
	
		arr[index] = value;
		st[node] = value;
	}
	else {
			ll mid = getMid(ss, se);
			
			if (index >= ss && index <= mid)
				updateValue(arr, st, ss, mid, index, 
							value, 2 * node + 1);
			else
				updateValue(arr, st, mid + 1, se, 
							index, value, 2 * node + 2);
			
			st[node] = max(st[2 * node + 1], 
					st[2 * node + 2]);
	}
	return;
}

ll getMax(ll* st, ll n, ll l, ll r)
{
	return MaxUtil(st, 0, n - 1, l, r, 0);
}

ll constructSTUtil(ll arr[], ll ss, ll se, 
					ll* st, ll si)
{
	if (ss == se) 
	{
		st[si] = arr[ss];
		return arr[ss];
	}
	ll mid = getMid(ss, se);
	
	st[si] = max(constructSTUtil(arr, ss, mid, st, 
								si * 2 + 1),
				constructSTUtil(arr, mid + 1, se, 
								st, si * 2 + 2));
	
	return st[si];
}

ll* constructST(ll arr[], ll n)
{
	ll x = (ll)(ceil(log2(n)));
	ll max_size = 2 * (ll)pow(2, x) - 1;
	ll* st = new ll[max_size];
	constructSTUtil(arr, 0, n - 1, st, 0);
	return st;
}
void pointupdate(ll r_arr[],vector<ll> ind, ll max_ele){
	for(ll i=0;i<ind.size();i++)
		r_arr[(int)(ind.at(i))]=max_ele;
}
void pointUpdate(ll r_arr[], ll arr[], ll j, ll i, ll k,ll n){
		
	//cout<<r_arr[j]<<" "<<r_arr[i]<<endl;
	if(r_arr[j]<r_arr[i]){
		ll temp=r_arr[j];
		r_arr[j]=r_arr[i];
		ll st=0ll>(j-k)?0ll:(j-k);
		ll end=n-1>(j+k)?(j+k):n-1;
		for(ll m=st;m<=j;m++){
			if(arr[m]>arr[j])
				r_arr[m]=r_arr[j]+(r_arr[m]-temp);
			if(arr[m]==arr[j]&&r_arr[m]!=r_arr[j])
				pointUpdate(r_arr,arr,m,j,k,n);
		}
	}
	else{
		r_arr[i]=r_arr[j];
	}
}
void check(ll r_arr[],ll arr[],ll k,ll n){
	ll* str=constructST(r_arr,n);
	for(ll i=0;i<idx[1].size();i++){
		r_arr[idx[1].at(i)]=1;
		updateValue(r_arr,str,0,n-1,idx[1].at(i),1,0);
	}
	ll j=2;

	while(idx[j].size()>0){
		//cout<<j<<" "<<idx[j].size()<<endl;
		vector<ll> v;
		for(ll i=0;i<idx[j].size();i++){
			//cout<<idx[j].at(i)<<endl;
			ll st=0ll>(idx[j].at(i)-k)?0ll:(idx[j].at(i)-k);
			ll end=(n-1)<(idx[j].at(i)+k)?(n-1):(idx[j].at(i)+k);
			ll m=getMax(str,n,st,end);
			r_arr[idx[j].at(i)]=m+1;
			v.push_back(m+1);
			
		}
		for(ll i=0;i<idx[j].size();i++)
			updateValue(r_arr,str,0,n-1,idx[j].at(i),v.at(i),0);
		j++;
		//cout<<endl;
	}
	
/*if(k==8){
	for(ll i=0;i<n;i++)
	    cout<<rr_arr[i]<<" ";
	cout<<endl;
}*/	if(n<=1000){
	for(ll i=0;i<n;i++){
		ll st=0ll>(i-k)?0ll:(i-k);
		ll end=(n-1)<(i+k)?(n-1):(i+k);
		for(ll j=st;j<=i;j++){
			//cout<<r_arr[j]<<" "<<r_arr[i]<<endl;
			if(arr[j]==arr[i]&&r_arr[j]!=r_arr[i]){
				pointUpdate(r_arr, arr, j,i,k,n);
			}
		}
 
		
		}
	}
	else{
	for(ll i=2;i<100002;i++){
		if(idx[i].size()==0)
			break;
		vector<ll> ind;
		ll max_ele=r_arr[idx[i].at(0)];
		ind.push_back(idx[i].at(0));
		for(ll j=1;j<idx[i].size();j++){
			if(idx[i].at(j)<=(idx[i].at(j-1)+k)){
				ind.push_back(idx[i].at(j));
				max_ele=max(max_ele,r_arr[idx[i].at(j)]);
			}
			else {
				pointupdate(r_arr,ind,max_ele);
				ind.clear();
				ind.push_back(j);
				max_ele=r_arr[idx[i].at(j)];
			}
		}
		
	}
}
	/*for(ll i=0;i<n;i++){
		ll st=max(0ll,i-k);
		ll end=min(n-1,i+k);
		ll count1=0,count2=0;
		count1=count_min_in_range(rr_arr,st,end,rr_arr[i],count1);
		count2=count_min_in_range(arr,st,end,arr[i],count2);
		
			cout<<count1<<" "<<count2<<" "<<i<<" "<<k<<endl;
		
	}*/
	
}
void compress(ll arr[], ll n)
{
    vector <pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
        v.push_back(make_pair(arr[i], i));
 
    sort(v.begin(), v.end());
    std::set<ll> s;
    vector<ll> v2;
    for(ll i=0;i<n;i++){
        if(s.find(v.at(i).first)==s.end())
        {
            s.insert(v.at(i).first);
            v2.push_back(v.at(i).first);
        }
    }
    for (ll i=0; i<n; i++)
        arr[v[i].second] = lower_bound(v2.begin(),v2.end(),v.at(i).first)-v2.begin()+1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t-->0){
		ll n,s;
		cin>>n>>s;
		ll arr[n];
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			//idx[arr[i]].push_back(i);
		}
		compress(arr,n);
		for(ll i=0;i<n;i++){
			//cout<<arr[i]<<" ";
			idx[arr[i]].push_back(i);
		}
		//cout<<endl;
		ll low=0;
		ll high=n;
		while(low<=high){
			ll mid=(low+high)/2;
			//cout<<mid<<endl;
			ll r_arr[n]={0};
			check(r_arr,arr,mid,n);
			ll sum=0;
			/*if(mid==8){
				ll st=max(0ll,5-mid);
				ll end=min(n-1,5+mid);
				for(ll i=st;i<=end;i++)
					cout<<r_arr[i]<<" ";
				cout<<endl;
				for(ll i=st;i<=end;i++)
					cout<<arr[i]<<" ";
				cout<<endl;


			}*/
			for(ll i=0;i<n;i++){
				//cout<<r_arr[i]<<" ";
				sum+=r_arr[i];
			}
			//cout<<endl;
			if(sum<=s)
				low=mid+1;
			else
				high=mid-1;

		}
		cout<<low<<endl;
		for(ll i=0;i<n;i++)
		    idx[arr[i]].clear();
	}
	
}