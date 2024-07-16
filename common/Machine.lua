dofile("game:\\common\\Assembler.lua")
dofile("game:\\common\\Core.lua")



--ForceTEXT("E")


--F720PMode()
--Stop Lobby Host At Leave From Map 
--WriteVirtualShort("0x8245B21A",55)

--Stop Lobby After Leave Lobby Rules Select
WriteVirtualShort("0x8245B21A",44)




--WriteVirtualBytes("0x822AA054","6000000060000000")
--WriteVirtualBytes("0x822AA0C4","4800")

--Speed
--823F8950 (2 something there)
--822aab48
--822b3744

--WriteVirtualBytes("0x823F8358","4E800020")
--WriteVirtualBytes("0x822B3610","4E800020")


--WriteVirtualBytes("0x822ACAF8","60000000")
--WriteVirtualBytes("0X822ABAD8","4800")
--WriteVirtualBytes("0x822AB9B4","4800")
--WriteVirtualBytes("0x822AB6FC","60000000")
--WriteVirtualBytes("0x822ACAFC","60000000")
--WriteVirtualBytes("0x822AB6BC","60000000")
--822abb80
--822b3900
--WriteVirtualBytes("0x822ABB80","60000000") --move

--WriteVirtualBytes("0x822AB90C","60000000") --move
--WriteVirtualBytes("0x822AB8CC","60000000") --move
--WriteVirtualBytes("0x822AB818","60000000") --move

--WriteVirtualBytes("0x822AB818","60000000") --move

--WriteVirtualBytes("0x822AB808","FCC04090")
--WriteVirtualBytes("0x822AB778","4800")
--WriteVirtualBytes("0x822AA298","60000000")


--WriteVirtualBytes("0X822AA874","60000000")
--WriteVirtualBytes("0x822AA8B4","60000000")
--WriteVirtualBytes("0x822AA948","FC000890")
--WriteVirtualBytes("0x822AA9A0","FD800890")
--WriteVirtualBytes("0x822AA9E8","FC000890")
--WriteVirtualBytes("0x822AC5D0","FD800890")
--WriteVirtualBytes("0x822AC784","FCA00890")

--WriteVirtualBytes("0X82456D3C","600000006000000060000000")

--WriteVirtualBytes("0x822728E8","4E800020") --Rnder point
--WriteVirtualBytes("0X823FB7E8","4E800020")


--WriteVirtualBytes("0X8229F1C0","4E800020")
--WriteVirtualBytes("0X8229B488","4E800020")
--WriteVirtualBytes("0x8229AF6C","4800")

--82466330 - ui Ring store (react to hold)
--8246633c
--82466350 - on release 1
--82466360 - on release 2

--ItemState on hold store
--824683f8
--824685b8 
--release
--824666ec
--82456a98 

--Back (B Button) Handle - 82456BAC

--move sursor visible
--WriteVirtualBytes("0x82463808","386000014E800020")
--WriteVirtualBytes("0x82456074","4800")
--WriteVirtualBytes("0x82456068","4800")
--WriteVirtualBytes("0x8245606C","4800")



--WriteVirtualBytes("0x82456700","4E800020") removing cursor fully






--82237168 
--82495950

--WriteVirtualBytes("0x822B6A78","4800") -- force do only normal jump

--18218FCEC float reacts to little guy too (Red guy, icon)

--WriteVirtualBytes("0x822BFC58","4E800020")





--WriteVirtualBytes("0X8224928c","38 80 00 01")
--WriteVirtualBytes("0x822491B0","4E800020") --8224B828 (ON Lo0ad)
--WriteVirtualBytes("0X8224B750","4E800020")



--DashPanelsNowAddSpeed(0.16)
--KickDashNowAddSpeed(0.16)
--DisableTrainingMode()
--AlwaysShowHidedButtons()
--UnlockAllGearToSelect()
--EveryBoxGivesRandomItem()
--EveryRandomBoxGivesTrueRandomItem()

--Xenia_StuckFIX_Test_ENABLED()


