#pragma once

#define WIN32_LEAN_AND_MEAN //cute
#define VC_EXTRALEAN
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <codecvt>
#include <map>
#include <dxgi.h>
#include <d3d11.h>
#include <deque>

inline bool once = false;

#include "SDK/Vector.hpp"

#include "Hooks/minhook/minhook.h"
#include "Util/crt.hpp"
#include "Util/IL2cppLib.hpp"

#include "SDK/UnityEngine.hpp"

#include "SDK/Game/PlayerCommand.hpp"
#include "SDK/Game/Entity.hpp"
#include "SDK/Game/WeaponBase.hpp"
#include "SDK/Game/PlayerRoot.hpp"
#include "SDK/Game/GameClient.hpp"

#include "Util/imgui/imgui.h"
#include "Util/imgui/imgui_impl_dx11.h"
#include "Util/imgui/imgui_impl_win32.h"

#include "Features/Menu/Menu.hpp"
#include "Features/Visuals/PlayerESP.hpp"
#include "Features/Aimbot/Aimbot.hpp"
#include "Hooks/Hooks.hpp"