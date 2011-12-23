#ifndef _NODEC_GC_BASE_H_
#define _NODEC_GC_BASE_H_

#include "config.h"

namespace nodec {

#ifdef NODEC_USE_BOEHM_GC
class GCBase : public gc_cleanup {
};
#else
class GCBase {
protected:
    virtual ~GCBase() {}
};
#endif

}

#endif // _NODEC_GC_BASE_H_
