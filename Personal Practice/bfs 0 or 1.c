
#include<bits/stdc++.h>

using namespace std;
const int MAX_NODE=1000;
vector<int> graph[MAX_NODE];
int edge,node,cost[MAX_NODE],visit[MAX_NODE],parent[MAX_NODE];
int costBetweenNodes[MAX_NODE][MAX_NODE];

void init(){
 for(int i=1;i<=node;i++)
 {

     cost[i]=visit[i]=0;
     graph[i].clear();


 }





}




int main(){


int cs,numberofTestcase;
cin>>numberofTestcase;
for(int cs=1;cs<=numberofTestcase;cs++){
    constructGraph();
    zeroOnebfs(1);
}
return 0;

}
