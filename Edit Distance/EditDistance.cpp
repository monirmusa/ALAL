
#include<bits/stdc++.h>
using namespace std;
const int SZ=1000;

string A,B;
int dp[SZ][SZ];

void input(){
cin>>A>>B;

}
void LCS(){

int szA=A.size();
int szB=B.size();
for(int i=1;i<=szA;i++) dp[i][0]=i;
for(int j=1;j<=szB;j++) dp[0][j]=j;

for(int i=1;i<=szA;i++){

    for(int j=1;j<=szB;j++){

        if(A[i-1]==B[j-1]){
            dp[i][j]=dp[i-1][j-1];
        }
        else{

            dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
        }
    }

}
 printf("maximum lcs length :: %d\n", dp[szA][szB]);

}
int main()
{
    input();
    LCS();
}
