

#include <bits/stdc++.h>

using namespace std;


const int NX = 1000;


vector < pair < int , int > > classTime;

 int numberOfClass;


 bool cmp( pair<int , int> a , pair<int, int> b )
 {
     if( a.first == b.first) return a.second < b.second;
     else return a.first < b.first;
 }

 void ini()
 {
     classTime.clear();
 }


 void input()
 {
     cin >> numberOfClass;
     ini();
     for( int i = 0 ; i < numberOfClass ; i++ )
     {
         int st, ed;
         cin >> st >> ed ;
         classTime.push_back(make_pair(st, -1));
         classTime.push_back(make_pair(ed, -2));
     }
 }

int main()
{
    int cs , testCase;
    cin >> testCase;
    for( cs = 1 ; cs <= testCase ; cs++ )
    {
        input();
        sort(classTime.begin(), classTime.end(), cmp);
        int sz = classTime.size();
        int cnt = 0 , maxClass = 0;
        for( int i = 0 ; i < sz ; i++ )
        {
            if( classTime[i].second == -2 ) cnt--;
            else cnt++;
            maxClass = max( maxClass , cnt );
        }

        printf("Minimum classRoom needed :: %d\n", maxClass);



    }
}
