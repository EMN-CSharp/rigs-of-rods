/*
    This source file is part of Rigs of Rods
    Copyright 2022 - 2026 Petr Ohlidal

    For more information, see http://www.rigsofrods.org/

    Rigs of Rods is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 3, as
    published by the Free Software Foundation.

    Rigs of Rods is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Rigs of Rods. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file
/// Helper/wrapper functions shared by native (ProceduralRoadAngelscript.cpp)
/// and generic (ProceduralRoadAngelscriptGeneric.cpp) procedural road bindings.
/// Native bindings register these directly (asCALL_CDECL/asCALL_CDECL_OBJFIRST),
/// generic bindings wrap them using WRAP_FN()/WRAP_OBJ_FIRST().

#pragma once

#include "Application.h"
#include "GameContext.h"
#include "ProceduralManager.h"
#include "ProceduralRoad.h"
#include "ScriptEngine.h"
#include "Terrain.h"

namespace ProceduralRoadAngelscriptWrappers {

using namespace RoR;

// class ProceduralRoad

/// The script API has no scene node parameter - the road mesh is attached under
/// the grouping scene node of the terrain's `ProceduralManager`, same as roads created by C++.
static void ProceduralRoad_finish(ProceduralRoad* self)
{
    if (!App::GetGameContext()->GetTerrain())
    {
        App::GetScriptEngine()->SLOG("ProceduralRoad::finish(): no terrain loaded, cannot attach the road mesh.");
        return;
    }
    self->finish(App::GetGameContext()->GetTerrain()->getProceduralManager()->getGroupingSceneNode());
}

} // namespace ProceduralRoadAngelscriptWrappers
