#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 1000;

vector <int> graph[ MAX_NODE ];
int low[ MAX_NODE ], discover[ MAX_NODE ], visit[ MAX_NODE ], node, edge, discover_time;
int isArticulationPoint[ MAX_NODE ];


void ini()
{
    for( int i = 0 ; i <= node ; i++ )
    {
        graph[i].clear();
        visit[i] = 0;
        isArticulationPoint[i] = 0;
    }
    discover_time = 1;
}

void constructGraph(){

    cin >> node >> edge;
    ini();
    for( int i = 0 ; i < edge ; i++ )
    {
        int u , v;
        cin >> u >> v;
         graph[u].push_back(v);
        graph[v].push_back(u);
    }

}

void dfs( int node, int parnt ) { ///without roo other node will call by actual time
                                 /// so this process will be bellow
    low[node] = discover[node] = discover_time++;
                              ///void ini() in discover_time = 1;so all value for first
                              ///node is 1
    visit[node] = 1;   ///this |^ node is visitting
    int sz = graph[node].size();///this |^ nodes neighbour size count
    int child = 0;   /// initially child is =0;gaes there is no child if is not neighbour
    for( int i = 0 ; i < sz; i++ ) {

        int nextNode = graph[node][i];
        if( parnt == nextNode ) continue;///if parent and nextNode is same so skip this node
        if( visit[nextNode] == 0 ) {
                   /// Forword adge connection so child update
            child++;
            dfs(nextNode, node );///again call to dfs and neighbour check
            low[node] = min( low[node] , low[nextNode]);///low time will be update between
                                                         /// current and nextNode  by minimum value

            // root node condition
            if( parnt == -1 && child > 1 ) { ///if paren -1 and it has minimum 2 child or neighbour
                isArticulationPoint[node] = 1;  ///(1 no low)

            } else if( parnt != -1 && low[nextNode] >= discover[node]) {
                                     /// ///(2 no low)
                isArticulationPoint[node] = 1;
            }

        } else {
              /// Backword adge connection so low time update
            low[node] = min( low[node], discover[nextNode] );
        }

    }
}



int main()
{
    int cs, numberOfTestCase;
    cin >> numberOfTestCase;
    for( cs = 1 ; cs <= numberOfTestCase ; cs++ ) {

        constructGraph();
        for( int i = 1 ; i <= node ; i++ )
        {
            if( visit[i] == 0 ) dfs( i , -1 );///initial time= an unvisitted node
                            ///will be root ,root note can be many;
                            ///if parent is -1 then it is root node
        }

        printf(" Articulation points ::");
        for( int i = 1; i <= node ; i++ )
        {
            if( isArticulationPoint[i] == 1 )
            {
                printf(" %d",i);
            }
        }
        printf("\n");

    }

    return 0;
}

/*

1
10 13
1 2
1 6
3 7
2 7
6 7
7 8
7 9
9 8
3 8
8 4
4 5
8 5
8 10

*/


