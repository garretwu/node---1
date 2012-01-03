#ifndef _NODEC_STRINGIFIABLE_H_
#define _NODEC_STRINGIFIABLE_H_

#include "pointer.h"

namespace nodec {

class String;

class Stringifiable {
public:
    virtual NODEC_CPTR(String) toString() const = 0;
};

}

#endif // _NODEC_STRINGIFIABLE_H_
