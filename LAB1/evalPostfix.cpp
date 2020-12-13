#include<iostream>
#include<cmath>
#include<cstring>
#define N 10
using namespace std;
template<class T>
class stack
{
    T data[N];
    int top= -1;
public:
    void push(T x)
    {
        if (top >= N-1)
        {
            cout<<"Stack Overflow!!! Error in expression.\n";
            exit(0);
        }
        else
        {
            top++;
            data[top]=x;
        }
    }
    T pop()
    {
        if (top <= -1)
        {
            cout<<"\nStack Underflow!! Error in expression";
            exit(0);
        }
        else
        {
            return data[top--];
        }
    }
};

bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '$')
        return true;
    else
        return false;
}

float calculate(float a, float b, char c)
{
    if(c == '+')
        return a+b;
    else if(c == '-')
        return b-a;
    else if(c == '*')
        return a*b;
    else if(c == '/')
        return b/a;
    else if(c == '$')
        return pow(b,a);
    else
        return -1;
}

float postfix_evaluation(string& postfix)
{
    int i;
    int l= postfix.length();
    float a,b;
    stack<float>stackobj;
    string holder = "";

    for(i=0;i<=l-1;i++)
    {
        if(isOperator(postfix[i]))
        {
            a=stackobj.pop();
            b=stackobj.pop();
            float val = calculate(a,b,postfix[i]);
            stackobj.push(val);
            holder = "";
            i++;
        }
        else
        {
            if(postfix[i] != '_')
            {
                holder += postfix[i];
            }
            else
            {
                stackobj.push(stof(holder));
                holder = "";
            }
        }
    };
    return stackobj.pop();
}

int main()
{
    string postfix;
    float answer;
    cout<<"\nEnter the postfix expression(Use'_'to separate term): \n";
    cin>>postfix;
    answer = postfix_evaluation(postfix);
    cout<<"\nThe result : "<<answer;
    return 0;
}
