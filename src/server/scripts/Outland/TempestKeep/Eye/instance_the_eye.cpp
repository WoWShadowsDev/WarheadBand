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

#include "InstanceScript.h"
#include "ScriptObject.h"
#include "the_eye.h"
#include <sstream>

class instance_the_eye : public InstanceMapScript
{
public:
    instance_the_eye() : InstanceMapScript("instance_the_eye", 550) { }

    struct instance_the_eye_InstanceMapScript : public InstanceScript
    {
        instance_the_eye_InstanceMapScript(Map* map) : InstanceScript(map) {}

        ObjectGuid ThaladredTheDarkenerGUID;
        ObjectGuid LordSanguinarGUID;
        ObjectGuid GrandAstromancerCapernianGUID;
        ObjectGuid MasterEngineerTelonicusGUID;
        ObjectGuid AlarGUID;
        ObjectGuid KaelthasGUID;
        ObjectGuid BridgeWindowGUID;
        ObjectGuid KaelStateRightGUID;
        ObjectGuid KaelStateLeftGUID;

        void Initialize() override
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_ALAR:
                    AlarGUID = creature->GetGUID();
                    break;
                case NPC_KAELTHAS:
                    KaelthasGUID = creature->GetGUID();
                    break;
                case NPC_THALADRED:
                    ThaladredTheDarkenerGUID = creature->GetGUID();
                    break;
                case NPC_TELONICUS:
                    MasterEngineerTelonicusGUID = creature->GetGUID();
                    break;
                case NPC_CAPERNIAN:
                    GrandAstromancerCapernianGUID = creature->GetGUID();
                    break;
                case NPC_LORD_SANGUINAR:
                    LordSanguinarGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* gobject) override
        {
            switch (gobject->GetEntry())
            {
                case GO_BRIDGE_WINDOW:
                    BridgeWindowGUID = gobject->GetGUID();
                    break;
                case GO_KAEL_STATUE_RIGHT:
                    KaelStateRightGUID = gobject->GetGUID();
                    break;
                case GO_KAEL_STATUE_LEFT:
                    KaelStateLeftGUID = gobject->GetGUID();
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 identifier) const override
        {
            switch (identifier)
            {
                case GO_BRIDGE_WINDOW:
                    return BridgeWindowGUID;
                case GO_KAEL_STATUE_RIGHT:
                    return KaelStateRightGUID;
                case GO_KAEL_STATUE_LEFT:
                    return KaelStateLeftGUID;
                case NPC_ALAR:
                    return AlarGUID;
                case NPC_KAELTHAS:
                    return KaelthasGUID;
                case DATA_KAEL_ADVISOR1:
                    return ThaladredTheDarkenerGUID;
                case DATA_KAEL_ADVISOR2:
                    return LordSanguinarGUID;
                case DATA_KAEL_ADVISOR3:
                    return GrandAstromancerCapernianGUID;
                case DATA_KAEL_ADVISOR4:
                    return MasterEngineerTelonicusGUID;
            }

            return ObjectGuid::Empty;
        }

        std::string GetSaveData() override
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "E Y " << GetBossSaveData();

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(char const* str) override
        {
            if (!str)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(str);

            char dataHead1, dataHead2;

            std::istringstream loadStream(str);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'E' && dataHead2 == 'Y')
            {
                for (uint32 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }
            }
            else
                OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_the_eye_InstanceMapScript(map);
    }
};

class spell_the_eye_countercharge : public SpellScriptLoader
{
public:
    spell_the_eye_countercharge() : SpellScriptLoader("spell_the_eye_countercharge") { }

    class spell_the_eye_counterchargeScript : public AuraScript
    {
        PrepareAuraScript(spell_the_eye_counterchargeScript);

        bool PrepareProc(ProcEventInfo&  /*eventInfo*/)
        {
            // xinef: prevent charge drop
            PreventDefaultAction();
            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_the_eye_counterchargeScript::PrepareProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_the_eye_counterchargeScript();
    }
};

void AddSC_instance_the_eye()
{
    new instance_the_eye();
    new spell_the_eye_countercharge();
}
