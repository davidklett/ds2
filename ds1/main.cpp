#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int
x );
int main()
{
    vector<list <int> > adjList;
    list<int> mtLst;  // an empty list

    for (int i=0; i<4; ++i)
    {
        adjList.push_back(mtLst); // push an empty list onto the adjList
        for (int j=0; j<=i; ++j)
            adjList[i].push_back(j);  // populate the list just pushed onto the vector

    }

    cout << *find_gt(adjList[3].begin(), adjList[3].end(), 5);

    return 0;
}

list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int
x )
{
    return stop;
}
