//
// Created by Amado Garcia on 9/9/20.
//

#include <iostream>
#include "Shaders.h"
#include "Math.h"
#include "Texture.h"


vector<double> Shaders::phong(double &u, double &v, double &w,
                               tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                               tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                               Texture &texture, tuple<double, double, double> &light)
{
    Math math;

    double tX = get<0>(tA) * u + get<0>(tB) * v + get<0>(tC) * w;
    double tY = get<1>(tA) * u + get<1>(tB) * v + get<1>(tC) * w;

    double nX = get<0>(nA) * u + get<0>(nB) * v + get<0>(nC) * w;
    double nY = get<1>(nA) * u + get<1>(nB) * v + get<1>(nC) * w;
    double nZ = get<2>(nA) * u + get<2>(nB) * v + get<2>(nC) * w;

    tuple<double, double, double> normal{nX, nY, nZ};
    double intensity{math.dot(math.norm(normal),math.norm(light))};
    if(intensity < 0)
    {
        return {0.0,0.0,0.0};
    }
    double b = 1 * intensity;
    double r = 1 * intensity;
    double g = 1 * intensity;


    auto color = texture.getColor(tX, tY);
    double b1 = b  * color[2];
    double g1 = g  * color[1];
    double r1 = r  * color[0];

    return {r1, g1, b1};
}

vector<double> Shaders::toon(double &u, double &v, double &w,
                               tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                               tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                               Texture &texture, tuple<double, double, double> &light)
{
    Math math;
    double tX = get<0>(tA) * u + get<0>(tB) * v + get<0>(tC) * w;
    double tY = get<1>(tA) * u + get<1>(tB) * v + get<1>(tC) * w;


    double nX = get<0>(nA) * u + get<0>(nB) * v + get<0>(nC) * w;
    double nY = get<1>(nA) * u + get<1>(nB) * v + get<1>(nC) * w;
    double nZ = get<2>(nA) * u + get<2>(nB) * v + get<2>(nC) * w;

    tuple<double, double, double> normal{nX, nY, nZ};
    double intensity{math.dot(math.norm(normal),math.norm(light))};

    if(intensity > 0)
    {
        if (intensity > 0.9)
        {
            intensity = 0.85;
        }
        else if(intensity > 0.7)
        {
            intensity = 0.65;
        }

        else if(intensity > 0.5)
        {
            intensity = 0.45;
        }
        else if(intensity > 0.3)
        {
            intensity = 0.25;
        }

        else if(intensity > 0.1)
        {
            intensity = 0.05;
        }
    }

    double b = intensity;
    double r = intensity;
    double g = intensity;


    auto color = texture.getColor(tX, tY);
    double b1 = b  * color[2];
    double g1 = g  * color[1];
    double r1 = r  * color[0];


    if(intensity > 0.0)
    {
        return {r1, g1, b1};
    }
    else
        return {0.0, 0.0, 0.0};
}

vector<double> Shaders::ultraviolet(double &u, double &v, double &w,
                             tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                             tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                             Texture &texture, tuple<double, double, double> &light)
{
    Math math;

    double tX = get<0>(tA) * u + get<0>(tB) * v + get<0>(tC) * w;
    double tY = get<1>(tA) * u + get<1>(tB) * v + get<1>(tC) * w;

    double nX = get<0>(nA) * u + get<0>(nB) * v + get<0>(nC) * w;
    double nY = get<1>(nA) * u + get<1>(nB) * v + get<1>(nC) * w;
    double nZ = get<2>(nA) * u + get<2>(nB) * v + get<2>(nC) * w;

    tuple<double, double, double> normal{nX, nY, nZ};
    double intensity{math.dot(math.norm(normal),math.norm(light))};
    if(intensity < 0)
    {
        return {0.0,0.0,0.0};
    }


//    if (intensity > 0.25)
//        intensity = 0.40;

    double b = intensity;
    double r = intensity;
    double g = intensity;


    auto color = texture.getColor(tX, tY);
    double b1 = 0.91  * color[2];
    double g1 = 0.22  * color[1];
    double r1 = 0.32  * color[0];

    return {r1, g1, b1};
}

