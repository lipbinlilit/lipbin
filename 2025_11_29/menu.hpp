
namespace pve {
    struct MenuItem {
        const char* const title;

        const MenuItem* (*func)(const MenuItem* current);

        const MenuItem* parent;

        const char* const greeting;

        const MenuItem* const* children;

    };



}
