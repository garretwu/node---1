#ifndef _NODEC_HTTP_SERVER_H_
#define _NODEC_HTTP_SERVER_H_

#include "mutable.h"
#include "string.h"

namespace nodec {

class HttpServer : MUTABLE(HttpServer)
public:
    virtual void listen(int) = 0;
    virtual void listen(Type<String>::Cptr) = 0;
    virtual void close() = 0;
};

}

#endif // _NODEC_HTTP_SERVER_H_
