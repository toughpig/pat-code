#include <iostream>
#include <cassert>
#include <chrono>
#include <thread>
using namespace std;

inline void print(int a){printf("%d\n",a);}

// 不带上下文的coro
static int __co_state = 0;
int static_reenter()
{
    switch(__co_state){case 0:;
            do {__co_state = __LINE__;return (-1);case __LINE__:;print(666);} while (0);
    } return -1;
}

// 带上下文的coro
#define freen(p)    do {free(p); p = nullptr; } while(0);

#define CORO_YIELD(n, ms) for(((__co_ctx_t*)*__co_ctx_param)->state = (n);;) { \
                            return (-1); \
                            if (false) { \
                                case (n):; \
                                print(n);break; \
                            } else { \
                                printf("sleep\n"); \
                                std::this_thread::sleep_for(std::chrono::milliseconds(1000)); \
                            }}

#define CORO_REENTER(__co_ctx_param)  struct __co_ctx_t {int state;int i;} *foo = (__co_ctx_t*)*__co_ctx_param; \
                            if (!foo) {*__co_ctx_param = malloc(sizeof(*foo));foo = (__co_ctx_t*)*__co_ctx_param;assert(foo); \
                            foo->state = 0;} switch (foo->state) {case 0:;;

#define yield(ms) CORO_YIELD(__COUNTER__ + 1, ms)
#define reenter CORO_REENTER(__co_ctx_param)
#define end_coro(v) } freen(*__co_ctx_param); return (v); 

int coreenter(void** __co_ctx_param)
{
    reenter{
        yield(100);
        printf("yield 1\n");
        yield(100);
        printf("yield 2\n");
        yield(100);
        printf("yield 3\n");
    }
    end_coro(-1);
}

// 经典 Duff's Device
// switch中的case标号可以出现在任意位置
// switch中嵌套while循环
// GCC7 以后的编译器，针对switch FallThrough的取消Warning选项 -Wimplicit-fallthrough=0
void classic_duffs_device()
{
    int n = 7;
    int count = (n + 7)/8;
    int cnt = 0;
    switch (n % 8)
    {
        case 0:
        {
            do{
                print(++cnt);
                case 7: print(++cnt);
                case 6: print(++cnt);
                case 5: print(++cnt);
                case 4: print(++cnt);
                case 3: print(++cnt);
                case 2: print(++cnt);
                case 1: print(++cnt);
            }while(--count);
        }
    }
}

int main()
{
    void *coro = nullptr;
    coreenter(&coro);
    coreenter(&coro);
    coreenter(&coro);
    coreenter(&coro);
    freen(coro);

    // classic_duffs_device();

    return 0;
}