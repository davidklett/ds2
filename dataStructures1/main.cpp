// demonstrates iterator usage with lists
// Modified code of Mikhail Nesterenko that iterates through vectors to
// work for lists
// Modified by Dianne Foreback 9/2018

#include <iostream>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;
using std:: endl;
using std::list;

// demo using constant list
void printList( const list<int> & aList )
{
    // for(list<int>::iterator ip=aList.begin();  will not work, const list requires const_iterator
    for(list<int>::const_iterator ip=aList.begin();
            ip != aList.end(); ++ip)
    {
        cout << *ip << " ";
    }
    cout << endl;
}

//another way to print a list
void printList2( list<int> & aList )
{
    list<int>::iterator itr = aList.begin( );
    while( itr !=aList.end( ) )
        cout << *itr++ << " ";
    cout << endl;
}

// demo using constant iterators
void printList3(  list<int>::const_iterator start,  list<int>::const_iterator stop )
{
    while( start != stop )
        cout << *start++ << " ";
    cout << endl;

}

list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x );


int main()
{
    list<int> lst;

    //vector of integer lists called adjList for adjacency list
    vector <list<int>> adjList;

    // inputing the numbers
    cout << "Enter numbers, 0 to quit: ";
    int num;
    cin >> num;
    while(num!=0)
    {
        list<int>::iterator ip=lst.end();
        lst.insert(ip,num);
        cin >> num;
    }
    cout << "Your numbers are: ";
    printList(lst);

    // output your number plus 5 but not done correctly
    cout << "Your numbers plus 5 are: ";
    for(list<int>::iterator ip=lst.begin();
            ip != lst.end(); ++ip)
    {
        cout << (*ip+5) << " ";
    }
    cout << endl;

    // demo function template that prints any container - see printContainer.h
    cout << "Your numbers plus 5 are not saved.  Using function template in printContainer.h to print. " << endl;
    cout << "Stored in the list are: ";
    print(lst);

    cout << "Your numbers plus 5 are now saved.  Stored in the list are: ";
    for(list<int>::iterator ip=lst.begin();
            ip != lst.end(); ++ip)
    {
        *ip = *ip + 5;
        cout << *ip << " ";
    }
    cout << endl;

    // inserting a new element after 3d element
    // don't go out of bounds
    if (lst.size() > 3)  // check if there are at least three elements in the vector
    {
        //list<int>::iterator toAdd = lst.begin()+3; // making toAdd point to 3d element- cannot do on a list but you can on a vector
        // with iterator arithmetic
        list<int>::iterator toAdd = lst.begin();
        for (int i = 0; i < 3; ++i)
            ++toAdd;
        lst.insert(toAdd,100); //inserting 100
    }
    cout << "List after inserting a new third element: ";
    printList3(lst.begin(), lst.end());


    // removing the minimum element
    // initially, assume the first element is smallest
    list<int>::iterator toRemove=lst.begin();

    // start with the second element and iterate
    for(list<int>::iterator ip=++(lst.begin()); ip != lst.end(); ++ip)
    {
        if(*toRemove > *ip) // found smaller element
            toRemove=ip;
    }
    lst.erase(toRemove); // removing the element to which toRemove points

    cout << "List after removing smallest element: ";
    printList(lst);


    lst.sort();   // sorting list elements
    cout << "List after sorting: ";
    printList(lst);

    // remove all elements from the list
    lst.erase(lst.begin(), lst.end());
    cout << "List after removing all elements";
    printList(lst);
}

list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x )
{
    return start;
}

