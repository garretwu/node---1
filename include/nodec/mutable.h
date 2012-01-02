#ifndef _NODEC_MUTABLE_H_
#define _NODEC_MUTABLE_H_

#include "value.h"
#include "object.h"
#include "gc_base.h"
#include "clonable.h"

namespace nodec {

template<typename T>
class MutableBase
    : public GCBase
    , public ObjectBase<T>
#ifdef NODEC_USE_EXPLICIT_IF
    , public Clonable<T>
#endif
{
public:
    bool instanceOf(TypeId id) {
        return id == Type<Mutable>::id()
            || ObjectBase<T>::instanceOf(id);
    }
    
    virtual NODEC_PTR_TYPE(T) clone() = 0;
};

#define NODEC_MUTABLE_DECLS(T) public: \
    typedef NODEC_PTR(T) Ptr; \
    typedef NODEC_CPTR(T) Cptr; \
    static Ptr create();

#define NODEC_MUTABLE(T) public Mutable, public MutableBase<T> { \
    NODEC_MUTABLE_DECLS(T)

}

#endif // _NODEC_MUTABLE_H_
