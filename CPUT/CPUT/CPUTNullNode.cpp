/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////
#include "CPUTNullNode.h"
#include "CPUTOSServices.h" // FOR TCHAR
#include "CPUTConfigBlock.h"
#include "CPUTAssetLibrary.h"

// Parse the information in the .set file for this type of node
//-----------------------------------------------------------------------------
CPUTResult CPUTNullNode::LoadNullNode(CPUTConfigBlock *pBlock, int *pParentID)
{
    CPUTResult result = CPUT_SUCCESS;

    // set the null/group node name
    mName = pBlock->GetValueByName(_L("name"))->ValueAsString();

    // get the parent ID
    *pParentID = pBlock->GetValueByName(_L("parent"))->ValueAsInt();

    LoadParentMatrixFromParameterBlock( pBlock );

    return result;
}