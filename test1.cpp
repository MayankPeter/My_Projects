#include<iomanip>
#include<iostream>
using namespace std;
int main()
 {
    int ar[] = {5, 11, 5923, 781};
    for (auto ele : ar) 
{
        cout << std::setfill(' ') << std::setw(4) << ele << endl; 
}
}
