/*
 *  trackball.h
 *  SGFramework
 *
 *  Created by bdr on 06.05.09.
 *  Copyright 2009 Hochschule Kempten. All rights reserved.
 *
 */

#ifndef _TRACKBALL_H_
#define _TRACKBALL_H_

#include <QPointF>

#include "Transformation.h"
#include "listener.h"
#include "ReshapeListener.h"
#include "idleobserver.h"

class Trackball: public Transformation, public Listener, public ReshapeListener, public IdleObserver
{
public:
    Trackball();
    virtual void doIt() override;
    virtual void mouseMotion(const QPoint& point) override;
    virtual void mouseLeftDown(const QPoint& point) override;
    virtual void mouseLeftUp(const QPoint& point) override;
    virtual void reshape(int w, int h) override;
		
private:
    //!Berechnen des Vektors v zur Kugeloberfläche aus der Mausposition p(x,y)
    void pointtovector(QPoint point, float v[3]);
    //!Bewegung des Trackballs starten
    void StartMotion(QPoint point);
    //!Bewegung des Trackballs stoppen, ggf. selbststaendige Rotation beginnen
    void StopMotion(QPoint point);
    float angle, axis[3];
    bool trackingMouse;
    bool redrawContinue;
    bool trackballMove;
    float lastPos[3];
    int winWidth, winHeight;
    QPointF startPoint, curPoint;
};

#endif
