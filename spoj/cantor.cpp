#include <iostream>
#include <cstdio>
using namespace std;
int n;
void rec(int x, int y, int px, int py,int index)
{
	if(index==n)
	{
		cout<<"TERM "<<n<<" IS "<<y<<"/"<<x<<endl;
		return;
	}
	if(x==1 && px==-1)
		rec(x,y+1,1,-1,index+1);
	else
		if(y==1 && py==-1)
			rec(x+1,y,-1,1,index+1);
		else
			rec(x+px,y+py,px,py,index+1);
}
int main()
{
	int k,i;
	cin>>k;
	for(i=1;i<=k;++i)
	{
		cin>>n;
		rec(1,1,1,-1,1);
	}
	return 0;
} 