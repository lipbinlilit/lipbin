#include <iostream>
#include "long_number.h"
#include <windows.h> 

using pve::LongNumber;

void test(const char* name, bool condition) {
    if (condition) {
        std::cout << "OK: " << name << std::endl;
    }
    else {
        std::cout << "ERROR: " << name << std::endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);  // только эти две строки
    SetConsoleCP(1251);

    std::cout << "=== ТЕСТЫ СРАВНЕНИЯ ===" << std::endl;

    LongNumber n5("-5"), n3("-3"), n3_copy("-3");
    LongNumber p2("2"), p2_copy("2"), p15("15");

    test("2 == 2", p2 == p2_copy);
    test("-3 == 2", !(n3 == p2));
    test("2 == 15", !(p2 == p15));
    test("-3 == -3", n3 == n3_copy);

    test("-3 != 2", n3 != p2);
    test("2 != 15", p2 != p15);
    test("2 != 2", !(p2 != p2_copy));

    test("15 > 2", p15 > p2);
    test("2 > -3", p2 > n3);
    test("-3 > -5", n3 > n5);
    test("2 > 2", !(p2_copy > p2));

    test("2 < 15", p2 < p15);
    test("-3 < 2", n3 < p2);
    test("-5 < -3", n5 < n3);

    std::cout << "\n=== ТЕСТЫ АРИФМЕТИКИ ===" << std::endl;

    LongNumber n5000("-5000"), n50("-50"), n30("-30"), n8("-8");
    LongNumber n7("-7"), n6("-6"), n3_2("-3"), n2_2("-2"), n1_2("-1");
    LongNumber p0("0"), p2_2("2"), p2_copy_2("2"), p3_2("3"), p4("4");
    LongNumber p5("5"), p7_2("7"), p8_2("8"), p10("10"), p15_2("15");
    LongNumber p20_2("20"), p50_2("50"), p50_copy_2("50");
    LongNumber p100("100"), p500("500"), p5000_2("5000");
    LongNumber n20_2("-20"), n4_2("-4"), p6_2("6");

    test("2 + 2 = 4", (p2_2 + p2_copy_2) == p4);
    test("2 + (-2) = 0", (p2_2 + n2_2) == p0);
    test("50 + 50 = 100", (p50_2 + p50_copy_2) == p100);
    test("-50 + 20 = -30", (n50 + p20_2) == n30);
    test("20 + (-50) = -30", (p20_2 + n50) == n30);

    test("2 - 2 = 0", (p2_2 - p2_copy_2) == p0);
    test("2 - (-2) = 4", (p2_2 - n2_2) == p4);
    test("20 - 50 = -30", (p20_2 - p50_2) == n30);

    test("2 * 2 = 4", (p2_2 * p2_copy_2) == p4);
    test("2 * (-1) = -2", (p2_2 * n1_2) == n2_2);
    test("0 * 50 = 0", (p0 * p50_2) == p0);
    test("20 * 5 = 100", (p20_2 * p5) == p100);
    test("100 * 50 * -1 = -5000", (p100 * p50_2 * n1_2) == n5000);

    return 0;
}