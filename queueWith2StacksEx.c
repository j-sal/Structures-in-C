/*******************************************************
* To process N queries, where each query is one of the *
*                  following 3 types:                  *
*                                                      *
* 1 x: Enqueue element x into the end of the queue.    *
* 2: Dequeue the element at the front of the queue.    *
* 3: Print the element at the front of the queue.      *
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
STACK fStk;
STACK rStk;

void enq();
int deq();
int show();

int main() {

   int n=0, i=0, queryN=0;

    fStk.stk[fStk.top] = -1;
    rStk.stk[rStk.top] = -1;
    fStk.top = -1;
    rStk.top = -1;

    scanf("%d",&n);

    while (i<n)
    {
        scanf("%d",&queryN);
        if(queryN==1){
            enq();
        }else if(queryN==2){
            deq();
        }else if(queryN==3){
            show();
        }else
            printf("wrong query option\n");
        i++;
    }
    return 0;
}
void enq ()
{
    int num; 
    if (fStk.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        scanf ("%d", &num);
        fStk.top = fStk.top + 1;
        fStk.stk[fStk.top] = num;
    }
    return;
}
/*  Function to delete an element from the stack */
int deq ()
{
    int num,i;
    if (fStk.top == 0)
    {
        //delete first elem
        num = fStk.stk[fStk.top];
        fStk.top = fStk.top - 1;
    }
    else
    {
        i = fStk.top; 
        while(i>0)
        {
            num = fStk.stk[fStk.top];
            fStk.top = fStk.top - 1;
            rStk.top = rStk.top + 1;
            rStk.stk[rStk.top] = num;

            i--;
        }

        //delete first elem
        num = fStk.stk[fStk.top];
        fStk.top = fStk.top - 1;

        //put elems back
        i = rStk.top; 
        while(i>-1)
        {
            num = rStk.stk[rStk.top];
            rStk.top = rStk.top - 1;
            fStk.top = fStk.top + 1;
            fStk.stk[fStk.top] = num;

            i--;
        }

    }
    return(num);
}
int show()
{
    int num,i;
    i=0;
    num = fStk.stk[i];
    printf ("%d\n", num);
    return(num);
}