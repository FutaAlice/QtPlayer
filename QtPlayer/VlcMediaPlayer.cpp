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

#if defined(Q_OS_MAC)       // Mac
// TODO
#elif defined(Q_OS_UNIX)    // Linux
#pragma comment(lib, "libvlc.a")
#elif defined(Q_OS_WIN)     // Windows
#pragma comment(lib, "libvlc.lib")
#endif

unsigned int VlcMediaPlayer::s_ref = 0;
libvlc_instance_t *VlcMediaPlayer::s_pVlcInstance = NULL;

VlcMediaPlayer::VlcMediaPlayer(QWidget* pWidget)
    : IMediaPlayer(pWidget)
    , m_pVlcPlayer(NULL)
{
    /* Initialize libVLC */
    if (0 == s_ref++)
    {
        s_pVlcInstance = libvlc_new(0, NULL);
        if (NULL == s_pVlcInstance)
        {
            assert(false);
        }
    }
}


VlcMediaPlayer::~VlcMediaPlayer()
{
    if (0 == --s_ref)
    {
        libvlc_release(s_pVlcInstance);
    }
}

bool VlcMediaPlayer::Open(const char *url)
{
    /* Stop if something is playing */
    //if (m_pVlcPlayer && libvlc_media_player_is_playing(m_pVlcPlayer))
    //{
    //    Stop();
    //}
    Stop();

    /* Create a new Media */
    libvlc_media_t *vlcMedia = libvlc_media_new_path(s_pVlcInstance, url);
    /* Fail to open url*/
    if (!vlcMedia)
    {
        return false;
    }

    /*::avformat-format=hevc*/
    libvlc_media_add_option(vlcMedia, ":avcodec-options{flags=low_delay}");
    libvlc_media_add_option(vlcMedia, ":demux=hevc");
    //libvlc_media_add_option(vlcMedia, ":sout-ts-dts-delay=0");
    
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
    if (m_pVlcPlayer && libvlc_media_player_is_playing(m_pVlcPlayer))
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

void VlcMediaPlayer::ChangeVolume(int vol)
{
    if (m_pVlcPlayer)
    {
        libvlc_audio_set_volume(m_pVlcPlayer, vol);
    }
}
