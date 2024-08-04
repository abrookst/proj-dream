#include "raylib.h"
#include <cstdlib>
#include <vector>
#include <cstring>

struct audioObject {
    Music music;
    Sound sound;
    const char* name;
    bool isMusic;
};

audioObject* find(const char* file);

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
    void UpdateMusic();
    void Pause(const char*);
    void Restart(const char*);
    void Stop(const char*);

    int GetMusicVolume();
    void SetMusicVolume(int);
    int GetSfxVolume();
    void SetSfxVolume(int);
};

AudioEngine::AudioEngine() { InitAudioDevice(); }

AudioEngine::~AudioEngine() 
{
    CloseAudioDevice();
    for (const char* file : loadedCache)
    {
        audioObject* temp = Find(file);
        if (temp->isMusic)
        {
            UnloadMusicStream(temp->music);
        }
        else 
        {
            UnloadSound(temp->sound);
        }
    }
}


void AudioEngine::PlayMusic(
        const char* file)
{
    bool isCached = false;
    for (int i = 0; i < loadedCache.size(); i++)
    {
        if (loadedCache[i] == file)
        {
            isCached = true;
        }
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
    for (int i = 0; i < loadedCache.size(); i++)
    {
        if (loadedCache[i] == file) { isCached = true; }
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

void AudioEngine::UpdateMusic()
{
    for (int i=0; i<loadedCache.size(); i++) 
    {
        UpdateMusicStream(Find(loadedCache[i])->music);
    }
}

void AudioEngine::Pause(
        const char* file)
{
    audioObject* temp = Find(file);
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
    if (temp->isMusic) { StopMusicStream(temp->music); }
    else { StopSound(temp->sound); }
}

void AudioEngine::Restart(const char* file)
{
    audioObject* temp = Find(file);
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

/* Audio Engine Requirments:
 * x Play (multiple tracks)
 * x Pause
 * x Stop
 * . Restart
 * . Volume Control (fade and swell)
 * . Speed/Pitch Control (Option to have speed affect pitch) 
 */
