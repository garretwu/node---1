#ifndef _NODEC_EVENT_EMITTER_H_
#define _NODEC_EVENT_EMITTER_H_

#include "string.h"
#include "function.h"
#include "array.h"

namespace nodec {

class EventEmitter : NODEC_MUTABLE(EventEmitter)
public:
    // TODO: implement the following methods
    virtual void addListener(Type<String>::Cptr event, Type<Function>::Ptr func) {}
    virtual void removeListerner(Type<String>::Cptr event, Type<Function>::Cptr func) {}
    virtual void removeAllListener() {}
    virtual void removeAllListener(Type<String>::Cptr event) {}
    virtual void emit(Type<String>::Cptr event, Type<Array>::Cptr args) {}
    virtual Type<Array>::Ptr listeners(Type<String>::Cptr event) { return Array::create(); }
};

#define NODEC_EVENT_EMITTER(T) public nodec::EventEmitter { \
    NODEC_MUTABLE_DECLS(T, nodec::EventEmitter)

}

#endif // _NODEC_EVENT_EMITTER_H_
