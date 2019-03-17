#include "stdint.h"
#include "stddef.h"

#ifndef VEC_H
#define VEC_H

namespace lak
{
    template<typename T>
    struct vec2
    {
        union { T x; T r; };
        union { T y; T g; };
        inline T &operator[](const size_t index) { return (&x)[index]; }
        inline const T &operator[](const size_t index) const { return (&x)[index]; }
        template<typename R>
        vec2<T> &operator=(const vec2<R> &rhs) {
            x = (T)rhs.x;
            y = (T)rhs.y;
            return *this;
        }
        template<typename L>
        operator vec2<L>() { return vec2<L>{x, y}; }
    };

    using vec2f_t = vec2<float>;
    using vec2i_t = vec2<int>;
    using vec2s_t = vec2<size_t>;
    using vec2i8_t = vec2<int8_t>;
    using vec2u8_t = vec2<uint8_t>;
    using color2_t = vec2<uint8_t>;
    using vec2i16_t = vec2<int16_t>;
    using vec2u16_t = vec2<uint16_t>;
    using vec2i32_t = vec2<int32_t>;
    using vec2u32_t = vec2<uint32_t>;
    using vec2i64_t = vec2<int64_t>;
    using vec2u64_t = vec2<uint64_t>;

    template<typename T>
    struct vec3
    {
        union { T x; T r; };
        union { T y; T g; };
        union { T z; T b; };
        inline T &operator[](const size_t index) { return (&x)[index]; }
        inline const T &operator[](const size_t index) const { return (&x)[index]; }
        template<typename R>
        vec3<T> &operator=(const vec3<R> &rhs) {
            x = (T)rhs.x;
            y = (T)rhs.y;
            z = (T)rhs.z;
            return *this;
        }
        template<typename L>
        operator vec3<L>() { return vec3<L>{x, y, z}; }
    };

    using vec3f_t = vec3<float>;
    using vec3i_t = vec3<int>;
    using vec3s_t = vec3<size_t>;
    using vec3i8_t = vec3<int8_t>;
    using vec3u8_t = vec3<uint8_t>;
    using color3_t = vec3<uint8_t>;
    using vec3i16_t = vec3<int16_t>;
    using vec3u16_t = vec3<uint16_t>;
    using vec3i32_t = vec3<int32_t>;
    using vec3u32_t = vec3<uint32_t>;
    using vec3i64_t = vec3<int64_t>;
    using vec3u64_t = vec3<uint64_t>;

    template<typename T>
    struct vec4
    {
        union { T x; T r; };
        union { T y; T g; };
        union { T z; T b; };
        union { T w; T a; };
        inline T &operator[](const size_t index) { return (&x)[index]; }
        inline const T &operator[](const size_t index) const { return (&x)[index]; }
        template<typename R>
        vec4<T> &operator=(const vec4<R> &rhs) {
            x = (T)rhs.x;
            y = (T)rhs.y;
            z = (T)rhs.z;
            w = (T)rhs.w;
            return *this;
        }
        template<typename L>
        operator vec4<L>() { return vec4<L>{x, y, z, w}; }
    };

    using vec4f_t = vec4<float>;
    using vec4i_t = vec4<int>;
    using vec4s_t = vec4<size_t>;
    using vec4i8_t = vec4<int8_t>;
    using vec4u8_t = vec4<uint8_t>;
    using color4_t = vec4<uint8_t>;
    using vec4i16_t = vec4<int16_t>;
    using vec4u16_t = vec4<uint16_t>;
    using vec4i32_t = vec4<int32_t>;
    using vec4u32_t = vec4<uint32_t>;
    using vec4i64_t = vec4<int64_t>;
    using vec4u64_t = vec4<uint64_t>;
}

#endif // VEC_H