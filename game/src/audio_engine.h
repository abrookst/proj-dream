#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H

#include "raylib.h"
#include <cstdlib>
#include <vector>
#include <cstring>

struct volume
{
    float oldVolume = 0.5;
    float newVolume = 0.5;
    float volumeEasingTimePassed = 0;
    float volumeEasingTimeTotal = 0;
};

struct speed
{
    float oldSpeed = 1;
    float newSpeed = 1;
    float speedEasingTimePassed = 0;
    float speedEasingTimeTotal = 0;
};

struct audioObject
{
    Music music;
    Sound sound;
    const char* name;
    bool isMusic = false;
    volume vol;
    speed spd;
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

    void SetMasterVolume(float vol) { SetMasterVolume(vol); }
    float SetMasterVolume() { return this->GetMasterVolume(); }
    void SetSoundVolume(const char*, float, float);
    void SetAllMusicVolume(float, float);
    void SetAllSfxVolume(float, float);

    void SetSoundSpeed(const char*, float, float);

private:
    std::vector<audioObject*> audioVector;
    std::vector<const char*> loadedCache;

    audioObject* Find(const char*);
};

#endif