--WriteVirtualBytes("0x822B60F8","4E800020")
--WriteVirtualBytes("0x822B60F8","4E800020



--WriteVirtualBytes("0X822B6448","60000000") --TrickRankHelperCalcuate
--WriteVirtualBytes("0x822B857C","60000000") 

--1701848A8

--822B6780 (kick ON SPEED GAIN)


--8270CD78



--8249250C
--82492570
--824925F4
--82a5637c
--822a4cd4 (T)
--824a4c84 (T)
--822a53cc (T)
--822c9f7c (T)
--822cd484 (T)
--82a56320
--82a56394
--82a56384


--WriteVirtualBytes("0x822A4BC0","4E800020")
--WriteVirtualBytes("0x824A4690","4E800020")
--WriteVirtualBytes("0x822A5140","4E800020")
--WriteVirtualBytes("0x822C9E90","4E800020")
--WriteVirtualBytes("0x822CD3F0","4E800020")
--822B9384 ON Gear Change

--WriteVirtualBytes("0x822B938C","60000000") --Side Switch
--WriteVirtualBytes("0x822B9394","60000000") --Side Switch
--WriteVirtualBytes("0x822B93A8","60000000") --Side Switch
--WriteVirtualBytes("0x822B93B0","60000000") --Side Switch
--WriteVirtualBytes("0x822DA970","60000000") --Side Switch
--WriteVirtualBytes("0x822DA728","4E800020") --Side Switch


--WriteVirtualBytes("0x822B1B58","60000000")
--WriteVirtualBytes("0x822A4370","4E800020")
--WriteVirtualBytes("0x82454360","60000000")
--WriteVirtualBytes("0x822C0560","60000000")
--save 17063F85C (170187DDC)

--R30 0x644(TRICK VALUES)


--822b6aac (trick calculate)

--WriteVirtualBytes("0x822B6AB4","60000000")
--WriteVirtualBytes("0x822B6AB0","60000000")
--WriteVirtualBytes("0x822B6AA8","60000000")
--WriteVirtualBytes("0x822B6AB0","60000000")
--WriteVirtualBytes("0x822B6AE8","60000000")
--WriteVirtualBytes("0x822B6AF8","60000000")
--WriteVirtualBytes("0x822B6B0C","60000000")

--WriteVirtualBytes("0x822B6958","60000000") -- NO CHARE ANYMORE BIGGEST JUMP
--WriteVirtualBytes("0x822B6DC0","4800") -- NO CHARE ANYMORE BIGGEST JUMP
--WriteVirtualBytes("0x822B698C","4800")
--WriteVirtualBytes("0X824554FC","60000000")
--82B47E90




--824770FC(8245A04C,8245551C)





--TrickCalculateasdasf
--822b6aa8 
--506 (back)

--822ab38c
--823b2398



--822B6914 ControlLock compare

--WriteVirtualBytes("0x822B6914","4800") --No Jump, Only For Specific ramps ,no tricks at all


--NETWORK SOME

--WriteVirtualBytes("0x822AB158","4E800020")

----WriteVirtualBytes("0x823B2200","4E800020")

--WriteVirtualBytes("0x82299EB0","4E800020")

--WriteVirtualBytes("0x82495800","386000014E800020")

--WriteVirtualBytes("0x82213458","4E800020")


--183E53810


--WriteVirtualFloat("0x82176278",GameSpeed) --Game Default Speed

--WriteVirtualShort("0x8222B576",FrameRateValue) --Game Default Speed
--WriteVirtualShort("0x8222B592",CalculatedFrameRateEX) --Game Default Speed
--WriteVirtualFloat("0x82180898",FrameRateValue) --Game Default Speed
--WriteVirtualFloat("0x82196A34",CalculatedFrameRate) --Game Default Speed


--83E52F58  --- 82212C60 (fc) (writters 822134A0 82213668) 
-----------CURSASRASRA-_______
--8223305c
--82494680
--82434af0

--8222B584




--CHECK THIS
--8222bdec
--8222cef0


--WriteVirtualBytes("0x8222CEF0","60000000")
--WriteVirtualBytes("0x8222BDEC","60000000")


--WriteVirtualBytes("0x82501410","60000000")
--WriteVirtualBytes("0x825012A8","4E800020")
--WriteVirtualBytes("0X82437360","4E800020")





--WriteVirtualBytes("0x8248B45C","4800")
--WriteVirtualBytes("0X8248B47C","60000000")
--WriteVirtualBytes("0X8248B48C","60000000")

--WriteVirtualBytes("0x824D0478","386000004E800020")



--(r9,-> 8278d8d8)
--WriteVirtualBytes("0x8248B588","4800")
--WriteVirtualBytes("0X8248B5BC","60000000")
--WriteVirtualBytes("0x8248B6F4","60000000")


--WriteVirtualBytes("0x8278D934","4800")
--WriteVirtualBytes("0x8278D924","4800")
--WriteVirtualBytes("0X8248AFB0","60000000")

--WriteVirtualBytes("0x8290B170","4E800020")

--  EtxProducerRegister((int)dword_820992A4, (int)&dword_82AE8D60, 4, 0, 0x40, (int)dword_82B76A30);
--EtxProducerRegister((int)dword_82098FC4, (int)&dword_82AE8CC0, 3, 0, 0x40, (int)&NuipRuntimeState.EtxProducer);


--83E53144 (this components failed to install know why (RACE START CRASH,ONLY WITH DISABLE TRAINING MODE))

--WriteVirtualBytes("0x82239AC8","4E800020") -- Character Install
--WriteVirtualBytes("0X82240490","4E800020") -- Character Install


--Game Stucked Here (82211D9C-824a04bc-824a0414-8244d184-8244d404-8244c530-824f4888-824f8ab4-824f7664-824f4510)

--Game Stucked Here (824D247c-82211d9c-824a04b4-824a01e8-8244e088-8244c3fc-824f4890-82501054-824f8ab4-824f7664-824f4510)

--Game Stucked Here (824D247c-82211E58-824BB8EC-8249BC6C-824E669C-824E6500-824F7A98-82501054-824f7664-824f4510)


--Can Fix SoftLocks But (Need To Be Tested)

--WriteVirtualBytes("0X824E669C","60000000")
--WriteVirtualBytes("0x824F7688","60000000")

------------------------
--WriteVirtualBytes("0x824F4888","60000000")
--WriteVirtualBytes("0x82501054","60000000")

--change on trick land 822BEDC0
--822BEC70 oNLY AT land?

------------------------------
--WriteVirtualBytes("0x824BF458","60000000")
--WriteVirtualBytes("0x824BF494","60000000")
--83E58D80
--8249C334

--822246AC NEIF HEADE COMPARE
--822247C8
--sub_822248D0
--sub_822249B0
--sub_82224638

--82224638 (check if neif file , but a3 can be just pack means just checker) <- 82225698  <-822863F0  <- 82228304<-..82285FA8 <- 82289A70 <- 82289A70
--824E3950
--824e3958
--824ddd34
--824d3964

--824D2A10  CALL DECOMPRESS LZX 
--824D2A10

--82a56450 -- MAYBE NO

--WriteVirtualInt("0x821A8BA8","1280")
--WriteVirtualInt("0x821A8BAC","720")

--WriteVirtualInt("0x821A8BB8","1280")
---WriteVirtualInt("0x821A8BBC","720")

--WriteVirtualShort("0x822112E6","1280")
---WriteVirtualShort("0x822112EA","720")



--WriteVirtualShort("0x8222ABE2","1280")
--WriteVirtualShort("0x8222ABF2","1280")
--WriteVirtualShort("0x8222AC06","1280")
--WriteVirtualShort("0x8222AC12","1280")
--WriteVirtualShort("0x82257B16","1280")

--WriteVirtualFloat("0x8219695C","1280") ----?????



--WriteVirtualShort("0x8222ABE2","1280")

--?PixCaptureVideoFrame@D3D@@YAXPAVCDevice@1@KKKW4_D3DFORMAT@@KKPBU_D3DPRIVATE_SCALER_PARAMETERS@@PBU_D3DGAMMARAMP@@@Z
--824e9628
--824d9628


--WriteVirtualInt("0x82B3484C","1280")


--WriteVirtualInt("0x82B34828","1280")
--82B3484C ?
--82B34828 ?


--8223A7A0

--WriteVirtualBytes("0x82447F44","60000000")

-- sub_824B3538????/

--WriteVirtualBytes("0x8244EA78","4E800020")
--WriteVirtualBytes("0x824E96C8","4E800020")

--WriteVirtualBytes("0x82249790","4800")


--WriteVirtualBytes("0x822721D8","60000000")

--WriteVirtualBytes("0x82272170","60000000")

--Pause(Stop Chr FUll) Disable
--WriteVirtualBytes("0x822720B8","60000000")
--WriteVirtualBytes("0x822720D0","60000000")
------------------------------------------

--WriteVirtualBytes("0x82272430","4E800020")


--PauseElementAccesseros
--8224c720
--823faf2c
--824

--8224C6F8
--8224b2f8
--8224a68c
--8224a454

--WriteVirtualBytes("0x823FAF20","4800")

--WriteVirtualBytes("0x824B0018","4E800020")
--0x50
--WriteVirtualBytes("0x82272170","60000000") 

--Cords Camera ACcess
--8254aeb4
--8254aeac
--8280c374
--824c1264
--8280c4b4

--WriteVirtualBytes("0x82750F48","386000024E800020")

--WriteVirtualBytes("0x8248B748","4800")
--WriteVirtualBytes("0X8248B588","4800")
--WriteVirtualBytes("0x8248B794","60000000")
--WriteVirtualBytes("0x8248B77C","60000000")
--WriteVirtualBytes("0X8248B6F4","60000000")
--WriteVirtualBytes("0x8248B5BC","60000000")

--WriteVirtualBytes("0x824869B4","4800")

---net???????/
--WriteVirtualShort("0x824869BE","3")
--WriteVirtualShort("0x824869BA","1")

--GameMessageRecievers(Net ONly)???
--824861b8
--82458428
--8245eb14 (ONly AT MAtch Serach StaRT)
--WriteVirtualBytes("0X82486A9C","60000000")



--WriteVirtualBytes("0x82212F54","38C00002") -- Force 2P

--821848CC

--net set sygnal 000000008248F5E4


--Game Sygnals Net Accessers 0x4C (BLA BLA)
--824861B8
--824578fc(???? somewhere )
--8245d81c
--824883ac
--8245eb14
--824884a4
--824884a4
--82486474

--Stop Hosting Lobby (0x4C resets from oxB) (WRITETER)
--824884a4
--82486458
--8248649c
--82487ff0






-------------------------
--82232860
--82232900

--82463490 (On Board Confirm, Gear Parts Confirm)
--824607E4





-------------serch (MB PLAYERS SOME????)
--8248a4a8

--Lobby Datas Itself Accesers
--8278d8e0
--Next(Xenia,Xam API)
--8248B4A0
--8248B4BC
--8248B4C8
--8248B720

--WriteVirtualBytes("0x8248B73C","4800")

--WriteVirtualBytes("0x8248E098","60000000")
--WriteVirtualBytes("0x8248DF90","60000000")
--WriteVirtualBytes("0x8248AEE8","4800")
--WriteVirtualBytes("0x8248C058","8248C0AC8248C0AC8248C0AC8248C0AC8248C0AC8248C0AC")




--WriteVirtualBytes("0x8248E07C","60000000")

--WriteVirtualBytes("0x8248C158","4800")
--WriteVirtualBytes("0x8248C170","60000000")
--WriteVirtualBytes("0x8248C180","60000000")

--WriteVirtualBytes("0x8228D784","60000000")
--WriteVirtualBytes("0x82290C5C","82290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA882290CA8")




--821A95D0(VFT OF ) a1
--WriteVirtualBytes("0x82486A9C","60000000")
--WriteVirtualBytes("0X8245D834","60000000")

--WriteVirtualBytes("0x822AB79C","60000000")

--822AA320 (0X748)


--WriteVirtualBytes("0x822AB7D8","60000000")

--WriteVirtualBytes("0x822AB4AC","4800")



--netplay
--WriteVirtualBytes("0x8248B73C","4800")	
--WriteVirtualBytes("0X8248B748","4800")	

--WriteVirtualBytes("0x8248B77C","4800")	
--WriteVirtualBytes("0X824864AC","4800")	

--828093B0 (FIGURE WHAT IS htat)
--WriteVirtualBytes("0x828093B0","4E800020")
--WriteVirtualBytes("0x82807008","4E800020") -- messes animations
--WriteVirtualBytes("0x822AB778","60000000") --little better moving

--WriteVirtualBytes("0x822AB93C","60000000") --
--WriteVirtualBytes("0x822AB914","38C00000")
--WriteVirtualBytes("0X822AB9B4","4800")
--WriteVirtualBytes("0x822ABA6C","60000000")
--WriteVirtualBytes("0x822ABA90","4800")
--WriteVirtualBytes("0x822ABB94","4800")
--WriteVirtualBytes("0x822ABC0C","60000000")
--WriteVirtualBytes("0x822AB4CC","60000000")
--WriteVirtualBytes("0x822AB4F8","60000000")
--WriteVirtualBytes("0x822AB5D4","4800")

--WriteVirtualBytes("0x822AA8D4","4800") --block more
--	WriteVirtualBytes("0x822AA914","4800") --old times camera rails ,..))
--	WriteVirtualBytes("0x822AAA20","4800")
--	WriteVirtualBytes("0x822AAA44","4800")
--	WriteVirtualBytes("0x822AAA60","4800")
--	WriteVirtualBytes("0x822AAB98","4800")
--WriteVirtualBytes("0x822B80D0","4E800020") -- no move atall
--WriteVirtualBytes("0x82299558","4E800020") -- used to interpolate slope rotation

