
#ifndef ENGINE_KEY_HANDLER_HPP
#define ENGINE_KEY_HANDLER_HPP

#include "vector"
#include "../include/enums/key.hpp"

class KeyHandler {

private:
    std::vector<Key> _keys_active;

    static std::vector<Key> fetch_keys() ;

public:
    void tick();
};

#endif //ENGINE_KEY_HANDLER_HPP
