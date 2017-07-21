/*******************************************************************************

VlcMediaPlayer.h
使用libvlc实现的IMediaPlayer

构造时传入QWidget*
调用OpenFile或OpenURL或Open打开文件并渲染窗体

例如:
    QWidget* pWidget = new QOpenGLWidget();
    pWidget->show();
    auto player = new VlcMediaPlayer(pWidget);
    player->Open("test.hevc");

*******************************************************************************/

#ifndef VLCMEDIAPLAYER_H
#define VLCMEDIAPLAYER_H

#include "IMediaPlayer.h"

struct libvlc_media_player_t;
struct libvlc_instance_t;
class VlcMediaPlayer :
    public IMediaPlayer
{
public:
    VlcMediaPlayer(QWidget* pWidget);
    ~VlcMediaPlayer();

    // 禁用拷贝构造和赋值
    VlcMediaPlayer(const VlcMediaPlayer&) = delete;
    VlcMediaPlayer& operator=(VlcMediaPlayer&) = delete;

    // Control
    virtual bool Open(const char* url);
    virtual void Play();
    virtual void Pause();
    virtual void Stop();
    virtual void ChangeVolume(int vol) ;

private:
    // 播放器对象
    libvlc_media_player_t *m_pVlcPlayer;

private:
    // libvlc实例，所有窗体的渲染共用一个
    static libvlc_instance_t *s_pVlcInstance;
    static unsigned int s_ref;
};

#endif // VLCMEDIAPLAYER_H