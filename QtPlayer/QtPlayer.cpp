#include "QtPlayer.h"
#include "VlcMediaPlayer.h"

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

    auto player = new VlcMediaPlayer(ui.videoWidget);
    player->Open("test.hevc");

    //player->Open("test.mp4");

    //auto player2 = new VlcMediaPlayer(ui.videoWidget2);
    //player2->Open("test.hevc");

    //Sleep(1000);
    //player->Pause();

}
