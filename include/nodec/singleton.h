#ifndef _NODEC_SINGLETON_H_
#define _NODEC_SINGLETON_H_

#include "type.h"
#include "value.h"
#include "object.h"
#include "string.h"

namespace nodec {

template<typename T>
class SingletonBase
    : public Singleton
    , public Object<T> {
public:
    static T* instance() {
        static T t;
        return &t;
    }
    
    Type<String>::Cptr toString() {
        return String::create();
    }

protected:
    SingletonBase() {}
    virtual ~SingletonBase() {}
};

#define SINGLETON(T) public SingletonBase<T> { \
private: \
    friend class SingletonBase<T>; \
    T() : SingletonBase<T>() {} \
    ~T() {} \
public: \
    typedef T* Ptr; \
    typedef const T* Cptr; \

}

#endif // _NODEC_SINGLETON_H_
