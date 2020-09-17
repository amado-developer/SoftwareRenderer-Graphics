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
    Texture t("dog.bmp");
    Texture t2("box.bmp");
    t.read();
    t2.read();
    Render r(t2);
    r.glCreateWindow(1920, 1080);
    r.glViewPort(0, 0, 1920, 1080);
    r.glClearColor(0.1, 0.1, 0.1);
    r.glClear(false);
    r.setIsPixels(true);
    tuple<double, double, double> modelPosition(0.0,0.0,-5.0);
    r.createViewMatrix(make_tuple(0.0,0.0,0.0), make_tuple(0.0,0.0,0.0));
    r.createProjectionMatrix(0.1,1000.0,60.0);
    r.lookAt(modelPosition, make_tuple(2.0, 2.0, 0.0));
    r.setLight(math.norm(make_tuple(0.0, 0.0, 1.0)));
    Shaders s;
    r.setActiveRender(&s.gourad);
    r.load("box.obj", {0.0, -2.0,-5.0}, {1.0, 1.0, 1.0}, {270.0,0.0,0.0});
    r.setTexture(t);
    r.load("dog.obj", {0.0, -2.0,-5.0}, {0.1, 0.1, 0.1}, {270.0,0.0,0.0});
    r.glFinish("obj.bmp");
    return 0;
}



