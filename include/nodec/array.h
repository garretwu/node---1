#ifndef _NODEC_ARRAY_H_
#define _NODEC_ARRAY_H_

#include "mutable.h"

namespace nodec {

class Array : NODEC_MUTABLE(Array)
public:
    virtual Size length() const = 0;
    virtual void set(Size, Value) = 0;
    virtual Value get(Size) = 0;
    virtual Value shift() = 0;
    virtual void unshift(Value) = 0;
    virtual void push(Value) = 0;
    virtual Value pop() = 0;
    virtual Ptr concat(Cptr) = 0;
};

}

#endif // _NODEC_ARRAY_H_
