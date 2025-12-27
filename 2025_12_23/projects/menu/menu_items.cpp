#include "menu_items.hpp"
#include "menu_functions.hpp"

#include <cstddef>

const pve::MenuItem pve::RUSSIAN = {
    "1 - Русский язык",
    pve::show_russian,
    &pve::SUBJECTS1
};

const pve::MenuItem pve::LITERATURE = {
    "2 - Русская литература",
    pve::show_literature,
    &pve::SUBJECTS1
};

const pve::MenuItem pve::MATH = {
    "3 - Математика",
    pve::show_math,
    &pve::SUBJECTS1
};

const pve::MenuItem pve::PE = {
    "4 - Я люблю физкультуру",
    pve::show_pe,
    &pve::SUBJECTS1
};

const pve::MenuItem pve::BACK_TO_SUBJECTS = {
    "0 - Выйти в предыдущее меню",
    pve::back_to_main,
    &pve::SUBJECTS1
};

namespace {
    const pve::MenuItem* const subjects1_children[] = {
        &pve::BACK_TO_SUBJECTS,
        &pve::RUSSIAN,
        &pve::LITERATURE,
        &pve::MATH,
        & pve::PE
    };
    const int subjects1_size = sizeof(subjects1_children) / sizeof(subjects1_children[0]);
}

const pve::MenuItem pve::SUBJECTS1 = {
    "1 - Изучать предметы 1-го класса",
    pve::show_menu,
    &pve::SUBJECTS,
    subjects1_children,
    subjects1_size
};

const pve::MenuItem pve::SUBJECTS2 = {
    "2 - изучать предметы 2-го класса",
    pve::show_subjects2,
    &pve::SUBJECTS,
    nullptr,
    0
};

const pve::MenuItem pve::SUBJECTS3 = {
    "3 - изучать предметы 3-го класса",
    pve::show_subjects3,
    &pve::SUBJECTS,
    nullptr,
    0
};


const pve::MenuItem pve::BACK_TO_MAIN = {
    "0 - Выйти в главное меню",
    pve::back_to_main,
    &pve::SUBJECTS,
    nullptr,
    0
};

namespace {
    const pve::MenuItem* const subjects_children[] = {
        &pve::BACK_TO_MAIN,
        &pve::SUBJECTS1,
        &pve::SUBJECTS2,
        &pve::SUBJECTS3
    };
    const int subjects_size = sizeof(subjects_children) / sizeof(subjects_children[0]);
}

const pve::MenuItem pve::SUBJECTS = {
    "1 - Предметы какого класса школы вы хотите изучить?",
    pve::show_menu,
    &pve::MAIN,
    subjects_children,
    subjects_size
};

const pve::MenuItem pve::EXIT = {
    "0 - Я уже закончил школу и все знаю",
    pve::exit,
    &pve::MAIN,
    nullptr,
    0
};

namespace {
    const pve::MenuItem* const main_children[] = {
        &pve::EXIT,
        &pve::SUBJECTS
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const pve::MenuItem pve::MAIN = {
    "Главное меню",
    pve::show_menu,
    nullptr,
    main_children,
    main_size
};