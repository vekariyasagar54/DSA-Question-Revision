Evaluation of Prefix

In this article, we will discuss how to evaluate an expression written in prefix notation. The method is similar to evaluating a postfix expression. Please read Evaluation of Postfix Expression article to know how to evaluate postfix expressions

Algorithm:

EVALUATE_PREFIX(STRING)
Step 1: Put a pointer P at the end of the end
Step 2: If character at P is an operand push it to Stack
Step 3: If the character at P is an operator pop two 
        elements from the Stack. Operate on these elements
        according to the operator, and push the result 
        back to the Stack
Step 4: Decrement P by 1 and go to Step 2 as long as there
        are characters left to be scanned in the expression.
Step 5: The Result is stored at the top of the Stack, 
        return it
Step 6: End
Example to demonstrate working of the algorithm  

Expression: +9*26

Character | Stack       |  Explanation
Scanned   | (Front to   |
          |  Back)      | 
-------------------------------------------
6           6             6 is an operand, 
                            push to Stack
2           6 2           2 is an operand, 
                            push to Stack
*           12 (6*2)      * is an operator, 
                          pop 6 and 2, multiply 
                          them and push result 
                          to Stack 
9           12 9          9 is an operand, push 
                          to Stack
+           21 (12+9)     + is an operator, pop
                          12 and 9 add them and
                          push result to Stack

Result: 21
Examples:  

Input : -+8/632
Output : 8

Input : -+7*45+20
Output : 25
Complexity The algorithm has linear complexity since we scan the expression once and perform at most O(N) push and pop operations which take constant time.
Implementation of the algorithm is given below.  

Implementation:


// C++ program to evaluate a prefix expression.
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
    // If the character is a digit then it must
    // be an operand
    return isdigit(c);
}

double evaluatePrefix(string exprsn)
{
    stack<double> Stack;

    for (int j = exprsn.size() - 1; j >= 0; j--) {

        // Push operand to Stack
        // To convert exprsn[j] to digit subtract
        // '0' from exprsn[j].
        if (isOperand(exprsn[j]))
            Stack.push(exprsn[j] - '0');

        else {

            // Operator encountered
            // Pop two elements from Stack
            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();

            // Use switch case to operate on o1
            // and o2 and perform o1 O o2.
            switch (exprsn[j]) {
            case '+':
                Stack.push(o1 + o2);
                break;
            case '-':
                Stack.push(o1 - o2);
                break;
            case '*':
                Stack.push(o1 * o2);
                break;
            case '/':
                Stack.push(o1 / o2);
                break;
            }
        }
    }

    return Stack.top();
}

// Driver code
int main()
{
    string exprsn = "+9*26";
    cout << evaluatePrefix(exprsn) << endl;
    return 0;
}

Output
21
Note: 
To perform more types of operations only the switch case table needs to be modified. This implementation works only for single digit operands. Multi-digit operands can be implemented if some character-like space is used to separate the operands and operators.

Below given is the extended program which allows operands to have multiple digits.

// C++ program to evaluate a prefix expression.
#include <bits/stdc++.h>
using namespace std;

double evaluatePrefix(string exprsn)
{
    stack<double> Stack;

    for (int j = exprsn.size() - 1; j >= 0; j--) {
      
        // if jth character is the delimiter ( which is
        // space in this case) then skip it
        if (exprsn[j] == ' ')
            continue;

        // Push operand to Stack
        // To convert exprsn[j] to digit subtract
        // '0' from exprsn[j].
        if (isdigit(exprsn[j])) {
          
            // there may be more than 
            // one digits in a number
            double num = 0, i = j;
            while (j < exprsn.size() && isdigit(exprsn[j]))
                j--;
            j++;

            // from [j, i] exprsn contains a number
            for (int k = j; k <= i; k++)
                num = num * 10 + double(exprsn[k] - '0');

            Stack.push(num);
        }
        else {

            // Operator encountered
            // Pop two elements from Stack
            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();

            // Use switch case to operate on o1
            // and o2 and perform o1 O o2.
            switch (exprsn[j]) {
            case '+':
                Stack.push(o1 + o2);
                break;
            case '-':
                Stack.push(o1 - o2);
                break;
            case '*':
                Stack.push(o1 * o2);
                break;
            case '/':
                Stack.push(o1 / o2);
                break;
            }
        }
    }

    return Stack.top();
}

// Driver code
int main()
{
    string exprsn = "+ 9 * 12 6";
    cout << evaluatePrefix(exprsn) << endl;
    return 0;

   
}

Output
81
Time Complexity: O(n)
Space Complexity: O(n)
