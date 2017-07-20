#include "IMediaPlayer.h"

#include <QtWidgets/QWidget>
#include <QtWidgets/qfiledialog.h>


IMediaPlayer::IMediaPlayer(QWidget* pWidget)
    : m_pWidget(pWidget)
{
}


IMediaPlayer::~IMediaPlayer()
{
}

bool IMediaPlayer::OpenFile()
{
    QString fileOpen = QFileDialog::getOpenFileName(NULL, "Load a file", "~");
    if (!fileOpen.isEmpty())
        return Open(fileOpen.toUtf8().constData());
    else
        return false;
}

bool IMediaPlayer::OpenURL(const char * url)
{
    return Open(url);
}
