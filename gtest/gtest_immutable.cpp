#include <gtest/gtest.h>
#include <nodec/immutable.h>
#include <nodec/string.h>

class GTestImmutable
    : public nodec::Immutable
    , public nodec::ImmutableBase<GTestImmutable> {
};

class GTestImmutableImpl
    : public GTestImmutable {
public:
    nodec::Type<nodec::String>::Cptr toString() {
        nodec::Type<nodec::String>::Cptr p;
        return p;
    }
};

#ifdef NODEC_GTEST_BUILD_ERRORS
//#define NODEC_GTEST_IMMUTABLE_BUILD_ERRORS
#endif

#ifdef NODEC_GTEST_IMMUTABLE_BUILD_ERRORS
TEST(GTestImmutalbe, Error)
{
    nodec::Type<GTestImmutable>::Ptr p;
}
#endif

class GTestImmutableBase {
    virtual int x() {}
};

TEST(GTestImmutable, Test)
{
    // check EBCO
    ASSERT_EQ(sizeof(GTestImmutableImpl), sizeof(nodec::GCBase) + sizeof(GTestImmutableBase));
}
