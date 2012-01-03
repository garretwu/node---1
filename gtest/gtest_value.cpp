#include <gtest/gtest.h>
#include <nodec/value.h>
#include <boost/any.hpp>

#ifdef NODEC_GTEST_BUILD_ERRORS
//#define NODEC_GTEST_VALUE_BUILD_ERRORS
#endif

#ifdef NODEC_GTEST_VALUE_BUILD_ERRORS
TEST(GTestValue, Error)
{
    const nodec::Value v = 3;
    v = 5;
}

TEST(GTestAny, Error)
{
    const boost::any a = 3;
    a = 5;
}

#if 0
// OK
TEST(GTestValue, Error2)
{
    const nodec::Value v = 3;
    
    int i;
    int& ir = i;
    ASSERT_TRUE(nodec::to<int&>(v, &ir));
    ASSERT_EQ(ir, 3);
}
#endif

TEST(GTestAny, Error2)
{
    const boost::any a = 3;

    int i;
    int& ir = i;
    ir = boost::any_cast<int&>(a);
}

TEST(GTestValue, Error3)
{
    int* ip;
    nodec::Value v = 5;
    nodec::Value* vp = &v;
    nodec::to<const int>(vp, &ip);
}

TEST(GTestAny, Error3)
{
    boost::any a = 5;
    boost::any* ap = &a;
    int* ip = boost::any_cast<const int>(ap);
}

TEST(GTestValue, Error4)
{
    nodec::Value v = 3;
    const nodec::Value* vp = &v;
    
    int* ip;
    ASSERT_TRUE(nodec::to<int>(vp, &ip));
    ASSERT_EQ(*ip, 3);
}

TEST(GTestAny, Error4)
{
    boost::any a = 3;
    const boost::any* ap = &a;
    
    int* ip  = boost::any_cast<int>(ap);
    ASSERT_EQ(*ip, 3);
}
#endif

TEST(GTestValue, Test)
{
    nodec::Value v = 3;
    
    int i;
    ASSERT_TRUE(nodec::to<int>(v, &i));
    ASSERT_EQ(i, 3);
    
    v = 5;
    ASSERT_TRUE(nodec::to<const int>(v, &i));
    ASSERT_EQ(i, 5);
    
    long l;
    ASSERT_FALSE(nodec::to<long>(v, &l));
}

TEST(GTestAny, Test)
{
    boost::any a = 3;
    
    int i = boost::any_cast<int>(a);
    ASSERT_EQ(i, 3);
    
    a = 5;
    i = boost::any_cast<const int>(a);
    ASSERT_EQ(i, 5);
    
    ASSERT_ANY_THROW(long l = boost::any_cast<long>(a));
}

TEST(GTestValue, Test2)
{
    const int ci = 5;
    nodec::Value v = ci;
    
    int i;
    ASSERT_TRUE(nodec::to<int>(v, &i));
    ASSERT_EQ(i, 5);
}

TEST(GTestAny, Test2)
{
    const int ci = 5;
    boost::any a = ci;
    
    int i = boost::any_cast<int>(a);
    ASSERT_EQ(i, 5);
}

TEST(GTestValue, Test3)
{
    int i = 9;
    nodec::Value v = &i;
    
    int* ip;
    ASSERT_TRUE(nodec::to<int*>(v, &ip));
    ASSERT_EQ(ip, &i);
    
    const int* cip;
    ASSERT_FALSE(nodec::to<const int*>(v, &cip));
}

TEST(GTestAny, Test3)
{
    int i = 9;
    boost::any a = &i;
    
    int* ip = boost::any_cast<int*>(a);
    ASSERT_EQ(ip, &i);
    
    ASSERT_ANY_THROW(const int* cip = boost::any_cast<const int*>(a));
}

TEST(GTestValue, Test4)
{
    const int i = 11;
    nodec::Value v = &i;
    
    int* ip;
    ASSERT_FALSE(nodec::to<int*>(v, &ip));
    
    const int* cip;
    ASSERT_TRUE(nodec::to<const int*>(v, &cip));
    ASSERT_EQ(cip, &i);
}

