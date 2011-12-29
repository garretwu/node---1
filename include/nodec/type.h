#ifndef _NODEC_TYPE_H_
#define _NODEC_TYPE_H_

#include <inttypes.h>
#include <boost/type_traits/is_base_of.hpp>
#include "gc_base.h"
#ifdef NODEC_USE_SP
#include "shared_ptr.h"
#endif

namespace nodec {

enum Category {
    PRIMITIVE,
    MUTABLE,
    IMMUTABLE,
    SINGLETON,
    UNDEFINED,
};

class GarbageCollectable {};
class Mutable   : public GarbageCollectable {};
class Immutable : public GarbageCollectable {};
class Singleton : public GarbageCollectable {};

typedef uintptr_t TypeId;

template<typename T, Category =
    boost::is_base_of<GarbageCollectable, T>::value
        ? boost::is_base_of<Mutable, T>::value
            ? MUTABLE
            : boost::is_base_of<Immutable, T>::value
                ? IMMUTABLE
                : boost::is_base_of<Singleton, T>::value
                    ? SINGLETON
                    : UNDEFINED
        : PRIMITIVE>
class Type {
public:
    TypeId id();
};

template<typename T>
class Type<T, MUTABLE> {
public:
#ifdef NODEC_USE_SP
    typedef typename SharedPtr<T>::Type Ptr;
    typedef typename SharedPtr<const T>::Type Cptr;
#else
    typedef T* Ptr;
    typedef const T* Cptr;
#endif
};

template<typename T>
class Type<T, IMMUTABLE> {
public:
#ifdef NODEC_USE_SP
    typedef typename SharedPtr<const T>::Type Cptr;
#else
    typedef const T* Cptr;
#endif
    TypeId id();
};

template<typename T>
class Type<T, SINGLETON> {
public:
    typedef T* Ptr;
    typedef const T* Cptr;
    TypeId id();
};

template<typename T, Category C>
TypeId Type<T, C>::id() {
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

typedef size_t Size;

}

#endif // _NODEC_TYPE_H_
