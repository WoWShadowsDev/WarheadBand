/*
 * This file is part of the WarheadCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "CreatureData.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Warhead::Impl::EnumUtilsImpl
{

/*************************************************************************\
|* data for enum 'CreatureFlagsExtra' in 'CreatureData.h' auto-generated *|
\*************************************************************************/
template <>
WH_API_EXPORT EnumText EnumUtils<CreatureFlagsExtra>::ToString(CreatureFlagsExtra value)
{
    switch (value)
    {
        case CREATURE_FLAG_EXTRA_INSTANCE_BIND: return { "CREATURE_FLAG_EXTRA_INSTANCE_BIND", "CREATURE_FLAG_EXTRA_INSTANCE_BIND", "creature kill bind instance with killer and killer's group" };
        case CREATURE_FLAG_EXTRA_CIVILIAN: return { "CREATURE_FLAG_EXTRA_CIVILIAN", "CREATURE_FLAG_EXTRA_CIVILIAN", "not aggro (ignore faction/reputation hostility)" };
        case CREATURE_FLAG_EXTRA_NO_PARRY: return { "CREATURE_FLAG_EXTRA_NO_PARRY", "CREATURE_FLAG_EXTRA_NO_PARRY", "creature can't parry" };
        case CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN: return { "CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN", "CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN", "creature can't counter-attack at parry" };
        case CREATURE_FLAG_EXTRA_NO_BLOCK: return { "CREATURE_FLAG_EXTRA_NO_BLOCK", "CREATURE_FLAG_EXTRA_NO_BLOCK", "creature can't block" };
        case CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS: return { "CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS", "CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS", "creature can't do crush attacks" };
        case CREATURE_FLAG_EXTRA_NO_XP: return { "CREATURE_FLAG_EXTRA_NO_XP", "CREATURE_FLAG_EXTRA_NO_XP", "creature kill does not provide XP" };
        case CREATURE_FLAG_EXTRA_TRIGGER: return { "CREATURE_FLAG_EXTRA_TRIGGER", "CREATURE_FLAG_EXTRA_TRIGGER", "trigger creature" };
        case CREATURE_FLAG_EXTRA_NO_TAUNT: return { "CREATURE_FLAG_EXTRA_NO_TAUNT", "CREATURE_FLAG_EXTRA_NO_TAUNT", "creature is immune to taunt auras and 'attack me' effects" };
        case CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE: return { "CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE", "CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE", "creature won't update movement flags" };
        case CREATURE_FLAG_EXTRA_GHOST_VISIBILITY: return { "CREATURE_FLAG_EXTRA_GHOST_VISIBILITY", "CREATURE_FLAG_EXTRA_GHOST_VISIBILITY", "creature will only be visible to dead players" };
        case CREATURE_FLAG_EXTRA_UNUSED_12: return { "CREATURE_FLAG_EXTRA_UNUSED_12", "CREATURE_FLAG_EXTRA_UNUSED_12", "TODO: Implement CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK (creature will use offhand attacks)" };
        case CREATURE_FLAG_EXTRA_NO_SELL_VENDOR: return { "CREATURE_FLAG_EXTRA_NO_SELL_VENDOR", "CREATURE_FLAG_EXTRA_NO_SELL_VENDOR", "players can't sell items to this vendor" };
        case CREATURE_FLAG_EXTRA_IGNORE_COMBAT: return { "CREATURE_FLAG_EXTRA_IGNORE_COMBAT", "CREATURE_FLAG_EXTRA_IGNORE_COMBAT", "" };
        case CREATURE_FLAG_EXTRA_WORLDEVENT: return { "CREATURE_FLAG_EXTRA_WORLDEVENT", "CREATURE_FLAG_EXTRA_WORLDEVENT", "custom flag for world event creatures (left room for merging)" };
        case CREATURE_FLAG_EXTRA_GUARD: return { "CREATURE_FLAG_EXTRA_GUARD", "CREATURE_FLAG_EXTRA_GUARD", "Creature is guard" };
        case CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH: return { "CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH", "CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH", "creature ignores feign death" };
        case CREATURE_FLAG_EXTRA_NO_CRIT: return { "CREATURE_FLAG_EXTRA_NO_CRIT", "CREATURE_FLAG_EXTRA_NO_CRIT", "creature can't do critical strikes" };
        case CREATURE_FLAG_EXTRA_NO_SKILL_GAINS: return { "CREATURE_FLAG_EXTRA_NO_SKILL_GAINS", "CREATURE_FLAG_EXTRA_NO_SKILL_GAINS", "creature won't increase weapon skills" };
        case CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS: return { "CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS", "CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS", "Taunt is subject to diminishing returns on this creature" };
        case CREATURE_FLAG_EXTRA_ALL_DIMINISH: return { "CREATURE_FLAG_EXTRA_ALL_DIMINISH", "CREATURE_FLAG_EXTRA_ALL_DIMINISH", "creature is subject to all diminishing returns as players are" };
        case CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ: return { "CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ", "CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ", "creature does not need to take player damage for kill credit" };
        case CREATURE_FLAG_EXTRA_AVOID_AOE: return { "CREATURE_FLAG_EXTRA_AVOID_AOE", "CREATURE_FLAG_EXTRA_AVOID_AOE", "pussywizard: ignored by aoe attacks (for icc blood prince council npc - Dark Nucleus)" };
        case CREATURE_FLAG_EXTRA_NO_DODGE: return { "CREATURE_FLAG_EXTRA_NO_DODGE", "CREATURE_FLAG_EXTRA_NO_DODGE", "xinef: target cannot dodge" };
        case CREATURE_FLAG_EXTRA_MODULE: return { "CREATURE_FLAG_EXTRA_MODULE", "CREATURE_FLAG_EXTRA_MODULE", "Used by module creatures to avoid blizzlike checks." };
        case CREATURE_FLAG_EXTRA_IGNORE_ASSISTANCE_CALL: return { "CREATURE_FLAG_EXTRA_IGNORE_ASSISTANCE_CALL", "Creatures are not aggroed by other mobs assistance functions", "" };
        case CREATURE_FLAG_EXTRA_UNUSED_27: return { "CREATURE_FLAG_EXTRA_UNUSED_27", "CREATURE_FLAG_EXTRA_UNUSED_27", "" };
        case CREATURE_FLAG_EXTRA_UNUSED_28: return { "CREATURE_FLAG_EXTRA_UNUSED_28", "CREATURE_FLAG_EXTRA_UNUSED_28", "" };
        case CREATURE_FLAG_EXTRA_DUNGEON_BOSS: return { "CREATURE_FLAG_EXTRA_DUNGEON_BOSS", "CREATURE_FLAG_EXTRA_DUNGEON_BOSS", "creature is a dungeon boss (SET DYNAMICALLY, DO NOT ADD IN DB)" };
        case CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING: return { "CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING", "CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING", "creature ignore pathfinding" };
        case CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK: return { "CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK", "CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK", "creature is immune to knockback effects" };
        case CREATURE_FLAG_EXTRA_HARD_RESET: return { "CREATURE_FLAG_EXTRA_HARD_RESET", "CREATURE_FLAG_EXTRA_HARD_RESET", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
WH_API_EXPORT size_t EnumUtils<CreatureFlagsExtra>::Count() { return 32; }

template <>
WH_API_EXPORT CreatureFlagsExtra EnumUtils<CreatureFlagsExtra>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return CREATURE_FLAG_EXTRA_INSTANCE_BIND;
        case 1: return CREATURE_FLAG_EXTRA_CIVILIAN;
        case 2: return CREATURE_FLAG_EXTRA_NO_PARRY;
        case 3: return CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN;
        case 4: return CREATURE_FLAG_EXTRA_NO_BLOCK;
        case 5: return CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS;
        case 6: return CREATURE_FLAG_EXTRA_NO_XP;
        case 7: return CREATURE_FLAG_EXTRA_TRIGGER;
        case 8: return CREATURE_FLAG_EXTRA_NO_TAUNT;
        case 9: return CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE;
        case 10: return CREATURE_FLAG_EXTRA_GHOST_VISIBILITY;
        case 11: return CREATURE_FLAG_EXTRA_UNUSED_12;
        case 12: return CREATURE_FLAG_EXTRA_NO_SELL_VENDOR;
        case 13: return CREATURE_FLAG_EXTRA_IGNORE_COMBAT;
        case 14: return CREATURE_FLAG_EXTRA_WORLDEVENT;
        case 15: return CREATURE_FLAG_EXTRA_GUARD;
        case 16: return CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH;
        case 17: return CREATURE_FLAG_EXTRA_NO_CRIT;
        case 18: return CREATURE_FLAG_EXTRA_NO_SKILL_GAINS;
        case 19: return CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS;
        case 20: return CREATURE_FLAG_EXTRA_ALL_DIMINISH;
        case 21: return CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ;
        case 22: return CREATURE_FLAG_EXTRA_AVOID_AOE;
        case 23: return CREATURE_FLAG_EXTRA_NO_DODGE;
        case 24: return CREATURE_FLAG_EXTRA_MODULE;
        case 25: return CREATURE_FLAG_EXTRA_IGNORE_ASSISTANCE_CALL;
        case 26: return CREATURE_FLAG_EXTRA_UNUSED_27;
        case 27: return CREATURE_FLAG_EXTRA_UNUSED_28;
        case 28: return CREATURE_FLAG_EXTRA_DUNGEON_BOSS;
        case 29: return CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING;
        case 30: return CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK;
        case 31: return CREATURE_FLAG_EXTRA_HARD_RESET;
        default: throw std::out_of_range("index");
    }
}

template <>
WH_API_EXPORT size_t EnumUtils<CreatureFlagsExtra>::ToIndex(CreatureFlagsExtra value)
{
    switch (value)
    {
        case CREATURE_FLAG_EXTRA_INSTANCE_BIND: return 0;
        case CREATURE_FLAG_EXTRA_CIVILIAN: return 1;
        case CREATURE_FLAG_EXTRA_NO_PARRY: return 2;
        case CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN: return 3;
        case CREATURE_FLAG_EXTRA_NO_BLOCK: return 4;
        case CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS: return 5;
        case CREATURE_FLAG_EXTRA_NO_XP: return 6;
        case CREATURE_FLAG_EXTRA_TRIGGER: return 7;
        case CREATURE_FLAG_EXTRA_NO_TAUNT: return 8;
        case CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE: return 9;
        case CREATURE_FLAG_EXTRA_GHOST_VISIBILITY: return 10;
        case CREATURE_FLAG_EXTRA_UNUSED_12: return 11;
        case CREATURE_FLAG_EXTRA_NO_SELL_VENDOR: return 12;
        case CREATURE_FLAG_EXTRA_IGNORE_COMBAT: return 13;
        case CREATURE_FLAG_EXTRA_WORLDEVENT: return 14;
        case CREATURE_FLAG_EXTRA_GUARD: return 15;
        case CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH: return 16;
        case CREATURE_FLAG_EXTRA_NO_CRIT: return 17;
        case CREATURE_FLAG_EXTRA_NO_SKILL_GAINS: return 18;
        case CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS: return 19;
        case CREATURE_FLAG_EXTRA_ALL_DIMINISH: return 20;
        case CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ: return 21;
        case CREATURE_FLAG_EXTRA_AVOID_AOE: return 22;
        case CREATURE_FLAG_EXTRA_NO_DODGE: return 23;
        case CREATURE_FLAG_EXTRA_MODULE: return 24;
        case CREATURE_FLAG_EXTRA_IGNORE_ASSISTANCE_CALL: return 25;
        case CREATURE_FLAG_EXTRA_UNUSED_27: return 26;
        case CREATURE_FLAG_EXTRA_UNUSED_28: return 27;
        case CREATURE_FLAG_EXTRA_DUNGEON_BOSS: return 28;
        case CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING: return 29;
        case CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK: return 30;
        case CREATURE_FLAG_EXTRA_HARD_RESET: return 31;
        default: throw std::out_of_range("value");
    }
}
}
