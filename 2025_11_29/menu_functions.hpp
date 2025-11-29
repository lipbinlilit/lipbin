
#include "menu.hpp"

namespace pve {
    
    const MenuItem* show_menu(const MenuItem* current);
    const MenuItem* exit(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current); 

    const MenuItem* READ_PUSHKIN(const MenuItem* current);
    const MenuItem* READ_LERMONTOV(const MenuItem* current);
    const MenuItem* READ_KRILOV(const MenuItem* current);

    const MenuItem* BOOK_DUBROVSKI(const MenuItem* current);
    const MenuItem* BOOK_EVGENI_ONEGIN(const MenuItem* current);
    const MenuItem* BOOK_ZIMNI_VECHER(const MenuItem* current);
}