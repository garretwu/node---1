#ifndef _NODEC_SINGLETON_H_
#define _NODEC_SINGLETON_H_

#include "value.h"
#include "object.h"
#include "string.h"

namespace nodec {

template<typename T>
class SingletonBase
    : public Singleton
    , public ObjectBase {
public:
    static T* instance() {
        static T t;
        return &t;
    }
    
    Type<String>::Cptr toString() const {
        return String::create();
    }
    
    bool instanceOf(TypeId id) const {
        return id == Type<Singleton>::id()
            || ObjectBase::instanceOf(id);
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
    typedef const T* Cptr; \
    nodec::TypeId type() const { \
        return nodec::Type<T>::id(); \
    } \
    bool instanceOf(TypeId id) const { \
        return id == type() \
            || SingletonBase<T>::instanceOf(id); \
    }

}

#endif // _NODEC_SINGLETON_H_
