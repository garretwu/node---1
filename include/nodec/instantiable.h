#ifndef _NODEC_INSTANTIABLE_H_
#define _NODEC_INSTANTIABLE_H_

#include "type.h"

namespace nodec {

class Instantiable {
protected:
    Instantiable() {}
    ~Instantiable() {}

public:
    virtual bool instanceOf(TypeId) = 0;
};

}

#endif // _NODEC_INSTANTIABLE_H_