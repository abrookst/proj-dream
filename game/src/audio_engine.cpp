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
    std::vector<audioObject*> audioVector;
    std::vector<const char*> loadedCache;

    audioObject* Find(const char*);

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
    float SetMasterVolume() { return GetMasterVolume(); }
    void SetSoundVolume(const char*, float, float);
    void SetAllMusicVolume(float, float);
    void SetAllSfxVolume(float, float);

    void SetSoundSpeed(const char*, float, float);
};

AudioEngine::AudioEngine() { InitAudioDevice(); }

AudioEngine::~AudioEngine() 
{
    CloseAudioDevice();
    for (const char* file : loadedCache)
    {
        audioObject* temp = Find(file);
        if (!temp) { return; }
        if (temp->isMusic) { UnloadMusicStream(temp->music); }
        else { UnloadSound(temp->sound); }
    }
    for (audioObject* obj : audioVector) { delete obj; }
}


void AudioEngine::PlayMusic(
        const char* file)
{
    bool isCached = false;
    for (const char* name : loadedCache)
    {
        if (name == file) { isCached = true; }
        break;
    }
    
    if (isCached) { PlayMusicStream(Find(file)->music); }
    else
    {
        audioObject* temp = new audioObject{};
        char fullPath[17+strlen(file)];
        strcpy(fullPath, "./resources/audio/");
        strcat(fullPath, file);
        temp->music = LoadMusicStream(fullPath);
        temp->isMusic = true;
        temp->name = file;
        PlayMusicStream(temp->music);
        loadedCache.push_back(file);
        audioVector.push_back(temp);
    }
}

void AudioEngine::PlaySfx(
        const char* file)
{
    bool isCached = false;
    for (const char* name : loadedCache)
    {
        if (name == file) { isCached = true; }
        break;
    }
    
    if (isCached) { PlaySound(Find(file)->sound); }
    else
    {
        audioObject* temp = new audioObject{};
        char fullPath[17+strlen(file)];
        strcpy(fullPath, "./resources/audio/");
        strcat(fullPath, file);
        temp->sound = LoadSound(fullPath);
        temp->name = file;
        PlaySound(temp->sound);
        audioVector.push_back(temp);
    }
}

void AudioEngine::UpdateAudio()
{
    for (audioObject* obj : audioVector) 
    {
        if (obj->isMusic && IsMusicStreamPlaying(obj->music))
        {
            UpdateMusicStream(obj->music); 
        } 
        volume* vol = &obj->vol;
        speed* spd = &obj->spd;
        if (vol->volumeEasingTimeTotal)
        {
            vol->volumeEasingTimePassed += GetFrameTime();
            if (vol->volumeEasingTimePassed > vol->volumeEasingTimeTotal) {
                vol->oldVolume = vol->newVolume;
                vol->volumeEasingTimePassed = 0;
                vol->volumeEasingTimeTotal = 0;
                break;
            }
            float retVol = vol->oldVolume + 
                ((vol->newVolume - vol->oldVolume) * 
                 (vol->volumeEasingTimePassed / vol->volumeEasingTimeTotal));
            if (obj->isMusic) { SetMusicVolume(obj->music, retVol); }
        }
        if (obj->spd.speedEasingTimeTotal)
        {
            obj->spd.speedEasingTimePassed += GetFrameTime();
            if (spd->speedEasingTimePassed > spd->speedEasingTimeTotal) {
                spd->oldSpeed = spd->newSpeed;
                spd->speedEasingTimePassed = 0;
                spd->speedEasingTimeTotal = 0;
                break;
            }
            float retSpeed = spd->oldSpeed + 
                ((spd->newSpeed - spd->oldSpeed) * 
                 (spd->speedEasingTimePassed / spd->speedEasingTimeTotal));
            if (obj->isMusic) { SetMusicSpeed(obj->music, retSpeed); }
        }
    }
}

void AudioEngine::Pause(
        const char* file)
{
    audioObject* temp = Find(file);
    if (!temp) { return; }
    if (temp->isMusic)
    {
        Music* mus = &temp->music; 
        if (IsMusicStreamPlaying(*mus)) { PauseMusicStream(*mus); } 
        else if (IsMusicReady(*mus)) { ResumeMusicStream(*mus); }
    }
    else
    {
        Sound* sou = &temp->sound; 
        if (IsSoundPlaying(*sou)) { PauseSound(*sou); } 
        else if (IsSoundReady(*sou)) { ResumeSound(*sou); }
    }
}

void AudioEngine::Stop(
        const char* file)
{
    audioObject* temp = Find(file);
    if (!temp) { return; }
    if (temp->isMusic) { StopMusicStream(temp->music); }
    else { StopSound(temp->sound); }
}

void AudioEngine::Restart(
        const char* file)
{
    audioObject* temp = Find(file);
    if (!temp) { return; }
    if (temp->isMusic)
    {
        StopMusicStream(temp->music);
        PlayMusicStream(temp->music);
    }
    else
    {
        StopSound(temp->sound);
        PlaySound(temp->sound);
    }
}

audioObject* AudioEngine::Find(
        const char* file)
{
    for (int i=0; i<audioVector.size(); i++) 
    {
        if (audioVector.at(i)->name == file)
        {
            return audioVector.at(i);
        }
    }
    return NULL;
}

void AudioEngine::SetSoundVolume(
        const char* file,
        float volume, float time)
{
    audioObject* temp = Find(file);
    if (!temp) { return; }
    temp->vol.newVolume = volume;
    temp->vol.volumeEasingTimeTotal = time;
}

void AudioEngine::SetAllMusicVolume(
        float volume,
        float time)
{
    for (audioObject* obj : audioVector)
    {
        if (!obj->isMusic) { continue; }
        obj->vol.newVolume = volume;
        obj->vol.volumeEasingTimeTotal = time;
    }
}

void AudioEngine::SetAllSfxVolume(
        float volume,
        float time)
{
    for (audioObject* obj : audioVector)
    {
        if (obj->isMusic) { continue; }
        obj->vol.newVolume = volume;
        obj->vol.volumeEasingTimeTotal = time;
    }
}

void AudioEngine::SetSoundSpeed(
        const char* file,
        float speed,
        float time)
{
    audioObject* temp = Find(file);
    if (!temp) { return; }
    temp->spd.newSpeed = speed;
    temp->spd.speedEasingTimeTotal = time;
}