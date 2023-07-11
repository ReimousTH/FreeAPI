local shown = false
param0 = 3.0
param1 = 3.0
param2 = 4.0
--5 Woah Respawn
--6 Speed Max ???
--7
--8 Jump
--9 Land
--10 (pupils strange)
--11 Switch
--12 GhostState
--13 Trick
--14 Trick
--15 TrickBackward
--16 Same
--17 FailedStartTrick
--18 Crash
--19 Crash
--0xD Trick
--0xD Grind Too?

--CHR State CallBack
--823EBE7C
--823EBEB0
--822aa274 (WORKs even in training)
--8225d504
--822b0024
--16BC Real Offset (from base,base)


--Hip Mid State CallBack
--822c7ca0
--822c3f30
--822a903c
--822a8b3c
--822801d8
--824a01e8
--824A04B4
--82211d9c
--824d247c

--cHECK
--824B15F8
--824B1614

--824B15AC Stored GameSpeed

--WriteVirtualBytes("0x822435F4","4800") -- Now that Down Button Always Shown
--WriteVirtualBytes("0X8244FFA0","60000000") -- Now that Down Button Always Shown
--WriteVirtualBytes("0x82450014","60000000") -- Now that Down Button Always Shown
--WriteVirtualBytes("0X8244FFA8","60000000") -- Now that Down Button Always Shown
--WriteVirtualBytes("0x823F03D0","386000014E800020") -- Now that Down Button Always Shown

--WriteVirtualBytes("0x8244FF20","60000000")
--WriteVirtualBytes("0x8244FF3C","60000000")
--WriteVirtualBytes("0x82454434","60000000") // cHANGE iTEMS AT INSTAND=T
--WriteVirtualBytes("0X822437D0","60000000")
--WriteVirtualBytes("0X822437E4","60000000")
--WriteVirtualBytes("0X8224388C","60000000")
--WriteVirtualBytes("0X82243880 ","4800")
--WriteVirtualBytes("0x82A54AE0","386000014E800020")
--WriteVirtualBytes("0X823E8B38","386000014E800020")
--WriteVirtualBytes("0X823E88A8","386000014E800020")
--WriteVirtualBytes("0x82A54AE0","386000014E800020")
--WriteVirtualBytes("0X82241FB4","60000000")
--WriteVirtualBytes("0X82241FD0","60000000")
--WriteVirtualBytes("0x82494678","3B600001") --Make Game Think That Kinnect is Connected
--WriteVirtualBytes("0x82450310","60000000")
--WriteVirtualBytes("0x82234554","60000000")
--WriteVirtualBytes("0x822343E4","60000000")
--WriteVirtualBytes("0X82234414","60000000")
--WriteVirtualBytes("0X8223441C","60000000")
--WriteVirtualBytes("0x822343F0","4800")
--WriteVirtualBytes("0x82491C40","60000000") 
--WriteVirtualBytes("0x82491C4C","60000000") 
--WriteVirtualBytes("0x82235DC0","60000000")
--WriteVirtualBytes("0x824D0D70","386000004E800020")
--WriteVirtualBytes("0X8290F1D0","4800")
--WriteVirtualBytes("0X822334EC","60000000")
--WriteVirtualBytes("0X82233494","60000000")
--WriteVirtualBytes("0X82491B18","60000000")
--WriteVirtualBytes("0x824B2F9C","60000000")
--WriteVirtualBytes("0x822A9F58","4E800020")
--WriteVirtualBytes("0X82ACB32C","386000014E800020")
--=WriteVirtualBytes("0x822343E4","60000000")
--WriteVirtualBytes("0x822343A8","60000000")
--WriteVirtualBytes("0x82ACB3EC","010002CB020002CB7D6903A64E800420")
--WriteVirtualBytes("0x82ACB39C","010002BC020002BC7D6903A64E800420")
--WriteVirtualBytes("0x824D0D70","386000014E800020")

--WriteVirtualBytes("0x82232E1C","38C00001")
--WriteVirtualBytes("0x82232E10","38E00001")

