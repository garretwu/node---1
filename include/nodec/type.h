#ifndef _NODEC_TYPE_H_
#define _NODEC_TYPE_H_

#include <inttypes.h>
#include <boost/type_traits/is_base_of.hpp>
#include "config.h"
#ifdef NODEC_USE_SP
#include "shared_ptr.h"
#endif

namespace nodec {

class Mutable {};
class Immutable {};
class Single {};

typedef uintptr_t TypeId;

template<typename T
    , bool = boost::is_base_of<Immutable, T>::value
    , bool = boost::is_base_of<Single, T>::value>
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
class Type<T, true, false> {
public:
#ifdef NODEC_USE_SP
    typedef typename SharedPtr<const T>::Type Cptr;
#else
    typedef const T* Cptr;
#endif
    TypeId id();
};

template<typename T>
class Type<T, true, true> {
public:
    typedef const T* Cptr;
    TypeId id();
};

template<typename T, bool B1, bool B2>
TypeId Type<T, B1, B2>::id() {
    static char c;
    return reinterpret_cast<TypeId>(&c);
}

#ifdef NODEC_USE_SP
#define NODEC_PTR(T) SharedPtr<T>::Type
#define NODEC_CPTR(T) SharedPtr<const T>::Type
#define NODEC_PTR_TYPE(T) typename SharedPtr<T>::Type
#define NODEC_CPTR_TYPE(T) typename SharedPtr<const T>::Type
#else
#define NODEC_PTR(T) T*
#define NODEC_CPTR(T) const T*
#define NODEC_PTR_TYPE(T) T*
#define NODEC_CPTR_TYPE(T) const T*
#endif

}

#endif // _NODEC_TYPE_H_
