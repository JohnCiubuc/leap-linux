#ifndef SCRIPTENGINE_H
#define SCRIPTENGINE_H

#include <QObject>
#include <QDebug>
#include <QList>
#include <QFile>
#include <QProcess>
#include <QHash>
#include <QTimer>


#include "xkeys.h"


#define FINGER_MOD 1

// if you add more commands. change size of bool in runScript
enum script_command_enums
{
    com_key_down,
    com_key_up,
    com_key_send,
    com_launch,
    com_mode_lock,
    com_key_press
};

class scriptengine : public QObject
{
    Q_OBJECT
public:
    scriptengine();
    void setScriptFile(QString sPathToScript);
    void setDefinitions(QString sPathToDefines);
public slots:
    int runScript(QString mode_id, int modifiers = 0);
    void preScript(int iFingersExtended = 0);
private slots:
    void updateScriptFile();
    QList<QByteArray> getScriptSection(QString mode_id);
private:
    QByteArray baScriptData;
    QHash<QString,int> hDefines;
    QString sScriptFile;
    QStringList slModeList;
    QStringList slCommandList;
    xkeys * XKeys;
    QTimer * tFileUpdateTimer;

    QString sFingerMod;
};

#endif // SCRIPTENGINE_H
