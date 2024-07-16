dofile("game:\\common\\Config.lua")


if (FixCrash) then Xenia_StuckFIX_Test_ENABLED("FixedD3DReset") end

if (DashPanelAddSpeed) then DashPanelsNowAddSpeed(DashPanelAddSpeedMultiplier) end
if (KickDashAddSpeed) then KickDashNowAddSpeed(KickDashAddSpeedMultiplier) end
if (DisableCalibration) then SkipTrainingMoveAction(CalibrationModeSkipPreparation) end
if (SkipTrainingMode) then DisableTrainingMode() end
if (ForceShowHiddenButtons) then AlwaysShowHidedButtons() end
if (ForceUnlockAllGears) then UnlockAllGearToSelect() end

if (RandomItemBoxes) then EveryBoxGivesRandomItem() end
if (AbsoluteRandomItemBoxes) then EveryRandomBoxGivesTrueRandomItem() end

if (ForceJapaneseVoices) then  ForceJPDUB() end
if (ForceJapaneseText) then ForceJPTEXT() end

if (DisableKinectGuyICON) then OFFKinectGuyICON() end

if (HUDMode == "Hidden") then CDisableHUD() end

if (DeltaTimer) then DeltaTimerFixes() end

if (ForceRegionText ~= "A") then ForceTEXT(ForceRegionText) end

