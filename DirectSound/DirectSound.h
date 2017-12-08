/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DirectSound.h
* @brief	This Program is DirectSound DLL Project.
* @author	Alopex/Helium
* @version	v1.11a
* @date		2017-10-31	v1.00a	alopex	Create Project
* @date		2017-12-03	v1.01a	alopex	Add Enum
* @date		2017-12-8	v1.11a	alopex	Code Do Not Rely On MSVCR Library
*/
#pragma once

#ifndef __DIRECTSOUND_H_
#define __DIRECTSOUND_H_

//Macro Definition
#ifdef  DIRECTSOUND_EXPORTS
#define DIRECTSOUND_API	__declspec(dllexport)
#else
#define DIRECTSOUND_API	__declspec(dllimport)
#endif

//Class Definetion
#define DSVOLUME_DB(Volume)	((LONG)(-30*(100 - Volume)))	//音量(分贝)

//Enum Definetion
//DirectSound设备协作级别
enum DirectSoundCoopFlags
{
	DSCoopFlags_Normal = 0,			//DSSCL_NORMAL(正常)
	DSCoopFlags_Priority = 1,		//DSSCL_PRIORITY(优先)
	DSCoopFlags_Exclusive = 2,		//DSSCL_EXCLUSIVE(独占)
	DSCoopFlags_WritePrimary = 3,	//DSSCL_WRITEPRIMARY(完全控制)
};

//DirectSound播放状态
enum DirectSoundPlayState
{
	DSPlayState_Loop = 0,	//PlayState:Loop(循环播放)
	DSPlayState_Once = 1,	//PlayState:Once(单次播放)
};

//Class
class DIRECTSOUND_API DirectSound
{
private:
	LPDIRECTSOUND8 m_pDirectSound;	//IDirectSound8 Interface Pointer(IDirectSound8接口指针)
	LPDIRECTSOUNDBUFFER m_pDirectSoundBuffer;	//IDirectSoundBuffer Interface Pointer(IDirectSoundBuffer接口指针)
	LPDIRECTSOUNDBUFFER m_pDirectSoundPrimary;	//IDirectSoundBuffer Interface Pointer(IDirectSoundBuffer接口指针:主缓冲)
	LPDIRECTSOUND3DBUFFER m_pDirectSound3DBuffer;	//IDirectSound3DBuffer Interface Pointer(IDirectSound3DBuffer接口指针)
	LPDIRECTSOUND3DLISTENER m_pDirectSound3DListener;	//IDirectSound3DListener Interface Pointer(IDirectSound3DBuffer接口指针:收听缓冲)

	DSBUFFERDESC m_DSPrimaryDesc;	//DirectSount Wave Buffer(Main)(主缓冲)
	DSBUFFERDESC m_DSBufferDesc;	//DirectSount Wave Buffer(副缓冲)

public:
	DirectSound();	//DirectSound Constructor Function(构造函数)
	~DirectSound();	//DirectSound Destructor Function(析构函数)

	//DirectSound初始化
	HRESULT WINAPI DirectSoundInit(HWND hWnd);	//DirectSound Initialize(SoundCoopFlags:Normal)
	HRESULT WINAPI DirectSoundInit(HWND hWnd, DWORD dwSoundCoopFlags);	//DirectSound Initialize
	HRESULT WINAPI DirectSoundInit(HWND hWnd, DirectSoundCoopFlags eDirectSoundCoopFlags);	//DirectSound Initialize
	HRESULT WINAPI DirectSound3DInit(HWND hWnd);	//DirectSound3D Initialize(SoundCoopFlags:Priority)

	//DirectSound加载
	HRESULT WINAPI DirectSoundLoadWave(LPWSTR lpszFileName);		//DirectSound Load Wave(加载Wav)
	HRESULT WINAPI DirectSoundLoad3DWave(LPWSTR lpszFileName);		//DirectSound Load 3D Wave(加载Wav:3D)

	//DirectSound控制
	void WINAPI DirectSoundPlay(void);	//DirectSound Play Wave(Once)(单次播放)
	void WINAPI DirectSoundPlay(DirectSoundPlayState eDSPlayState_X);	//DirectSound Play Wave(单次播放/循环播放)
	void WINAPI DirectSoundPlayOnce(void);//DirectSound Play Wave(Once)(单次播放)
	void WINAPI DirectSoundPlayLoop(void);//DirectSound Play Wave(Loop)(循环播放)
	void WINAPI DirectSoundStop(void);//DirectSound Stop Play(停止播放)
	void WINAPI DirectSoundSetVolume(LONG lVolume);//DirectSound SetVolume(设置音量)
	void WINAPI DirectSoundSetFrequency(DWORD dwFrequency);//DirectSound SetFrequency(设置频率)
	void WINAPI DirectSoundSetPan(LONG lPan);//DirectSound SetPan(No 3D Voice)(设置声道平衡:不支持3D)
	void WINAPI DirectSoundSetCurrentPosition(DWORD dwNewPositon);//DirectSound SetCurrentPosition(设置播放进度)
};

#endif