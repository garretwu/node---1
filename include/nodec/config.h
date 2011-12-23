#ifndef _NODEC_CONFIG_H_
#define _NODEC_CONFIG_H_

#ifdef NODEC_USE_BOEHM_GC
#include <gc_cpp.h>
#else
#define NODEC_USE_SP
#endif

#endif // _NODEC_CONFIG_H_