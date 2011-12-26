#ifndef _NODEC_FUNCTION_H_
#define _NODEC_FUNCTION_H_

#include "mutable.h"
#include "array.h"

namespace nodec {

class Function : MUTABLE(Function)
public:
    virtual Value invoke(Type<Array>::Ptr args) = 0;
};

}

#endif // _NODEC_FUNCTION_H_
