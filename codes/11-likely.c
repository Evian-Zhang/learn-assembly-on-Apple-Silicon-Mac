#define likely(x)    __builtin_expect(!!(x), 1)
#define unlikely(x)  __builtin_expect(!!(x), 0)

extern void foo();
extern void bar();

void likely_pattern(int a) {
    if (likely(a > 0)) {
        foo();
    } else {
        bar();
    }
}

void unlikely_pattern(int a) {
    if (unlikely(a > 0)) {
        foo();
    } else {
        bar();
    }
}
