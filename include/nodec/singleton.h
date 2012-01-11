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
private:
    struct NullDeleter {
        void operator()(void const *) const {}
    };
    
public:
    static NODEC_PTR_TYPE(T) instance() {
        static T t;
#ifdef NODEC_USE_SP
        NODEC_PTR_TYPE(T) p(&t, NullDeleter());
#else
        NODEC_PTR_TYPE(T) p(&t);
#endif
        return p;
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

#define NODEC_SINGLETON(T) public nodec::SingletonBase<T> { \
private: \
    friend class nodec::SingletonBase<T>; \
    T() : nodec::SingletonBase<T>() {} \
    ~T() {} \
public: \
    typedef T* Ptr; \
    typedef const T* Cptr; \
    nodec::TypeId type() const { \
        return nodec::Type<T>::id(); \
    } \
    bool instanceOf(nodec::TypeId id) const { \
        return id == type() \
            || nodec::SingletonBase<T>::instanceOf(id); \
    }

}

#endif // _NODEC_SINGLETON_H_
