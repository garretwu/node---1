#ifndef _NODEC_CLONABLE_H_
#define _NODEC_CLONABLE_H_

#include "type.h"

namespace nodec {

template<typename T>
class Clonable {
protected:
    Clonable() {}
    ~Clonable() {}
    
public:
    virtual typename NODEC_PTR(T) clone() = 0;
};

}

#endif // _NODEC_CLONABLE_H_
