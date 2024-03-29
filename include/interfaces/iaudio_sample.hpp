#ifndef ENGINE_IAUDIO_SAMPLE_HPP
#define ENGINE_IAUDIO_SAMPLE_HPP

class IAudioSample {
public:
    virtual void play() = 0;
    virtual void resume() = 0;
    virtual void set_volume(double volume) = 0;
    virtual void stop() = 0;
    virtual void set_looping(bool loop) = 0;
    [[nodiscard]] virtual bool is_playing() const = 0;
private:

};

#endif //ENGINE_IAUDIO_SAMPLE_HPP
