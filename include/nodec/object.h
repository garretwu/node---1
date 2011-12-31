#ifndef _NODEC_OBJECT_H_
#define _NODEC_OBJECT_H_

#include "typable.h"
#include "noncopyable.h"
#include "stringifiable.h"

namespace nodec {

template<typename T>
class ObjectBase
    : public Typable
    , public Stringifiable
    , private NonCopyable<T> {
public:
    TypeId type() {
        return Type<T>::id();
    }

    bool instanceOf(TypeId id) {
        return id == Type<Object>::id()
            || id == Type<T>::id();
    }
};

}

#endif // _NODEC_OBJECT_H_
