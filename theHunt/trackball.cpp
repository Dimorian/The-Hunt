/*
 *  trackball.cpp
 *  SGFramework
 *
 *  Created by bdr on 06.05.09.
 *  Copyright 2009 Hochschule Kempten. All rights reserved.
 *
 */
#define _USE_MATH_DEFINES
#include <cmath>
#include "trackball.h"

Trackball::Trackball()
{
	angle = 0.0;
	trackingMouse = false;
	redrawContinue = false;
	trackballMove = false;
	lastPos[0] = lastPos[1] = lastPos[2] = 0.0F;
}

void Trackball::reshape(int w, int h)
{
	winWidth = w;
	winHeight = h;
}

//!Berechnen des Vektors v zur Kugeloberfläche aus der Mausposition p(x,y)
void Trackball::pointtovector(QPoint point, float v[3])
{
    float length;
    float x=point.x(), y=point.y();
	
    /* x,y auf mittig ausgerichtete Halbkugel im Viewport projizieren*/
    v[0] = (2.0F*x - winWidth) / winWidth;
    v[1] = (2.0F*y - winHeight) / winHeight;
	length = v[0]*v[0]-v[1]*v[1];
 	//Wenn der Punkt außerhalb des Trackballs liegt, nimm den passenden "Randpunkt"
	if (length > 1.0)
		{
			float norm = 1/sqrt(length);
			v[0] *= norm;
			v[1] *= norm;
			v[2] = 0.0F;
		}
	else
		v[2] = sqrt(1.0f - length);
}

void Trackball::StartMotion(QPoint point)
{
	
    trackingMouse = true;
    redrawContinue = false;
    startPoint = point;
    curPoint = point;
    pointtovector(point, lastPos);
    trackballMove=true;
	
    resetTrafo();
}

void Trackball::StopMotion(QPoint point)
{
	
    trackingMouse = false;
	
    if (point != startPoint)
    {
		redrawContinue = true;
    } 
	else
    {
		angle = 0.0F;
		redrawContinue = false;
		trackballMove = false;
	}
}

void Trackball::doIt()
{
    if (redrawContinue)
	{
        rotate(angle, axis[0], axis[1], axis[2]);
	}
}


void Trackball::mouseMotion(const QPoint& point)
{
    float curPos[3], dx, dy, dz;
	
    pointtovector(point, curPos);
    if(trackingMouse)
	{
        dx = curPos[0] - lastPos[0];
        dy = curPos[1] - lastPos[1];
        dz = curPos[2] - lastPos[2];
		
		if (dx || dy || dz)
		{
			//angle = 90.0F * sqrt(dx*dx + dy*dy + dz*dz);
			
            axis[0] = lastPos[1]*curPos[2] - lastPos[2]*curPos[1];
            axis[1] = lastPos[2]*curPos[0] - lastPos[0]*curPos[2];
            axis[2] = lastPos[0]*curPos[1] - lastPos[1]*curPos[0];
			
            //Der Winkel kann berechnet werden als sin(angle) = |axis|
            //siehe Skript zum Kreuzprodukt, lastPos und curPos sind normiert!
			//angle = asin(sqrt(axis[0]*axis[0]+axis[1]*axis[1]+axis[2]*axis[2]));
			
			//Anmerkung zur Bestimmung des Winkel: Da die Winkel in der Regel sehr klein sind (ziemlich sicher
			//zwischen 0 und 45), kann man eigentlich genau so gut und aufwandsärmer wie unten rechnen
			//Der Sinus ist bei Winkeln zwischen 0 und 45 Grad recht nah an der Gerade
			//Ausprobieren und sehen, ob jemand einen Unterschied bemerkt ;-)
			angle = sqrt(axis[0]*axis[0]+axis[1]*axis[1]+axis[2]*axis[2]);
			
			//Vom Bogenmaß in Grad umrechnen
			angle *= 180.0F/M_PI;
            lastPos[0] = curPos[0];
            lastPos[1] = curPos[1];
            lastPos[2] = curPos[2];
		}
	}
    this->rotate(angle, axis[0], axis[1], axis[2]);
}

void Trackball::mouseLeftDown(const QPoint& point)
{
	StartMotion(point);
}
	
void Trackball::mouseLeftUp(const QPoint& point)
{
    StopMotion(point);
}

