#include<bits/stdc++.h>
#define N 9999999

using namespace std;
int ara[N];

vector<int> p;

int main(){

            int i,n,j,x;

            memset(ara,0,sizeof(ara));

            ara[0]=ara[1]=1;

            for(i=4;i<N;i+=2) ara[i]=1;

            for(i=3;i*i<N;i+=1){

                    if(ara[i]==0) {

                                for(j=i*i;j<N;j+=i){

                                                ara[j]=1;

                                }
                    }
            }
            for(i=2;i<N;i++){

                    if(ara[i]==0) p.push_back(i);

            }

            cin>>n;

            for(i=0;i<p.size();i++){

                    while(n%p[i]==0){

                            n= n/p[i];

                            cout<<p[i]<<" ";

                    }
                    if(n==1) break;

            }

            if(n!=1) cout<<endl;
}
