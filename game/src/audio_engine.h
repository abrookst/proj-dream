#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H

#include "raylib.h"
#include <cstdlib>
#include <vector>
#include <cstring>

struct Volume
{
    float oldVolume = 0.5;
    float newVolume = 0.5;
    float volumeEasingTimePassed = 0;
    float volumeEasingTimeTotal = 0;
};

struct Speed
{
    float oldSpeed = 1;
    float newSpeed = 1;
    float speedEasingTimePassed = 0;
    float speedEasingTimeTotal = 0;
};

struct AudioObject
{
    Music music;
    Sound sound;
    const char* name;
    bool isMusic = false;
    Volume vol;
    Speed spd;
};


class AudioEngine
{
public:
    AudioEngine();
    ~AudioEngine();

    void PlayMusic(const char*);
    void PlaySfx(const char*);
    void UpdateAudio();
    void Pause(const char*);
    void Restart(const char*);
    void Stop(const char*);

    void SetVolumeMaster(float vol) { SetMasterVolume(vol); }
    float GetVolumeMaster() { return GetMasterVolume(); }
    void SetVolumeSound(const char*, float, float);
    void SetVolumeAllMusic(float, float);
    void SetVolumeAllSfx(float, float);

    void SetSpeedSound(const char*, float, float);

private:
    std::vector<AudioObject*> audioVector;
    std::vector<const char*> loadedCache;

    AudioObject* Find(const char*);
};

#endif
