#include <iostream>
#include "set.h"
#define VMAX 10000 
using namespace std;

int main()
{
    Set <int> P = Set <int> (VMAX);
    Set <int> Q = Set <int> (VMAX);

    cout<<P.empty()<<"\n";
    P.insert(5);
    cout<<P.empty()<<"\n";
    P.insert((1<<8)+6);
    P.insert(3);

    cout<<P.find(4)<<"\n";
    cout<<P.find(3)<<"\n";
    P.erase(3);
    cout<<P.find(258)<<"\n";


    cout<<P.size()<<"\n";

    cout<<P.empty()<<"\n";

    cout<<P.begin()<<"\n";
    cout<<P.end()<<"\n";

    Q = P;
    cout<<"-------------------------\n";
    cout<<Q.find(5)<<"\n";
    cout<<Q.find(4)<<"\n";

    return 0;
}
