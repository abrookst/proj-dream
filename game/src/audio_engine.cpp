#include "raylib.h"
#include <cstdlib>
#include <vector>
#include <cstring>

struct audioObject {
    Music music;
    Sound sound;
    const char* name;
    bool isMusic;
    float oldVolume = 0.5;
    float newVolume = 0.5;
    float volumeEasingTimePassed = 0;
    float volumeEasingTimeTotal = 0;
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
    void SetSoundVolume(const char*, float, float);
    void SetAllMusicVolume(const char*, float, float);
    void SetAllSfxVolume(const char*, float, float);
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
        if (obj->volumeEasingTimeTotal)
        {
            obj->volumeEasingTimePassed += GetFrameTime();
            if (obj->volumeEasingTimePassed > obj->volumeEasingTimeTotal) {
                obj->oldVolume = obj->newVolume;
                obj->volumeEasingTimePassed = 0;
                obj->volumeEasingTimeTotal = 0;
                break;
            }
            float vol = obj->oldVolume + 
                ((obj->newVolume - obj->oldVolume) * 
                 (obj->volumeEasingTimePassed / obj->volumeEasingTimeTotal));
            if (obj->isMusic) { SetMusicVolume(obj->music, vol); }
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

void AudioEngine::Stop(const char* file)
{
    audioObject* temp = Find(file);
    if (!temp) { return; }
    if (temp->isMusic) { StopMusicStream(temp->music); }
    else { StopSound(temp->sound); }
}

void AudioEngine::Restart(const char* file)
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

void AudioEngine::SetSoundVolume(const char* file, float volume, float time)
{
    audioObject* temp = Find(file);
    if (!temp) { return; }
    temp->newVolume = volume;
    temp->volumeEasingTimeTotal = time;
}

/* Audio Engine Requirments:
 * X Play (multiple tracks)
 * X Pause
 * X Stop
 * X Restart
 * . Volume Control (fade and swell)
 * . Speed/Pitch Control (Option to have speed affect pitch) 
 */
