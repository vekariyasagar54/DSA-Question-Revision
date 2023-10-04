Infix to Postfix

Write a program to Convert Infix expression to Postfix.

Infix expression: The expression of the form a operator b (a + b). When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b operator (ab+). When an operator is followed by every pair of operands.

Examples:

Input: A + B * C + D
Output: ABC*+D+

Input: ((A + B) - C * (D / E)) + F
Output: AB+CDE/*-F+  

 

Why postfix representation of the expression? 
The compiler scans the expression either from left to right or from right to left. 
Consider the expression: a + b * c + d

The compiler first scans the expression to evaluate the expression b * c, then again scans the expression to add a to it. The result is then added to d after another scan. The repeated scanning makes it very inefficient and Infix expressions are easily readable and solvable by humans whereas the computer cannot differentiate the operators and parenthesis easily so, it is better to convert the expression to postfix(or prefix) form before evaluation.
The corresponding expression in postfix form is abc*+d+. The postfix expressions can be evaluated easily using a stack. 

 

Steps to convert Infix expression to Postfix expression using Stack:
Scan the infix expression from left to right. 
If the scanned character is an operand, output it. 
Else, 
If the precedence and associativity of the scanned operator are greater than the precedence and associativity of the operator in the stack(or the stack is empty or the stack contains a '(' ), then push it.
'^' operator is right associative and other operators like '+','-','*' and '/' are left-associative. Check especially for a condition when both,  operator at the top of the stack and the scanned operator are '^'. In this condition, the precedence of the scanned operator is higher due to its right associativity. So it will be pushed into the operator stack. In all the other cases when the top of the operator stack is the same as the scanned operator, then pop the operator from the stack because of left associativity due to which the scanned operator has less precedence. 
Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
If the scanned character is an ‘(‘, push it to the stack. 
If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
Repeat steps 2-6 until the infix expression is scanned. 
Print the output 
Pop and output from the stack until it is not empty.
Below is the implementation of the above algorithm: 

/* C++ implementation to convert
infix expression to postfix*/

#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s)
{

    stack<char> st; // For stack operations, we are using
                    // C++ built in stack
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else {
            while (!st.empty()
                   && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

// Driver's code
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";

    // Function call
    infixToPostfix(exp);
    return 0;
}

Output
abcd^e-fgh*+^*+i-
Time Complexity: O(N), where N is the size of the infix expression
Auxiliary Space: O(N)
