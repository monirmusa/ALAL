
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 1000;
const int INF = 1e9;
//const int INF = 1e9;

vector <int> graph[ MAX_NODE ], cost[ MAX_NODE ];
int dist[ MAX_NODE ], node , edge ;
bool visit[ MAX_NODE ];



void ini()
{
     for( int i = 1 ; i <= node ; i++ )
    {
        visit[i] = 0;
        dist[ i ] = INF; ///dist/cost dea boro 1 ta value dea hoece,,,
        graph[i].clear();///graph o cost List ke khali kora doece...
        cost[i].clear();
    }
}

void constructGraph()
{

    cin >> node >> edge;
    ini();
    int x , y, c;
    for( int i = 0 ; i < edge ; i++ )
    {
       cin >> x >> y >> c;  ///3 ta input extra for cost
       graph[x].push_back(y);  ///a->b =5 |b->a=5.....
       graph[y].push_back(x);
       cost[x].push_back(c);
       cost[y].push_back(c);
    }


}

void dijkstra(int source)
{
    dist[source] = 0;///emn 1 ta node ber kora jar cost sobche com.dori sourcetae ta..
                   /// first ta muloto
    while( 1 )
    {
        int current_node = -1; ///to compare with 0 and -1===so -1 is small
                               ///we catch a previous value
        for( int i = 1 ; i <= node ; i++ )
        {
         if( visit[i] == 0 && ( current_node == -1 || dist[current_node] > dist[i]))
            {
                   current_node = i;   ///1.visit hoe nae+
                                       ///1_st time a curren node -1(d) or(||) current
                                       ///node gulor modde kar distance kom take ber
                                       ///kore (i)  current_node a rakha
            }
        }
        if( current_node == -1 ) break;  ///na paele break
        visit[current_node] = 1;     /// visit ke 1 kora
        int sz = graph[current_node].size();
        for( int i = 0 ; i < sz ; i++ )
        {
            int nxt = graph[current_node][i]; ///current node er sathe adjacency cheak kora
            if( visit[nxt] ) continue;    ///thakle continue ba skip kora
            int cc = cost[current_node][i];/// current node er cost ta assign kore rakhbe
            if( dist[nxt] > dist[current_node] + cc )
            {                                   ///(dist[current_node] + cc) ae man ta
                                                /// choto hole ..dist[nxt] totha dist.. a assign korbe
                dist[nxt] = dist[current_node] + cc;
            }
        }
    }

    for( int i = 1 ; i <= node ; i++ )
    {
        printf("from %d to %d:: minimum cost:: %d\n", source , i , dist[i] );
    }
}





int main()
{
    constructGraph();
    dijkstra(1);

    return 0;
}

/*
9 9
1 2 5
2 3 10
2 4 8
4 5 7
4 6 10
4 8 11
8 7 20
6 7 1
7 9 5


*/


