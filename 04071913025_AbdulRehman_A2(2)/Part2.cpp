#include"stack.h"
#include<string>
bool is_operator(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%');
}
int postfixToResult(string postfix) {
    int i = 0, n1, n2;
    stack<int> s;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            s.push(postfix[i] - 48);
        }
        else if (is_operator(postfix[i])) {
            n1 = s.top();
            s.pop();
            n2 = s.top();
            s.pop();
            switch (postfix[i])
            {
            case '+':
                s.push(n2 + n1);
                break;
            case '-':
                s.push(n2 - n1);
                break;
            case '*':
                s.push(n2 * n1);
                break;
            case '/':
                s.push(n2 / n1);
                break;
            case '%':
                s.push(n2 % n1);
                break;
            case '^':
                s.push(n2 ^ n1);
                break;
            default:
                break;
            }
        }
        i++;
    }
    return s.top();
}

int main(int argc, char* argv[])
{
    cout << "Postfix Notation: " << argv[1] << endl;
    cout << "Result: " << postfixToResult(argv[1]) << endl;
    return 0;
}