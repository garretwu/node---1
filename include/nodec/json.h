#ifndef _NODEC_JSON_H_
#define _NODEC_JSON_H_

#include "singleton.h"
//#include "string.h"

namespace nodec {

class Json : SINGLETON(Json)
public:
    static Value parse(Type<String>::Cptr);
    static Type<String>::Cptr stringify(Value);
};

}

#endif // _NODEC_JSON_H_
