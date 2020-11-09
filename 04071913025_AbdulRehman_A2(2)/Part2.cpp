#include<iostream>
#include<string>
using namespace std;
template<typename T>
struct node {
    T data;
    node<T>* next;
};
template<typename T>
class stack {
    node<T>* top_ptr;
public:
    stack() {
        top_ptr = NULL;
    }
    ~stack() {
        make_empty();
    }
    void push(const T& val) {
        node<T>* temp;
        temp = new node<T>;
        temp->data = val;
        temp->next = top_ptr;
        top_ptr = temp;
    }
    void pop() {
        node<T>* temp;
        temp = top_ptr;
        top_ptr = top_ptr->next;
        delete temp;
    }
    T top() const {
        return top_ptr->data;
    }
    bool empty() const {
        return top_ptr == NULL;
    }
    bool full() const {
        node<T>* temp;
        temp = new node<T>;
        if (temp == NULL)
            return true;
        else {
            delete temp;
            return false;
        }
    }
    void make_empty() {
        while (!empty()) {
            pop();
        }
    }
};
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