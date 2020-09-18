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
    Texture t("../textures/doctor.bmp");
    Texture back("../textures/background.bmp");
    Texture t2("../textures/hulk.bmp");
    t.read();
    t2.read();
    back.readBackground();

    r.glCreateWindow(1920, 1080);
    r.glViewPort(0, 0, 1920, 1080);
    r.glClearColor(0.1, 0.1, 0.1);
    r.glClear(false);
    r.setIsPixels(true);
    tuple<double, double, double> modelPosition(0.0,0.0,-5.0);
    r.createViewMatrix(make_tuple(0.0,0.0,0.0), make_tuple(0.0,0.0,0.0));
    r.createProjectionMatrix(0.1,1000.0,60.0);
    r.lookAt(modelPosition, make_tuple(2.0, 2.0, 0.0));
    r.setLight(math.norm(make_tuple(2.0, 2.0, 2.0)));
    Shaders s;

    r.setActiveRender(&s.toon);
    r.setTexture(back);
    r.framebuffer = back.backgroundPixels;
    r.setTexture(t);
    r.load("../models/doctor.obj", {-5.0, -1.5,-5.0}, {2.0, 2.0, 2.0}, {0.0,90.0,-10.0});
    r.setTexture(t2);

    r.setActiveRender(&s.gourad);
    r.load("../models/hulk.obj", {4.0, -5.0, -5.0}, {1.0, 1.0, 1.0}, {-20.0,-140.0,0.0});
    r.glFinish("obj.bmp");
    return 0;
}



