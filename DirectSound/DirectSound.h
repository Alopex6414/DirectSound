/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Alopex/Helium
*     All rights reserved.
*
* @file		DirectSound.h
* @brief	This Program is DirectSound DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2017-10-31
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
#define DSVOLUME_DB(Volume)	((LONG)(-30*(100 - Volume)))

enum DirectSoundPlayState
{
	DSPlayState_Loop = 0,	//PlayState:Loop
	DSPlayState_Once = 1,	//PlayState:Once
};

//Class
class DIRECTSOUND_API DirectSound
{
private:
	LPDIRECTSOUND8 m_pDirectSound;	//IDirectSound8 Interface Pointer
	LPDIRECTSOUNDBUFFER m_pDirectSoundBuffer;	//IDirectSoundBuffer Interface Pointer
	LPDIRECTSOUNDBUFFER m_pDirectSoundPrimary;	//IDirectSoundBuffer Interface Pointer
	LPDIRECTSOUND3DBUFFER m_pDirectSound3DBuffer;	//IDirectSound3DBuffer Interface Pointer
	LPDIRECTSOUND3DLISTENER m_pDirectSound3DListener;	//IDirectSound3DListener Interface Pointer

	DSBUFFERDESC m_DSPrimaryDesc;	//DirectSount Wave Buffer(Main)
	DSBUFFERDESC m_DSBufferDesc;	//DirectSount Wave Buffer

public:
	DirectSound();	//DirectSound Constructor Function
	~DirectSound();	//DirectSound Destructor Function

	HRESULT WINAPI DirectSoundInit(HWND hWnd);	//DirectSound Initialize(SoundCoopFlags:Normal)
	HRESULT WINAPI DirectSoundInit(HWND hWnd, DWORD dwSoundCoopFlags);	//DirectSound Initialize
	HRESULT WINAPI DirectSound3DInit(HWND hWnd);	//DirectSound3D Initialize(SoundCoopFlags:Priority)
	HRESULT WINAPI DirectSoundLoadWave(LPWSTR lpszFileName);		//DirectSound Load Wave
	HRESULT WINAPI DirectSoundLoad3DWave(LPWSTR lpszFileName);	//DirectSound Load 3D Wave
	void WINAPI DirectSoundPlay(void);	//DirectSound Play Wave(Once)
	void WINAPI DirectSoundPlay(DirectSoundPlayState eDSPlayState_X);	//DirectSound Play Wave
	void WINAPI DirectSoundPlayOnce(void);//DirectSound Play Wave(Once)
	void WINAPI DirectSoundPlayLoop(void);//DirectSound Play Wave(Loop)
	void WINAPI DirectSoundStop(void);//DirectSound Stop Play
	void WINAPI DirectSoundSetVolume(LONG lVolume);//DirectSound SetVolume
	void WINAPI DirectSoundSetFrequency(DWORD dwFrequency);//DirectSound SetFrequency
	void WINAPI DirectSoundSetPan(LONG lPan);//DirectSound SetPan(No 3D Voice)
	void WINAPI DirectSoundSetCurrentPosition(DWORD dwNewPositon);//DirectSound SetCurrentPosition
};

#endif