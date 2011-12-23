//g++ -fsyntax-only ../include/nodec/*
//g++ -I../include -I../deps/ test.cpp
//g++ -DNODEC_USE_BOEHM_GC -I../include -I../deps/ test.cpp -lgc

#include <nodec/array.h>
#include <nodec/server.h>
#include <nodec/http_module.h>

#include <vector>
#include <iostream>

#ifdef NODEC_USE_BOEHM_GC
#define BOEHM_GC_INIT
//#define BOEHM_GC_FINALIZE
#endif

#ifdef BOEHM_GC_INIT
#include "gc.h"
#endif

#ifdef BOEHM_GC_FINALIZE
#include "javaxfc.h"
#endif

namespace nodec {

class StringImpl : public String {
public:
    Type<String>::Cptr charAt(int) { Type<String>::Cptr p(new StringImpl()); return p; }
    Type<String>::Cptr substring(int) { Type<String>::Cptr p(new StringImpl()); return p; }
    Type<String>::Cptr substring(int, int) { Type<String>::Cptr p(new StringImpl()); return p; }
    Type<String>::Cptr concat(Type<String>::Cptr) { Type<String>::Cptr p(new StringImpl()); return p; }
    Type<String>::Cptr toString() { Type<String>::Cptr p(new StringImpl()); return p; }
};

Type<String>::Cptr String::create(const char* s) { Type<String>::Cptr p(new StringImpl()); return p; }

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
    Type<Array>::Ptr clone() { Type<Array>::Ptr p(new ArrayImpl()); return p; }
    Type<String>::Cptr toString() { return String::create(""); }
    
private:
    std::vector<Value> vec_;
    
public:
    ~ArrayImpl() {
        std::cout << "destruct ArrayImpl" << std::endl;
    }
};

Type<Array>::Ptr Array::create() { Type<Array>::Ptr p(new ArrayImpl()); return p; }

class ServerImpl : public Server {
public:
    void listen(int) {}
    void listen(Type<String>::Cptr) {}
    void close() {}
    Type<Server>::Ptr clone() { Type<Server>::Ptr p(new ServerImpl()); return p; }
    Type<String>::Cptr toString() { return String::create(""); }
    
    ~ServerImpl() {
        std::cout << "destroy ServerImpl" << std::endl;
    }
};

Type<Server>::Ptr Server::create() { Type<Server>::Ptr p(new ServerImpl()); return p; }

Type<Server>::Ptr HttpModule::createServer() { return Server::create(); }
Type<String>::Cptr HttpModule::toString() { return String::create(""); }

}

#include <iostream>

int main() {
    using namespace std;
    using namespace nodec;
    
#ifdef BOEHM_GC_INIT
    GC_INIT();
#endif
    
    Type<Array>::Ptr a = Array::create();
    
//  error: noncopyable
//    ArrayImpl ai;
//    ArrayImpl bi = ai;

    a->push(7);
    int i = boost::any_cast<int>(a->get(0));
    cout << a->length() << " "
#ifdef NODEC_USE_SP
         << a.use_count()
#endif
         << endl;
    Type<Array>::Ptr b = a;
    b->push(9);
    b->push(11);
    cout << a->length() << " "
#ifdef NODEC_USE_SP
         << a.use_count()
#endif
         << endl;
    cout << boost::any_cast<int>(a->get(0)) << " "
         << boost::any_cast<int>(a->get(1)) << " "
         << boost::any_cast<int>(a->get(2)) << endl;
         
//  error: singleton
//    new HttpModule();


    Type<HttpModule>::Ptr http = HttpModule::get();
#ifdef INFINITE_LOOP
    while (1)
#endif
    {
        Type<Server>::Ptr s = http->createServer();
    }

#if NODEC_USE_BOEHM_BC    
    GC_gcollect();
#endif

#ifdef BOEHM_GC_FINALIZE
    GC_finalize_all();
#endif

    return 0;
}
