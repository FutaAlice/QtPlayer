#include "IMediaPlayer.h"

#include <QtWidgets/QWidget>
#include <QtWidgets/qfiledialog.h>


// Windows环境下进行字符替换
static void StrReplace(QString& str)
{
#if defined(Q_OS_MAC)       // Mac
#elif defined(Q_OS_UNIX)    // Linux
#elif defined(Q_OS_WIN)     // Windows
    str = str.replace(QRegExp("/"), "\\");
#endif
}


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
    {
        StrReplace(fileOpen);
        return Open(fileOpen.toUtf8().constData());
    }
    else
        return false;
}

bool IMediaPlayer::OpenURL(const char * url)
{
    return Open(url);
}
