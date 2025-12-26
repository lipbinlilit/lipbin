#include <gtest/gtest.h>
#include "bubble.h"
#include <vector>

TEST(BubbleSortTest, SortsCorrectly) {
    std::vector<int> actual = { 1, 8, 2, 5, 3, 11 };
    std::vector<int> expected = { 1, 2, 3, 5, 8, 11 };

    pve::sortings::bubble_sort(actual.data(), actual.size());

    ASSERT_EQ(expected.size(), actual.size()) << "Разные размеры массивов";
    for (size_t i = 0; i < actual.size(); i++) {
        ASSERT_EQ(expected[i], actual[i]) << "Массивы отличаются в элементе с индексом " << i;
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}