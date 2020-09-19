#include <iostream>
#include "Render.h"
#include "Texture.h"
#include "Shaders.h"
#include <vector>
#include "Math.h"
using namespace std;
int main()
{
    Math math;
    Render r;
    Texture back("../textures/background.bmp");
    Texture doctorStrange("../textures/doctor.bmp");
    Texture hulk("../textures/hulk.bmp");
    Texture robot("../textures/robot.bmp");
    Texture spiderman("../textures/spiderman.bmp");
    Texture cat("../textures/cat.bmp");
    Texture box("../textures/box.bmp");

    back.readBackground();
    doctorStrange.read();
    robot.read();
    hulk.read();
    spiderman.read();
    cat.read();
    box.read();


    r.glCreateWindow(1920, 1080);
    r.glViewPort(0, 0, 1920, 1080);
    r.glClearColor(0.1, 0.1, 0.1);
    r.glClear(false);
    r.setIsPixels(true);
    tuple<double, double, double> modelPosition(0.0,0.0,-5.0);
    r.createViewMatrix(make_tuple(0.0,0.0,0.0), make_tuple(0.0,0.0,0.0));
    r.createProjectionMatrix(0.1,1000.0,60.0);
    r.lookAt(modelPosition, make_tuple(2.0, 2.0, 0.0));
    r.setLight(math.norm(make_tuple(0.0, 1.0, 1.0)));

    Shaders s;
    r.setActiveRender(&s.gourad);

    r.setTexture(back);
    r.framebuffer = back.backgroundPixels;

    r.setTexture(doctorStrange);
    r.load("../models/doctor.obj", {-1.0, -2.5,-12.0}, {3.0, 3.0, 3.0}, {0.0,0.0,0.0});

    r.setTexture(hulk);
    r.load("../models/hulk.obj", {4.0, -5.0, -5.0}, {1.0, 1.0, 1.0}, {-20.0,-140.0,0.0});

    r.setTexture(robot);
    r.load("../models/robot.obj", {-5.2, -5.5, -4.0}, {0.015, 0.015, 0.015}, {-30.0,115.0,5.0});

    r.setTexture(spiderman);
    r.load("../models/spiderman.obj", {3.0, 1.3, -10.0}, {1.0, 1.0, 1.0}, {0.0,-90.0,5.0});

    r.setTexture(cat);
    r.load("../models/cat.obj", {1.9, 1.19, -10.0}, {0.002, 0.002, 0.002}, {270.0,-7.5,90.0});

    r.setTexture(box);
    r.load("../models/box.obj", {-0.5, -2.5, -10.0}, {2.0, 2.0, 2.0}, {-30.0,0.0,0.0});

    r.glFinish("obj.bmp");
    return 0;
}



