//
// Created by Amado Garcia on 9/9/20.
//

#include "Obj.h"
#include <iostream>
#include <fstream>
#include <sstream>

Obj::Obj(string filename) {
    this->filename = filename;
}
void Obj::read()
{
    ifstream inFile;
    inFile.open("./" + filename);
    if (!inFile) {
        cerr << "Unable to open file";
        exit(1);   // call system to stop
    }
    string line;
    vector<string> data{};

    while (getline(inFile, line))
    {
        istringstream iss(line);
        data.push_back(line);
    }

    string prefix;
    string values;
    for(auto line : data)
    {
        int point = line.find(" ");
        prefix = line.substr(0, point);
        values = line.substr(point + 1, line.length() - 1);

        if(prefix == "v")
        {
            vector<double> vertex{};
            string value;
            for(auto v: values)
            {
                if(v == ' ')
                {

                    if(value != "")
                        vertex.push_back(stof(value));
                    value = "";
                }
                else
                {
                    value = value + v;
                }
            }
            vertex.push_back(stof(value));
            vertices.push_back(vertex);
        }

        else if(prefix == "vt")
        {
            vector<double> tVertex{};
            string value{""};
            auto lol = values[0];
            for(auto v: values)
            {
                if(v == ' ')
                {
                    if(value == "")
                        continue;
                    tVertex.push_back(stof(value));
                    value = "";
                }
                else
                {
                    value = value + v;
                }
            }

            tVertex.push_back(stof(value));
            textureVertexes.push_back(tVertex);
        }

        else if(prefix == "vn")
        {
            vector<double> nVertex{};
            string value{""};
            for(auto v: values)
            {
                if(v == ' ')
                {
                    if(value == "")
                        continue;
                    nVertex.push_back(stof(value));
                    value = "";
                }
                else
                {
                    value = value + v;
                }
            }

            nVertex.push_back(stof(value));
            normalVertexes.push_back(nVertex);
        }

        else if(prefix == "f")
        {
            vector<string> face{};
            string value;
            for(auto  f: values)
            {
                if(f == ' ')
                {
                    face.push_back(value);
                    value = "";
                }
                else
                {
                    value = value + f;
                }

            }
            face.push_back(value);
            vector<int> facePosition1{};
            vector<int> facePosition2{};
            vector<int> facePosition3{};
            for(auto f : face)
            {
                int delimeter = f.find("/");
                string value = f.substr(0,  delimeter);
                f = f.substr(delimeter + 1, f.length() - 1);
                delimeter = f.find("/");
                string tValue = f.substr(0, delimeter);
                f = f.substr(delimeter + 1, f.length()-1);
                string nValue = f;

                if(value !="" && value !="\r")
                    facePosition1.push_back(stoi(value));
                if(tValue !="" && value !="\r")
                    facePosition2.push_back(stoi(tValue));
                if(nValue !="" && value !="\r")
                    facePosition3.push_back(stoi(nValue));
            }
            faces.push_back(make_tuple(facePosition1, facePosition2, facePosition3));
        }
    }
}
vector<vector<double>> Obj::getVertices()
{
    return this->vertices;
}
vector<vector<double>> Obj::getTextureVertexes()
{
    return this->textureVertexes;
}
vector<vector<double>> Obj:: getNormalVertexes()
{
    return this -> normalVertexes;
}
vector<tuple<vector<int>,vector<int>, vector<int>>> Obj::getFaces()
{
    return this->faces;
}

