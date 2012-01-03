#include <gtest/gtest.h>
#include <nodec/clonable.h>
#include <nodec/type.h>

#ifdef NODEC_GTEST_BUILD_ERRORS
//#define NODEC_GTEST_CLONABLE_BUILD_ERRORS
#endif

#ifdef NODEC_GTEST_CLONABLE_BUILD_ERRORS
TEST(GTestClonable, Error)
{
    nodec::Clonable<int> c;
}
#endif

class GTestClonable
    : public nodec::Mutable
    , public nodec::Clonable<GTestClonable> {
public:
    virtual void set(int) = 0;
    virtual int get() = 0;
};

class GTestClonableImpl
    : public GTestClonable {
public:
    void set(int n) { val = n; }
    int get() { return val; }
    
    nodec::Type<GTestClonable>::Ptr clone() const {
        GTestClonableImpl* x = new GTestClonableImpl;
        x->set(this->val);
        nodec::Type<GTestClonable>::Ptr p(x);
        return p;
    }
    
private:
    int val;
};

TEST(GTestClonable, Test)
{
    nodec::Type<GTestClonable>::Ptr p1(new GTestClonableImpl);
    p1->set(5);
    ASSERT_EQ(5, p1->get());
    nodec::Type<GTestClonable>::Ptr p2(p1->clone());
    ASSERT_EQ(5, p2->get());
    p2->set(7);
    ASSERT_EQ(7, p2->get());
    ASSERT_EQ(5, p1->get());
}

