//LAB5Q4
#include<iostream>
using namespace std;

int gcd(int u, int v)
{
    return(v!=0)? gcd(v,u%v):u;
}

int main()
{
    int num1,num2,result;
    cout<<"Enter the numbers to find GCD :";
    cin>>num1>>num2;
    result=gcd(num1,num2);
    if(gcd)

        cout<<"\The GCD of "<< num1 <<" and "<< num2<<" is:"<<result;
        else
            cout<<"\nInvalid input!!!";
        return 0;

}
