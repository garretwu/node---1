#ifndef _NODEC_TYPABLE_H_
#define _NODEC_TYPABLE_H_

#include "typedef.h"

namespace nodec {

class Typable {
public:
    virtual TypeId type() = 0;
};

}

#endif // _NODEC_TYPABLE_H_