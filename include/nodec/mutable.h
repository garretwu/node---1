#ifndef _NODEC_MUTABLE_H_
#define _NODEC_MUTABLE_H_

#include "value.h"
#include "noncopyable.h"
#include "clonable.h"

namespace nodec {

template<typename T>
class Mutable
    : private NonCopyable<T>
    , public Clonable<T> {
};

}

#endif // _NODEC_MUTABLE_H_
