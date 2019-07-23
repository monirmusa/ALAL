
#include<bits/stdc++.h>

using namespace std
const int MAX_NODE=1000;

vector <int> graph[MAX_NODE];
int edge,node,cost[MAX_NODE],visit[MAX_NODE],parent[MAX_NODE];
int costBetweenNodes[MAX_NODE][MAX_NODE];

void init(){
 for(int i=1;i<=node;i++)
 {

     cost[i]=visit[i]=0;
     graph[i].clear();
 }

}
void constructGraph(){

cin>> node>>edge;
ini();
int x,y;
for(int i=1;i<edge;i++){

        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
        }
}

void zeroOnebfs(int source){

    deque<int> q;
    q.push_front(source);
    cost[source]=0;
    visit[source]=1;
    while(!q.empty()){

        int current=q.front();
        q.pop_front();
        int sz=graph[current].size();

        for(int i=0;i<sz;i++)
        {
        int nxt=graph[current][i];
        if(visit[nxt]==0)
        {

            parent[nxt]=current;
            cost[nxt]=cost[current]+costBetweenNodes[current][nxt];




            if(costBetweenNodes[current][nxt]==0)
            {
                    push_front(nxt);
            }
            else{
                    push_back(nxt)

            }

        }

    }
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
