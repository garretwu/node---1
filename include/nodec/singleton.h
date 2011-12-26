#ifndef _NODEC_SINGLETON_H_
#define _NODEC_SINGLETON_H_

#include "immutable.h"

namespace nodec {

template<typename T>
class Singleton
    : public Single
    , public ImmutableObject<T> {
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
    Singleton() {}

private:
    static T* instance_;
};

template <typename T>
T* Singleton<T>::instance_ = 0;

#define SINGLETON(T) public Singleton<T> { \
private: \
    friend class Singleton<T>; \
    T() : Singleton<T>() {} \
    ~T() {} \

}

#endif // _NODEC_SINGLETON_H_
