#include <cstdlib>
#include <cassert>
#include <iostream>

/**
 *  Utility.
 */

#define freen(p)    do { free(p); p = nullptr; } while (0)

/**
 *  Coroutine with context.
 */

using co_ctx_t = void*;

#define CCO_CTX_PARAM       void** __co_ctx_param

#define CCO_CTX_DECL_BEGIN      struct __co_ctx_t { int state
#define CCO_CTX_DECL_END(ctx)   } *ctx = (__co_ctx_t*)*__co_ctx_param

#define CCO_BEGIN_WITH(ctx)                             \
	if (!ctx) {                                         \
		*__co_ctx_param = malloc(sizeof(*ctx));         \
		ctx = (__co_ctx_t*)*__co_ctx_param;      \
		assert(ctx);                                    \
		ctx->state = 0;                                 \
	}                                                   \
	switch (ctx->state) {                               \
	case 0:;
#define CCO_END_WITH(v)     \
	}                       \
	freen(*__co_ctx_param); \
	return (v)
#define CCO_END             \
	}                       \
	freen(*__co_ctx_param); \
	return

#define CCO_YIELD_WITH(v)                                           \
	do {                                                            \
		((__co_ctx_t*)*__co_ctx_param)->state = __LINE__;    \
		return (v);                                                 \
		case __LINE__:;                                             \
	} while (0)
#define CCO_YIELD                                                   \
	do {                                                            \
		((__co_ctx_t*)*__co_ctx_param)->state = __LINE__;    \
		return;                                                     \
		case __LINE__:;                                             \
	} while (0)

#define CCO_RETURN_WITH(v)  \
	do { freen(*__co_ctx_param); return (v); } while (0)
#define CCO_RETURN  \
	do { freen(*__co_ctx_param); return; } while (0)

#define CCO_CTX_FREE(ctx)   freen(ctx)

namespace {

int generator(CCO_CTX_PARAM, int n)
{
CCO_CTX_DECL_BEGIN;
	int i;
CCO_CTX_DECL_END(foo);

CCO_BEGIN_WITH(foo);
	for (foo->i = 0; foo->i < n; foo->i++) {
		CCO_YIELD_WITH(foo->i);
	}
CCO_END_WITH(-1);
}

void
quack(CCO_CTX_PARAM)
{
CCO_CTX_DECL_BEGIN;
	int i;
CCO_CTX_DECL_END(foo);

CCO_BEGIN_WITH(foo);
	for (foo->i = 0; foo->i < 3; foo->i++) {
		std::cout << "quack!" << std::endl;
		CCO_YIELD;
	}
	throw std::runtime_error("i just can quack for 3 times");
CCO_END;
}

} /* namespace */

void test_reentrant_co()
{
	co_ctx_t ctx = nullptr;

	int n = 0;
	std::cout << "[";
	while (true) {
		n = generator(&ctx, 10);
		if (n == -1) {
			break;
		}
		std::cout << n << ",";
	}
	std::cout << "\b]" << std::endl;

	try {
		while (true) quack(&ctx);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	CCO_CTX_FREE(ctx);
}

int main()
{
	test_reentrant_co();
}