#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtPlayer.h"

struct libvlc_media_player_t;
class QtPlayer : public QWidget
{
    Q_OBJECT
public:
    QtPlayer(QWidget *parent = Q_NULLPTR);
    void resizeEvent(QResizeEvent* e);

private slots:
    void openFile();
    void openURL();

private:
    Ui::QtPlayerClass ui;
    QWidget* m_pSubWidgets[16];
};
