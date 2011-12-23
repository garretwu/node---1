#ifndef _NODEC_SHARED_PTR_H_
#define _NODEC_SHARED_PTR_H_

//#define NODEC_DISABLE_BOOST_SP_GET_DELETER
#include <boost/shared_ptr.hpp>

namespace nodec {

template<typename T>
struct SharedPtr
{
    typedef boost::shared_ptr<T> Type;
};

}

#endif // _NODEC_SHARED_PTR_H_
