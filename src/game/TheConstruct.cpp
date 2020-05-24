
#include "TheConstruct.h"

#include "Guild/Guild.h"
#include "Guild/GuildMgr.h"
#include "ReputationMgr.h"
#include "CharacterDatabaseCache.h"

enum WEAPONS {
    AXE	    = 196,
    AXE2    = 197,
    BOW	    = 264,
    GUN	    = 266,
    MACE    = 198,
    MACE2   = 199,
    POLEARM = 200,
    SWORD   = 201,
    SWORD2  = 202,
    STAFF   = 227,
    DAGGER  = 1180,
    THROWN  = 2567,
    SPEAR   = 3386,
    CROSSBOW= 5011,
    WAND    = 5009,
    FIST    = 15590
};

enum ARMOR {
    CLOTH   = 9078,
    LEATHER = 9077,
    MAIL    = 8737,
    PLATE   = 750,
    SHIELD  = 9116
};

void DoAtLogin(Player *player) {
    /*
    Darkspear Trolls ID#530
    Orgrimmar - ID#76
    Thunder Bluff - ID#81
    Undercity - ID#68
    */
    std::vector<int> factions = {530, 76, 81, 68};
    InsertFactions(player, factions);

    std::vector<int> skills = {};
    std::vector<int> armors = {};
    std::vector<int> spells = {};
    std::vector<int> disabled_spells = {};
    switch (player->GetClass()) {
	case CLASS_DRUID:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_MACES, SKILL_2H_MACES, SKILL_STAVES, SKILL_DAGGERS, SKILL_FIST_WEAPONS};
	    armors = {SKILL_LEATHER, SKILL_CLOTH};
	    spells = {
		MACE, MACE2, STAFF, DAGGER, FIST,
		CLOTH, LEATHER,
		1066, // Aquatic form
                5487, // Bear form
		9634, // Dire bear form
		6795, // Growl
		6807, // Maul
		18960, // Teleport moonglade

                768,783,2782,2893,5209,5225,5229,8946,8983,9821,9827,9830,9835,9841,
                9846,9850,9853,9858,9863,9867,9876,9881,9885,9889,9892,9896,9898,9901,9904,9907,
                9908,9910,9912,9913,17402,18658,20719,20748,21850,22812,22829,22896,29166
	    };
            disabled_spells = {
                17329,17392,24977
            };
	    break;
	case CLASS_HUNTER:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_AXES, SKILL_2H_AXES, SKILL_SWORDS, SKILL_2H_SWORDS, SKILL_POLEARMS, SKILL_STAVES, SKILL_DAGGERS, SKILL_FIST_WEAPONS, SKILL_BOWS, SKILL_CROSSBOWS, SKILL_GUNS, SKILL_DUAL_WIELD};
	    armors = {SKILL_MAIL, SKILL_LEATHER, SKILL_CLOTH};
	    spells = {
		AXE, AXE2, SWORD, SWORD2, POLEARM, STAFF, DAGGER, FIST, BOW, CROSSBOW, GUN,
		CLOTH, LEATHER, MAIL,
		5149, // Tame beast
		1515, // Beast training
		6991, // Feed pet
		982, // Revive pet
		883, // Call pet
		2641, // Dismiss pet
                // Pet Skills
                24495, 24508, 24509, 24510, // Arcane Resistance
                7370, 26184, 26185, 26186, 26202, 28343, // Charge
                17254, 17262, 17263, 17264, 17265, 17266, 17267, 17268, // Bite
 	 	2980, 2981, 2982, 3667, 2975, 2976, 2977, 3666, // Claw
                24440, 24441, 24463, 24464, // Fire Resistance
                24475, 24476, 24477, 24478, // Frost Resistance
                24609, 24608, 24607, 24599, // Furious Howl
                4195, 4196, 4197, 4198, 4199, 4200, 4201, 4202, 5048, 5049, // Great Stamina
                14923, 14924, 14925, 14926, 14927, // Growl
 	 	24845, 25013, 25014, 25015, 25016, 25017, // Lightning Breath
                24547, 24556, 24557, 24558, 24559, 24560, 24561, 24562, 24631, 24632, // Natural Armor
                24494, 24511, 24512, 24513, // Nature Resistance
                24451, 24454, 24455, // Prowl
                24641, 24584, 24588, 24589, // Scorpid Poison
 	 	24424, 24580, 24581, 24582, // Screech
                24490, 24514, 24515, 24516, // Shadow Resistance
                26065, // Shell shield
                26094, 26189, 26190, // Thunderstomp
                23100, 23111, 23112, // Dash
                23146, 23149, 23150, // Dive
                1747, 1748, 1749, 1750, 1751, 16698, // Cower

                1002,1462,1494,1543,3045,3127,5116,5118,5384,6197,13159,13161,13163,13544,
                13555,13809,14266,14268,14271,14273,14277,14280,14287,14290,14295,14305,
                14311,14317,14322,14325,14327,15632,19801,19878,19879,19880,19882,19883,19884,
                19885,20190
	    };
            disabled_spells = {
                20904,20906,20910,24133
            };

            InsertPet(player);
	    break;
	case CLASS_MAGE:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_SWORDS, SKILL_STAVES, SKILL_DAGGERS, SKILL_WANDS};
	    armors = {SKILL_CLOTH};
	    spells = {
		SWORD, STAFF, DAGGER, WAND,
		CLOTH,
                23028, // Arcane Brilliance
                10140, // Conjure water rank 7
                10145, // Conjure food rank 6
                //28612, // Conjure food rank 7
                28272, // Polymorph: Pig

                // All the rest
                130,201,227,475,759,1180,1953,2139,2855,3552,5009,7301,9078,10053,10054,
                10151,10157,10161,10170,10174,10177,10181,10187,10193,10199,10202,10207,10212,
                10216,10220,10225,10230,12051,12826,22783
	    };
            disabled_spells = {
                13021,13033,18809
            };

            switch (player->GetRace()) {
                case RACE_GNOME:
                case RACE_HUMAN:
                    spells.push_back(3561);
                    spells.push_back(3562);
                    spells.push_back(3565);
                    spells.push_back(10059);
                    spells.push_back(11416);
                    spells.push_back(11419);
                    break;
                case RACE_TROLL:
                case RACE_UNDEAD:
                    spells.push_back(3563);
                    spells.push_back(3566);
                    spells.push_back(3567);
                    spells.push_back(11417);
                    spells.push_back(11418);
                    spells.push_back(11420);
                    break;
            }
	    break;
	case CLASS_PALADIN:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_AXES, SKILL_2H_AXES, SKILL_SWORDS, SKILL_2H_SWORDS, SKILL_MACES, SKILL_2H_MACES, SKILL_POLEARMS};
	    armors = {SKILL_PLATE_MAIL, SKILL_MAIL, SKILL_LEATHER, SKILL_CLOTH, SKILL_SHIELD};
	    spells = {
		AXE, AXE2, MACE, MACE2, POLEARM,
		CLOTH, LEATHER, MAIL, PLATE, SHIELD,

                1020,1038,1044,1152,3127,4987,5502,5573,10278,10293,10301,10308,10310,10314,10318,
                10326,10329,13819,19746,19752,19838,19854,19896,19898,19900,19943,19979,20164,
                20271,20293,20308,20349,20357,20729,20773,23214,24239,25780,25782,25890,25894,25895
	    };
            disabled_spells = {
                20914,20920,20924,20928,20930,25898,25899
            };
	    break;
	case CLASS_PRIEST:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_MACES, SKILL_STAVES, SKILL_DAGGERS, SKILL_WANDS};
	    armors = {SKILL_CLOTH};
	    spells = {
		MACE, STAFF, DAGGER, WAND,
                CLOTH,

                528,552,988,1706,2053,6064,6346,10876,10890,10894,10901,10909,10912,
                10917,10929,10934,10938,10942,10947,10952,10953,10955,10958,10961,10965,
                15261,20770,21564,27681,27683
	    };
            disabled_spells = {
                18807,27801,27841,27871
            };

            switch (player->GetRace()) {
                case RACE_DWARF:
                    spells.push_back(6346);
                    spells.push_back(19243);
                    break;
                case RACE_HUMAN:
                    spells.push_back(19243);
                    spells.push_back(19275);
                    break;
                case RACE_NIGHTELF:
                    spells.push_back(19293);
                    spells.push_back(19305);
                    break;
                case RACE_UNDEAD:
                    spells.push_back(19266);
                    spells.push_back(19280);
                    break;
                case RACE_TROLL:
                    spells.push_back(19285);
                    spells.push_back(19312);
                    break;
            }
	    break;
	case CLASS_ROGUE:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_SWORDS, SKILL_MACES, SKILL_DAGGERS, SKILL_FIST_WEAPONS, SKILL_BOWS, SKILL_CROSSBOWS, SKILL_GUNS, SKILL_THROWN, SKILL_DUAL_WIELD};
	    armors = {SKILL_LEATHER, SKILL_CLOTH};
	    spells = {
		SWORD, MACE, DAGGER, FIST, BOW, CROSSBOW, GUN, THROWN,
		CLOTH, LEATHER,
                2842, // Poisons

                921,1725,1769,1787,1804,1833,1842,1857,1860,2094,2836,3127,3421,5277,6510,
                6774,8643,11198,11269,11275,11281,11286,11290,11294,11297,11300,11303,11305,
                11343,11358,11400,13230
	    };
            disabled_spells = {
                17347,17348
            };
	    break;
	case CLASS_SHAMAN:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_AXES, SKILL_2H_AXES, SKILL_MACES, SKILL_2H_MACES, SKILL_POLEARMS, SKILL_STAVES, SKILL_DAGGERS, SKILL_FIST_WEAPONS};
	    armors = {SKILL_MAIL, SKILL_LEATHER, SKILL_CLOTH, SKILL_SHIELD};
	    spells = {
		AXE, MACE, POLEARM, STAFF, DAGGER, FIST,
		CLOTH, LEATHER, MAIL, SHIELD,
		3599, // Searing totem rank 1
		8071, // Stoneskin totem rank 1
		5394, // Healing Stream totem rank 1

                131,526,546,556,2484,2645,2870,6196,6495,8012,8143,8166,8170,8177,10396,10408,
                10414,10428,10432,10438,10442,10448,10463,10468,10473,10479,10497,10538,10587,
                10601,10605,10614,10623,10627,11315,15112,15208,16316,16342,16356,16362,16387,
                20608,20777,25908
	    };
	    disabled_spells = {
                AXE2, MACE2, 17359
            };
	    break;
	case CLASS_WARLOCK:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_SWORDS, SKILL_STAVES, SKILL_DAGGERS, SKILL_WANDS};
	    armors = {SKILL_CLOTH};
	    spells = {
		SWORD, STAFF, DAGGER, WAND,
		CLOTH,
		688, // Summon Imp
                691, // Summon Felhunter
		697, // Summon Voidwalker
		712, // Summon Succubus

                126,132,603,696,698,1122,2970,5500,5697,5784,6215,11661,11668,11672,11675,
                11678,11684,11689,11695,11700,11704,11708,11713,11717,11719,11722,11726,11730,
                11735,11740,11743,17728,17923,17924,17926,17928,17937,17953,18540,18647,20757,
                23161
	    };
            disabled_spells = {
                18871,18881,18932,18938
            };
	    break;
	case CLASS_WARRIOR:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_AXES, SKILL_2H_AXES, SKILL_SWORDS, SKILL_2H_SWORDS, SKILL_MACES, SKILL_2H_MACES, SKILL_POLEARMS, SKILL_STAVES, SKILL_DAGGERS, SKILL_FIST_WEAPONS, SKILL_BOWS, SKILL_CROSSBOWS, SKILL_GUNS, SKILL_THROWN, SKILL_DUAL_WIELD};
	    armors = {SKILL_PLATE_MAIL, SKILL_MAIL, SKILL_LEATHER, SKILL_CLOTH, SKILL_SHIELD};
	    spells = {
		AXE, AXE2, SWORD, SWORD2, MACE, MACE2, POLEARM, STAFF, DAGGER, FIST, BOW, CROSSBOW, GUN, THROWN,
		CLOTH, LEATHER, MAIL, PLATE, SHIELD,
		71, // Defensive stance
		2458, // Berserker stance
		355, // Taunt
		7386, // Sunder Armor
		20252, // Intercept

                676,871,1161,1672,1680,1719,2565,2687,3127,5246,6554,7373,11551,11556,
                11567,11574,11578,11581,11585,11597,11601,11605,18499,20230,20560,20569,
                20617,20662
	    };
            disabled_spells = {
                21552,21553,23893,23894,23924,23925
            };
	    break;
    }

    InsertSkills(player, skills);
    InsertArmors(player, armors);
    InsertSpells(player, spells);
    InsertSpells(player, disabled_spells, true);
    InsertRiding(player);
    InsertHomebind(player);
}

