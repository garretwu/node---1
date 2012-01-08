#ifndef _NODEC_IMMUTABLE_H_
#define _NODEC_IMMUTABLE_H_

#include "value.h"
#include "object.h"
#include "gc_base.h"

namespace nodec {

class ImmutableBase
    : public Immutable
    , public GCBase
    , public ObjectBase {
public:
    bool instanceOf(TypeId id) const {
        return id == Type<Immutable>::id()
            || ObjectBase::instanceOf(id);
    }
};

#define NODEC_IMMUTABLE_DECLS(T, B) public: \
    typedef NODEC_CPTR(T) Cptr; \
    static Cptr create(); \
    nodec::TypeId type() const { \
        return nodec::Type<T>::id(); \
    } \
    bool instanceOf(nodec::TypeId id) const { \
        return id == type() \
            || B::instanceOf(id); \
    }

#define NODEC_IMMUTABLE(T) public nodec::ImmutableBase { \
    NODEC_IMMUTABLE_DECLS(T, nodec::ImmutableBase)

}

#endif // _NODEC_IMMUTABLE_H_
