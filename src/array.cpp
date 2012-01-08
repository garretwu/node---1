#include <vector>
#include <nodec/array.h>

namespace nodec {

class ArrayImpl : public Array {
public:    
    size_t length() const { return vec_.size(); }
    void set(size_t i, Value v) { vec_[i] = v; }
    Value get(size_t i) { return vec_[i]; }
    Value shift() { return 0; }
    void unshift(Value) {}
    void push(Value v) { vec_.push_back(v); }
    Value pop() { return 0; }
    Type<Array>::Ptr concat(Type<Array>::Cptr) { Type<Array>::Ptr p(new ArrayImpl()); return p; }
    Type<Array>::Ptr clone() const { Type<Array>::Ptr p(new ArrayImpl()); return p; }
    Type<String>::Cptr toString() const { return String::create(); }
    
private:
    std::vector<Value> vec_;
    
public:
    ~ArrayImpl() {
        std::cout << "destruct ArrayImpl" << std::endl;
    }
};

Type<Array>::Ptr Array::create() { Type<Array>::Ptr p(new ArrayImpl()); return p; }

}
