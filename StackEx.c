/*******************************************************
* To process N queries, where each query is one of the *
*                  following 3 types:                  *
*                                                      *
*   1 x: Push element x into the stack.                *
*   2: Delete  the element at the top of the stack.    *
*   3: Print the maximum element in the stack.         *
*                                                      *
*******************************************************/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXSIZE 100000
 
struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK elems;
STACK mElem;
 
void push();
int pop();
int show();

int main() {

    int n=0, i=0, queryN=0;
    
    elems.stk[elems.top] = -1;

    scanf("%d",&n);

    while (i<n)
    {
        scanf("%d",&queryN);
        if(queryN==1){
            push();
        }else if(queryN==2){
            pop();
        }else if(queryN==3){
            show();
        }else
            printf("wrong query option\n");
        i++;
    }
    return 0;
}

// To add an element to the top of the stack
void push ()
{
    int num; 
    if (elems.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        scanf ("%d", &num);
        elems.top = elems.top + 1;
        elems.stk[elems.top] = num;
		//to keep record of the highest value
        if(elems.stk[elems.top] >= mElem.stk[mElem.top]){
            mElem.top = mElem.top + 1;
            mElem.stk[mElem.top] = num;
        }
    }
    return;
}

// To delete an element from the top of the stack 
int pop ()
{
    int num;
    if (elems.top == - 1)
    {
        printf ("Stack is Empty\n");
        return (elems.top);
    }
    else
    {
        num = elems.stk[elems.top];
        if(elems.stk[elems.top] == mElem.stk[mElem.top]){
            num = mElem.stk[mElem.top];
            mElem.top = mElem.top - 1;
        }
        elems.top = elems.top - 1;
    }
    return(num);
}

//shows the max element
int show()
{
    int num;
    num = mElem.stk[mElem.top];
    printf ("%d\n", num);
    return(num);
}