-- ARMS LEFT RIGHT 
--822CEB40 ,822D0DB4, 823F84E4, 822aed18, 
--82a56454, 822ce864, 8228c0c4, 8228a15c, 82279824, 822a4828, 822a4a08


--disabled ( SomeWhere Left-Right Catch Colission, Colission Target Itself misses, some objects dont work, also swim, can jump from grind, no charge effect anymore)
--WriteVirtualBytes("0x822CEB10","4E800020")
--WriteVirtualBytes("0x822D0C70","4E800020")
--WriteVirtualBytes("0x823F8358","4E800020")
--WriteVirtualBytes("0x822AEC48","4E800020")
--WriteVirtualBytes("0x822CE830","4E800020")
--WriteVirtualBytes("0x8228BFA0","4E800020")
--WriteVirtualBytes("0x8228A0B8","4E800020")
--WriteVirtualBytes("0x82279788","4E800020")
--WriteVirtualBytes("0x822A4800","4E800020")
--WriteVirtualBytes("0x822A49E0","4E800020")


--WriteVirtualBytes("0x822BB274","4800")
--WriteVirtualBytes("0x822BB2A4","4800")
--WriteVirtualBytes("0x822BB378","60000000")
--WriteVirtualBytes("0x822BB398","60000000")
--WriteVirtualBytes("0X822BB3A0","60000000")
--WriteVirtualBytes("0x822BB3BC","60000000") -- HERE IS IT


