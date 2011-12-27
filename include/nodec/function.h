#ifndef _NODEC_FUNCTION_H_
#define _NODEC_FUNCTION_H_

#include "mutable.h"

namespace nodec {

class Function {};

template<typename T>
class Callable
    : public Function
    , public MutableObject<T> {
public:
    virtual Value call(Value) = 0;
};

}

#endif // _NODEC_FUNCTION_H_
