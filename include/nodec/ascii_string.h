#ifndef _NODEC_ASCII_STRING_H_
#define _NODEC_ASCII_STRING_H_

#include "string.h"

namespace nodec {

class AsciiString : public String {
public:
    static Type<AsciiString>::Cptr create(const char*);
    
    // TODO: there are many other methods.
};

}

#endif // _NODEC_ASCII_STRING_H_