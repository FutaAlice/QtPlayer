#include "QtPlayer.h"

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

#define qtu( i ) ((i).toUtf8().constData())
QtPlayer::QtPlayer(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    /* The basic file-select box */
    QString fileOpen("test.mp4");

    libvlc_instance_t *vlcInstance = libvlc_new(0, NULL);

    auto *vlcMedia = libvlc_media_new_path(vlcInstance,
                                           qtu(fileOpen));

    /* Create a new libvlc player */
    vlcPlayer = libvlc_media_player_new_from_media(vlcMedia);

    /* Release the media */
    libvlc_media_release(vlcMedia);



    //libvlc_instance_t *vlcInstance2 = libvlc_new(0, NULL);
    fileOpen = "1.mp4";
    auto *vlcMedia2 = libvlc_media_new_path(vlcInstance,
                                            qtu(fileOpen));
    vlcPlayer2 = libvlc_media_player_new_from_media(vlcMedia2);
    libvlc_media_release(vlcMedia2);


    /* Integrate the video in the interface */
    #if defined(Q_OS_MAC)
        libvlc_media_player_set_nsobject(vlcPlayer, (void *)ui.videoWidget->winId());
    #elif defined(Q_OS_UNIX)
        libvlc_media_player_set_xwindow(vlcPlayer, ui.videoWidget->winId());
    #elif defined(Q_OS_WIN)
        libvlc_media_player_set_hwnd(vlcPlayer, (void*)ui.videoWidget->winId());
        libvlc_media_player_set_hwnd(vlcPlayer2, (void*)ui.videoWidget2->winId());
    #endif

    /* And start playback */
    libvlc_media_player_play(vlcPlayer);
    libvlc_media_player_play(vlcPlayer2);

}