void DoPostLogin(Player *player) {
    AddToGuild(player);
}

void InsertFactions(Player *player, std::vector<int> factions) {
    static SqlStatementID insFaction;
    for (int faction : factions) {
	SqlStatement insert = CharacterDatabase.CreateStatement(insFaction, "REPLACE INTO character_reputation"
		"(guid, faction, standing, flags)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(faction);
	insert.addUInt32(42999);
	insert.addUInt32(FACTION_FLAG_VISIBLE);

	insert.Execute();
    }
}

void InsertSkills(Player *player, std::vector<int> skills) {
    static SqlStatementID insSkill;
    for (int skill : skills) {
	SqlStatement insert = CharacterDatabase.CreateStatement(insSkill, "REPLACE INTO character_skills"
		"(guid, skill, value, max)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(skill);
	insert.addUInt32(300);
	insert.addUInt32(300);

	insert.Execute();
    }
}

void InsertArmors(Player *player, std::vector<int> armors) {
    static SqlStatementID insArmor;
    for (int armor : armors) {
	SqlStatement insert = CharacterDatabase.CreateStatement(insArmor, "REPLACE INTO character_skills"
		"(guid, skill, value, max)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(armor);
	insert.addUInt32(1);
	insert.addUInt32(1);

	insert.Execute();
    }
}

void InsertSpells(Player *player, std::vector<int> spells, bool disabled) {
    static SqlStatementID insSpell;
    for (int spell : spells) {
	SqlStatement insert = CharacterDatabase.CreateStatement(insSpell, "REPLACE INTO character_spell"
		"(guid, spell, active, disabled)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(spell);
	insert.addUInt8(1);
	if (disabled) {
	    insert.addUInt8(1);
	} else {
	    insert.addUInt8(0);
	}

	insert.Execute();
    }
}

void InsertRiding(Player *player) {
    std::vector<int> ridings_special = {SKILL_RIDING_HORSE, SKILL_RIDING_WOLF, SKILL_RIDING_TIGER, SKILL_RIDING_RAM, SKILL_RIDING_RAPTOR, SKILL_RIDING_KODO};
    for (int riding : ridings_special) {
	static SqlStatementID insRidingSpecial;
	SqlStatement insert = CharacterDatabase.CreateStatement(insRidingSpecial, "REPLACE INTO character_skills"
		"(guid, skill, value, max)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(riding);
	insert.addUInt32(75);
	insert.addUInt32(75);

	insert.Execute();
    }

    std::vector<int> ridings = {SKILL_RIDING};
    for (int riding : ridings) {
	static SqlStatementID insRiding;
	SqlStatement insert = CharacterDatabase.CreateStatement(insRiding, "REPLACE INTO character_skills"
		"(guid, skill, value, max)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(riding);
	insert.addUInt32(150);
	insert.addUInt32(150);

	insert.Execute();
    }

    // spells
    std::vector<int> all_spells = {
	//33388, // apprentice riding
	33391 // journeyman riding
    };
    for (int spell : all_spells) {
	static SqlStatementID insSpell;
	SqlStatement insert = CharacterDatabase.CreateStatement(insSpell, "REPLACE INTO character_spell"
		"(guid, spell, active, disabled)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(spell);
	insert.addUInt8(1);
	insert.addUInt8(0);

	insert.Execute();
    }
}

void InsertHomebind(Player *player) {
    if (player->GetTeam() != ALLIANCE) {
	return;
    }

    static SqlStatementID insHomebind;
    SqlStatement insert = CharacterDatabase.CreateStatement(insHomebind, "REPLACE INTO character_homebind"
	    "(guid, map, zone, position_x, position_y, position_z)"
	    "VALUES (?,?,?,?,?,?)");

    insert.addUInt32(player->GetGUIDLow());
    insert.addUInt32(0);
    insert.addUInt32(1519);
    insert.addFloat(-8828.48f);
    insert.addFloat(625.829f);
    insert.addFloat(93.9437f);

    insert.Execute();
}

void InsertPet(Player *player) {
    CharacterPetCache *cache = new CharacterPetCache;

    static SqlStatementID insPet;
    SqlStatement insert = CharacterDatabase.CreateStatement(insPet, "REPLACE INTO character_pet"
	    "(id, entry, owner, modelid, CreatedBySpell, PetType, level, exp, Reactstate, loyaltypoints, loyalty, trainpoint, name, renamed, slot, curhealth, curmana, curhappiness, savetime, resettalents_cost, resettalents_time, abdata, teachspelldata)"
	    "VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");

    int id = insert.ID();
    cache->id = id;
    cache->entry = 2850;
    cache->owner = player->GetGUIDLow();
    cache->modelid = 6082;
    cache->CreatedBySpell = 13481;
    cache->PetType = 1;
    cache->level = 60;
    cache->exp = 0;
    cache->Reactstate = 1;
    cache->loyaltypoints = 1000;
    cache->loyalty = 6;
    cache->trainpoint = 285;
    cache->name = "Cat";
    cache->renamed = 0;
    cache->slot = 0;
    cache->curhealth = 2990;
    cache->curmana = 0;
    cache->curhappiness = 1000000;
    cache->savetime = time(nullptr);
    cache->resettalents_cost = 0;
    cache->resettalents_time = 0;
    cache->abdata = "7 2 7 1 7 0 129 23099 129 0 129 0 129 0 6 2 6 1 6 0";
    cache->TeachSpelldata = "0 0 0 0 0 0 0 0";
    
    PetSpellCache *psCache = new PetSpellCache;
    psCache->spell = 23099;
    psCache->active = 129;
    cache->spells.push_back(*psCache);

    insert.addUInt32(id);
    insert.addUInt32(2850);
    insert.addUInt32(player->GetGUIDLow());
    insert.addUInt32(6082);
    insert.addUInt32(13481);
    insert.addUInt8(1);
    insert.addUInt32(60);
    insert.addUInt32(0);
    insert.addUInt8(1);
    insert.addInt32(1000);
    insert.addUInt32(6);
    insert.addInt32(285);
    insert.addString("Cat");
    insert.addUInt8(0);
    insert.addUInt32(0);
    insert.addUInt32(2990);
    insert.addUInt32(0);
    insert.addUInt32(1000000);
    insert.addUInt32(time(nullptr));
    insert.addUInt32(0);
    insert.addUInt32(0);
    insert.addString("7 2 7 1 7 0 129 23099 129 0 129 0 129 0 6 2 6 1 6 0");
    insert.addString("0 0 0 0 0 0 0 0");
    insert.Execute();

    static SqlStatementID insPetSpell;
    SqlStatement petSpellStmt = CharacterDatabase.CreateStatement(insPetSpell, "INSERT INTO pet_spell (guid,spell,active) VALUES (?, ?, ?)");
    petSpellStmt.addUInt32(id);
    petSpellStmt.addUInt32(psCache->spell);
    petSpellStmt.addUInt32(psCache->active);
    petSpellStmt.Execute();

    sCharacterDatabaseCache.InsertCharacterPet(cache);
}

void AddToGuild(Player *player) {
    if (player->GetTeam() != ALLIANCE) {
	return;
    }

    uint32_t guildId = 1;
    Guild *guild = sGuildMgr.GetGuildById(guildId);
    GuildAddStatus status = guild->AddMember(player->GetGUIDLow(), guild->GetLowestRank());
    switch (status) {
	case GuildAddStatus::ALREADY_IN_GUILD:
	    BASIC_LOG("AddToGuild FAILED, player %s ALREADY_IN_GUILD", player->GetName());
	    break;
	case GuildAddStatus::GUILD_FULL:
	    BASIC_LOG("AddToGuild FAILED, player %s GUILD_FULL", player->GetName());
	    break;
	case GuildAddStatus::PLAYER_DATA_ERROR:
	    BASIC_LOG("AddToGuild FAILED, player %s PLAYER_DATA_ERROR", player->GetName());
	    break;
	case GuildAddStatus::UNKNOWN_PLAYER:
	    BASIC_LOG("AddToGuild FAILED, player %s UNKNOWN_PLAYER", player->GetName());
	    break;
    }
}
