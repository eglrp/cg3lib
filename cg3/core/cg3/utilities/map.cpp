#include "map.h"
namespace cg3 {

/**
 * \~English
 * @brief this function flips a std::map on a std::multimap. All the elements of the multimap will be sorted by the value of the map.
 * @param[in] src: input map
 * @return the flipped multimap
 */
template<typename A, typename B, template<class,class,class...> class M, class... Args>
inline std::multimap<B,A> flipMap(const M<A,B,Args...> &src) {
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(),
                   std::inserter(dst, dst.begin()),
                   flipPair<A,B>);
    return dst;
}

}
