#pragma once

class QWidget;
class IMediaPlayer
{
public:
    IMediaPlayer(QWidget* pWidget);
    virtual ~IMediaPlayer();

    virtual bool OpenFile();
    virtual bool OpenURL(const char* url);

    virtual bool Open(const char* url) = 0;
    virtual void Play() = 0;
    virtual void Pause() = 0;
    virtual void Stop() = 0;

protected:
    QWidget* m_pWidget;

};

