#ifndef _BASE_TCB_H
#define _BASE_TCB_H

#include <cstdint>

using namespace std;
// Thread control block
class tcb{
    
    public:
        int32_t *stackPtr;   /* Pointer to stack */
        struct tcb *nextPtr; /* Pointer to next thread */
};

typedef class tcb tcbType;

#endif
