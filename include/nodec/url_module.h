#ifndef _NODEC_URL_MODULE_H_
#define _NODEC_URL_MODULE_H_

#include "module.h"
#include "string.h"
#include "url.h"

namespace nodec {

class UrlModule : public Singleton<UrlModule> { MODULE(UrlModule)
public:
    Type<Url>::Ptr parse(Type<String>::Cptr, bool, bool);
    Type<String>::Cptr format(Type<Url>::Cptr);
    
    // TODO: resolve
};

MODULE_TYPE(UrlModule);

}

#endif // _NODEC_URL_MODULE_H_
