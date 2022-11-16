#ifndef ENGINE_ISOUNDENGINE_HPP
#define ENGINE_ISOUNDENGINE_HPP

#include "interfaces/iaudiosample.hpp"

class ISoundEngine {
public:
    virtual void play(IAudioSample sample) const;
};

#endif //ENGINE_ISOUNDENGINE_HPP
