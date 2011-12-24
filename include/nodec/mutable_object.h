#ifndef _NODEC_MUTABLE_OBJECT_H_
#define _NODEC_MUTABLE_OBJECT_H_

#include "value.h"
#include "object.h"
#include "mutable.h"

namespace nodec {

template<typename T>
class MutableObject
    : public Mutable<T>
    , public Object {
};

}

#endif // _NODEC_MUTABLE_OBJECT_H_
