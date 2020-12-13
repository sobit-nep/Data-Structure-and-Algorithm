#include<iostream>
#include<string>
#define MAX 20
using namespace std;
void reverseStr(string& str)
{
    int n = str.length();
    for(int i=0; i<n; i++)
    {
        if(str[i]=='(')
        {
            str[i] = ')';
        }
        else if(str[i] == ')')
        {
            str[i] ='(';
        }
    }
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }
}
class stack
{
    char data[MAX];
    int top = -1;
public:
    void push(char oprtr)
    {
        if(top == MAX-1)
        {
            cout<<"\nStack is full!!\n";
        }
        else
        {
            top++;
            data[top]=oprtr;
        }

    }

    char pop()
    {
        char oprtr;
        if(top == -1)
        {
            cout<<"\nStack is empty!!\n";
            return '\0';
        }
        else
        {
            oprtr = data[top];
            data[top]='\0';
            top--;
            return oprtr;
        }
    }

    int priority( char oprtr)
    {
        if(oprtr == '+' || oprtr == '-')
            {
                return 1;
            }

        if(oprtr == '*' || oprtr == '/')
            {
                return 2;
            }

        if(oprtr == '$')
            {
                return 3;
            }

        return 0;
    }

    string convert(string infix)
    {
        int i=0;
        int j;
        string prefix = "";
        while(infix[i]!='\0')
        {
            if(infix[i] >= 'a'&&infix[i] <= 'z' || infix[i] >= 'A' && infix[i]<='Z')
            {
                prefix += infix[i];
                i++;
            }
            else if(infix[i] == '(')
            {
                push(infix[i]);
                i++;
            }
            else if(infix[i] == ')')
            {
                while(data[top] != '(')
                {
                    prefix += pop();
                }
                pop();
                i++;
            }
            else
            {
                if(top == -1)
                {
                    push(infix[i]);
                    i++;
                }

                else if(priority(infix[i]) < priority(data[top]))
                {
                    prefix += pop();
                    if(top <1)
                    {
                        break;
                    }
                    push(infix[i]);
                    i++;
                }

                else if(priority(infix[i]) >= priority(data[top]))
                {
                    if(top < 0)
                    {
                        break;
                    }
                    if(infix[i] == '$' && data[top] == '$')
                    {
                        prefix += pop();
                    }
                    push(infix[i]);
                    i++;
                }
            }
        }
        while(top != -1)
        {
            prefix += pop();
        }
        return prefix;
    }
};

int main()
{
    stack stack1;
    string infix, prefix;
    cout<<"\nEnter the infix expression; ";
    cin>>infix;
    reverseStr(infix);
    prefix = stack1.convert(infix);
    reverseStr(prefix);
    cout<<"\n The corresponding prefix expression is: "<<prefix<<endl;
    return 0;
}
