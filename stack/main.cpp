#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    std::stack <int> myStack;
    myStack.push(15);
    myStack.push(20);
    std::cout << myStack.size();

    myStack.top() += 10; //adds 10 to the top of the stack
    myStack.pop();
    std::cout << myStack.size();

    std::vector <int> myV;
    myV.push_back(12);

    return 0;
}
