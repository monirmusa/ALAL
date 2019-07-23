#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
//
const int MAX_NODE=1000;
const int INF=1e9;

vector<int> graph[MAX_NODE],cost[MAX_NODE];
int dist[MAX_NODE],node,edge;
bool visit[MAX_NODE];

void init(){
for(int i=1;i<=node;i++){

    visit[i]=0;
    dist[i]=INF;
    graph[i].clear();
    cost[i].clear();
    }
}



void constractGraph(){
cin>>node>>edge;
init();
int x,y,c;
for(int i=0;i<edge;i++){
    cin>>x>>y>>c;
    graph[x].push_back(y);
    graph[y].push_back(x);
    cost[x].push_back(c);
    cost[y].push_back(c);


    }

}


void belmenford(int source){

dist[source]=0;
for(int step=1;step<node;step++){

    for(int i=1;i<=node;i++){
        int sz=graph[i].size();
        for(int j=0;j<sz;j++){
            int nxtNode=graph[i][j];
            int nxtCost=dist[i]+cost[i][j];
            if(dist[nxtNode]>nxtCost){
               dist[nxtNode]=nxtCost;
            }
        }
    }
}


int negCycle=0;
for(int i=1;i<=node;i++){
        int sz=graph[i].size();
        for(int j=1;j<=sz;j++){
            int nxtNode=graph[i][j];
            int nxtCost=dist[i]+cost[i][j];
            if(dist[nxtNode]>nxtCost){
              negCycle=1;
            }
        }
    }

if(negCycle){
    printf("has a negative cycle\n");
    return;
}

    for( int i = 1 ; i <= node ; i++ )
    {
        printf("from %d to %d:: minimum cost:: %d\n", source , i , dist[i] );
    }

}




int main(){
int cs,t;
cin>>t;
for(cs=1;cs<=t;cs++){
    constractGraph();
    belmenford(1);
}
return 0;

}
