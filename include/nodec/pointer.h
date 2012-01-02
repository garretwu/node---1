#ifndef _NODEC_POINTER_H_
#define _NODEC_POINTER_H_

#include "config.h"

#ifdef NODEC_USE_SP
#include "shared_ptr.h"
#define NODEC_PTR(T) nodec::SharedPtr<T>::Type
#define NODEC_CPTR(T) nodec::SharedPtr<const T>::Type
#define NODEC_PTR_TYPE(T) typename nodec::SharedPtr<T>::Type
#define NODEC_CPTR_TYPE(T) typename nodec::SharedPtr<const T>::Type
#else
#define NODEC_PTR(T) T*
#define NODEC_CPTR(T) const T*
#define NODEC_PTR_TYPE(T) T*
#define NODEC_CPTR_TYPE(T) const T*
#endif

#endif // _NODEC_POINTER_H_
