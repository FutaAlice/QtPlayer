#include "QtPlayer.h"
#include "VlcMediaPlayer.h"


QtPlayer::QtPlayer(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    memset(m_pSubWidgets, NULL, sizeof(m_pSubWidgets));

    for (auto i : m_pSubWidgets)
    {
        if (NULL == i)
        {
            i = new QWidget(this);
            auto player1 = new VlcMediaPlayer(i);
            player1->Open("test.mp4");
            i->resize(QSize(160, 100));
            i->move(QPoint(160, 100));
            break;
        }
    }

    //Sleep(1000);
    //player->Pause();

}
