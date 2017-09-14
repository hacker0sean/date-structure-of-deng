#include<iostream>
using namespace std;
int countOnes(unsigned int n);
int main()
{
    cout<<countOnes(441);
    return 0;
}

int countOnes(unsigned int n)
{
    int ones=0;
    while(n>0)
    {
        ones+=(1&n);
        n>>=1;
    }
    return ones;
}
