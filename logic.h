#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <QApplication>

#include "Leap.h"
#include "macro.h"
#include "scriptengine.h"


using namespace Leap;

class logic : public QObject
{
    Q_OBJECT
public:
    explicit logic(QObject *parent = 0);

signals:

public slots:
    void Leap_Hands     (Leap::HandList Hands);
    void Leap_Gestures  (Leap::GestureList Gestures, Leap::Hand hand);
private:
    macro * Macro;
    scriptengine * ScriptEngine;
    bool bHandKeyRot = false;
    bool bThumbKeyRot = false;
    int iFingersExtended;
    bool bThumbExtended;
};

#endif // LOGIC_H
