#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
}*head=NULL;
void insertion(int data)
{
	node *curr;
	node *newnode = new node;
	newnode->data=data;
	newnode->next=head;
	if(head==NULL)
	{
	head=newnode;
	curr=head;	
	}
	else
	{
		curr->next=newnode;
		curr=curr->next;	
	}
}
node* insertSortedList (node* start,int n)     //Function Signature
{
	node *curr1=start,*maxi=start,*mini=start;
	do                                         //Finding the address of minimum and maximum element
   {
   	if(curr1->data>maxi->data)
   	maxi=curr1;
   	if(curr1->data<mini->data)
   	mini=curr1;
   	curr1=curr1->next;
   }while(curr1!=start);
   
   
   node *newnode = new node;
   newnode->data=n;
	if(n>maxi->data||n<mini->data){   //handles edge case
	newnode->next=maxi->next;
	maxi->next=newnode;	
	}
	else
	{
		node *prev2=start,*curr2=start->next;  //Using two pointer
		while(prev2&&curr2)
		{
			if(prev2->data<n&&curr2->data>n)
			{
				newnode->next=curr2;
				prev2->next=newnode;	
				break;
			}	
			else
			{
				prev2=prev2->next;
				curr2=curr2->next;
			}
		}	
	}
	return newnode;	
}
//driver code
int main()
{
	int a[]={4,5,6,1,2};
	int n=sizeof(a)/sizeof(a[0]);
	
	for(int i=0;i<n;i++)
	{
		insertion(a[i]);
	}
	
	node *res=insertSortedList(head,0);
	node *temp=res;  
   do
   {
   	cout<<res->data<<" ";
   	res=res->next;
   }while(res!=temp);
}
