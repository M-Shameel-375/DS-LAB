#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    int top;
    int capacity;
    char *array;

public:
    // Constructor
    Stack(int size = 100) : capacity(size), top(-1)
    {
        array = new char[capacity];
    }
    // Push an element onto the stack
    void push(const char dataItem)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        array[++top] = dataItem;
    }

    // Pop an element from the stack
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return array[top--];
    }
    // Check if the stack is empty
    bool isEmpty() const
    {
        return top == -1;
    }
};

// Function to reverse a string using a stack
string reverseString(const string &input)
{
    Stack stack(input.length());
    string result;

    // Push all characters onto the stack
    for (char c : input)
    {
        stack.push(c);
    }

    // Pop all characters to form the reversed string
    while (!stack.isEmpty())
    {
        result += stack.pop();
    }

    return result;
}

int main()
{
    string input = "Muhammad Shameel";
    cout << "\n\tOriginal String: " << input << endl;
    string reversed = reverseString(input);
    cout << "\n\tReversed String: " << reversed << endl<<endl;
    return 0;
}