--0xC is State For Left arms
--0xC (right arm)


--11000000 (LEFT)
--10100000 (RIGHT)

--WriteVirtualBytes("0x822855CC","60000000") --it is
--WriteVirtualBytes("0x822859AC","60000000") --it is


--183E5490C (CAM ARRAY NERA) -> 1FF6A5130
--FF6A5A90
-- (1f0) 1FF6A5830


--WriteVirtualBytes("0x82279FD4","60000000")
--WriteVirtualBytes("0x82279FDC","60000000") --follow cam
--824B0A5C





--WriteVirtualBytes("0x8248B73C","4800")
--WriteVirtualBytes("0x8248B748","4800")

--8248E058 POSSIBLE some timer?

--82B4BC38 (emerald gear)
--82B49EF8 (turbo gear)



--store rotation
--8228FE9C 
--8228e614
--8228E830
--822903D4
--8228eadc

--WriteVirtualBytes("0x8228FE9C","60000000")
--822760BC rotation store 
--82299448 - original rotation small value 3.14 seems rotate


--TRICK SYSTEM FLAG Change
--822c0930
--822c0548

--WriteVirtualBytes("0x82757548","4E800020")


--NETWORK LOBBY on create store data
--8248a628
--ChangeMenuNext(null,0,1,-1,0)
--8248E084 (send message to who connect)

