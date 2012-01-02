#ifndef _NODEC_OBJECT_H_
#define _NODEC_OBJECT_H_

#include "type.h"
#include "noncopyable.h"
#include "typable.h"
#include "instantiable.h"
#include "stringifiable.h"

namespace nodec {

template<typename T>
class ObjectBase
    : private NonCopyable<T>
#ifdef NODEC_USE_EXPLICIT_IF
    , public Typable
    , public Instantiable
    , public Stringifiable
#endif
{
public:
    virtual TypeId type() {
        return Type<T>::id();
    }

    virtual bool instanceOf(TypeId id) {
        return id == Type<T>::id()
            || id == Type<Object>::id();
    }
    
    virtual NODEC_CPTR(String) toString() = 0;
};

}

#endif // _NODEC_OBJECT_H_
