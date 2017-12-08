/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _CPUTGeometrySprite_H
#define _CPUTGeometrySprite_H

#include "CPUT.h"
#include "d3d11.h"

class CPUTMaterial;
class CPUTRenderParameters;
class CPUTTexture;

class CPUTGeometrySprite
{
protected:
    class SpriteVertex
    {
    public:
        float mpPos[3];
        float mpUV[2];
    };

    ID3D11Buffer      *mpVertexBuffer;
    CPUTMaterial      *mpMaterial;
    ID3D11InputLayout *mpInputLayout;

public:
    CPUTGeometrySprite() :
        mpInputLayout(NULL),
        mpVertexBuffer(NULL),
        mpMaterial(NULL)
    {
    }
    ~CPUTGeometrySprite();
    HRESULT CreateSprite(
        float          spriteX = -1.0f,
        float          spriteY = -1.0f,
        float          spriteWidth  = 2.0f,
        float          spriteHeight = 2.0f,
        const cString &materialName = cString(_L("Sprite"))
    );
    void DrawSprite( CPUTRenderParameters &renderParams ) { DrawSprite( renderParams, *mpMaterial ); }
    void DrawSprite( CPUTRenderParameters &renderParams, CPUTMaterial &material );
};

#endif // _CPUTGeometrySprite_H