

#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 1000;
const int INF = 1e9;

vector <int> graph[ MAX_NODE ], reverseGreaph[ MAX_NODE ];
int node , edge ;
bool visit[ MAX_NODE ];

stack < int > topologicalList;


void clearGraph() /// To erase previous test case value
{
    for( int i = 0 ; i <= node ; i++ )
    {
        graph[i].clear();
        reverseGreaph[i].clear();
    }

    while(!topologicalList.empty()) topologicalList.pop();///Stak will be emty
}


void clearVisitedNodes()/// forword+Backwword BFS = 2 bfs; so when 1 bfs action will be
                       /// running at moment another bfs will be stop or clear
{
    for( int i = 0 ; i <= node ; i++ )
    {
        visit[i] = 0;
    }
}

void constructGraph(){

    cin >> node >> edge;
    clearGraph();
    for( int i = 0 ; i < edge ; i++ )
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); ///Forword BFS
        reverseGreaph[v].push_back(u);///Backword BFS according to main graph
    }
}


void dfsOnMainGraph(int node) ///Fordword Bfs
{
    visit[node] = true; /// node become true
    int sz = graph[node].size();///full graph size
    for( int i = 0 ; i < sz ; i++ )
    {
        int nextNode = graph[node][i];///which node become true it's all neighbear
        if( visit[nextNode] == false ) ///all neighbear will be visit if not visitted
            {
            dfsOnMainGraph(nextNode);///not visitted  neighbear again will be true or
                                     /// visit
        }
    }
    topologicalList.push(node);///visitted last to first will push in an stack
}

void dfsOnReverseGraph(int node)///Reverse BFS
{
    printf(" %d", node);
    visit[node] = true;
    int sz = reverseGreaph[node].size();
    for( int i = 0 ; i < sz ; i++ )
    {
        int nextNode = reverseGreaph[node][i];
        if( visit[nextNode] == false )/// neighbear  will be visit
        {
            dfsOnReverseGraph(nextNode);
        }
    }
}
int main()
{
    int cs, t;
    cin >> t;/// here 1= 1 time;
    for( cs = 1 ; cs <= t ; cs++ ) {

        constructGraph();
        clearVisitedNodes();
        for( int i = 1 ; i <= node ; i++ )/// to visit in Generel all node
        {
            if( visit[i] == false ) ///if not visited
            {
                dfsOnMainGraph(i);///visit ;so go to function
            }
        }
        clearVisitedNodes();
        int groupNumber = 1;/// group count
        while(!topologicalList.empty())///    topologicalList.push(node)==Stack base work
            {

            int node = topologicalList.top();///According to top element we will work
            topologicalList.pop();
            if( visit[node] == false ) ///if not visitted
                {

                printf("group number %d :", groupNumber);
                dfsOnReverseGraph(node);///Reverse DFS will be call
                groupNumber++;
                printf("\n");
            }

        }


    }


    return 0;
}

/*
1
8 14
2 1
1 5
5 2
6 2
6 5
3 2
3 4
4 3
6 7
7 6
7 3
8 7
8 4
8 8
*/


