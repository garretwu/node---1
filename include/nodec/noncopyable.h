#ifndef _NODEC_NONCOPYABLE_H_
#define _NODEC_NONCOPYABLE_H_

namespace nodec {

template<typename T>
class NonCopyable {
protected:
    NonCopyable() {}
    ~NonCopyable() {}

private:
    NonCopyable(const NonCopyable&);
    T& operator=(const T&);
};

}

#endif // _NODEC_NONCOPYABLE_H_
