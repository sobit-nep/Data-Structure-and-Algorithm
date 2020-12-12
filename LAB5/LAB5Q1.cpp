//LAB5Q1
#include<iostream>
using namespace std;
long int factorial(int);
int main()
{

int num;
cout<<"Enter a number factorial of which is required:";
cin>>num;
cout<<num<<"!="<<factorial(num);
return 0;
}
long int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return(n*factorial(n-1));
}

