/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Alopex/Helium
*     All rights reserved.
*
* @file		DirectCommon.h
* @brief	This File is DirectX Library Common Header.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2017-10-27
*/
#pragma once

#ifndef __DIRECTCOMMON_H_
#define __DIRECTCOMMON_H_

//Include Windows Header File
#include <Windows.h>

//Include C/C++ Running Header File
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <mmreg.h>
#include <wchar.h>
#include <tchar.h>
#include <time.h>
#include <mmsystem.h>

//Include DirectX Support Header File
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9math.h>
#include <dinput.h>
#include <dsound.h>

//Include Static Library File
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dsound.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"WinMM.lib")

//Macro Definition
#define SAFE_RELEASE(Pointer)	{if(Pointer){(Pointer)->Release();(Pointer) = NULL;}}//Release Pointer
#define SAFE_DELETE(Pointer)	{if(Pointer){delete(Pointer);(Pointer) = NULL;}}//Delete Pointer
#define SAFE_DELETE_ARRAY(Pointer) {if(Pointer){delete[](Pointer);(Pointer) = NULL;}}//Delete Pointer Array

#ifndef VERIFY
#define VERIFY(x)	if(FAILED(x)){return E_FAIL;}//Verify Expression
#endif

#endif