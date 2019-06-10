#include<bits/stdc++.h>
using namespace std;

int main(){
           long long int i,n,temp = 0;

           cin>>n;

           for(int i =2 ;i*i<=n;i++){           //sqrt(i) *****

                        if(n%i == 0) {

                                    temp =1 ;

                                    break;

                        }

           }

           if(n==0 || n==1) temp = 1;

           if(temp==1) cout<<"Not Prime"<<endl;

           if(temp==0) cout<<"Prime"<<endl;

return 0;
}
