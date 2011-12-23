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
    virtual typename Type<T>::Ptr clone() = 0;
};

}

#endif // _NODEC_CLONABLE_H_
