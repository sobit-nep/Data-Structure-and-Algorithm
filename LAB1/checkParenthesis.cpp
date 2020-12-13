#include <iostream>
#include <string>

using namespace std;

#define MAX 10

int check_bracket(std::string expression);

class Stack
{
    char bckt[MAX];
    int top=-1;
public:
    char push(char x)
    {
        if (top >= (MAX - 1))
        {
            cout << "\nOverflow!!";
            return -1;
        }
        else
        {
            top += 1;
            bckt[top] = x;
            return x;
        }
    }
    char pop()
    {
        if (top < 0)
        {
            cout<<"\nUnderflow!!";
            return -1;
        }
        else
        {
            return bckt[top--];
        }
    }
};

bool check_bckt(string alg_exp)
{
    Stack brackets;

    for (int i = 0; i < alg_exp.length(); i++)
    {
        char c = alg_exp[i];

        if (c == '(' or c == '{' or c == '[' )
        {
            brackets.push(c);
        }

        else if (c == ')' or c == '}' or c == ']' )
        {
            char bckt_in_stack;

            switch (c)
            {

            case ')':
                bckt_in_stack = brackets.pop();
                if (bckt_in_stack != '(')
                    return false;
                break;

            case '}':
                bckt_in_stack = brackets.pop();
                if (bckt_in_stack != '{')
                    return false;
                break;

            case ']':
                bckt_in_stack = brackets.pop();
                if (bckt_in_stack != '[')
                    return false;
                break;

            default:
                break;
            }
        }
        else
            continue;
    }
    return true;
}

int main()
{
    string expression;
    cout << "Enter an algebraic expression: ";
    cin>>expression;
    if (check_bckt(expression))
        cout << "\nExpression is valid.";
    else
        cout << "\nExpression is invalid.";
    return 0;
}