---------
--WriteVirtualBytes("0x822E36BC","60000000")
--WriteVirtualBytes("0x822E36C0","60000000")
--WriteVirtualBytes("0x82222D28","60000000")
--WriteVirtualBytes("0x82222D24","60000000")
----------



WriteVirtualBytes("0x82222B80","4E800020")

--WriteVirtualBytes("0x82222B80","4E800020")
--WriteVirtualBytes("0x822229F8","4E800020")
--WriteVirtualBytes("0x822229A0","48000000")
WriteVirtualBytes("0x8222302C","60000000")
WriteVirtualBytes("0x82223084","60000000")
--WriteVirtualBytes("0x82222908","4E800020")
--WriteVirtualBytes("0x82213108","9BBE20B8")
--WriteVirtualBytes("0x82213144","60000000")
--WriteVirtualBytes("0X822C997C","4800")
--WriteVirtualBytes("0X822C9990","4800")

--WriteVirtualBytes("0x82232DD8","90BE7F10")
--WriteVirtualBytes("0x82233A34","60000000")
--WriteVirtualBytes("0x82233A64","60000000")
--WriteVirtualBytes("	","38800000")
--WriteVirtualBytes("0x82233A84","38600000")

--WriteVirtualBytes("0x822C7D24","60000000")
--WriteVirtualBytes("0x822C7D28","60000000")
--WriteVirtualBytes("0x822C7D4C","60000000")
--WriteVirtualBytes("0x822C90C8","3BA00000")
--WriteVirtialBytesRange("0x822C65B0","4E800020")


--Here 822E36BC (where meessage reseted to o)

--NUI::Input::Instance + (1DC0) + (num*8)
--825a56748
--88014e8

--jump (all here vectors xm)
--822C9AB4
--822339bc
--struct_a1_5 *a1
--lr 0000000082450380

--WriteVirtualBytes("0x822A9F9C","0x39600003") Teleport Or move character to same posi
--WriteVirtualBytes("0x823BAFE0","4E800020")
--WriteVirtualBytes("0x823B97A8","4E800020")
--WriteVirtualBytes("0x82291A68","4E800020")
--WriteVirtualBytes("0X8227FB48","4E800020")
--WriteVirtualBytes("0x822C9938","4E800020")
--WriteVirtualBytes("0x822CB840","4E800020")

--WriteVirtualBytes("0x822A9044","60000000")
--WriteVirtualBytes("0x8227E4E0","4E800020")
--WriteVirtualBytes("0x8227EBB0","4E800020")
--WriteVirtualBytes("0x822B8498","4E800020")

--822a9ec8 (input near)
--822a9ef4

--824b15f8 (0x28) float

--824B15F8 
--824B1614
--822C6250 (280 inpuT MOVE offset)


--822C6250
--822C6254
--1FF588A00
--240POINTER 
--822c33ec
--822c3424
--822c87d0
--1FF5889F0


--0.5,1.0

--0.5/1.0 - 1.0 > -3.5


--f1>f2:
--(f1/f2) - 1.0 > 3.5
--result = (f1/f2) - 1.0


--Cursor
--82492500

--CAMERA
--8249a038
--824B0154  

--0x7C(ik what is it)

--824325b8
--82222980
--824924ac

--sTATE jUMP CALL BACK EXAPMLE
--822C9050
--822C861C
--822C5BE8
--822A9044
--822A8B3C
--822801D8
--824A01E8
--824A04B4
--82211D9c
--824d247c

--KickDashCallBack
--822C9050
--822C861C
--822C5BE8
--822A9044
--822A8B3C
--822801D8
--824A01E8
--824A04B4
--82211D9c
--824d247c

--GrindCallBackMB
--822b1818
--822a3700
--822801d8
--824a01e8
--824a04b4
--82211d9c
--824d247c


--0x310(struct_v35) (POINTER That Crash Only Training)
--822c33ec
--822c3424
--822c87d0


