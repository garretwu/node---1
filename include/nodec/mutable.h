#ifndef _NODEC_MUTABLE_H_
#define _NODEC_MUTABLE_H_

#include "type.h"
#include "value.h"
#include "object.h"
#include "clonable.h"
#include "noncopyable.h"

namespace nodec {

template<typename T>
class MutableBase
    : public Clonable<T>
    , private NonCopyable<T>
    , public Object {
};

#define MUTABLE(T) public Mutable, public MutableBase<T> { \
public: \
    typedef NODEC_PTR(T) Ptr; \
    typedef NODEC_CPTR(T) Cptr; \
    static Ptr create(); \

}

#endif // _NODEC_MUTABLE_H_
