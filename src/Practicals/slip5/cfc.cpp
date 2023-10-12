// We have populated the solutions for the 10 easiest problems for your support.
// Click on the SUBMIT button to make a submission to this problem.

#include <bits/stdc++.h>
#include <iostream>
#include<string.h>
using namespace std;

int hash1[26];
int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--)
	{
	    int n;
	    cin>>n;
	    char str[n];
        char strAlis[n/2+1];
        char strBob[n/2+1];
        int flag=1;
        int k=0,in=0;
	    for(int i=0;i<n;i++){
	        cin>>str[i];
	        if(flag==1){
                strAlis[k]=str[i];
                k++;
                flag=0;
            }
            else{
                 strBob[in]=str[i];
                in++;
                flag=1;
            }
	    }
	    
	    if(strcmp(strAlis,strBob)==0)
	    cout<<"YES\n";
	    else
	    cout<<"NO\n";
	    
	}
	
	return 0;
}
// We have populated the solutions for the 10 easiest problems for your support.
// Click on the SUBMIT button to make a submission to this problem.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int hash1[27];
int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--)
	{
	    int n;
	    cin>>n;
	    for(int i=0;i<27;i++){
	        hash1[i]=0;
	    }
	    char str[n];
	    for(int i=0;i<n;i++){
	        cin>>str[i];
	        int asc=str[i];
	        hash1[asc-96]++;
	    }
	    int c=0;
	    for(int i=0;i<27;i++){
	        if(hash1[i]>=2&&hash1[i]%2==0){
	            c++;
	        }
	    }
	    if(n%2!=0)
	    c--;
	    cout<<"c :"<<c<<endl;
	    if(c==(n/2))
	    cout<<"YES\n";
	    else
	    cout<<"NO\n";
	    
	}
	
	return 0;
}




