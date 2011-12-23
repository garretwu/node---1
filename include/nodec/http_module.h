#ifndef _NODEC_HTTP_MODULE_H_
#define _NODEC_HTTP_MODULE_H_

#include "module.h"
#include "server.h"

namespace nodec {

class HttpModule : public Singleton<HttpModule> { MODULE(HttpModule)    
public:
    Type<Server>::Ptr createServer();
    Type<String>::Cptr toString();
};

MODULE_TYPE(HttpModule);

}

#endif // _NODEC_HTTP_MODULE_H_
