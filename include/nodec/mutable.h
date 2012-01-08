#ifndef _NODEC_MUTABLE_H_
#define _NODEC_MUTABLE_H_

#include "value.h"
#include "object.h"
#include "gc_base.h"

namespace nodec {

class MutableBase
    : public Mutable
    , public GCBase
    , public ObjectBase
{
public:
    bool instanceOf(TypeId id) const {
        return id == Type<Mutable>::id()
            || ObjectBase::instanceOf(id);
    }
};

#define NODEC_MUTABLE_DECLS(T, B) public: \
    typedef NODEC_PTR(T) Ptr; \
    typedef NODEC_CPTR(T) Cptr; \
    static Ptr create(); \
    Ptr clone() const; \
    nodec::TypeId type() const { \
        return nodec::Type<T>::id(); \
    } \
    bool instanceOf(nodec::TypeId id) const { \
        return id == type() \
            || B::instanceOf(id); \
    }

#define NODEC_MUTABLE(T) public nodec::MutableBase { \
    NODEC_MUTABLE_DECLS(T, nodec::MutableBase)

}

#endif // _NODEC_MUTABLE_H_
