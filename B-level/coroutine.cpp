#include <iostream>
using namespace std;

#define CORO_REENTER_IMPL(c) \
  switch (coroutine_stackless_ref _coro_value = c) \
    case -1: if (_coro_value) \
             { \
      goto terminate_coroutine; \
              terminate_coroutine: \
      _coro_value = -1; \
      goto bail_out_of_coroutine; \
              bail_out_of_coroutine: \
      break; \
              } \
              else case 0:

//放弃退出
#define CORO_YIELD_IMPL(n,ms) \
  for (_coro_value = (n);;) \
    if (_coro_value == 0) \
                    { \
      case (n): ; \
      break; \
                    } \
                    else \
      switch (_coro_value ? 0 : 1) \
        for (;;) \
          case -1: if (_coro_value) \
            goto terminate_coroutine; \
                   else for (;;) \
            case 1: if (_coro_value) \
              goto bail_out_of_coroutine; \
                   else case 0:\
                     coroutine_stackless_wait(c,id,ms);

int main()
{

    return 0;
}