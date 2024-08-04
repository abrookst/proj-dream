#include "raylib.h"
#include <cstdlib>
#include <vector>
#include <cstring>

struct audioObject {
    Music music;
    Sound sound;
    char* name;
    bool isMusic;
};

audioObject* find(char* file);

class AudioEngine
{
    std::vector<audioObject*> audioVector;
    std::vector<char*> loadedCache;

    audioObject* find(char*);

public:
    AudioEngine();
    ~AudioEngine();

    void PlayMusic(char*);
    void PlaySfx(char*);
    void UpdateMusic();
    void Pause(char*);
    void Restart(char*);

    int GetMusicVolume();
    void SetMusicVolume(int);
    int GetSfxVolume();
    void SetSfxVolume(int);
};

AudioEngine::AudioEngine() { InitAudioDevice(); }

AudioEngine::~AudioEngine() 
{
    CloseAudioDevice();
    for (char* file : loadedCache)
    {
        audioObject* temp = find(file);
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
        char* file)
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

void AudioEngine::PlaySfx(
        char* file)
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

void AudioEngine::UpdateMusic()
{

    for (int i=0; i<loadedCache.size(); i++) 
    {
        UpdateMusicStream(find(loadedCache[i])->music);
    }
}

void AudioEngine::Pause(
        char* file)
{
    audioObject* temp = find(file);
    if (temp->isMusic)
    {
        if (IsMusicStreamPlaying(temp->music))
        {
            PauseMusicStream(temp->music);
        } 
        else if (IsMusicReady(temp->music))
        {
            ResumeMusicStream(temp->music);
        }
    }
    else
    {
        if (IsSoundPlaying(temp->sound))
        {
            PauseSound(temp->sound);
        } 
        else if (IsSoundReady(temp->sound))
        {
            ResumeSound(temp->sound);
        }
    }
}

audioObject* AudioEngine::find(
        char* file)
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
 * . Stop
 * . Restart
 * . Volume Control (fade and swell)
 * . Speed/Pitch Control (Option to have speed affect pitch) 
 */
