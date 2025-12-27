#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const pve::MenuItem* pve::show_menu(const MenuItem* current) {

    std::cout << "Выберите пункт меню:" << std::endl;
    for (int i = 0; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << "> ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    if (user_input >= 0 && user_input < current->children_count) {
        return current->children[user_input];
    }
    else {
        std::cout << "Выберите двругой вариант. Для этого пока рано." << std::endl;
        return current;
    }
}

const pve::MenuItem* pve::exit(const MenuItem* current) {
    std::exit(0);
    return nullptr;
}

const pve::MenuItem* pve::show_subjects1(const MenuItem* current) {
    std::cout << "Вы выбрали изучать предметы 1-го класса" << std::endl;
    return current;
}

const pve::MenuItem* pve::show_subjects2(const MenuItem* current) {
    std::cout << "Вы выбрали изучать предметы 2-го класса" << std::endl;
    return current->parent;
}

const pve::MenuItem* pve::show_subjects3(const MenuItem* current) {
    std::cout << "Вы выбрали изучать предметы 3-го класса" << std::endl;
    return current->parent;
}

const pve::MenuItem* pve::back_to_main(const MenuItem* current) {
    return current->parent->parent;
}

const pve::MenuItem* pve::show_russian(const MenuItem* current) {
    std::cout << "Вы выбрали русский язык" << std::endl;
    return current->parent;
}

const pve::MenuItem* pve::show_literature(const MenuItem* current) {
    std::cout << "Вы выбрали русскую литературу" << std::endl;
    return current->parent;
}

const pve::MenuItem* pve::show_math(const MenuItem* current) {
    std::cout << "Вы выбрали математику" << std::endl;
    return current->parent;
}

const pve::MenuItem* pve::show_pe(const MenuItem* current) {
    std::cout << "Вы любите физкультуру" << std::endl;
    return current->parent;
}

const pve::MenuItem* pve::back_to_subjects(const MenuItem* current) {
    return current->parent->parent;
}