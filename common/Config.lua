--[Global]--
DisableCalibration = true -- Disables calibration from the Training Mode screen. SOMETIMES might do nothing in Story Mode 
CalibrationModeSkipPreparation = true -- Automatically skips "On you Gear!" requirement to move stick to progress


--[Physics]--
DashPanelAddSpeed = false -- Makes Dash Panels add velocity instead of setting it to the max speed of a gear
DashPanelAddSpeedMultiplier = 0.25

KickDashAddSpeed = false -- Makes Kick Dash add velocity instead of setting it to the max speed of a gear
KickDashAddSpeedMultiplier = 0.25


--[Cheats and misc.]--
ForceShowHiddenButtons = false -- Forces to show every HIDDEN button in the menus
ForceUnlockAllGears = false -- Allows to select any gear for any character. Can break bots (stuck with the default gear)

RandomItemBoxes = false -- Randomizes Item Boxes, native random algorithm
AbsoluteRandomItemBoxes = false --Randomizes Item Boxes, custom algorithm that makes EVERYTHING random without restrictions


--[Other]--
ForceJapaneseVoices = false
ForceRegionText = "A" -- (EJGFSI) A - Standard Behaviour
--Breaks sky dive END (EXPORT) SECTION for now
DeltaTimer = true -- Allow game work naturally on current CPU perfomance, previous it was ~= static thats why you can feel slowdown when fps dropdown, + too much round deltatime floats and others stuff that does thing worse(recommend fps 68 but with delta 60), now +- fixed, still have many bugs recommend for netplay, + just play
DebugMode = false -- Only for dev stuff
HUDMode = "Togglable" -- "Standard", "Togglable", "Hidden"
DisableKinectGuyICON = false -- remove from display KinectGUY



--[Input Remap] -- Force Specifig Slots for input in case if you have some issues
XINPUT_1P = 0 
XINPUT_2P = 1





--==[XENIA ONLY]==--
FixCrash = true -- Can cause issues with visuals
SkipTrainingMode = false -- Skips Training mode, requires protect_zero = true in Xenia config.
NetPlayFix = false -- Fix xenia netplay(#xenia-netplay): https://github.com/AdrianCassar/xenia-canary/releases, sligh modification to search lobby, due some XLobbySearch missing properties (that should be) any lobby consider as invalid, so here little modification :)



--822b1da8
--823216f0
--823221d8
--822b4218
