#ifndef _NODEC_MODULE_H_
#define _NODEC_MODULE_H_

#include "singleton.h"

#define MODULE(T) \
private: \
    friend class Singleton<T>; \
    T() : Singleton<T>() {} \
    ~T() {}

#define MODULE_TYPE(T) \
template<> \
class Type<T> { \
public: \
    typedef T* Ptr; \
    typedef const T* Cptr; \
    TypeId id() { \
        static char c; \
        return reinterpret_cast<TypeId>(&c); \
    } \
};
    
#endif // _NODEC_MODULE_H_
