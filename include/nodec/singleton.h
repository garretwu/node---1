#ifndef _NODEC_SINGLETON_H_
#define _NODEC_SINGLETON_H_

#include "type.h"
#include "value.h"
#include "object.h"
#include "noncopyable.h"

namespace nodec {

template<typename T>
class SingletonBase
    : public Singleton
    , private NonCopyable<T>
    , public Object {
public:
    static T* get() {
        if (!instance_)
            instance_ = new T;
        return instance_;
    }
    
    static void reset() {
        delete instance_;
        instance_ = 0;
    }

protected:
    SingletonBase() {}

private:
    static T* instance_;
};

template <typename T>
T* SingletonBase<T>::instance_ = 0;

#define SINGLETON(T) public SingletonBase<T> { \
private: \
    friend class SingletonBase<T>; \
    T() : SingletonBase<T>() {} \
    ~T() {} \

}

#endif // _NODEC_SINGLETON_H_
