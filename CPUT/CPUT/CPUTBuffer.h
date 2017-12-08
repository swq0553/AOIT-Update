/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _CPUTBUFFER_H
#define _CPUTBUFFER_H

#include "CPUT.h"
#include "CPUTRefCount.h"

class CPUTBuffer : public CPUTRefCount
{
protected:
    cString      mName;
    eCPUTMapType mMappedType;

    ~CPUTBuffer(){} // Destructor is not public.  Must release instead of delete.
public:
    CPUTBuffer(){mMappedType = CPUT_MAP_UNDEFINED;}
    CPUTBuffer(cString &name) {mName = name; mMappedType = CPUT_MAP_UNDEFINED;}
    const cString &GetName() { return mName; }
};

#endif //_CPUTBUFFER_H