vector<double> Shaders::rainbow(double &u, double &v, double &w,
                                    tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                                    tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                                    Texture &texture, tuple<double, double, double> &light)
{
    Math math;

    double tX = get<0>(tA) * u + get<0>(tB) * v + get<0>(tC) * w;
    double tY = get<1>(tA) * u + get<1>(tB) * v + get<1>(tC) * w;

    double nX = get<0>(nA) * u + get<0>(nB) * v + get<0>(nC) * w;
    double nY = get<1>(nA) * u + get<1>(nB) * v + get<1>(nC) * w;
    double nZ = get<2>(nA) * u + get<2>(nB) * v + get<2>(nC) * w;

    tuple<double, double, double> normal{nX, nY, nZ};
    double intensity{math.dot(math.norm(normal),math.norm(light))};

    if(intensity < 0)
    {
        return {0.0,0.0,0.0};
    }


    double b = intensity;
    double r = intensity;
    double g = intensity;

    auto color = texture.getColor(tX, tY);


    //red
    if(tX <= 0.1429)
    {
        r = color[0];
        g = 0;
        b = 0;
    }

    //orange
    if(tX > 0.1429 && tX <= 0.2857)
    {
        r = color[0];
        g = 0.498 * color[1];
        b = 0;
    }

    //Yellow
    if(tX > 0.2857 && tX <= 0.4386 )
    {
        r = color[0];
        g = color[1];
        b = 0;
    }

    //Green
    if(tX > 0.4386 && tX <= 0.5714 )
    {
        r = 0;
        g = color[1];
        b = 0;
    }

    //Blue
    if(tX > 0.4386 && tX <= 0.5714 )
    {
        r = 0;
        g = 0;
        b = color[2];
    }

    //Purple
    if(tX > 0.5714 && tX <= 0.7143)
    {
        r = 0.29 * color[0];
        g = 0;
        b = 0.5098 * color[2];
    }

    //Violet
    if(tX > 0.7143 && tX <= 1)
    {
        r = 0.56 * color[0];
        g = 0;
        b = color[2];
    }



//    double b1 = 0.91  * color[2];
//    double g1 = 0.22  * color[1];
//    double r1 = 0.32  * color[0];

    return {r, g, b};
}

vector<double> Shaders::comic(double &u, double &v, double &w,
                                tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                                tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                                Texture &texture, tuple<double, double, double> &light)
{
    Math math;

    double tX = get<0>(tA) * u + get<0>(tB) * v + get<0>(tC) * w;
    double tY = get<1>(tA) * u + get<1>(tB) * v + get<1>(tC) * w;

    double nX = get<0>(nA) * u + get<0>(nB) * v + get<0>(nC) * w;
    double nY = get<1>(nA) * u + get<1>(nB) * v + get<1>(nC) * w;
    double nZ = get<2>(nA) * u + get<2>(nB) * v + get<2>(nC) * w;

    tuple<double, double, double> normal{nX, nY, nZ};
    double intensity{math.dot(math.norm(normal),math.norm(light))};

    if(intensity < 0)
    {
        return {0.0,0.0,0.0};
    }

    auto color = texture.getColor(tX, tY);
    double b = color[2];
    double g = color[1];
    double r = color[0];

    b *= b * intensity;
    g *= g * intensity;
    r *= r * intensity;

    b *= 10;
    b = ceil(b);
    b /= 10;

    g *= 10;
    g = ceil(g);
    g /= 10;

    r *= 10;
    r = ceil(r);
    r /= 10;

    return {r, g, b};
}

vector<double> Shaders::gray(double &u, double &v, double &w,
                                tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                                tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                                Texture &texture, tuple<double, double, double> &light)
{
    Math math;

    double tX = get<0>(tA) * u + get<0>(tB) * v + get<0>(tC) * w;
    double tY = get<1>(tA) * u + get<1>(tB) * v + get<1>(tC) * w;

    double nX = get<0>(nA) * u + get<0>(nB) * v + get<0>(nC) * w;
    double nY = get<1>(nA) * u + get<1>(nB) * v + get<1>(nC) * w;
    double nZ = get<2>(nA) * u + get<2>(nB) * v + get<2>(nC) * w;

    tuple<double, double, double> normal{nX, nY, nZ};
    double intensity{math.dot(math.norm(normal),math.norm(light))};

    if(intensity < 0)
    {
        return {0.0,0.0,0.0};
    }

    auto color = texture.getColor(tX, tY);
    double b = color[2];
    double g = color[1];
    double r = color[0];
    auto ba = b;

    b = b*intensity;
    g = ba*intensity;
    r = ba*intensity;


    return {r, g, b};
}

vector<double> Shaders::negative(double &u, double &v, double &w,
                                tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                                tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                                Texture &texture, tuple<double, double, double> &light)
{
    Math math;

    double tX = get<0>(tA) * u + get<0>(tB) * v + get<0>(tC) * w;
    double tY = get<1>(tA) * u + get<1>(tB) * v + get<1>(tC) * w;

    double nX = get<0>(nA) * u + get<0>(nB) * v + get<0>(nC) * w;
    double nY = get<1>(nA) * u + get<1>(nB) * v + get<1>(nC) * w;
    double nZ = get<2>(nA) * u + get<2>(nB) * v + get<2>(nC) * w;

    tuple<double, double, double> normal{nX, nY, nZ};
    double intensity{math.dot(math.norm(normal),math.norm(light))};

    if(intensity < 0)
        intensity += 1;
    else
        intensity = 1 - intensity;

    auto color = texture.getColor(tX, tY);
    double b = color[2];
    double g = color[1];
    double r = color[0];

    r = 1 - r;
    b = 1 - b;
    g = 1 - g;

    b *= intensity;
    g *= intensity;
    r *= intensity;

    if(intensity < 0)
        return {0, 0, 0};

    return {r, g, b};
}




