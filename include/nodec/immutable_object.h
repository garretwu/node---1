#ifndef _NODEC_IMMUTABLE_OBJECT_H_
#define _NODEC_IMMUTABLE_OBJECT_H_

#include "value.h"
#include "object.h"
#include "immutable.h"

namespace nodec {

template<typename T>
class ImmutableObject
    : public Immutable<T>
    , public Object {
};

}

#endif // _NODEC_IMMUTABLE_OBJECT_H_
