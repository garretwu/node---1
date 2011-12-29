#ifndef _NODEC_JSON_H_
#define _NODEC_JSON_H_

#include "singleton.h"

namespace nodec {

class Json : NODEC_SINGLETON(Json)
public:
    static Value parse(Type<String>::Cptr);
    static Type<String>::Cptr stringify(Value);
};

}

#endif // _NODEC_JSON_H_
