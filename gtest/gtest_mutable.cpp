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
    nodec::Type<GTestMutable>::Ptr clone() const {
        nodec::Type<GTestMutable>::Ptr p(new GTestMutableImpl);
        return p;
    }
    
    nodec::Type<nodec::String>::Cptr toString() const {
        nodec::Type<nodec::String>::Cptr p;
        return p;
    }
    
    static int count;
    
    GTestMutableImpl() : GTestMutable() { count++; }
    ~GTestMutableImpl() { count--; }
};

int GTestMutableImpl::count = 0;

#ifdef NODEC_GTEST_BUILD_ERRORS
//#define NODEC_GTEST_MUTABLE_BUILD_ERRORS
#endif

#ifdef NODEC_GTEST_MUTABLE_BUILD_ERRORS
TEST(GTestImmutalbe, Error)
{
    nodec::Type<GTestMutable>::Ptr p(new GTestMutableImpl());
    nodec::Type<nodec::Immutable>::Cptr p2 = p;
}
#endif

class GTestMutableBase {
    virtual int x() {}
};

TEST(GTestMutable, Test)
{
    // check EBCO
    ASSERT_EQ(sizeof(GTestMutableImpl), sizeof(nodec::GCBase) + sizeof(GTestMutableBase));
}

TEST(GTestMutable, Test2)
{
    // no build errors
    nodec::Type<GTestMutable>::Ptr p(new GTestMutableImpl());
    nodec::Type<nodec::Mutable>::Ptr p2 = p;
    nodec::Type<nodec::Mutable>::Cptr p3 = p;
    nodec::Type<nodec::Object>::Ptr p4 = p;
    nodec::Type<nodec::Object>::Cptr p5 = p;
}

TEST(GTestMutable, Test3)
{
    nodec::Type<GTestMutable>::Ptr p(new GTestMutableImpl());
    ASSERT_TRUE(p->instanceOf(nodec::Type<GTestMutable>::id()));
    ASSERT_TRUE(p->instanceOf(nodec::Type<nodec::Mutable>::id()));
    ASSERT_TRUE(p->instanceOf(nodec::Type<nodec::Object>::id()));
}

#ifdef NODEC_USE_SP
TEST(GTestMutable, Test4)
{
    {
        nodec::Type<GTestMutable>::Ptr p(new GTestMutableImpl());
        ASSERT_EQ(p.use_count(), 1);
        ASSERT_EQ(GTestMutableImpl::count, 1);
    }
    ASSERT_EQ(GTestMutableImpl::count, 0);
}
#endif
