#ifndef _NODEC_URL_H_
#define _NODEC_URL_H_

#include "mutable_object.h"
#include "string.h"

namespace nodec {

class Url : public MutableObject<Url> {
public:
    static Type<Url>::Ptr create();
    
    Type<String>::Cptr getHref();
    Type<String>::Cptr getProtocol();
    Type<String>::Cptr getHost();
    Type<String>::Cptr getAuth();
    Type<String>::Cptr getHostName();
    Type<String>::Cptr getPort();
    Type<String>::Cptr getPathName();
    Type<String>::Cptr getSearch();
    Type<String>::Cptr getPath();
    Type<String>::Cptr getQuery();
    Type<String>::Cptr getHash();
    
    // TODO: setter
};

}

#endif // _NODEC_URL_H_
