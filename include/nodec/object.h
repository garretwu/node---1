#ifndef _NODEC_OBJECT_H_
#define _NODEC_OBJECT_H_

#include <boost/utility.hpp>
#include "type.h"
#include "typable.h"
#include "instantiable.h"
#include "stringifiable.h"

namespace nodec {

class ObjectBase
    : private boost::noncopyable
#ifdef NODEC_USE_EXPLICIT_IF
    , public Typable
    , public Instantiable
    , public Stringifiable
#endif
{
public:
    virtual TypeId type() const = 0;

    virtual bool instanceOf(TypeId id) const {
        return id == Type<Object>::id();
    }
    
    virtual NODEC_CPTR(String) toString() const = 0;
};

}

#endif // _NODEC_OBJECT_H_
