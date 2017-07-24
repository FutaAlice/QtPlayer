#include "QtPlayer.h"
#include "VlcMediaPlayer.h"


QtPlayer::QtPlayer(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    memset(m_pSubWidgets, NULL, sizeof(m_pSubWidgets));
}

void QtPlayer::openFile()
{
    int w = width() / 4, h = (height() - 24) / 4;
    for (int i = 0; i < 16; ++i)
    {
        if (m_pSubWidgets[i] == NULL)
        {
            m_pSubWidgets[i] = new QWidget(this);
            auto player = new VlcMediaPlayer(m_pSubWidgets[i]);

            // 打开成功
            if (player->OpenFile())
            {
                resizeEvent(NULL);
                m_pSubWidgets[i]->show();
            }
            else
            {
                delete player;
                delete m_pSubWidgets[i];
                m_pSubWidgets[i] = NULL;
            }
            break;
        }
    }
}

void QtPlayer::resizeEvent(QResizeEvent *e)
{
    int w = width() / 4, h = (height() - 24) / 4;
    for (int i = 0; i < 16; ++i)
    {
        if (NULL == m_pSubWidgets[i])
            continue;
        m_pSubWidgets[i]->resize(QSize(w, h));
        m_pSubWidgets[i]->move(QPoint((i % 4) * w, (i / 4) * h));
    }
    QPoint pos = ui.btnOpenFile->pos();
    pos.setY(height() - 24);
    ui.btnOpenFile->move(pos);

    pos = ui.btnOpenURL->pos();
    pos.setY(height() - 24);
    ui.btnOpenURL->move(pos);

    pos = ui.lineEdit->pos();
    pos.setY(height() - 24);
    ui.lineEdit->move(pos);
}

void QtPlayer::openURL()
{
    int w = width() / 4, h = height() / 4;
    for (int i = 0; i < 16; ++i)
    {
        if (m_pSubWidgets[i] == NULL)
        {
            m_pSubWidgets[i] = new QWidget(this);
            auto player = new VlcMediaPlayer(m_pSubWidgets[i]);
            // 打开成功
            if (player->OpenURL(ui.lineEdit->text().toUtf8().constData()))
            {
                resizeEvent(NULL);
                m_pSubWidgets[i]->show();
            }
            else
            {
                delete player;
                delete m_pSubWidgets[i];
                m_pSubWidgets[i] = NULL;
            }
            break;
        }
    }
}
