#pragma once

#include <cstddef>

// The number of elements in a C-style array.
template <typename T, std::size_t N>
constexpr std::size_t c_array_nelems (T(&)[N]) { return N; }

// The size of each element in a C-style array.
template <typename T, std::size_t N>
constexpr std::size_t c_array_elemsz (T(&)[N]) { return sizeof (T); }

// The total size occupied by a C-style array.
template <typename T, std::size_t N>
constexpr std::size_t c_array_totsz  (T(&)[N]) { return sizeof (T[N]); }