TEST(GTestAny, Test4)
{
    const int i = 11;
    boost::any a = &i;
    
    ASSERT_ANY_THROW(int* ip = boost::any_cast<int*>(a));
    
    const int* cip = boost::any_cast<const int*>(a);
    ASSERT_EQ(cip, &i);
}

TEST(GTestValue, Test5)
{
    nodec::Value v = 3;
    
    int i;
    int& ir = i;
    ASSERT_TRUE(nodec::to<int&>(v, &ir));
    ASSERT_EQ(ir, 3);
    
    v = 5;
    ASSERT_TRUE(nodec::to<const int&>(v, &ir));
    ASSERT_EQ(ir, 5);
    
    long l;
    long& lr = l;
    ASSERT_FALSE(nodec::to<long&>(v, &lr));
}

TEST(GTestAny, Test5)
{
    boost::any a = 3;
    
    int i;
    int& ir = i;
    ir = boost::any_cast<int&>(a);
    ASSERT_EQ(ir, 3);
    
    a = 5;
    ir = boost::any_cast<const int&>(a);
    ASSERT_EQ(ir, 5);
    
    long l;
    long& lr = l;
    ASSERT_ANY_THROW(lr = boost::any_cast<long&>(a));
}

TEST(GTestValue, Test6)
{
    const nodec::Value v = 3;
    
    int i;
    ASSERT_TRUE(nodec::to<int>(v, &i));
    ASSERT_EQ(i, 3);
    
    ASSERT_TRUE(nodec::to<const int>(v, &i));
    ASSERT_EQ(i, 3);
    
    long l;
    ASSERT_FALSE(nodec::to<long>(v, &l));
}

TEST(GTestAny, Test6)
{
    const boost::any a = 3;
    
    int i = boost::any_cast<int>(a);
    ASSERT_EQ(i, 3);
    
    i = boost::any_cast<const int>(a);
    ASSERT_EQ(i, 3);
    
    ASSERT_ANY_THROW(long l = boost::any_cast<long>(a));
}

TEST(GTestValue, Test7)
{
    const nodec::Value v = 3;
    
    int i;
    int& ir = i;
    ASSERT_TRUE(nodec::to<const int&>(v, &ir));
    ASSERT_EQ(ir, 3);
}

TEST(GTestAny, Test7)
{
    const boost::any a = 3;
    
    int i;
    int& ir = i;
    ir = boost::any_cast<const int&>(a);
    ASSERT_EQ(ir, 3);
}

TEST(GTestValue, Test8)
{
    nodec::Value v = 3;
    nodec::Value* vp = &v;
    
    int* ip;
    ASSERT_TRUE(nodec::to<int>(vp, &ip));
    ASSERT_EQ(*ip, 3);
    
    
    long* lp;
#if 1
    ASSERT_FALSE(nodec::to<long>(vp, &lp));
#else
    ASSERT_TRUE(nodec::to<long>(vp, &lp));
    ASSERT_EQ(*lp, 3);
#endif
}

TEST(GTestAny, Test8)
{
    boost::any a = 3;
    boost::any* ap = &a;
    
    int* ip  = boost::any_cast<int>(ap);
    ASSERT_EQ(*ip, 3);
    
//    Segmentation fault
//    long* lp = boost::any_cast<long>(ap);
//    ASSERT_EQ(*lp, 3);
}

TEST(GTestValue, Test9)
{
    nodec::Value v = 3;
    const nodec::Value* vp = &v;
    
    const int* ip;
    ASSERT_TRUE(nodec::to<int>(vp, &ip));
    ASSERT_EQ(*ip, 3);
    
    v = 5;
    ASSERT_TRUE(nodec::to<const int>(vp, &ip));
    ASSERT_EQ(*ip, 5);
}

TEST(GTestAny, Test9)
{
    boost::any a = 3;
    const boost::any* ap = &a;
    
    const int* ip = boost::any_cast<int>(ap);
    ASSERT_EQ(*ip, 3);
    
    a = 5;
    ip = boost::any_cast<const int>(ap);
    ASSERT_EQ(*ip, 5);
}
