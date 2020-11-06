#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	int a[n], b[m];
	
	for (int i=0; i<n; i++)
        cin>>a[i];
        
    for(int i=0; i<m; i++ )
    	cin>>b[i];
    	
    int count=0, max_a=0, min_b=100;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]>max_a)
        {
            max_a=a[i];
        }
    }
    
    for(int i=0;i<m;i++)
    {
        if(b[i]<min_b)
        {
            min_b=b[i];
        }
    }
    
    for (int k=max_a;k<=min_b;k++)
    {
        int flag=1;
        for(int i=0;i<n;i++)
        {
            if(k%a[i]!=0)
            {
                flag=0;
            }
        }
        for(int j=0;j<m;j++)
        {
            if(b[j]%k!=0)
            {
                flag=0;
            }
        }
        if(flag==1)
        {
            count++;
        }
    }
    
    cout<<count;
    return 0;
    
    
}
