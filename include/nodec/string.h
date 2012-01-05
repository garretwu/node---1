#ifndef _NODEC_STRING_H_
#define _NODEC_STRING_H_

#include "immutable.h"

namespace nodec {

class String : NODEC_IMMUTABLE(String)
public:
    enum Encoding {
        ASCII,
        UTF8,
        UTF16,
        UTF32,
    };
    
    static Cptr create(const Byte*, Encoding, Size = 0);

    virtual Size length() const = 0;
    virtual Char charAt(Size) const = 0;
    virtual Cptr substring(Size) const = 0;
    virtual Cptr substring(Size, Size) const = 0;
    virtual Cptr concat(Cptr) const = 0;
    virtual Int compareTo(Cptr) const = 0;
    virtual bool startsWith(Cptr) const = 0;
    virtual bool startsWith(Cptr, Size) const = 0;
    virtual bool endsWith(Cptr) const = 0;
    virtual bool endsWith(Cptr, Size) const = 0;
    virtual Size indexOf(Char) const = 0;
    virtual Size indexOf(Char, Size) const = 0;
    virtual Size indexOf(Cptr) const = 0;
    virtual Size indexOf(Cptr, Size) const = 0;
    virtual Size lastIndexOf(Char) const = 0;
    virtual Size lastIndexOf(Char, Size) const = 0;
    virtual Size lastIndexOf(Cptr) const = 0;
    virtual Size lastIndexOf(Cptr, Size) const = 0;
    virtual const Char* toCStr() const = 0;
};

}

#endif // _NODEC_STRING_H_
