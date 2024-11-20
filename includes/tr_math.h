#ifndef TR_MATH_H
#define TR_MATH_H

#include <cassert>

template<typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template <unsigned int N, typename T>
requires arithmetic<T>
struct Vec {
    T data[N];

    T& operator[](const unsigned int i) {
        assert(i < N);
        return data[i];
    }

    T operator[](const unsigned int i) const {
        assert(i < N);
        return data[i];
    }
};

template<unsigned int N, typename S, typename T>
requires arithmetic<S> && arithmetic<T>
auto operator*(const Vec<N, S>& lhs, const Vec<N, T>& rhs) {
    using ResultType = typename std::common_type<S, T>::type;
    ResultType ret{};
    for(unsigned int i = 0; i < N; i++) {
        ret += ((ResultType) lhs[i] * (ResultType) rhs[i]);
    }
    return ret;
}

typedef Vec<3, float> Vec3f;
typedef Vec<3, int> Vec3i;
typedef Vec<2, float> Vec2f;


#endif //TR_MATH_H

