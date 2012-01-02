#include <gtest/gtest.h>
#include <nodec/mutable.h>
#include <nodec/string.h>

class GTestMutable
    : public nodec::Mutable
    , public nodec::MutableBase<GTestMutable> {
};

class GTestMutableImpl
    : public GTestMutable {
public:
    nodec::Type<GTestMutable>::Ptr clone() {
        nodec::Type<GTestMutable>::Ptr p(new GTestMutableImpl);
        return p;
    }
    
    nodec::Type<nodec::String>::Cptr toString() {
        nodec::Type<nodec::String>::Cptr p;
        return p;
    }
};

class GTestMutableBase {
    virtual int x() {}
};

TEST(GTestMutable, Test)
{
    // check EBCO
    ASSERT_EQ(sizeof(GTestMutableImpl), sizeof(nodec::GCBase) + sizeof(GTestMutableBase));
}
