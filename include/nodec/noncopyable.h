#ifndef _NODEC_NONCOPYABLE_H_
#define _NODEC_NONCOPYABLE_H_

namespace nodec {

class NonCopyable {
protected:
    NonCopyable() {}
    ~NonCopyable() {}

private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
};

}

#endif // _NODEC_NONCOPYABLE_H_
