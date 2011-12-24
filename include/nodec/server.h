#ifndef _NODEC_SERVER_H_
#define _NODEC_SERVER_H_

#include "mutable_object.h"
#include "string.h"

namespace nodec {

class Server : public MutableObject<Server> {
public:
    static Type<Server>::Ptr create();
    
    virtual void listen(int) = 0;
    virtual void listen(Type<String>::Cptr) = 0;
    virtual void close() = 0;
};

}

#endif // _NODEC_SERVER_H_
