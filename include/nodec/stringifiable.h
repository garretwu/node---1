#ifndef _NODEC_STRINGIFIABLE_H_
#define _NODEC_STRINGIFIABLE_H_

#include "type.h"

namespace nodec {

class String;

class Stringifiable {
protected:
    Stringifiable() {}
    ~Stringifiable() {}

public:
    virtual NODEC_CPTR(String) toString() = 0;
};

}

#endif // _NODEC_STRINGIFIABLE_H_
