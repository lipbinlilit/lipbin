#pragma once

#include "menu.hpp"

namespace pve {
    const MenuItem* show_menu(const MenuItem* current);
    const MenuItem* exit(const MenuItem* current);

    const MenuItem* show_subjects1(const MenuItem* current);
    const MenuItem* show_subjects2(const MenuItem* current);
    const MenuItem* show_subjects3(const MenuItem* current);
    const MenuItem* back_to_main(const MenuItem* current);

    const MenuItem* show_russian(const MenuItem* current);
    const MenuItem* show_literature(const MenuItem* current);
    const MenuItem* show_math(const MenuItem* current);
    const MenuItem* show_pe(const MenuItem* current);
    const MenuItem* back_to_subjects(const MenuItem* current);
}