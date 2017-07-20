#pragma once
#include "IMediaPlayer.h"


struct libvlc_media_player_t;
class VlcMediaPlayer :
    public IMediaPlayer
{
public:
    VlcMediaPlayer(QWidget* pWidget);
    ~VlcMediaPlayer();

    virtual bool Open(const char* url);
    virtual void Play();
    virtual void Pause();
    virtual void Stop();

private:
    libvlc_media_player_t *m_pVlcPlayer;
};

