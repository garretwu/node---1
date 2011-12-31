#ifndef _NODEC_TYPABLE_H_
#define _NODEC_TYPABLE_H_

#include "type.h"

namespace nodec {

class Typable {
protected:
    Typable() {}
    ~Typable() {}

public:
    virtual TypeId type() = 0;
    virtual bool instanceOf(TypeId) = 0;
};

}

#endif // _NODEC_TYPABLE_H_