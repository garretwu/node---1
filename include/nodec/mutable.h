#ifndef _NODEC_MUTABLE_H_
#define _NODEC_MUTABLE_H_

#include "value.h"
#include "object.h"
#include "clonable.h"
#include "gc_base.h"

namespace nodec {

template<typename T>
class MutableBase
    : public GCBase
    , public ObjectBase<T>
    , public Clonable<T> {
public:
    bool instanceOf(TypeId id) {
        return id == Type<Mutable>::id()
            || ObjectBase<T>::instanceOf(id);
    }
};

#define NODEC_MUTABLE_DECLS(T) public: \
    typedef NODEC_PTR(T) Ptr; \
    typedef NODEC_CPTR(T) Cptr; \
    static Ptr create();

#define NODEC_MUTABLE(T) public Mutable, public MutableBase<T> { \
    NODEC_MUTABLE_DECLS(T)

}

#endif // _NODEC_MUTABLE_H_
