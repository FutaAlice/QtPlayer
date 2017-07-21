#include "QtPlayer.h"
#include "VlcMediaPlayer.h"


QtPlayer::QtPlayer(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    auto player1 = new VlcMediaPlayer(ui.videoWidget1);
    player1->Open("test.mp4");

    //auto player2 = new VlcMediaPlayer(ui.videoWidget2);
    //player2->Open("test.mp4");

    //auto player3 = new VlcMediaPlayer(ui.videoWidget3);
    //player3->Open("test.mp4");

    //auto player4 = new VlcMediaPlayer(ui.videoWidget4);
    //player4->Open("test.mp4");

    //auto player5 = new VlcMediaPlayer(ui.videoWidget5);
    //player5->Open("test.mp4");

    //auto player6 = new VlcMediaPlayer(ui.videoWidget6);
    //player6->Open("test.mp4");

    //Sleep(1000);
    //player->Pause();

}
