#ifdef NODEC_USE_BOEHM_GC
#include "gc.h"
#endif

int main() {
#ifdef NODEC_USE_BOEHM_GC
    GC_INIT();
#endif


#ifdef NODEC_USE_BOEHM_GC
    GC_gcollect();
#endif
    return 0;
}
