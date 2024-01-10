#include <array>
#include <cstdint>
#include <vector>
#include <gtest/gtest.h>
#include <entt/core/algorithm.hpp>
#include "../common/boxed_int.h"

TEST(Algorithm, StdSort) {
    // well, I'm pretty sure it works, it's std::sort!!
    std::array<int, 5> arr{{4, 1, 3, 2, 0}}; // NOLINT
    const entt::std_sort sort;

    sort(arr.begin(), arr.end());

    for(auto i = 0u; i < (arr.size() - 1u); ++i) {
        ASSERT_LT(arr[i], arr[i + 1u]); // NOLINT
    }
}

TEST(Algorithm, StdSortBoxedInt) {
    // well, I'm pretty sure it works, it's std::sort!!
    std::array<test::boxed_int, 6> arr{{{4}, {1}, {3}, {2}, {0}, {6}}}; // NOLINT
    const entt::std_sort sort;

    sort(arr.begin(), arr.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.value > rhs.value;
    });

    for(auto i = 0u; i < (arr.size() - 1u); ++i) {
        ASSERT_GT(arr[i].value, arr[i + 1u].value); // NOLINT
    }
}

TEST(Algorithm, InsertionSort) {
    std::array<int, 5> arr{{4, 1, 3, 2, 0}}; // NOLINT
    const entt::insertion_sort sort;

    sort(arr.begin(), arr.end());

    for(auto i = 0u; i < (arr.size() - 1u); ++i) {
        ASSERT_LT(arr[i], arr[i + 1u]); // NOLINT
    }
}

TEST(Algorithm, InsertionSortBoxedInt) {
    std::array<test::boxed_int, 6> arr{{{4}, {1}, {3}, {2}, {0}, {6}}}; // NOLINT
    const entt::insertion_sort sort;

    sort(arr.begin(), arr.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.value > rhs.value;
    });

    for(auto i = 0u; i < (arr.size() - 1u); ++i) {
        ASSERT_GT(arr[i].value, arr[i + 1u].value); // NOLINT
    }
}

TEST(Algorithm, InsertionSortEmptyContainer) {
    std::vector<int> vec{};
    const entt::insertion_sort sort;
    // this should crash with asan enabled if we break the constraint
    sort(vec.begin(), vec.end());
}

TEST(Algorithm, RadixSort) {
    std::array<std::uint32_t, 5> arr{{4, 1, 3, 2, 0}}; // NOLINT
    const entt::radix_sort<8, 32> sort;

    sort(arr.begin(), arr.end(), [](const auto &value) {
        return value;
    });

    for(auto i = 0u; i < (arr.size() - 1u); ++i) {
        ASSERT_LT(arr[i], arr[i + 1u]); // NOLINT
    }
}

TEST(Algorithm, RadixSortBoxedInt) {
    std::array<test::boxed_int, 6> arr{{{4}, {1}, {3}, {2}, {0}, {6}}}; // NOLINT
    const entt::radix_sort<2, 6> sort;

    sort(arr.rbegin(), arr.rend(), [](const auto &instance) {
        return instance.value;
    });

    for(auto i = 0u; i < (arr.size() - 1u); ++i) {
        ASSERT_GT(arr[i].value, arr[i + 1u].value); // NOLINT
    }
}

TEST(Algorithm, RadixSortEmptyContainer) {
    std::vector<int> vec{};
    const entt::radix_sort<8, 32> sort;
    // this should crash with asan enabled if we break the constraint
    sort(vec.begin(), vec.end());
}
