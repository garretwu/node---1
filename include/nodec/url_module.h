#ifndef _NODEC_URL_MODULE_H_
#define _NODEC_URL_MODULE_H_

#include "singleton.h"
#include "string.h"
#include "url.h"

namespace nodec {

class UrlModule : SINGLETON(UrlModule)
public:
    Type<Url>::Ptr parse(Type<String>::Cptr, bool, bool);
    Type<String>::Cptr format(Type<Url>::Cptr);
    
    // TODO: resolve
};

}

#endif // _NODEC_URL_MODULE_H_
