#ifndef _NODEC_TYPE_H_
#define _NODEC_TYPE_H_

#include <boost/type_traits/is_base_of.hpp>
#include "gc_base.h"
#include "pointer.h"
#include "typedef.h"

namespace nodec {

enum Category {
    PRIMITIVE,
    OBJECT,
    MUTABLE,
    IMMUTABLE,
    SINGLETON,
    UNDEFINED,
};

class Object {};
class Mutable   : public Object {};
class Immutable : public Object {};
class Singleton : public Object {};

#define NODEC_TYPE_ID() static TypeId id() { \
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
                    : OBJECT
        : PRIMITIVE>
class Type {
public:
    NODEC_TYPE_ID();
};

template<typename T>
class Type<T, OBJECT> {
public:
    typedef NODEC_PTR_TYPE(T) Ptr;
    typedef NODEC_CPTR_TYPE(T) Cptr;
    NODEC_TYPE_ID();
};

template<typename T>
class Type<T, MUTABLE> {
public:
    typedef NODEC_PTR_TYPE(T) Ptr;
    typedef NODEC_CPTR_TYPE(T) Cptr;
    NODEC_TYPE_ID();
};

template<typename T>
class Type<T, IMMUTABLE> {
public:
    typedef NODEC_CPTR_TYPE(T) Cptr;
    NODEC_TYPE_ID();
};

template<typename T>
class Type<T, SINGLETON> {
public:
    typedef NODEC_PTR_TYPE(T) Ptr;
    typedef NODEC_CPTR_TYPE(T) Cptr;
    NODEC_TYPE_ID();
};

}

#endif // _NODEC_TYPE_H_
