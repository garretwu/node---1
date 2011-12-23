#ifndef _NODEC_TYPE_H_
#define _NODEC_TYPE_H_

#include <inttypes.h>
#include "config.h"
#ifdef NODEC_USE_SP
#include "shared_ptr.h"
#endif

namespace nodec {

typedef uintptr_t TypeId;

#ifdef NODEC_USE_SP
template<typename T>
class Type {
public:
    typedef typename SharedPtr<T>::Type Ptr;
    typedef typename SharedPtr<const T>::Type Cptr;
    
    TypeId id();
};
#else
template<typename T>
class Type {
public:
    typedef T* Ptr;
    typedef const T* Cptr;
    
    TypeId id();
};
#endif

template<typename T>
TypeId Type<T>::id() {
    static char c;
    return reinterpret_cast<TypeId>(&c);
}

}

#endif // _NODEC_TYPE_H_
