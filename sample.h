//
// Created by teeeb on 2016. 12. 24..
//

#pragma once

float verticles[] = {
        //BACK
        -0.5f,0.5f,-0.5f,
        -0.5f,-0.5f,-0.5f,
        0.5f,-0.5f,-0.5f,
        0.5f,0.5f,-0.5f,

        //FRONT
        -0.5f,0.5f,0.5f,
        -0.5f,-0.5f,0.5f,
        0.5f,-0.5f,0.5f,
        0.5f,0.5f,0.5f,

        //RIGHT
        0.5f,0.5f,-0.5f,
        0.5f,-0.5f,-0.5f,
        0.5f,-0.5f,0.5f,
        0.5f,0.5f,0.5f,

        //LEFT
        -0.5f,0.5f,-0.5f,
        -0.5f,-0.5f,-0.5f,
        -0.5f,-0.5f,0.5f,
        -0.5f,0.5f,0.5f,

        //TOP
        -0.5f,0.5f,0.5f,
        -0.5f,0.5f,-0.5f,
        0.5f,0.5f,-0.5f,
        0.5f,0.5f,0.5f,

        //BOTTOM
        -0.5f,-0.5f,0.5f,
        -0.5f,-0.5f,-0.5f,
        0.5f,-0.5f,-0.5f,
        0.5f,-0.5f,0.5f
};
int vertCount=6*4*3;
float colors[]={
        1,0,0,1,    //jobb lent
        0,0,1,1,    //bal lent
        1,1,1,1,    //jobb fent
        0,0,0,1,    //bal fent
        1,0,0,1,    //jobb lent
        0,0,1,1,    //bal lent
        1,1,1,1,    //jobb fent
        0,0,0,1,     //bal fent
        1,0,0,1,    //jobb lent
        0,0,1,1,    //bal lent
        1,1,1,1,    //jobb fent
        0,0,0,1,     //bal fent
        1,0,0,1,    //jobb lent
        0,0,1,1,    //bal lent
        1,1,1,1,    //jobb fent
        0,0,0,1,     //bal fent
        1,0,0,1,    //jobb lent
        0,0,1,1,    //bal lent
        1,1,1,1,    //jobb fent
        0,0,0,1,     //bal fent
        1,0,0,1,    //jobb lent
        0,0,1,1,    //bal lent
        1,1,1,1,    //jobb fent
        0,0,0,1     //bal fent
};
int colorCount=6*4*4;
float textureCoords[] = {

};

unsigned indices[] = {
        //BACK
        0,3,1,
        1,3,2,

        //FRONT
        4,5,7,
        7,5,6,

        //RIGHT
        8,11,9,
        9,11,10,

        //LEFT
        12,13,15,
        15,13,14,

        //TOP
        16,19,17,
        17,19,18,

        //BOTTOM
        20,21,23,
        23,21,22
};
int indiceCount=6*6;
float normals[] = {

};