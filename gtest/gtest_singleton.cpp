#include <gtest/gtest.h>
#include <nodec/singleton.h>

class GTestSingleton : NODEC_SINGLETON(GTestSingleton)
};

class GTestSingletonX {
    virtual int x() {}
};

TEST(GTestSingleton, Test)
{
    // check EBCO
    ASSERT_EQ(sizeof(GTestSingleton), sizeof(GTestSingletonX));
}

/*
TEST(GTestSingleton, Test2)
{
    // no build errors
    nodec::Type<GTestSingleton>::Ptr p = GTestSingleton::instance();
    nodec::Type<nodec::Singleton>::Ptr p2 = p;
    nodec::Type<nodec::Singleton>::Cptr p3 = p;
    nodec::Type<nodec::Object>::Ptr p4(p);
    nodec::Type<nodec::Object>::Cptr p5(p);
}
*/

