#include<bits/stdc++.h>

using namespace std;

int ara[9999999];

int main(){

            int i,j,n,N=9999999;

            int sq = sqrt(N);

            ara[0]=1;

            ara[1]=1;

            for(i=4;i<N;i+=2) ara[i]=1;

            for(i=3;i<=sq;i+=2){

                if(ara[i]==0){

                                for(j=i*i ; j<=N ;j+=i) ara[j]=1;

                }

            }

            cin>>n;

            if(ara[n]==0) cout<<"Prime"<<endl;

            else cout<<"Not Prime"<<endl;

            return 0;

}
