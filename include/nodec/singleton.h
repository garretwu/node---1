#ifndef _NODEC_SINGLETON_H_
#define _NODEC_SINGLETON_H_

#include "value.h"
#include "object.h"
#include "string.h"

namespace nodec {

template<typename T>
class SingletonBase
    : public Singleton
    , public ObjectBase<T> {
public:
    static T* instance() {
        static T t;
        return &t;
    }
    
    Type<String>::Cptr toString() {
        return String::create();
    }
    
    bool instanceOf(TypeId id) {
        return id == Type<Singleton>::id()
            || ObjectBase<T>::instanceOf(id);
    }

protected:
    SingletonBase() {}
    virtual ~SingletonBase() {}
};

#define NODEC_SINGLETON(T) public SingletonBase<T> { \
private: \
    friend class SingletonBase<T>; \
    T() : SingletonBase<T>() {} \
    ~T() {} \
public: \
    typedef T* Ptr; \
    typedef const T* Cptr;

}

#endif // _NODEC_SINGLETON_H_
