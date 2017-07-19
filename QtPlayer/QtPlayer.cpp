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

QtPlayer::QtPlayer(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    libvlc_instance_t * inst;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;

    // Load the VLC engine
    inst = libvlc_new(0, NULL);

    // Create a new item

    m = libvlc_media_new_path(inst, "test.mp4");

    // Create a media player playing environement
    mp = libvlc_media_player_new_from_media(m);
    libvlc_media_release(m);
    // play the media_player
    libvlc_media_player_play(mp);
}
