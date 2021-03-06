#ifndef ANIMATION_H
#define ANIMATION_H

#include <QList>

#include "Frame.h"
#include "savable.h"

class Animation : public Savable
{
    bool SaveToFile(QFile &file);
    bool LoadFromFile(QFile &file);

private:
    QString animationName;
    QList<Frame*> frameList;
    bool loop;
    int nextAnimationID;

public:

    Animation();

    Frame *GetFrame(int ID);
    Frame *GetFrameAtIndex(int i);
    void AddFrame(Frame *newFrame);
    void DeleteFrame(int ID);
    int GetFrameCount();

    int GetNumFrames();

    QString GetName();
    void SetName(QString newName);

    bool GetLoop() { return loop; }
    void SetLoop(bool newLoop) { loop = newLoop; }

    void DestroyAllFrames();
};

#endif // ANIMATION_H
