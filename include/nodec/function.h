#ifndef _NODEC_FUNCTION_H_
#define _NODEC_FUNCTION_H_

#include "mutable_object.h"
#include "value.h"
#include "array.h"

namespace nodec {

class Function : public MutableObject<Function> {
public:
    virtual Value invoke(Type<Array>::Ptr args) = 0;
};

}

#endif // _NODEC_FUNCTION_H_
