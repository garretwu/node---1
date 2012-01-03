#include <string.h>
#include <nodec/string.h>

namespace nodec {

Size NOPOS = -1;

template<typename T>
class StringImpl : public String {
public:
    Size length() const { return str.length(); }
    
    Char charAt(Size index) const { return str.at(index); }
    
    Cptr substring(Size begin) const {
        Cptr p(new StringImpl(str, begin));
        return p;
    }
    
    Cptr substring(Size begin, Size end) const {
        Cptr p(new StringImpl(str, begin, end - begin));
        return p;
    }
    
    Cptr concat(Cptr other) const {
        std::basic_string<T> s(str);
        s.append(other->toCStr());
        Cptr p(new StringImpl(s));
        return p;
    }
    
    bool compareTo(Cptr) const { return false; }
    bool startsWith(Cptr) const { return false; }
    bool startsWith(Cptr, Size) const { return false; }
    bool endsWith(Cptr) const { return false; }
    bool endsWith(Cptr, Size) const { return false; }
    Size indexOf(Char) const { return 0; }
    Size indexOf(Char, Size) const { return 0; }
    Size indexOf(Cptr) const { return 0; }
    Size indexOf(Cptr, Size) const { return 0; }
    Size lastIndexOf(Char) const { return 0; }
    Size lastIndexOf(Char, Size) const { return 0; }
    Size lastIndexOf(Cptr) const { return 0; }
    Size lastIndexOf(Cptr, Size) const { return 0; }
    
    const Char* toCStr() const {
        return str.c_str();
    }
    
    Cptr toString() {
        return create();
    }
    
protected:
    std::basic_string<T> str;
    
    StringImpl() : str() {}
    StringImpl(const std::basic_string<T>& s) : str(s) {}
    StringImpl(
        const std::basic_string<T>& s,
        Size pos,
        Size count = NOPOS)
        : str(s, pos, count) {}
};

class Utf32String : public StringImpl<uint32_t> {
public:
    static Cptr create() { Cptr p(new Utf32String()); return p; }
    static Cptr create(const char* s) { Cptr p(new Utf32String()); return p; }
};

Type<String>::Cptr String::create() { return Utf32String::create(); }
Type<String>::Cptr String::create(const char* s) { return Utf32String::create(s); }

}
