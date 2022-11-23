// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VlcImports.h"
#include "VlcTypes.h"

#define VLC_DECLARE(Func) \
	static FLibvlc##Func##Proc Func;

class FVlc
{
public:

	static const uint32 MaxPlanes = 5;

public:

	static FString GetPluginDir();
	static bool Initialize();
	static void Shutdown();

public:

	VLC_DECLARE(New)
	VLC_DECLARE(Release)
	VLC_DECLARE(Retain)

	VLC_DECLARE(Errmsg)
	VLC_DECLARE(Clearerr)

	VLC_DECLARE(EventAttach)
	VLC_DECLARE(EventDetach)

	VLC_DECLARE(LogGetContext)
	VLC_DECLARE(LogSet)
	VLC_DECLARE(LogUnset)

	VLC_DECLARE(Free)
	VLC_DECLARE(GetChangeset)
	VLC_DECLARE(GetCompiler)
	VLC_DECLARE(GetVersion)

	VLC_DECLARE(Clock)

	VLC_DECLARE(MediaEventManager)
	VLC_DECLARE(MediaGetDuration)
	VLC_DECLARE(MediaGetStats)
	VLC_DECLARE(MediaNewCallbacks)
	VLC_DECLARE(MediaNewLocation)
	VLC_DECLARE(MediaNewPath)
	VLC_DECLARE(MediaRelease)
	VLC_DECLARE(MediaRetain)

	VLC_DECLARE(MediaPlayerEventManager)
	VLC_DECLARE(MediaPlayerGetMedia)
	VLC_DECLARE(MediaPlayerNew)
	VLC_DECLARE(MediaPlayerNewFromMedia)
	VLC_DECLARE(MediaPlayerRelease)
	VLC_DECLARE(MediaPlayerRetain)
	VLC_DECLARE(MediaPlayerSetMedia)

	VLC_DECLARE(MediaPlayerCanPause)
	VLC_DECLARE(MediaPlayerGetFps)
	VLC_DECLARE(MediaPlayerGetLength)
	VLC_DECLARE(MediaPlayerGetPosition)
	VLC_DECLARE(MediaPlayerGetRate)
	VLC_DECLARE(MediaPlayerGetState)
	VLC_DECLARE(MediaPlayerGetTime)
	VLC_DECLARE(MediaPlayerIsSeekable)
	VLC_DECLARE(MediaPlayerSetPosition)
	VLC_DECLARE(MediaPlayerSetRate)
	VLC_DECLARE(MediaPlayerSetTime)

	VLC_DECLARE(MediaPlayerIsPlaying)
	VLC_DECLARE(MediaPlayerTogglePause)
	VLC_DECLARE(MediaPlayerPlay)
	VLC_DECLARE(MediaPlayerSetPause)
	VLC_DECLARE(MediaPlayerStop)

	VLC_DECLARE(AudioGetTrack)
	VLC_DECLARE(AudioSetCallbacks)
	VLC_DECLARE(AudioSetFormat)
	VLC_DECLARE(AudioSetFormatCallbacks)
	VLC_DECLARE(AudioSetTrack)

	VLC_DECLARE(VideoGetSize)
	VLC_DECLARE(VideoGetSpu)
	VLC_DECLARE(VideoGetSpuCount)
	VLC_DECLARE(VideoGetTrack)
	VLC_DECLARE(VideoNewViewpoint)
	VLC_DECLARE(VideoSetCallbacks)
	VLC_DECLARE(VideoSetFormat)
	VLC_DECLARE(VideoSetFormatCallbacks)
	VLC_DECLARE(VideoSetSpu)
	VLC_DECLARE(VideoSetTrack)
	VLC_DECLARE(VideoUpdateViewpoint)

	VLC_DECLARE(AudioGetTrackDescription)
	VLC_DECLARE(VideoGetSpuDescription)
	VLC_DECLARE(VideoGetTrackDescription)
	VLC_DECLARE(TrackDescriptionListRelease)

	VLC_DECLARE(FourccGetChromaDescription)

public:

	static int64 Delay(int64 Timestamp)
	{
		return Timestamp - Clock();
	}

protected:

	static void FreeDependency(void*& Handle);
	static bool LoadDependency(const FString& Dir, const FString& Name, void*& Handle);

private:

	static void* CoreHandle;
	static void* LibHandle;
	static FString PluginDir;

#if PLATFORM_WINDOWS
	static void* GccHandle;
#endif
};