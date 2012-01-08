#include <nodec/http_server.h>

namespace nodec {

class HttpServerImpl : public HttpServer {
public:
    void listen(int) {}
    void listen(Type<String>::Cptr) {}
    void close() {}
    Type<HttpServer>::Ptr clone() const { Type<HttpServer>::Ptr p(new HttpServerImpl()); return p; }
    Type<String>::Cptr toString() const { return String::create(); }
};

Type<HttpServer>::Ptr HttpServer::create() { Type<HttpServer>::Ptr p(new HttpServerImpl()); return p; }

}
