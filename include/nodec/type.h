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

class Object {};
class Mutable   : public Object {};
class Immutable : public Object {};
class Singleton : public Object {};

typedef size_t Size;
typedef uintptr_t TypeId;

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

#define TYPE_ID() static TypeId id() { \
    static char c; \
    return reinterpret_cast<TypeId>(&c); \
}

template<typename T, Category =
    boost::is_base_of<Object, T>::value
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
    TYPE_ID();
};

template<typename T>
class Type<T, MUTABLE> {
public:
    typedef NODEC_PTR_TYPE(T) Ptr;
    typedef NODEC_CPTR_TYPE(T) Cptr;
    TYPE_ID();
};

template<typename T>
class Type<T, IMMUTABLE> {
public:
    typedef NODEC_CPTR_TYPE(T) Cptr;
    TYPE_ID();
};

template<typename T>
class Type<T, SINGLETON> {
public:
    typedef T* Ptr;
    typedef const T* Cptr;
    TYPE_ID();
};

}

#endif // _NODEC_TYPE_H_
