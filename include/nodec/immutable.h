#ifndef _NODEC_IMMUTABLE_H_
#define _NODEC_IMMUTABLE_H_

#include "type.h"
#include "value.h"
#include "object.h"
#include "noncopyable.h"

namespace nodec {

template<typename T>
class ImmutableBase
    : private NonCopyable<T>
    , public Object {
};

#define IMMUTABLE(T) public Immutable, public ImmutableBase<T> { \
public: \
    typedef NODEC_CPTR(T) Cptr; \
    static Cptr create(); \

}

#endif // _NODEC_IMMUTABLE_H_
