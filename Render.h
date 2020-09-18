//
// Created by Amado Garcia on 9/9/20.
//

#ifndef TRANSFORMATIONS_RENDER_H
#define TRANSFORMATIONS_RENDER_H

#include <vector>
#include <string>
#include "Math.h"
#include "Texture.h"
using namespace std;
class Render
{
    private:
    unsigned char backgroundColor[3];
        unsigned char pointColor[3];
        bool isPixels;
        int width;
        int height;
        string *filename;
        int vX;
        int vY;
        int vW;
        int vH;
//        vector<double> bbox(int quantity, ...);
        std::vector<unsigned char> fileHeader();
        std::vector<unsigned char> infoHeader();

        vector<vector<double>> zbuffer;
        tuple<double, double, double> barycentric(tuple<double, double, double> A, tuple<double, double, double> B, tuple<double, double, double> C, tuple<double, double> P);
        void glPoint(int x, int y);
        inline int glAdaptToViewportXCoordinates(int x);
        inline int glAdaptToViewportYCoordinates(int y);
        inline void swap(int &x, int &y);
        Math math;
        Texture texture = Texture(nullptr);
        tuple<double, double, double> light;
        vector<double>(*activeShader)(double &u, double &v, double &w,
                                      tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                                      tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                                      Texture &texture, tuple<double, double, double> &light);
        vector<vector<double>> viewMatrix;
        vector<vector<double>> projectionMatrix;
        vector<vector<double>> viewportMatrix;

    public:
        vector<vector<vector<unsigned char>>> framebuffer;
        void setTexture(Texture texture);
        void glClear(bool isAllWindow);
        void glFinish(char *filename);
        void glClearColor(double r, double g, double b);
        void glColor(double r, double g, double b);
        void glCreateWindow(int width, int height);
        void glViewPort(int x, int y, int width, int height);
        void glVertex(int x, int y);
        void glLine(int &x1, int &y1, int &x2, int &y2);
        void load(string filename, vector<double> translate, vector<double> scale, vector<double> rotate);
        void setIsPixels(bool isPixels);
        Texture getTexture();
        tuple<double, double, double> getLight();
        void setLight( tuple<double, double, double> light);
        void setActiveRender(vector<double>(*activeShader)
                (double &u, double &v, double &w,
                 tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                 tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                 Texture &texture, tuple<double, double, double> &light));
        tuple<double, double, double>
        transform(tuple<double, double, double> vertex, vector<vector<double>> viewMatrix);
        tuple<double, double, double> directionTransform(tuple<double, double, double> vertex, vector<vector<double>> viewMatrix);
        void createViewMatrix(tuple<double, double, double> cameraPosition, tuple<double, double, double> cameraRotation);
        void lookAt(tuple<double, double, double> eye, tuple<double, double, double> cameraPosition);
        void createProjectionMatrix(double n, double f, double fov);
        vector<vector<double>> createObjectMatrix(vector<double> translate,  vector<double> rotate={0,0,0}, vector<double> scale={1,1,1});
        vector<vector<double>> createRotationMatrix(vector<double> rotate);

        void glTriangle(tuple<double, double, double> A, tuple<double, double, double> B, tuple<double, double, double> C,
                    tuple<double, double> tA, tuple<double, double> tB, tuple<double, double> tC,
                    tuple<double, double, double> nA, tuple<double, double, double> nB,
                    tuple<double, double, double> nC);

        vector<double> bbox(double quantity, ...);

    Render();

    void colorBackground();
};


#endif //SHADERS_RENDER_H
