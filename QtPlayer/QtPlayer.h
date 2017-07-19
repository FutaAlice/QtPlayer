#pragma once

#include <QtWidgets/QWidget>
#include <map>
#include "ui_QtPlayer.h"

struct libvlc_media_player_t;
class QtPlayer : public QWidget
{
    Q_OBJECT

public:
    QtPlayer(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtPlayerClass ui;

    libvlc_media_player_t *vlcPlayer;
    libvlc_media_player_t *vlcPlayer2;
};
