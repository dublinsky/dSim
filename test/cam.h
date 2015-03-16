//
//  cam.h
//  test
//
//  Created by XuHao on 14-4-15.
//  Copyright (c) 2014年 xuhao. All rights reserved.
//

#ifndef __test__cam__
#define __test__cam__

#include <iostream>
#include "vector3f.h"
#include <OpenGL/gl.h>
#include <OPenGL/glu.h>
#include <math.h>
class cam
{
public:
    vector3f eye,center,pose;
        float theta,fai;
    cam(
        double    eyeX,
        double    eyeY,
        double    eyeZ,
        double    centerX,
        double    centerY,
        double    centerZ,
        double    upX,
        double    upY,
        double    upZ):
        eye(eyeX,eyeY,eyeZ),center(centerX,centerY,centerZ),pose(upX,upY,upZ)
    {
        float rad=(center-eye).abs();
        theta=asin( (center-eye).y/rad);
        fai=atan((center.x-eye.x)/(center.y-eye.y));
        
    }
    cam():
        eye(0,0,0),center(0,1,1),pose(0,0,1),theta(0),fai(0)
    {

    }
    void setcam()
    {
        glMatrixMode (GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(eye.x, eye.y, eye.z, center.x, center.y,center.z, pose.x, pose.y, pose.z);
    }
    void movefirstVision(float x,float y)
    {
        theta+=y;
        fai+=x;
        center.x=10*sin(fai)*cos(theta)+eye.x;
        center.y=10*cos(fai)*cos(theta)+eye.y;
        center.z=10*sin(theta)+eye.z;
        setcam();
        printf("%f %f %f\n",center.x,center.y,center.z );
    }
};
#endif /* defined(__test__cam__) */
