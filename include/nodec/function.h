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
public:
    bool instanceOf(TypeId id) const {
        return id == Type<Function>::id()
            || MutableBase<T>::instanceOf(id);
    }
};

#define NODEC_FUNCTION(T) public Function, public FunctionBase<T> { \
    NODEC_MUTABLE_DECLS(T)

}

#endif // _NODEC_FUNCTION_H_
