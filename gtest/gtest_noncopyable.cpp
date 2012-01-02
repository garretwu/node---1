#include <gtest/gtest.h>
#include <nodec/noncopyable.h>
#include <boost/noncopyable.hpp>

#ifdef NODEC_GTEST_BUILD_ERRORS
//#define NODEC_GTEST_NONCOPYABLE_BUILD_ERRORS
#endif

#ifdef NODEC_GTEST_NONCOPYABLE_BUILD_ERRORS
TEST(GTestNonCopyable, Error)
{
    nodec::NonCopyable<int> nc;
}

class GTestNC : private nodec::NonCopyable<GTestNC> {
//class GTestNC : private boost::noncopyable {
};

TEST(GTestNonCopyable, Error2)
{
    GTestNC nc1, nc2 = nc1;
}

TEST(GTestNonCopyable, Error3)
{
    GTestNC nc1, nc2; nc1 = nc2;
}
#endif