----------SHEEEEEEEEEEEEET---------------
--822b1bdc
--A114A3DA
--822b1bd8

--Trick State
--822c0248
--WriteVirtualBytes("0x822BFC58","4E800020") --CamRot
--WriteVirtualBytes("0x822BB1D8","4E800020") --CamRot
--WriteVirtualBytes("0x822C09A0","4E800020") --CamRot
--WriteVirtualBytes("0x822C03D0","4E800020") --Nop Break Trick At All
--sWriteVirtualBytes("0x822C0688","4800") 

--Trick Where Rotation is set
--822B1C24 (this is also running after repeat)

--822b1EF8(mostly after repeat 
--822BEBE0(mostly after repeat 



--Cheat Engine Tradional Rotation Free 
--What Access To IT After Trick
--822b1c24
--822b1ef0
--Land
--822b9ca4
--822ba214

--General
--Two Just 
--Five More including all trick and etc


--Floats That All Nans Structure That Access
--82212c50
--82492cb4 store nan wtf
--WriteVirtualBytes("0x82492470","4E800020")
--WriteVirtualBytes("0x822C9938","4E800020")
--WriteVirtualBytes("0x822C7CA0","4E800020")


--Function that accesses 0x74 (of Hip Controller struct)
--822c87d8

--WriteVirtualBytes("0x822C03D0","4E800020")
--WriteVirtualBytes("0x822C1520","4E800020")
--WriteVirtualBytes("0x822C16D0","60000000")
--Force Trick Controll
--WriteVirtialBytesRange("0x822C165C","0x822C1680","60000000")
--WriteVirtialBytesRange("0x822C16D4","0x822C16F8","60000000")
--WriteVirtualBytes("0x822C1690","60000000")
--WriteVirtualBytes("0x822C16FC","60000000")
--WriteVirtualBytes("0x822C1724","60000000")
--WriteVirtualBytes("0x822C1730","60000000")
--WriteVirtualBytes("0x822C1738","60000000")
--WriteVirtualBytes("0x822C1740","60000000")
--RAMPS(3)
--WriteVirtualBytes("0x822C1788","FC206890") -- Fixed For One Ramp
--WriteVirtualBytes("0x822C04C0","FC206890") -- Fixed For One Ramp
--WriteVirtualBytes("0x822C06EC","FC206890") -- Fixed For Second Ramp
--WriteVirtualBytes("0x822C0870","60000000") -- Fixed For Second Ramp
--WriteVirtualBytes("0x822C0F48","60000000") -- Fixed For Second Ramp
--WriteVirtualBytes("0x822C1374","60000000") -- Fixed For Second Ramp

--WriteVirtualBytes("0x82A5463C","60000000")

--WriteVirtualBytes("0x822C178C","60000000")


--WriteVirtualBytes("0x822A9078","60000000")
--WriteVirtualBytes("0x822A9084","60000000")

--WriteVirtualBytes("0x822C0F48","60000000")
--WriteVirtualBytes("0x822C0D94","60000000")

--Grind(floatD4 Transform Corrector)
--822BD2BC(once on start)
--822bcd00 (update)

--AfterGrind(2 times)
--822b25ac

--WriteVirtualBytes("0x822BCD00","D05F00D4")
--WriteVirtualBytes("0x822BD2BC","D05F00D4")
--822760bc

--WriteVirtualBytes("0x822BC9C0","4E800020")

--?????//:82284404
--Break Jump Rump Totally
--WriteVirtualBytes("0x82284008","4E800020")

--WriteVirtualBytes("0x822701B4","FD40F890")
--WriteVirtualBytes("0x82270244","FD40F890")
--WriteVirtualBytes("0x82270078","FD40F890")

--WriteVirtualBytes("0x822BD2BC","60000000")
--WriteVirtualBytes("0x822BCD00","60000000")
	
--WriteVirtualBytes("0x822BCA50","60000000")
--WriteVirtialBytesRange("0x822BCCC8","0x822BCD50","60000000")
--WriteVirtialBytesRange("0x822BD2E0","0x822BD30C","60000000")

--MainMenu KinnectNuiBoxCallBack(0x78 P1 Input)
--824326EC
--824924ac
--82222980

--300 p1pinput
--824326e0

--WriteVirtualBytes("0x82464F30","60000000") MainMenu OK Function
--WriteVirtualBytes("0x82464F1C","60000000") -- Goto Some

--WriteVirtualBytes("0x822A5130","60000000")
--WriteVirtualBytes("0x8276F640","60000000")

--KICK DASH WITH 0x0F00000000
--82A56454(822CEB14,r8 4 call backl)

--WriteVirtualBytes("0x822CEB4C","60000000")

--WriteVirtualBytes("0x822CA570","60000000")
--WriteVirtualBytes("0x822CA584","60000000")
--WriteVirtualBytes("0x822C7CA0","4E800020")


---------------BIG FIIIIIIIIIIIIIIIIIIIIIIIIIXXXXXXXXXXXXXXXXX------------------
--WriteVirtualBytes("0x82298400","4E800020")
--WriteVirtualBytes("0x822A8AB0","4E800020") -- Original that reacts

--ARMSUP ACCESS 82A56458
--823D1D20
--8228C0FC 
--8228A174


--Others

--822a8bec
--822a8bfc
--82a56450

--Some oF THEse allow jump at rails
--WriteVirtualBytes("0x823D1B28","4E800020")
--WriteVirtualBytes("0x8228A0B8","4E800020")
--WriteVirtualBytes("0x8228BFA0","4E800020")

--WriteVirtualBytes("0x822A4370","4E800020")
--WriteVirtualBytes("0x822A4370","4E800020")
--WriteVirtualBytes("0x8228BFA0","4E800020")
--WriteVirtualBytes("0X8222AD80","39000000")
--WriteVirtualBytes("0x82477764","60000000")
--WriteVirtualBytes("0x824708A8","4E800020")
--WriteVirtualBytes("0x82299EB0","4E800020")
--WriteVirtualBytes("0x824561A0","60000000")
--WriteVirtualBytes("0x824561C0","60000000")
--WriteVirtualBytes("0X824561B4","60000000")
--WriteVirtualBytes("0X82492570","60000000")
--WriteVirtualBytes("0X8249257C","60000000")

--WriteVirtualBytes("0x82492604","60000000")
--WriteVirtualBytes("0x8249260C","60000000")

--WriteVirtualBytes("0x824926CC","60000000")
--WriteVirtualBytes("0x824926D0","60000000")

--WriteVirtualBytes("0x8249258C","60000000")
--WriteVirtualBytes("0x82494E6C","60000000")
--WriteVirtualBytes("0x8245625C","4800")
--WriteVirtualBytes("0x82455EFC","4800")
--WriteVirtualBytes("0x823F45F8","4800")
--WriteVirtualBytes("0x8245625C","4800")
--WriteVirtualBytes("0x82455F5C","60000000")
--WriteVirtualBytes("0x82455F68","60000000")
WriteVirtualBytes("0x82456B14","4800")  -- Sursor Break (i dont know here also 1558 is global input block other means cursor is not detected i guess)


--WriteVirtualBytes("0x82494E18","4E800020")
--WriteVirtualBytes("0x824560A8 ","4E800020") Get Rid of sursor

--ArmUP ACCESSES 
--822A8BEC
--822a8bfc
--82a56450

--WriteVirtualBytes("0x822A8AB0","4E800020")
--WriteVirtualBytes("0x822A8BEC","60000000")

--WriteVirtualBytes("0x822A8B3C","60000000") -- Stuck in Getset bla bla

--WriteVirtualBytes("0x822A9078","4800") -- Get Rid of slowdown O_O


--WriteVirtualBytes("0x822A4458","4E800020") 


--WriteVirtualBytes("0x822A8BF8","600000006000000060000000")
--WriteVirtualBytes("0X822A3B30","4E800020")
--WriteVirtualBytes("0x822A4EE0","4E800020")
--WriteVirtualBytes("0x822A8C10","60000000")


--HoldHands ACCESSES
--822AE850 
--8228fdd0
--82281d00
--82281e3c
--8244920c
--8229a4cc
--822a8c08
--OthersCallINObjects
--WriteVirtualBytes("0x822AE860","39200004")
--WriteVirtualBytes("0x8228FDE4","60000000") --
--WriteVirtualBytes("0x82281D28","60000000") --cam
--WriteVirtualBytes("0x82281E44","60000000") --sound
--WriteVirtualBytes("0x8244920C","39600001") 
--WriteVirtualBytes("0x822A8C10","60000000") 


--WriteVirtualBytes("0x822AE268","4E800020")
--WriteVirtualBytes("0X8227FF90","4E800020")
--WriteVirtualBytes("0X82282E78","4E800020")
--WriteVirtualBytes("0X822A8D0C","60000000")



--ArmsUPRealAccess
--82a56454
--823d0464
--8228c104
--8228a174
--WriteVirtualBytes("0x8228A0B8","4E800020")
--WriteVirtualBytes("0x823D0258","4E800020")
--WriteVirtualBytes("0x8228BFA0","4E800020")
--WriteVirtualBytes("0x822A8D0C","60000000")
--WriteVirtualBytes("0x823DB818","4800")
--WriteVirtualBytes("0x824A027C","60000000")




--WriteVirtualBytes("0x8227FF90","4E800020")
--WriteVirtualBytes("0x82ACB45C","386000024E800020")
--WriteVirtualBytes("0x82ACB24C","386001014E800020")
--WriteVirtualBytes("0x82439658","386001014E800020")
--WriteVirtualBytes("0x824D2108","4E800020")
--WriteVirtualBytes("0X824D2024","60000000")
--WriteVirtualBytes("0x824D0B80","38600002")
--WriteVirtualBytes("0x82439658","38600001")
--WriteVirtualBytes("0x823E07E4","60000000")
--WriteVirtualBytes("0x8222AEA8","38600001") -- Real (language hand)

--WriteVirtualBytes("0x8222AEE0","38A0004A") --TextFormat (45 = english,4a = JP)
--WriteVirtualBytes("0x8222AEE4","38800000") -- IsJapaneseDub
--WriteVirtualBytes("0x82A54FD0","3C603E804E800020") -- IsJapaneseDub

WriteVirtualBytes("0x8226086C","60000000") -- fix free hand timer
WriteVirtualBytes("0x8222CA38","4E800020") -- OTHER






--WriteVirtualBytes("0x822130F8","39400001") -- fix free hand timer
--WriteVirtualBytes("0X82213144","60000000") -- fix free hand timer
--WriteVirtualBytes("0X82246BC8","60000000") -- Fix Crashesh ALLLLLLLLLLLLLLLLLLLLL (STORY MODE PLAYABLE)







--WriteVirtualBytes("0x82438CC8","4E800020") -- Disable Crash Func
WriteVirtualBytes("0X82438CF4","4800") -- Disable Crash Func(alternative)






--WriteVirtualBytes("0x822130F8","39400001")


--821A4CB4 - 83E52F84

--WriteVirtualBytes("0X82246BE4","4800")
--170181D60

--Holdhands and many other 822A8BBC suppose to be 0x200 (0x822A8BCC restore)


--Rings (On Gave From ItemRing or any others)
--82280598(2)
--822a99c4(match startup)
--823ca3ac(damage)

--WriteVirtualBytes("0x8224D52C","8224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D9088224D908")
--WriteVirtualBytes("0x822E351C","822E354C822E354C822E354C822E354C822E354C822E354C822E354C822E354C")

--WriteVirtualBytes("0x822A8600","60000000")
--WriteVirtualBytes("0x822A8998","4E800020")
--WriteVirtualBytes("0x822A4458","4E800020")

------------------[Remove Calibarion]--------------------
--WriteVirtualBytes("0x822A4768","4E800020")
--WriteVirtualBytes("0x822A4770","4E800020")
------------------[------------------]--------------------



--WriteVirtualBytes("0x82246BE4","4800")
--WriteVirtualBytes("0x82212F4C","38800001")

--WriteVirtualBytes("0X82246A34","3A800003")
--WriteVirtualBytes("0x82246A2C","3B000003")

--WriteVirtualBytes("0x82299DA0","4E800020")
--WriteVirtualBytes("0x822A4800","4E800020")
--WriteVirtualBytes("0x822A49E0","4E800020")


--WriteVirtualBytes("0x82299EB0","4E800020")
--WriteVirtualBytes("0x822C5CC0","60000000") -- Fix Brake not working for normal normal boards
--WriteVirtualBytes("0x822C5CB0","60000000") -- Fix Brake not working for normal normal boards
--WriteVirtualBytes("0x82299EB0","4E800020")

--	

--WriteVirtualBytes("0x822C6AD8","4E800020")
--WriteVirtualBytes("0x822C7CA0","4E800020")
--WriteVirtualBytes("0x82256430","4E800020")
--WriteVirtualBytes("0x822963E4","60000000") --SSonic Ring Dec
--WriteVirtualBytes("0X82296348","4E800020") --Disable Super Mode
--WriteVirtualBytes("0x82296370","4800") --Disable Super Mode

--WriteVirtualBytes("0x82290C5C","822911608229116082291160822911608229116082291160822911608229116082291160822911608229116082291160822911608229116082291160822911608229116082291160")


--WriteVirtualBytes("0x8227E354","38600001")


--82295E90 Chaos Emerald Gear Constructor

--StanceDwordOntrickLand????
--822a919c
--8229a578
--82256450

--WriteVirtualBytes("0x8227E108","60000000")





--WriteVirtualBytes("0x8227E114","4800") -- Set default gear to second
--WriteVirtualBytes("0x82212E5C","60000000") -- Cutscene run

--WriteVirtualBytes("0X82222908","4E800020")
--WriteVirtualBytes("0x82289A30","4E800020") -- can stuck loading 

--WriteVirtualBytes("0x82211D94","4E800020") --ForceStuckMode

--TrainingModeFinally
--8245E710
WriteVirtualBytes("0x8227E410","38600001") -- Free From Gamepad Action ( Ready-Set-Go and Complete with be an instant and you dont have to rotate stick anymore)
--WriteVirtualBytes("0x8245E6F8","60000000") -- No Training Mode (full skip) (dont recomment use with story mode)

--WriteVirtualBytes("0X822C62E8","60000000") -- Block Move LEft Right (r3 +0x40 : -1 : 1) 

--acessers
--822a4520
--822c9328
--822c8974
--WriteVirtualBytes("0x822A4458","4E800020")
--WriteVirtualBytes("0x822C9300","4E800020")
--WriteVirtualBytes("0X822C8958","4E800020") -- All this fucking time was curve OMG


WriteVirtualBytes("0x821A2484","822C8958") -- (Replace Bike Move To Normal One)



--821A1EF0  THIS CAUSES MORE ISSUES
--Loading
--WriteVirtualBytes("0x8226D2D0","4E800020")-- 0x8226D2FC (lr = 000000008229FD94) -- Breaks Bots Controls
--WriteVirtualBytes("0X8229A650","4E800020")
--WriteVirtualBytes("0X8229FD40","4E800020")


--Training
--WriteVirtualBytes("0X8229B488","4E800020")





--WriteVirtualBytes("0x82213138","60000000")
--WriteVirtualBytes("0x8221316C","60000000")

--WriteVirtualBytes("0x822A8D0C","60000000")


--WriteVirtialBytesRange("82240B08","82240B38","60000000")


--WriteVirtualBytes("0x8226D7B0","4E800020")
--WriteVirtualBytes("0x822A0200","4E800020")

--822a8bfc
--822a8bec

--WriteVirtualBytes("0x8276FDDC","4800")
--WriteVirtualBytes("0x8276FE48","4800")
--WriteVirtualBytes("0X8276F6C8","60000000")
--WriteVirtualBytes("0x8276F6D0","60000000")
--WriteVirtualBytes("0x8276FD00","60000000")
--WriteVirtualBytes("0x8276F994","4800")
--WriteVirtualBytes("0x8276F9C0","4800")

--WriteVirtualBytes("0x82438578","4E800020") --nukll

--mostly 0x78,0x78+4 (P1,P2 KinnectMashineInputPointer)
--&KinnectNuiBox::Instance->gap74[4 * a2 + 4];
--82764750

--824325b8
--82222984
--824924ac


--WriteVirtualBytes("0x8229A6D4","60000000")
--WriteVirtualBytes("0x8229A6EC","60000000")

--WriteVirtualBytes("0x8229A650","4E800020")

-----seg_83E52F84
--vtable = 821A4CB4





--Current Crasshesh Points
------------------------0x8229FD90(R3 = 0, idk ) R31(Vtable) = 821A1EF0
----Callbacks 
--000000008227E418
--000000008227E414
--0000000082280224
--00000000824A01E8
--00000000824A04B4
--0000000082211D9C
--00000000824D247C


--0x78NUI BUT ON MissionConstructOrStartAllofitLEvels
--82461308
--8246137c









--WriteVirtualBytes("0x82A528C4","4800")
--8222A234
--WriteVirtualBytes("0X8222A234","60000000") --here


--WriteVirtualBytes("0x822250FC","60000000") -- brEAKS TEXTURES

--WriteVirtualBytes("0x8244C800","60000000") --JP SEGA
--WriteVirtualBytes("0x8244C7F8","4800") 	


--0000000082753810
--WriteVirtualBytes("0x82753718","4E800020")


--nOT nui camera


--82501384 
--WriteVirtualBytes("0x82501384","60000000")


--WriteVirtualBytes("0x82B5D2AC","00000001")

--WriteVirtualBytes("0x82908EF8","4E800020")
------------------


--WriteVirtualBytes("0x82438088","4800")


--Ring Animation End
--82477b64
--Ring Animation Start
--82479080


--Alternative Ring Vtable 82 1A 8E E0



--83E506A0 (table current selection)

WriteVirtualBytes("0X8245F0CC","60000000")

--WriteVirtualBytes("0x8245551C","60000000")

--8245dGde0
--8245C8A8
--8245DDE0



--WriteVirtualBytes("0x8245DE38","4800")
--WriteVirtualBytes("0X8245DE2C","4800")
--WriteVirtualBytes("0X8245C8BC","4800")
--WriteVirtualBytes("0x8245C7E8","4E800020")





--WriteVirtualBytes("0X8245DD80","4800")
--WriteVirtualBytes("0X8245E140","4800")
--WriteVirtualBytes("0X8245E1F8","60000000")

--WriteVirtualBytes("0X8245E1B8","3880000")


--WriteVirtualBytes("0x8245E1C0","38C00000")
--8247CC1C sOME hERE


--8245D1B0
--82454648
--8245DDE0

--83E506A4 SelectedGearTable(Also)

--WriteVirtualBytes("0X8245E434","38C00001")


--InputSomeStatic 183E52FDC ,170182770 ,1FF6A24E0

--8228B718

------------[Unlock All Gear To Select]-------------
WriteVirtualBytes("0x8247CB60","386000014E800020") --Butons
WriteVirtualBytes("0x8228B2F0","60000000") --Breaks Bike Character Only XD
----------------------------------------------------



--MoveToLeftRight(ArmsUP)
--822A5278
--822A67D0
--822A4CD4
--822A4C84

--WriteVirtualBytes("0x822A6758","4E800020")
--WriteVirtualBytes("0x822A6758","4E800020")
--WriteVirtualBytes("0x822A4BC0","4E800020")



function test(arg1)




end
--test(0)