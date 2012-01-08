//g++ -I../deps/ -fsyntax-only -fno-rtti -fno-exceptions ../include/nodec/*

#include <nodec/http_server.h>
#include <nodec/json.h>

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

#include <iostream>

int main() {
    using namespace std;
    using namespace nodec;
    using namespace boost;
    
#ifdef BOEHM_GC_INIT
    GC_INIT();
#endif
    
    Type<Array>::Ptr a = Array::create();
    
//  error: noncopyable
//    ArrayImpl ai;
//    ArrayImpl bi = ai;

    a->push(7);
    int i;
    to<int>(a->get(0), &i);
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
    int j[3];
    to<int>(a->get(0), &j[0]);
    to<int>(a->get(1), &j[1]);
    to<int>(a->get(2), &j[2]);
    for (i = 0; i < sizeof(j)/sizeof(int); i++) {
        cout << j[i] << " ";
    }
    cout << endl;

//  error: singleton
//    new HttpModule();

#ifdef INFINITE_LOOP
    while (1)
#endif
    {
        Type<HttpServer>::Ptr s = HttpServer::create();
    }
    
    Type<Json>::Ptr json = Json::instance();
    json->toString();
    cout << Type<Json>::id() << endl;
    cout << json->instanceOf(Type<Json>::id())  << " "
         << json->instanceOf(Type<Singleton>::id()) << " "
         << json->instanceOf(Type<Immutable>::id()) << endl;

#ifdef NODEC_USE_BOEHM_GC
    GC_gcollect();
#endif

#ifdef BOEHM_GC_FINALIZE
    GC_finalize_all();
#endif

    return 0;
}
