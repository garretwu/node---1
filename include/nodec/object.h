#ifndef _NODEC_OBJECT_H_
#define _NODEC_OBJECT_H_

#include "gc_base.h"
#include "stringifiable.h"

namespace nodec {

class Object
    : public GCBase
    , public Stringifiable {
};

}

#endif // _NODEC_OBJECT_H_
