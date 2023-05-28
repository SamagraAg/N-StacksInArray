#include <bits/stdc++.h>
class NStack
{
public:
    int n, s;
    int *arr, *top, *next;
    int freespot;
    NStack(int N, int S)
    {
        n = N; // no. of Stacks
        s = S; // size of Arr
        arr = new int[s];
        next = new int[s];
        top = new int[n];

        // Initialze top
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // Initialze next
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;

        // Initialze freespot
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check Overflow
        if (freespot == -1)
            return false;
        else
        {
            // fetch index for push
            int index = freespot;

            // Insert the element
            arr[index] = x;
            
            // update the freespot
            freespot = next[index];

            // update the next of Index
            next[index] = top[m - 1];

            // update the top[m-1]
            top[m - 1] = index;

            return true;
        }
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check Underflow
        if (top[m-1] == -1)
            return -1;
        // fetch index for pop
        int index = top[m - 1];

        // update the top[m-1] to next element of stack
        top[m - 1] = next[index];

        // update the next[Index] point it ot freespot
        next[index] = freespot;

        // update the freespot, make it index
        freespot = index;

        return arr[index];
    }
};
