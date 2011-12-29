#ifndef _NODEC_OBJECT_H_
#define _NODEC_OBJECT_H_

#include "noncopyable.h"
#include "stringifiable.h"

namespace nodec {

template<typename T>
class Object
    : private NonCopyable<T>
    , public Stringifiable {
};

}

#endif // _NODEC_OBJECT_H_
