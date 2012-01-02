#include <nodec/string.h>

namespace nodec {

class StringImpl : public String {
public:
    Type<String>::Cptr charAt(int) { Type<String>::Cptr p(new StringImpl()); return p; }
    Type<String>::Cptr substring(int) { Type<String>::Cptr p(new StringImpl()); return p; }
    Type<String>::Cptr substring(int, int) { Type<String>::Cptr p(new StringImpl()); return p; }
    Type<String>::Cptr concat(Type<String>::Cptr) { Type<String>::Cptr p(new StringImpl()); return p; }
    Type<String>::Cptr toString() { Type<String>::Cptr p(new StringImpl()); return p; }
};

Type<String>::Cptr String::create() { Type<String>::Cptr p (new StringImpl()); return p; }
Type<String>::Cptr String::create(const char* s) { Type<String>::Cptr p(new StringImpl()); return p; }

}
