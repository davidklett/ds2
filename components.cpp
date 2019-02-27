// David Klett
// Data Structures Project 1
// 2/26/2019
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;
using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::vector;

//Function prototypes:
list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x);
void printAdjList(vector<list<int>> adjList);
bool connComponent(const list<int>& a, const list<int>& b);
bool merge2(list<int> &a, list<int> &b);

int main()
{

  string fileName;
  //Prompt user for input for the file name
    cout << "Please enter the graph filename to process: ";
    cin >> fileName;
    cout << "The adjacency list for your graph is: " << endl;
    vector<list<int>> adjList;
    list<int> mtLst;  // an empty list

      string line;
      ifstream myfile (fileName); //use the user's input name for the file
      int countV = 0;

      if (myfile.is_open())
      {
        //Iterate through vector:
        while ( getline (myfile,line) )
        {
          adjList.push_back(mtLst);

                std::istringstream is( line );
                int x;
                //populating the linked-list
                while( is >> x ) {
                    std::list<int>::iterator gt_iter = find_gt(adjList[countV].begin(),adjList[countV].end(), x);
                    adjList[countV].insert(gt_iter, x);
                }

          countV++;
        }
        myfile.close();
      }

      else cout << "Can't access file";

    printAdjList(adjList);
    cout << endl;
    bool flag = 1;

    //Prompt user to merge the lists:
    do{

      cout << "Enter two list ids to potentially merge together or -1 to quit: ";
      int list1, list2;
      list1 = 0;
      list2 = 0;

      cin >> list1 >> list2;
      cout << endl;
      int temp1 = list1;
      int temp2 = list2;
      if((list1 != -1) || (list2 != -1)) //test if user wants to quit
      {
          if(merge2(adjList[list1], adjList[list2]))
          {
               list1 = temp1;
               list2 = temp2;
               if(adjList[list1].size() > adjList[list2].size())
               {
                   list2 = temp2;
                   adjList.erase(adjList.begin() + list2);
               }
               else
               {
                   list1 = temp1;
                   adjList.erase(adjList.begin() + list1);
               }
               cout << "The lists are merged.";
               printAdjList(adjList); //need to reorder the vector

          }else{

               cout << "The lists are not merged.";
               printAdjList(adjList);

               }

      }
      else
      {
          flag = 0;
      }

    }while(flag);

    return 0;
}
//Function definitions: ///////////////////////////////////////////////////////////

// find_gt function
list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop,int x)
{

  std::list<int>::iterator temp_iter;

  for(temp_iter = start; temp_iter != stop; ++temp_iter)
  {
        if(*temp_iter > x)
            return temp_iter;
  }

  return stop;

}

//print the adjacency list:
void printAdjList(vector<list<int>> adjList)
{
  int numRows = adjList.size();
  std::list<int>::iterator temp;
  for(int i = 0; i < numRows; i++)
  {
      cout << "list" << i << " ";
    for(temp = adjList[i].begin(); temp != adjList[i].end(); ++temp)
    {
      cout  << *temp << " ";
    }

    cout << endl;
  }
}

//boolean function, returns whether two lists contain a common node (same number)
bool connComponent(const list<int>& a, const list<int>& b)
{
      std::list<int>::iterator temp_iter1, temp_iter2;
      std::list<int> first;
      first.assign(a.begin(), a.end());
      std::list<int> second;
      second.assign(b.begin(), b.end());
      temp_iter2 = second.begin();
        for(temp_iter1 = first.begin(); temp_iter1 != first.end(); ++temp_iter1)
        {

            if(*temp_iter1 == *temp_iter2)
            {
              return true;
            }
            else
            {
              if(*temp_iter1 > *temp_iter2)
              {
                ++temp_iter2;
              }
              if(*temp_iter1 == *temp_iter2)
                return true;
            }
        }
    return false;
}

//merge two lists together
bool merge2(list<int> &a, list<int> &b)
{
    if(connComponent(a, b))
    {
        int size1 = a.size();
        int size2 = b.size();
        list<int> &greaterList = a;
        list<int> &lesserList = b;
        list<int>::iterator gtIter; //change from great to something else
        list<int>::iterator ltIter; //change from 'from' to something else

        //figure out which list to merge into
        if(size1 < size2)
        {
            greaterList = b; //used to be lesserList
            lesserList = a; //used to be greaterList
        }
        else
        {
            greaterList = a;
            lesserList = b;
        }

        for(ltIter = lesserList.begin(); ltIter != lesserList.end(); ++ltIter)
        {
            int base = *ltIter;
            gtIter = find_gt(greaterList.begin(), greaterList.end(), base);
            greaterList.insert(gtIter, base);
        }

        //make the merged list unique
        greaterList.unique();
        //Clear out old list
        lesserList.clear();
            return true;
    }
    else{
        return false;
    }

}
