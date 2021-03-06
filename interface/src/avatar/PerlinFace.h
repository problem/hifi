//
//  PerlinFace.h
//  interface
//
//  Created by Clément Brisset on 9/4/13.
//  Copyright (c) 2013 High Fidelity, Inc. All rights reserved.
//

#ifndef __interface__PerlinFace__
#define __interface__PerlinFace__

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <QObject>
#include "InterfaceConfig.h"

class Head;

class PerlinFace {
public:
    PerlinFace(Head* owningHead);
    ~PerlinFace();

    void update();
    void render();

private:
    void init();

    void updatePositions();
    void updateVertices();

    void addTriangles(int vertexID1, int vertexID2, int vertexID3, GLubyte r, GLubyte g, GLubyte b);
    void addJunction(int vertexID1, int vertexID2, GLubyte r, GLubyte g, GLubyte b);
    void addVertex(GLubyte r, GLubyte g, GLubyte b, int vertexID, glm::vec3 normal);

    glm::vec3 getVec3(int vertexID);

    Head* _owningHead;

    bool _initialized;

    int _vertexNumber;
    int _trianglesCount;

    static glm::vec3* _vertices;
    glm::vec3* _oldNormals;
    glm::vec3* _newNormals;

    static GLfloat* _triangles;
    static GLfloat* _normals;
    static GLubyte* _colors;

    GLfloat* _trianglesPos;
    GLfloat* _normalsPos;
    GLubyte* _colorsPos;

    GLuint _vboID;
    GLuint _nboID;
    GLuint _cboID;

    float _browsD_L;
    float _browsD_R;
    float _browsU_C;
    float _browsU_L;
    float _browsU_R;

    float _mouthSize;
    float _mouthSmileLeft;
    float _mouthSmileRight;

    float _eyeBlink_L;
    float _eyeBlink_R;
    float _eyeOpen_L;
    float _eyeOpen_R;

    friend void staticCleanup();
};

#endif /* defined(__interface__Face__) */
