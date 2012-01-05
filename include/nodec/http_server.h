#ifndef _NODEC_HTTP_SERVER_H_
#define _NODEC_HTTP_SERVER_H_

#include "event_emitter.h"

namespace nodec {

class HttpServer : NODEC_EVENT_EMITTER(HttpServer)
public:
    virtual void listen(Int) = 0;
    virtual void listen(Type<String>::Cptr) = 0;
    virtual void close() = 0;
};

}

#endif // _NODEC_HTTP_SERVER_H_
