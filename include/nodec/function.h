#ifndef _NODEC_FUNCTION_H_
#define _NODEC_FUNCTION_H_

#include "mutable.h"

namespace nodec {

class Callable {
    virtual Value operator()(Value) = 0;
};

class Function
    : public Mutable {
};

template<typename T>
class FunctionBase
    : public Callable
    , public MutableBase<T> {
};

#define FUNCTION(T) public Function, public FunctionBase<T> { \
public: \
    typedef NODEC_PTR(T) Ptr; \
    typedef NODEC_CPTR(T) Cptr; \
    static Ptr create(); \

}

#endif // _NODEC_FUNCTION_H_
