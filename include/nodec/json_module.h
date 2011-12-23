#ifndef _NODEC_JSON_MODULE_H_
#define _NODEC_JSON_MODULE_H_

#include "module.h"
#include "value.h"
#include "string.h"

namespace nodec {

class JsonModule : public Singleton<JsonModule> { MODULE(JsonModule)
public:
    Value parse(Type<String>::Cptr);
    Type<String>::Cptr stringify(Value);
};

MODULE_TYPE(JsonModule);

}

#endif // _NODEC_JSON_MODULE_H_
