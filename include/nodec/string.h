#ifndef _NODEC_STRING_H_
#define _NODEC_STRING_H_

#include "immutable.h"

namespace nodec {

class String : IMMUTABLE(String)
public:
    static Cptr create(const char*);

    virtual Cptr charAt(int) = 0;
    virtual Cptr substring(int) = 0;
    virtual Cptr substring(int, int) = 0;
    virtual Cptr concat(Cptr) = 0;
    
    // TODO: there are many other methods.
};

}

#endif // _NODEC_STRING_H_
