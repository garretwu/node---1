#ifndef _NODEC_SOCKET_H_
#define _NODEC_SOCKET_H_

#include "event_emitter.h"

namespace nodec {

class Socket : EVENT_EMITTER(Socket)
public:
    virtual void connect(int) = 0;
    virtual void write(Type<String>::Cptr) = 0;
    // and so on
};

}

#endif // _NODEC_SOCKET_H_