--other deltas 824E5858


--NETLAY

--8245C2DC (READ ppp index, but when i go back to select chr, netplay included)
--WriteVirtualBytes("0x8245C140","4E800020")
--WriteVirtualBytes("0X8245CE98","4E800020")
--WriteVirtualBytes("0x8248DE68","4E800020")
--8245D0C8 -- store selected ID, to Static

--ON NETplay create button
--0x8247BE4C<-8247be4c-<8245ed60-<824582d4-<DLL-<8244e294

--WriteVirtualBytes("0x8248E074","60000000") --Desync after start
--WriteVirtualBytes("0x8248E07C","60000000")
--WriteVirtualBytes("0x8248E8A8","60000000")

--WriteVirtualBytes("0x824B0CF8","4800") --ye can breka camera ( yet neee float pls)
--WriteVirtualBytes("0x822995AC","60000000")
--WriteVirtualBytes("0x82275428","4E800020")
--WriteVirtualBytes("0x8227BE7C","60000000")
--WriteVirtualBytes("0x8227BE8C","60000000")

--822A9000  (dword310 -> next reaction in movevement huh )

--8228FE9C
--8228FEF4
--8228E614
--8228E830
--822903D4
--8228EADC

--other pos

--822ABB78
--822B38FC 

--othre pos
--822AF130 

--WriteVirtualBytes("0x822A9008","4800")
--WriteVirtualBytes("0x8228FE60","4800")

