#ifndef _NODEC_SINGLETON_H_
#define _NODEC_SINGLETON_H_

#include "immutable_object.h"

namespace nodec {

template<typename T>
class Singleton : public ImmutableObject<T> {
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

}

#endif // _NODEC_SINGLETON_H_
