#ifndef _NODEC_JSON_MODULE_H_
#define _NODEC_JSON_MODULE_H_

#include "singleton.h"
#include "string.h"

namespace nodec {

class JsonModule : SINGLETON(JsonModule)
public:
    Value parse(Type<String>::Cptr);
    Type<String>::Cptr stringify(Value);
};

}

#endif // _NODEC_JSON_MODULE_H_
