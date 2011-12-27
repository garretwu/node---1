#ifndef _NODEC_EVENT_EMITTER_H_
#define _NODEC_EVENT_EMITTER_H_

#include "string.h"
#include "function.h"
#include "array.h"

namespace nodec {

class EventEmitter {};

template<typename T>
class EventEmittable
    : public EventEmitter
    , public MutableObject<T> {
public:
    virtual void addListener(Type<String>::Cptr event, Type<Function>::Ptr func) = 0;
    virtual void on(Type<String>::Cptr event, Type<Function>::Ptr func) = 0;
    virtual void once(Type<String>::Cptr event, Type<Function>::Ptr func) = 0;
    virtual void removeListerner(Type<String>::Cptr event, Type<Function>::Cptr func) = 0;
    virtual void removeAllListener() = 0;
    virtual void removeAllListener(Type<String>::Cptr event);
    virtual void emit(Type<String>::Cptr event, Type<Array>::Cptr args) = 0;
    virtual Type<Array>::Ptr listeners(Type<String>::Cptr event) = 0;
};

#define EVENT_EMITTER(T) public EventEmittable<T> { \
public: \
    typedef NODEC_PTR(T) Ptr; \
    typedef NODEC_CPTR(T) Cptr; \
    static Ptr create(); \

}

#endif // _NODEC_EVENT_EMITTER_H_
