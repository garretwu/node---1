#ifndef _NODEC_URL_H_
#define _NODEC_URL_H_

#include "mutable.h"
#include "string.h"

namespace nodec {

class Url : MUTABLE(Url)
public:
    static Ptr parse(Type<String>::Cptr);
    static Type<String>::Cptr format(Cptr);
    
    virtual Type<String>::Cptr getHref() = 0;
    virtual Type<String>::Cptr getProtocol() = 0;
    virtual Type<String>::Cptr getHost() = 0;
    virtual Type<String>::Cptr getAuth() = 0;
    virtual Type<String>::Cptr getHostName() = 0;
    virtual Type<String>::Cptr getPort() = 0;
    virtual Type<String>::Cptr getPathName() = 0;
    virtual Type<String>::Cptr getSearch() = 0;
    virtual Type<String>::Cptr getPath() = 0;
    virtual Type<String>::Cptr getQuery() = 0;
    virtual Type<String>::Cptr getHash() = 0;
    
    // TODO: setter
};

}

#endif // _NODEC_URL_H_
