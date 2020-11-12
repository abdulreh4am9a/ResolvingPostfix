#include"stack.h"
#include<string>
int power(int base, int exp) {
    int result = 1;
    while (exp != 0) {
        result *= base;
        exp--;
    }
    return result;
}
bool is_operator(char x) //simple function to check whether the character is an operator or not
{
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%');
}
int is_digit(char x) { //simple function to check whether the character is a digit and if it is digit returns its integer value else returns -1
    switch (x)
    {
    case '0':return 0;break;
    case '1':return 1;break;
    case '2':return 2;break;
    case '3':return 3;break;
    case '4':return 4;break;
    case '5':return 5;break;
    case '6':return 6;break;
    case '7':return 7;break;
    case '8':return 8;break;
    case '9':return 9;break;
    default:return -1;break;
    }
}
int postfixToResult(string postfix) { //function to evaluate the postfix notation
    int i = 0, n1, n2; //i for loop and n1 n2 to get two operands from stack
    stack<int> s; //stack to perform relevant operations
    while (postfix[i] != '\0') { //reading the string index by index until the null operator arrives
        if (is_digit(postfix[i]) != -1) { //using is_digit function to check whether a character is digit or not
            s.push(is_digit(postfix[i])); //if character is digit pushing its integer value to stack
        }
        else if (is_operator(postfix[i])) { //else if the character is operator poping out two operands from stack and performing that operator on them and again pushing them to stack
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
                s.push(power(n2,n1));
                break;
            default:
                break;
            }
        }
        i++;
    }
    return s.top(); //in the end the result is present in stack so returning it
}

int main(int argc, char* argv[])
{
    cout << "Postfix Notation: " << argv[1] << endl;
    cout << "Result: " << postfixToResult(argv[1]) << endl;
    return 0;
}