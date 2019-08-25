#include<iostream>
#include<typeinfo>
using namespace std;
int main()
{
int a;
const char* ch = typeid(a).name();
if(*ch=='i')
a=10;
else
a=20;
cout << a << endl;
}
