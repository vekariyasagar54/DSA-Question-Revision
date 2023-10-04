Evaluation of Postfix

 
The Postfix notation is used to represent algebraic expressions. The expressions written in postfix form are evaluated faster compared to infix notation as parenthesis is not required in postfix. We have discussed infix to postfix conversion. In this post, the evaluation of postfix expressions is discussed.

 

Example: 

Input: str = "2 3 1 * + 9 -"
Output: -4
Explanation: 

Scan 2, it's a number, so push it to stack. Stack contains '2' 
Scan 3, again a number, push it to stack, stack now contains '2 3' (from bottom to top) 
Scan 1, again a number, push it to stack, stack now contains '2 3 1' 
Scan *, it's an operator, pop two operands from stack, apply the * operator on operands, we get 3*1 which results in 3. We push the result 3 to stack. The stack now becomes '2 3'. 
Scan +, it's an operator, pop two operands from stack, apply the + operator on operands, we get 3 + 2 which results in 5. We push the result 5 to stack. The stack now becomes '5'. 
Scan 9, it's a number, so we push it to the stack. The stack now becomes '5 9'. 
Scan -, it's an operator, pop two operands from stack, apply the - operator on operands, we get 5 - 9 which results in -4. We push the result -4 to the stack. The stack now becomes '-4'. 
There are no more elements to scan, we return the top element from the stack (which is the only element left in a stack).
Input: str = "100 200 + 2 / 5 * 7 +"
Output: 757

Evaluation of Postfix Expression Using Stack:
Follow the steps mentioned below to evaluate postfix expression using stack:

Create a stack to store operands (or values). 
Scan the given expression from left to right and do the following for every scanned element. 
If the element is a number, push it into the stack 
If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack 
When the expression is ended, the number in the stack is the final answer                                                                                                            
Below is the implementation of the above approach:


// C++ program to evaluate value of a postfix expression 
#include <iostream> 
#include <string.h> 

using namespace std;

// Stack type 
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

// Stack Operations 
struct Stack* createStack( unsigned capacity ) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 

    if (!stack) return NULL; 

    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 

    if (!stack->array) return NULL; 

    return stack; 
} 

int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 

char peek(struct Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 

char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 

void push(struct Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 


// The main function that returns value of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
    // Create a stack of capacity equal to expression size 
    struct Stack* stack = createStack(strlen(exp)); 
    int i; 

    // See if stack was created successfully 
    if (!stack) return -1; 

    // Scan all characters one by one 
    for (i = 0; exp[i]; ++i) 
    { 
        // If the scanned character is an operand (number here), 
        // push it to the stack. 
        if (isdigit(exp[i])) 
            push(stack, exp[i] - '0'); 

        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            switch (exp[i]) 
            { 
            case '+': push(stack, val2 + val1); break; 
            case '-': push(stack, val2 - val1); break; 
            case '*': push(stack, val2 * val1); break; 
            case '/': push(stack, val2/val1); break; 
            } 
        } 
    } 
    return pop(stack); 
} 

// Driver program to test above functions 
int main() 
{ 
    char exp[] = "231*+9-"; 
    cout<<"postfix evaluation: "<< evaluatePostfix(exp); 
    return 0; 
} 

Output
postfix evaluation: -4
Time Complexity: O(N) 
Auxiliary Space: O(N)

There are the following limitations of the above implementation. 
It supports only 4 binary operators '+', '*', '-' and '/'. It can be extended for more operators by adding more switch cases. 
The allowed operands are only single-digit operands. The program can be extended for multiple digits by adding a separator-like space between all elements (operators and operands) of the given expression. 
Below given is the extended program which allows operands to have multiple digits. 


// C++ program to evaluate value of a postfix 
// expression having multiple digit operands 
#include <bits/stdc++.h>
using namespace std;

// Stack type 
class Stack 
{ 
    public:
    int top; 
    unsigned capacity; 
    int* array; 
}; 

// Stack Operations 
Stack* createStack( unsigned capacity ) 
{ 
    Stack* stack = new Stack();

    if (!stack) return NULL; 

    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = new int[(stack->capacity * sizeof(int))]; 

    if (!stack->array) return NULL; 

    return stack; 
} 

int isEmpty(Stack* stack) 
{ 
    return stack->top == -1 ; 
} 

int peek(Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 

int pop(Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 

void push(Stack* stack,int op) 
{ 
    stack->array[++stack->top] = op; 
} 


// The main function that returns value 
// of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
    // Create a stack of capacity equal to expression size 
    Stack* stack = createStack(strlen(exp)); 
    int i; 

    // See if stack was created successfully 
    if (!stack) return -1; 

    // Scan all characters one by one 
    for (i = 0; exp[i]; ++i) 
    { 
        //if the character is blank space then continue 
        if(exp[i] == ' ')continue; 
        
        // If the scanned character is an 
        // operand (number here),extract the full number 
        // Push it to the stack. 
        else if (isdigit(exp[i])) 
        { 
            int num=0; 
            
            //extract full number 
            while(isdigit(exp[i])) 
            { 
            num = num * 10 + (int)(exp[i] - '0'); 
                i++; 
            } 
            i--; 
            
            //push the element in the stack 
            push(stack,num); 
        } 
        
        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            
            switch (exp[i]) 
            { 
            case '+': push(stack, val2 + val1); break; 
            case '-': push(stack, val2 - val1); break; 
            case '*': push(stack, val2 * val1); break; 
            case '/': push(stack, val2/val1); break; 
            
            } 
        } 
    } 
    return pop(stack); 
} 

// Driver code
int main() 
{ 
    char exp[] = "100 200 + 2 / 5 * 7 +"; 
    cout << evaluatePostfix(exp); 
    return 0; 
} 

Output
757
Time Complexity: O(N) 
Auxiliary Space: O(N)
