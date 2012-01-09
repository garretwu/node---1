#ifndef _NODEC_OBJECT_H_
#define _NODEC_OBJECT_H_

#include <boost/utility.hpp>
#include "type.h"
#include "pointer.h"

namespace nodec {

class String;

class ObjectBase : private boost::noncopyable
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
