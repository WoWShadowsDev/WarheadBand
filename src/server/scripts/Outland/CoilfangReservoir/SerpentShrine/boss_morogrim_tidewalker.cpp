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

#include "ScriptObject.h"
#include "ScriptedCreature.h"
#include "serpent_shrine.h"

enum Yells
{
    SAY_AGGRO                       = 0,
    SAY_SUMMON                      = 1,
    SAY_SUMMON_BUBLE                = 2,
    SAY_SLAY                        = 3,
    SAY_DEATH                       = 4,
    EMOTE_WATERY_GRAVE              = 5,
    EMOTE_EARTHQUAKE                = 6,
    EMOTE_WATERY_GLOBULES           = 7
};

enum Spells
{
    SPELL_TIDAL_WAVE                = 37730,
    SPELL_WATERY_GRAVE              = 38028,
    SPELL_WATERY_GRAVE_1            = 38023,
    SPELL_WATERY_GRAVE_2            = 38024,
    SPELL_WATERY_GRAVE_3            = 38025,
    SPELL_WATERY_GRAVE_4            = 37850,
    SPELL_EARTHQUAKE                = 37764,
    SPELL_SUMMON_MURLOC1            = 39813,
    SPELL_SUMMON_WATER_GLOBULE_1    = 37854,
    SPELL_SUMMON_WATER_GLOBULE_2    = 37858,
    SPELL_SUMMON_WATER_GLOBULE_3    = 37860,
    SPELL_SUMMON_WATER_GLOBULE_4    = 37861
};

enum Misc
{
    // Creatures
    NPC_WATER_GLOBULE               = 21913,
    NPC_TIDEWALKER_LURKER           = 21920,

    EVENT_SPELL_TIDAL_WAVE          = 1,
    EVENT_SPELL_WATERY_GRAVE        = 2,
    EVENT_SPELL_EARTHQUAKE          = 3,
    EVENT_SUMMON_MURLOCS            = 4,
    EVENT_KILL_TALK                 = 5
};

const uint32 wateryGraveId[4] = {SPELL_WATERY_GRAVE_1, SPELL_WATERY_GRAVE_2, SPELL_WATERY_GRAVE_3, SPELL_WATERY_GRAVE_4};
const uint32 waterGlobuleId[4] = {SPELL_SUMMON_WATER_GLOBULE_1, SPELL_SUMMON_WATER_GLOBULE_2, SPELL_SUMMON_WATER_GLOBULE_3, SPELL_SUMMON_WATER_GLOBULE_4};

class boss_morogrim_tidewalker : public CreatureScript
{
public:
    boss_morogrim_tidewalker() : CreatureScript("boss_morogrim_tidewalker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSerpentShrineAI<boss_morogrim_tidewalkerAI>(creature);
    }

    struct boss_morogrim_tidewalkerAI : public BossAI
    {
        boss_morogrim_tidewalkerAI(Creature* creature) : BossAI(creature, DATA_MOROGRIM_TIDEWALKER)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void KilledUnit(Unit*) override
        {
            if (events.GetNextEventTime(EVENT_KILL_TALK) == 0)
            {
                Talk(SAY_SLAY);
                events.ScheduleEvent(EVENT_KILL_TALK, 6000);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            summon->SetInCombatWithZone();
        }

        void JustDied(Unit* killer) override
        {
            Talk(SAY_DEATH);
            BossAI::JustDied(killer);
        }

        void EnterCombat(Unit* who) override
        {
            BossAI::EnterCombat(who);
            Talk(SAY_AGGRO);

            events.ScheduleEvent(EVENT_SPELL_TIDAL_WAVE, 10000);
            events.ScheduleEvent(EVENT_SPELL_WATERY_GRAVE, 28000);
            events.ScheduleEvent(EVENT_SPELL_EARTHQUAKE, 40000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_SPELL_TIDAL_WAVE:
                    me->CastSpell(me->GetVictim(), SPELL_TIDAL_WAVE, false);
                    events.ScheduleEvent(EVENT_SPELL_TIDAL_WAVE, 20000);
                    break;
                case EVENT_SPELL_WATERY_GRAVE:
                    Talk(SAY_SUMMON_BUBLE);
                    if (me->HealthAbovePct(25))
                    {
                        Talk(EMOTE_WATERY_GRAVE);
                        me->CastCustomSpell(SPELL_WATERY_GRAVE, SPELLVALUE_MAX_TARGETS, 4, me, false);
                    }
                    else
                    {
                        Talk(EMOTE_WATERY_GLOBULES);
                        for (uint8 i = 0; i < 4; ++i)
                            me->CastSpell(me, waterGlobuleId[i], true);
                    }
                    events.ScheduleEvent(EVENT_SPELL_WATERY_GRAVE, 25000);
                    break;
                case EVENT_SPELL_EARTHQUAKE:
                    Talk(EMOTE_EARTHQUAKE);
                    me->CastSpell(me, SPELL_EARTHQUAKE, false);
                    events.ScheduleEvent(EVENT_SPELL_EARTHQUAKE, urand(45000, 60000));
                    events.ScheduleEvent(EVENT_SUMMON_MURLOCS, 8000);
                    break;
                case EVENT_SUMMON_MURLOCS:
                    Talk(SAY_SUMMON);
                    for (uint32 i = SPELL_SUMMON_MURLOC1; i < SPELL_SUMMON_MURLOC1 + 11; ++i)
                        me->CastSpell(me, i, true);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

class spell_morogrim_tidewalker_watery_grave : public SpellScriptLoader
{
public:
    spell_morogrim_tidewalker_watery_grave() : SpellScriptLoader("spell_morogrim_tidewalker_watery_grave") { }

    class spell_morogrim_tidewalker_watery_grave_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_morogrim_tidewalker_watery_grave_SpellScript);

        bool Load() override
        {
            targetNumber = 0;
            return true;
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            if (Unit* target = GetHitUnit())
                if (targetNumber < 4)
                    GetCaster()->CastSpell(target, wateryGraveId[targetNumber++], true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_morogrim_tidewalker_watery_grave_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }

    private:
        uint8 targetNumber;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_morogrim_tidewalker_watery_grave_SpellScript();
    }
};

class spell_morogrim_tidewalker_water_globule_new_target : public SpellScriptLoader
{
public:
    spell_morogrim_tidewalker_water_globule_new_target() : SpellScriptLoader("spell_morogrim_tidewalker_water_globule_new_target") { }

    class spell_morogrim_tidewalker_water_globule_new_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_morogrim_tidewalker_water_globule_new_target_SpellScript);

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            Warhead::Containers::RandomResize(unitList, 1);
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);

            // Xinef: if we have target we currently follow, return
            if (Unit* target = GetCaster()->GetVictim())
                if (GetCaster()->GetThreatMgr().GetThreat(target) >= 100000.0f)
                    return;

            // Xinef: acquire new target
            if (Unit* target = GetHitUnit())
                GetCaster()->AddThreat(target, 1000000.0f);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_morogrim_tidewalker_water_globule_new_target_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_morogrim_tidewalker_water_globule_new_target_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_morogrim_tidewalker_water_globule_new_target_SpellScript();
    }
};

void AddSC_boss_morogrim_tidewalker()
{
    new boss_morogrim_tidewalker();
    new spell_morogrim_tidewalker_watery_grave();
    new spell_morogrim_tidewalker_water_globule_new_target();
}
