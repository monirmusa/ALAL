#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 1000;

vector <int> graph[ MAX_NODE ];
int edge, node, cost[ MAX_NODE ], visit[ MAX_NODE ], parent[ MAX_NODE ];
int costBetweenNodes[ MAX_NODE ][ MAX_NODE ];

void ini()
{
     for( int i = 1 ; i <= node ; i++ )
    {
        visit[i] = cost[i] = 0;
        graph[i].clear();
    }
}

void constructGraph()
{

    cin >> node >> edge;
    ini();
    int x , y;
    for( int i = 0 ; i < edge ; i++ )
    {
       cin >> x >> y;


       graph[x].push_back(y);
       graph[y].push_back(x);
    }


}


void bfs(int source)
{
    queue < int > q;
    q.push(source); ///D
    cost[source] = 0;
    visit[source] = 1;///visir array er man
    while( !q.empty() )
    {
        int current = q.front();///d
        q.pop();
        int sz = graph[current].size();///ekhon b dori...b=3...||kajta bujte
        for( int i = 0 ; i < sz ; i++ )
        {
            int nxt = graph[current][i];///b-d  | b-c |b-a
            if( visit[nxt] == 0 )  ///age visit hoe nae
            {                         ///a ke visit korbo
                visit[nxt] = 1;   ///visit suru korlam & array te 1 bosalam
                parent[ nxt ] = current;   ///current holo b(2) ae value ke Parent[nxt]
                                           ///te rakhlam ba current take sorae falaelam
                                           /// o parent a porinoto korlam
                cost[nxt] = cost[current] + 1;///cost er value 2+2=4 holo
                q.push(nxt);                 /// a ta push korlam queue te.
            }
        }
    }

    for( int i = 1 ; i <= node ; i++ )
    {
        printf("from %d to %d:: minimum cost:: %d\n", source , i , cost[i] );
    }


}

void bfsZerroOne(int source)
{
    deque < int > q;
    q.push_front(source);     ///G
    cost[source] = 0;
    visit[source] = 1;       ///visit hocce ba hoece
    while( !q.empty() ) {
        int current = q.front();      ///G in the front
        q.pop_front();
        visit[current] = 1;      ///visit hocce dori A
        int sz = graph[current].size(); ///a->G,B,D ba 3 ta ,so 3 bar loop gurbe
        for( int i = 0 ; i < sz ; i++ )
        {
            int nxt = graph[current][i];///1.a->b;   2.a->g;   3.a->d
            if( visit[nxt] == 0 )    ///a->b suru korlam
                                       /// a->b age visit hoe nae so 0;so if a dukbe
            {
                parent[ nxt ] = current;/// current holo a
                cost[nxt] = cost[current] + costBetweenNodes[current][nxt];
                   ///cost[nxt]= cost[a](5)+costBetweenNodes[a][b](2)===cost[nxt]=5+2=7


                if( costBetweenNodes[current][nxt] == 0 ) ///watch 1 example d->e
                {
                    q.push_front(nxt);
                }
                else
                {
                    q.push_back(nxt);
                }
            }
        }
    }
}

void print_road( int current_node, int source_node )
{
    if( current_node == source_node )
    {
        printf("%d", current_node );
        return;
    }
    print_road( parent[current_node] , source_node );
    printf(" - %d",current_node);
}

int main()
{
    int cs, numberOfTestCase;
    cin >> numberOfTestCase;
    for( cs = 1 ; cs <= numberOfTestCase ; cs++ ) {

        constructGraph();
        bfs(1);
    }

    return 0;
}

/*
9 9
1 2
2 3
2 4
4 5
4 6
4 8
8 7
6 7
7 9


*/


