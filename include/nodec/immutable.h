#ifndef _NODEC_IMMUTABLE_H_
#define _NODEC_IMMUTABLE_H_

#include "value.h"
#include "object.h"
#include "gc_base.h"

namespace nodec {

template<typename T>
class ImmutableBase
    : public GCBase
    , public ObjectBase<T> {
public:
    bool instanceOf(TypeId id) const {
        return id == Type<Immutable>::id()
            || ObjectBase<T>::instanceOf(id);
    }
};

#define NODEC_IMMUTABLE_DECLS(T) public: \
    typedef NODEC_CPTR(T) Cptr; \
    static Cptr create();

#define NODEC_IMMUTABLE(T) public Immutable, public ImmutableBase<T> { \
    NODEC_IMMUTABLE_DECLS(T)

}

#endif // _NODEC_IMMUTABLE_H_
