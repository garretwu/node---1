#ifndef _NODEC_IMMUTABLE_H_
#define _NODEC_IMMUTABLE_H_

#include "noncopyable.h"

namespace nodec {

template<typename T>
class Immutable
    : private NonCopyable<T> {
};

}

#endif // _NODEC_IMMUTABLE_H_
