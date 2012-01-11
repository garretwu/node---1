#include <gtest/gtest.h>
#include <nodec/mutable.h>
#include <nodec/string.h>

class GTestMutable : NODEC_MUTABLE(GTestMutable)
};

class GTestMutableImpl : public GTestMutable {
public:
    nodec::Type<GTestMutable>::Ptr clone() const {
        return GTestMutable::create();
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

nodec::Type<GTestMutable>::Ptr GTestMutable::create() {
    nodec::Type<GTestMutable>::Ptr p(new GTestMutableImpl);
    return p;
}

#ifdef NODEC_GTEST_BUILD_ERRORS
//#define NODEC_GTEST_MUTABLE_BUILD_ERRORS
#endif

#ifdef NODEC_GTEST_MUTABLE_BUILD_ERRORS
TEST(GTestMutalbe, Error)
{
    nodec::Type<GTestMutable>::Ptr p = GTestMutable::create();
    nodec::Type<nodec::Immutable>::Cptr p2 = p;
}

TEST(GTestMutable, Error2)
{
    new GTestMutable();
}

TEST(GTestMutable, Error3)
{
    // noncopyable
    GTestMutableImpl x, y = x;
}

TEST(GTestMutable, Error4)
{
    // noncopyable
    GTestMutableImpl x, y;
    x = y;
}
#endif

class GTestMutableX {
    virtual int x() {}
};

TEST(GTestMutable, Test)
{
    // check EBCO
    ASSERT_EQ(sizeof(GTestMutableImpl), sizeof(nodec::GCBase) + sizeof(GTestMutableX));
}

TEST(GTestMutable, Test2)
{
    // no build errors
    nodec::Type<GTestMutable>::Ptr p = GTestMutable::create();
    nodec::Type<nodec::Mutable>::Ptr p2 = p;
    nodec::Type<nodec::Mutable>::Cptr p3 = p;
    nodec::Type<nodec::Object>::Ptr p4 = p;
    nodec::Type<nodec::Object>::Cptr p5 = p;
}

TEST(GTestMutable, Test3)
{
    nodec::Type<GTestMutable>::Ptr p = GTestMutable::create();
    ASSERT_TRUE(p->instanceOf(nodec::Type<GTestMutable>::id()));
    ASSERT_TRUE(p->instanceOf(nodec::Type<nodec::Mutable>::id()));
    ASSERT_TRUE(p->instanceOf(nodec::Type<nodec::Object>::id()));
}

#ifdef NODEC_USE_SP
TEST(GTestMutable, Test4)
{
    {
        nodec::Type<GTestMutable>::Ptr p = GTestMutable::create();
        ASSERT_EQ(p.use_count(), 1);
        ASSERT_EQ(GTestMutableImpl::count, 1);
        
        nodec::Type<GTestMutable>::Ptr p2 = GTestMutable::create();
        ASSERT_EQ(p2.use_count(), 1);
        ASSERT_EQ(GTestMutableImpl::count, 2);
        
        p = p2;
        ASSERT_EQ(p.use_count(), 2);
        ASSERT_EQ(p2.use_count(), 2);
        ASSERT_EQ(GTestMutableImpl::count, 1);
    }
    ASSERT_EQ(GTestMutableImpl::count, 0);
}
#endif
