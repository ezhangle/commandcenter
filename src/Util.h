#pragma once

#include "sc2api/sc2_api.h"
#include "Common.h"

class CCBot;

namespace Util
{
    struct IsUnit 
    {
        sc2::UNIT_TYPEID m_type;

        IsUnit(sc2::UNIT_TYPEID type);
        bool operator()(const sc2::Unit& unit, const sc2::ObservationInterface*);
    };

    int GetPlayer(const sc2::Unit & unit);
    bool IsCombatUnit(const sc2::Unit & unit);
    bool IsCombatUnitType(const sc2::UnitTypeID type);
    bool IsSupplyProvider(const sc2::Unit & unit);
    bool IsSupplyProviderType(const sc2::UnitTypeID type);
    bool IsTownHall(const sc2::Unit & unit);
    bool IsTownHallType(const sc2::UnitTypeID & type);
    bool IsRefinery(const sc2::Unit & unit);
    bool IsRefineryType(const sc2::UnitTypeID & type);
    bool IsDetector(const sc2::Unit & type);
    bool IsDetectorType(const sc2::UnitTypeID & type);
    bool IsGeyser(const sc2::Unit & unit);
    bool IsMineral(const sc2::Unit & unit);
    bool IsWorker(const sc2::Unit & unit);
    bool IsWorkerType(const sc2::UnitTypeID & unit);
    bool IsIdle(const sc2::Unit & unit);
    bool IsCompleted(const sc2::Unit & unit);
    float GetAttackRange(const sc2::UnitTypeID & type, CCBot & bot);
    
    bool UnitCanBuildTypeNow(const sc2::Unit & unit, const sc2::UnitTypeID & type, CCBot & m_bot);
    sc2::UnitTypeID WhatBuilds(const sc2::UnitTypeID & type);
    int GetUnitTypeWidth(const sc2::UnitTypeID type, const CCBot & bot);
    int GetUnitTypeHeight(const sc2::UnitTypeID type, const CCBot & bot);
    int GetUnitTypeMineralPrice(const sc2::UnitTypeID type, const CCBot & bot);
    int GetUnitTypeGasPrice(const sc2::UnitTypeID type, const CCBot & bot);
    sc2::UnitTypeID GetTownHall(const sc2::Race & race);
    sc2::UnitTypeID GetSupplyProvider(const sc2::Race & race);
    std::string GetStringFromRace(const sc2::Race & race);
    sc2::Race GetRaceFromString(const std::string & race);
    sc2::Point2D CalcCenter(const std::vector<sc2::Unit> & units);
    sc2::UnitTypeID GetUnitTypeIDFromName(const sc2::ObservationInterface * obs, const std::string & name);
    const sc2::Unit & GetClosestEnemyUnitTo(const sc2::Unit & ourUnit, const sc2::ObservationInterface * obs);

    float Dist(const sc2::Point2D & p1, const sc2::Point2D & p2);
    float DistSq(const sc2::Point2D & p1, const sc2::Point2D & p2);
    
    // Kevin-provided helper functions
    void    VisualizeGrids(const sc2::ObservationInterface* obs, sc2::DebugInterface* debug);
    float   TerainHeight(const sc2::GameInfo& info, const sc2::Point2D& point);
    bool    Placement(const sc2::GameInfo& info, const sc2::Point2D& point);
    bool    Pathable(const sc2::GameInfo& info, const sc2::Point2D& point);

    bool    IsResearchAbility(const sc2::ABILITY_ID & ability);
    bool    IsBuildCommand(const sc2::ABILITY_ID & ability);
    bool    IsBuilding(const sc2::UnitTypeID & type);
    bool    IsMorphCommand(const sc2::AbilityID & ability);
    sc2::UnitTypeID AbilityIDToUnitTypeID(const sc2::AbilityID & ability);
    sc2::UpgradeID  AbilityIDToUpgradeID(const sc2::AbilityID & ability);
    sc2::UnitTypeID GetEquivalentUnitTypeID(const sc2::UnitTypeID & id);
    sc2::AbilityID  UnitTypeIDToAbilityID(const sc2::UnitTypeID & id);
};
