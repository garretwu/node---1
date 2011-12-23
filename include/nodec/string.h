#ifndef _NODEC_STRING_H_
#define _NODEC_STRING_H_

#include "immutable.h"

namespace nodec {

class String : public Immutable<String> {
public:
    static Type<String>::Cptr create(const char*);

public:
    virtual Type<String>::Cptr charAt(int) = 0;
    virtual Type<String>::Cptr substring(int) = 0;
    virtual Type<String>::Cptr substring(int, int) = 0;
    virtual Type<String>::Cptr concat(Type<String>::Cptr) = 0;
    
    // TODO: there are many other methods.
};

}

#endif // _NODEC_STRING_H_
