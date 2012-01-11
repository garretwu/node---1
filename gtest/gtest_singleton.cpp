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

TEST(GTestSingleton, Test2)
{
    // no build errors
    nodec::Type<GTestSingleton>::Ptr p = GTestSingleton::instance();
    nodec::Type<nodec::Singleton>::Ptr p2 = p;
    nodec::Type<nodec::Singleton>::Cptr p3 = p;
    nodec::Type<nodec::Object>::Ptr p4(p);
    nodec::Type<nodec::Object>::Cptr p5(p);
}

TEST(GTestSingleton, Test3)
{
    nodec::Type<GTestSingleton>::Ptr p = GTestSingleton::instance();
    ASSERT_TRUE(p->instanceOf(nodec::Type<GTestSingleton>::id()));
    ASSERT_TRUE(p->instanceOf(nodec::Type<nodec::Singleton>::id()));
    ASSERT_TRUE(p->instanceOf(nodec::Type<nodec::Object>::id()));
}

#ifdef NODEC_USE_SP
class GTestSingleton2 : public nodec::SingletonBase<GTestSingleton2> {
public:
    nodec::TypeId type() const {
        return nodec::Type<GTestSingleton2>::id();
    }
    
    static int count;
    
private:
    friend class nodec::SingletonBase<GTestSingleton2>;
    GTestSingleton2() : nodec::SingletonBase<GTestSingleton2>() { count++; }
    ~GTestSingleton2() { count--; }
};

int GTestSingleton2::count = 0;

TEST(GTestSingleton, Test4)
{
    {
        nodec::Type<GTestSingleton2>::Ptr p = GTestSingleton2::instance();
        ASSERT_EQ(p.use_count(), 1);
        ASSERT_EQ(GTestSingleton2::count, 1);
        
        nodec::Type<GTestSingleton2>::Ptr p2 = GTestSingleton2::instance();
        ASSERT_EQ(p.use_count(), 1);
        ASSERT_EQ(GTestSingleton2::count, 1);
        
        p = p2;
        ASSERT_EQ(p.use_count(), 2);
        ASSERT_EQ(p2.use_count(), 2);
        ASSERT_EQ(GTestSingleton2::count, 1);
    }
    ASSERT_EQ(GTestSingleton2::count, 1);
    
}
#endif
