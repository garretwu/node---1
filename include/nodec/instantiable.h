#ifndef _NODEC_INSTANTIABLE_H_
#define _NODEC_INSTANTIABLE_H_

#include "typedef.h"

namespace nodec {

class Instantiable {
public:
    virtual bool instanceOf(TypeId) = 0;
};

}

#endif // _NODEC_INSTANTIABLE_H_