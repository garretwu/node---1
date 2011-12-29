#ifndef _NODEC_EVENT_EMITTER_H_
#define _NODEC_EVENT_EMITTER_H_

#include "string.h"
#include "function.h"
#include "array.h"

namespace nodec {

class EventEmittable {
public:
    virtual void addListener(Type<String>::Cptr event, Type<Function>::Ptr func) = 0;
    virtual void removeListerner(Type<String>::Cptr event, Type<Function>::Cptr func) = 0;
    virtual void removeAllListener() = 0;
    virtual void removeAllListener(Type<String>::Cptr event);
    virtual void emit(Type<String>::Cptr event, Type<Array>::Cptr args) = 0;
    virtual Type<Array>::Ptr listeners(Type<String>::Cptr event) = 0;
};

class EventEmitter
    : public Mutable {
};

template<typename T>
class EventEmitterBase
    : public EventEmittable
    , public MutableBase<T> {
public:
    bool instanceOf(TypeId id) {
        return id == Type<EventEmitter>::id()
            || MutableBase<T>::instanceOf(id);
    }
};

#define NODEC_EVENT_EMITTER(T) public EventEmitter, public EventEmitterBase<T> { \
    NODEC_MUTABLE_DECLS(T)

}

#endif // _NODEC_EVENT_EMITTER_H_
