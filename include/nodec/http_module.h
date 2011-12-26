#ifndef _NODEC_HTTP_MODULE_H_
#define _NODEC_HTTP_MODULE_H_

#include "singleton.h"
#include "server.h"

namespace nodec {

class HttpModule : SINGLETON(HttpModule)    
public:
    Type<Server>::Ptr createServer() const;
    Type<String>::Cptr toString();
};

}

#endif // _NODEC_HTTP_MODULE_H_
