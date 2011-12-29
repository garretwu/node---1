#ifndef _NODEC_OBJECT_H_
#define _NODEC_OBJECT_H_

#include "noncopyable.h"
#include "instantiable.h"
#include "stringifiable.h"

namespace nodec {

template<typename T>
class ObjectBase
    : private NonCopyable<T>
    , public Instantiable
    , public Stringifiable {
public:
    virtual TypeId type() {
        return Type<T>::id();
    }

    virtual bool instanceOf(TypeId id) {
        return id == Type<Object>::id()
            || id == Type<T>::id();
    }
};

}

#endif // _NODEC_OBJECT_H_
