#include "QtPlayer.h"
#include "VlcMediaPlayer.h"


QtPlayer::QtPlayer(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    memset(m_pSubWidgets, NULL, sizeof(m_pSubWidgets));


    //Sleep(1000);
    //player->Pause();

}

void QtPlayer::openFile()
{
    int w = width() / 4, h = height() / 4;
    for (int i = 0; i < 16; ++i)
    {
        if (m_pSubWidgets[i] == NULL)
        {
            m_pSubWidgets[i] = new QWidget(this);
            auto player1 = new VlcMediaPlayer(m_pSubWidgets[i]);
            m_pSubWidgets[i]->resize(QSize(w, h));
            m_pSubWidgets[i]->move(QPoint((i % 4) * w, (i / 4) * h));
            m_pSubWidgets[i]->show();
            player1->OpenFile();
            break;
        }
    }
}

void QtPlayer::openURL()
{
    int w = width() / 4, h = height() / 4;
    for (int i = 0; i < 16; ++i)
    {
        if (m_pSubWidgets[i] == NULL)
        {
            m_pSubWidgets[i] = new QWidget(this);
            auto player1 = new VlcMediaPlayer(m_pSubWidgets[i]);
            m_pSubWidgets[i]->resize(QSize(w, h));
            m_pSubWidgets[i]->move(QPoint((i % 4) * w, (i / 4) * h));
            m_pSubWidgets[i]->show();
            player1->OpenURL(ui.lineEdit->text().toUtf8().constData());
            break;
        }
    }
}