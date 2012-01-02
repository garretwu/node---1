#include <cassert>
#include <exception>

namespace boost {

void throw_exception(const std::exception&) {
    assert(0);
}

}
