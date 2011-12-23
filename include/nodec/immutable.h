#ifndef _NODEC_IMMUTABLE_H_
#define _NODEC_IMMUTABLE_H_

#include "value.h"
#include "noncopyable.h"

namespace nodec {

template<typename T>
class Immutable
    : private NonCopyable<Immutable<T> >
    , public Object {
};

}

#endif // _NODEC_IMMUTABLE_H_
