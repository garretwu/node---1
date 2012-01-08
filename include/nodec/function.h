#ifndef _NODEC_FUNCTION_H_
#define _NODEC_FUNCTION_H_

#include "mutable.h"

namespace nodec {

class Function : NODEC_MUTABLE(Function)
public:
    virtual Value operator()(Value) = 0;
};

#define NODEC_FUNCTION(T) public nodec::Function { \
    NODEC_MUTABLE_DECLS(T, nodec::Function)

}

#endif // _NODEC_FUNCTION_H_
