#ifdef int
#undef int
#define DEFINE_INT_LL
#endif

#include <atcoder/all>
using namespace atcoder;

#ifdef DEFINE_INT_LL
#undef DEFINE_INT_LL
#define int LL
#endif
