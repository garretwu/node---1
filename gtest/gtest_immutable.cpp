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
    nodec::Type<nodec::String>::Cptr toString() const {
        nodec::Type<nodec::String>::Cptr p;
        return p;
    }
    
    static int count;
    
    GTestImmutableImpl() : GTestImmutable() { count++; }
    ~GTestImmutableImpl() { count--; }
};

int GTestImmutableImpl::count = 0;

#ifdef NODEC_GTEST_BUILD_ERRORS
//#define NODEC_GTEST_IMMUTABLE_BUILD_ERRORS
#endif

#ifdef NODEC_GTEST_IMMUTABLE_BUILD_ERRORS
TEST(GTestImmutalbe, Error)
{
    nodec::Type<GTestImmutable>::Ptr p;
}

TEST(GTestImmutable, Error2)
{
    nodec::Type<GTestImmutable>::Cptr p(new GTestImmutableImpl());
    nodec::Type<nodec::Object>::Ptr p2 = p;
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

TEST(GTestImmutable, Test2)
{
    // no build errors
    nodec::Type<GTestImmutable>::Cptr p(new GTestImmutableImpl());
    nodec::Type<nodec::Immutable>::Cptr p2 = p;
    nodec::Type<nodec::Object>::Cptr p3 = p;
}

TEST(GTestImmutable, Test3)
{
    nodec::Type<GTestImmutable>::Cptr p(new GTestImmutableImpl());
    ASSERT_TRUE(p->instanceOf(nodec::Type<GTestImmutable>::id()));
    ASSERT_TRUE(p->instanceOf(nodec::Type<nodec::Immutable>::id()));
    ASSERT_TRUE(p->instanceOf(nodec::Type<nodec::Object>::id()));
}

#ifdef NODEC_USE_SP
TEST(GTestImmutable, Test4)
{
    {
        nodec::Type<GTestImmutable>::Cptr p(new GTestImmutableImpl());
        ASSERT_EQ(p.use_count(), 1);
        ASSERT_EQ(GTestImmutableImpl::count, 1);
    }
    ASSERT_EQ(GTestImmutableImpl::count, 0);
}
#endif
