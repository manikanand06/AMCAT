#include<bits/stdc++.h>
using namespace std;
int *cellComplete(int *cells,int days){
	int res[8]={};
	while(days--)
	{
		for(int i=0;i<8;i++)
		{
			if(i==0) res[i]=0^cells[i+1];
			else if(i==7) res[i]=0^cells[i-1];
			else res[i]=cells[i-1]^cells[i+1];
		}
		for(int i=0;i<8;i++)
		cells[i]=res[i];	
	}	
}
int main()
{
	int cells[]={1,0,0,0,0,1,0,0};
	int days=1;
	cellComplete(cells,days);
	for(int i=0;i<8;i++)
	cout<<cells[i]<<" ";
}
