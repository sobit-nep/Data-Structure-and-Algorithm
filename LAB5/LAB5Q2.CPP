//LAB5Q2
#include<iostream>
using namespace std;
int fibonacci(int);
int main()
{
    int num;
    cout<<"Enter the number  of terms(Fibonacci series):";
    cin>>num;
    cout<<"Fibonacci series upto "<<num<<" terms:";
    for(int i=0;i<num;i++)
    {
    cout<<"\t"<<fibonacci(i);
    }
    return 0;
}
int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return(fibonacci(n-1)+fibonacci(n-2));
}
