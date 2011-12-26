#ifndef _NODEC_ARRAY_H_
#define _NODEC_ARRAY_H_

#include "mutable.h"

namespace nodec {

class Array : MUTABLE(Array)
public:
    static Ptr create();
    
    virtual size_t length() const = 0;
    virtual void set(size_t, Value) = 0;
    virtual Value get(size_t) = 0;
    virtual Value shift() = 0;
    virtual void unshift(Value) = 0;
    virtual void push(Value) = 0;
    virtual Value pop() = 0;
    virtual Ptr concat(Cptr) = 0;
};

}

#endif // _NODEC_ARRAY_H_
