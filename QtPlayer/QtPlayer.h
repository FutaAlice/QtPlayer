#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtPlayer.h"

class QtPlayer : public QWidget
{
    Q_OBJECT

public:
    QtPlayer(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtPlayerClass ui;
};
