#include "VlcMediaPlayer.h"
#include <assert.h>
#include <QtWidgets/QWidget>

# ifdef __cplusplus
extern "C" {
# endif
#include <vlc/vlc.h>
# ifdef __cplusplus
}
# endif

#ifdef WIN32    // Windows
#pragma comment(lib, "libvlc.lib")
#else           // Linux
#pragma comment(lib, "libvlc.a")
#endif


VlcMediaPlayer::VlcMediaPlayer(QWidget* pWidget)
    : IMediaPlayer(pWidget)
    , m_pVlcPlayer(NULL)
{
}


VlcMediaPlayer::~VlcMediaPlayer()
{
}

bool VlcMediaPlayer::Open(const char *url)
{

    /* Stop if something is playing */
    if (m_pVlcPlayer &&
        libvlc_media_player_is_playing(m_pVlcPlayer))
    {
        Stop();
    }

    /* Initialize libVLC */
    libvlc_instance_t *vlcInstance = libvlc_new(0, NULL);
    if (NULL == vlcInstance)
    {
        assert(false);
    }

    /* Create a new Media */
    libvlc_media_t *vlcMedia = libvlc_media_new_path(vlcInstance,
                                                     url);
    /* Fail to open */
    if (!vlcMedia)
    {
        return false;
    }

    /* Create a new libvlc player */
    m_pVlcPlayer = libvlc_media_player_new_from_media(vlcMedia);

    /* Release the media */
    libvlc_media_release(vlcMedia);

    Play();
    return true;
}

void VlcMediaPlayer::Play()
{
    /* Integrate the video in the interface */
#if defined(Q_OS_MAC)
    libvlc_media_player_set_nsobject(m_pVlcPlayer, (void*)m_pWidget->winId());
#elif defined(Q_OS_UNIX)
    libvlc_media_player_set_xwindow(m_pVlcPlayer, m_pWidget->winId());
#elif defined(Q_OS_WIN)
    libvlc_media_player_set_hwnd(m_pVlcPlayer, (void*)m_pWidget->winId());
#endif

    /* And start playback */
    libvlc_media_player_play(m_pVlcPlayer);
}

void VlcMediaPlayer::Pause()
{
    if (m_pVlcPlayer &&
        libvlc_media_player_is_playing(m_pVlcPlayer))
    {
        libvlc_media_player_pause(m_pVlcPlayer);
    }
}

void VlcMediaPlayer::Stop()
{
    if (m_pVlcPlayer)
    {
        /* stop the media player */
        libvlc_media_player_stop(m_pVlcPlayer);

        /* release the media player */
        libvlc_media_player_release(m_pVlcPlayer);

        /* Reset application values */
        m_pVlcPlayer = NULL;
    }
}
