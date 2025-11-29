#include <cstdlib>
#include <iostream>

#include "menu_functions.hpp"
#include "menu.hpp"

const pve::MenuItem* pve::show_menu(const MenuItem* current) {

    std::cout << current->greeting << std::endl;

    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }

    std::cout << current->children[0]->title << std::endl;
    std::cout << "читалка> ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;
    return current->children[user_input];
}

const pve::MenuItem* pve::exit(const MenuItem* current) {
    std::exit(0);
}
const pve::MenuItem* pve::go_back(const MenuItem* current) {
    return current->parent;
}



const pve::MenuItem* pve::BOOK_DUBROVSKI(const MenuItem* current) {
    std::cout<<"*содержание Дубровского*"
    return current->parent;
}
const pve::MenuItem* pve::BOOK_EVGENI_ONEGIN(const MenuItem* current) {
    std::cout<<"*содержание Евгения Онегина*"

    return current->parent;
}
const pve::MenuItem* pve::BOOK_ZIMNI_VECHER(const MenuItem* current) {
    std::cout<<"*содержание зимнего вечера*"

    return current->parent;
}
