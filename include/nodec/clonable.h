#ifndef _NODEC_CLONABLE_H_
#define _NODEC_CLONABLE_H_

#include "pointer.h"

namespace nodec {

template<typename T>
class Clonable {
public:
    virtual NODEC_PTR_TYPE(T) clone() = 0;
};

}

#endif // _NODEC_CLONABLE_H_
