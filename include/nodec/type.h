#ifndef _NODEC_TYPE_H_
#define _NODEC_TYPE_H_

#include <inttypes.h>
#include "config.h"
#ifdef NODEC_USE_SP
#include "shared_ptr.h"
#endif
#include "immutable.h"

namespace nodec {

typedef uintptr_t TypeId;

template<typename T>
class Type {
public:
#ifdef NODEC_USE_SP
    typedef typename SharedPtr<T>::Type Ptr;
    typedef typename SharedPtr<const T>::Type Cptr;
#else
    typedef T* Ptr;
    typedef const T* Cptr;
#endif
    TypeId id();
};

template<typename T>
TypeId Type<T>::id() {
    static char c;
    return reinterpret_cast<TypeId>(&c);
}

}

#endif // _NODEC_TYPE_H_
