#ifndef _NODEC_ASCII_STRING_H_
#define _NODEC_ASCII_STRING_H_

#include "string.h"

namespace nodec {

class AsciiString : public String {
public:
    static Cptr create(const char*);
};

}

#endif // _NODEC_ASCII_STRING_H_