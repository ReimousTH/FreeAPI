
function DashPanelsNowAddSpeed(Multiplier)

--------------------DASH PANELS------------
--822EFB98 Store Speed


WriteVirtualBytes("0x82600E78","4E800020") -- Void function
-- .set start,0x82600E7C
-- lfs       f0, 0x1AC(r29) # DashSpeed
-- lfs       f13, 0x77C(r31) #CurrentSpeed
-- fadd f12,f0,f13 # Current + Set
-- fdiv f12,f0,f12 # Multiplier
-- lis r11,(start+tfloat)@ha
-- lfs f0,(start+tfloat)@l(r11)
-- fmul f12,f12,f0 # Cut Multiplier
-- fmul f12,f12,f13 # M*CS
-- fadd f12,f12,f13 # M +(M*CS)
-- lfs       f0, 0x1AC(r29) 
-- fcmpu     cr6, f12, f0
-- // If (CurrentSpeed + Modifers) <= DashSpeed
-- blt cr6,sub_store
-- // If CurrentSpeed >= DashSpeed
-- bge cr6,sub_store2
-- sub_store:
-- stfs f0,0x77c(r31)
-- blr
-- sub_store2:
-- #reworkTime
-- stfs f12,0x77C(r31) # Store
-- blr
-- tfloat:.float 0.16
WriteVirtualBytes("0x822EFB98","483112E5") -- BR function
WriteVirtualBytes("0x82600E7C","C0 1D 01 AC C1 BF 07 7C FD 80 68 2A FD 80 60 24 3D 60 82 60 C0 0B 0E C0 FD 8C 00 32 FD 8C 03 72 FD 8C 68 2A C0 1D 01 AC FF 0C 00 00 41 98 00 08 40 98 00 0C D0 1F 07 7C 4E 80 00 20 D1 9F 07 7C 4E 80 00 20 3E 23 D7 0A")
WriteVirtualFloat(HEX("0x82600E7C")+HEX("0x44"),Multiplier)


end


function KickDashNowAddSpeed(Multiplier)


--------------KICK DASH SPEED LIMIT BREAK----------------
--822b2cc0(need to think)
WriteVirtualBytes("0x82601168","4E800020")
--8260116C
-- bl -(0x822B2CC0-0x8260116C)
WriteVirtualBytes("0x822B2CC0","4834E4AD")
-- .set start,0x8260116C
-- fmr f0,f1
-- lfs       f13, 0x71C(r31) #CurrentSpeed
-- fadd f12,f0,f13 # Current + Set
-- fdiv f12,f0,f12 # Multiplier
-- lis r11,(start+tfloat)@ha
-- lfs f0,(start+tfloat)@l(r11)
-- fmul f12,f12,f0 # Cut Multiplier
-- fmul f12,f12,f13 # M*CS
-- fadd f12,f12,f13 # M +(M*CS)
-- fcmpu     cr6, f12, f1
-- // If (CurrentSpeed + Modifers) <= DashSpeed
-- blt cr6,sub_store
-- // If CurrentSpeed >= DashSpeed
-- bge cr6,sub_store2
-- sub_store:
-- fmr f0,f1
-- stfs f0,0x71C(r31)
-- blr
-- sub_store2:
-- #reworkTime
-- stfs f12,0x71C(r31) # Store
-- blr
-- tfloat:.float 0.16
-- tfloatX:.float 1.0
WriteVirtualBytes("0x8260116C","FC 00 08 90 C1 BF 07 1C FD 80 68 2A FD 80 60 24 3D 60 82 60 C0 0B 11 B0 FD 8C 00 32 FD 8C 03 72 FD 8C 68 2A FF 0C 08 00 41 98 00 08 40 98 00 10 FC 00 08 90 D0 1F 07 1C 4E 80 00 20 D1 9F 07 1C 4E 80 00 20 3E 23 D7 0A")
WriteVirtualFloat(HEX("0x8260116C")+HEX("0x44"),Multiplier)
end


function SkipTrainingMoveAction(result)


--WriteVirtualBytes("0x822A8C10","60000000")
--WriteVirtualBytes("0x822B7648","39 20 00 07")

--WriteASM("0x822B7648","li r3,0x1\nli r4,0x1")
--bl

--822C3428 (STW INPUT 0x310, trainign should be)
--822C33EC
--822C7D18 (HIP seems after preap)

--822A8B3C move 
--WriteVirtualBytes("0x822C62E8","60000000")
--822A4520
--82240C14
--822C8974
--822c6944
--822c77bc
--WriteVirtualBytes("0x822C67F8","4E800020")
--WriteVirtualBytes("0x822C8958","4E800020") --block move but that does not block other

WriteVirtualBytes("0x822C3424","38C00001")


if (result) then WriteVirtualBytes("0x822B746C","39 60 00 07")    end -- Force straight to move

WriteVirtualBytes("0x82240AB8","4E800020") --Remove Calibarion UI and seems actions too

end

--Works only at story mode
function DisableTrainingMode()
if (IsXbox360())  then return end
WriteVirtualBytes("0x8245E6F8","60000000") -- No Training Mode (full skip) (dont recomment use with story mode)
end

function AlwaysShowHidedButtons()
---------------[Always Show Hided Buttons]-------------
WriteVirtualBytes("0X8245F0CC","60000000") 
-------------------------------------------------------
end

function UnlockAllGearToSelect()
------------[Unlock All Gear To Select]-------------
WriteVirtualBytes("0x8247CB60","386000014E800020") --Butons
WriteVirtualBytes("0x8228B2F0","60000000") --Breaks Bike Character Only XD
--WriteVirtualBytes("0x8245E494","60000000") -- Remove Gear ReChanger only for players
----------------------------------------------------
end

function EveryBoxGivesRandomItem()
------------Every Box Random and give Random Item always-------------
WriteVirtualBytes("0x82308294","3960000B")
WriteVirtualBytes("0x823082A0","4800")
WriteVirtualBytes("0x8230857C","60000000")
WriteVirtualBytes("0x82308528","60000000")
WriteVirtualBytes("0x823085B0","60000000")
----------------------------------------------------------------------
end


function EveryRandomBoxGivesTrueRandomItem()
------------[Every Box Give Abosulute Random Item, example]--------------
-- .set rand,0x82A54FD0
-- mflr      r12
-- stw       r12, -8(r1)
-- stwu      r1, -0x60(r1)
-- lis r11,rand@ha
-- ori r11,r11,rand@l
-- mtctr r11
-- bctrl
-- li        r11, 0x11
-- divw      r11, r3, r11
-- mulli     r11, r11, 0x11
-- subf      r11, r11, r3
-- addi      r3, r11, 5
-- addi      r1, r1, 0x60
-- lwz       r12, -8(r1)
-- mtlr      r12
-- blr
WriteVirtualBytes("0x82306F00","7D 88 02 A6 91 81 FF F8 94 21 FF A0 3D 60 82 A5 61 6B 4F D0 7D 69 03 A6 4E 80 04 21 39 60 00 11 7D 63 5B D6 1D 6B 00 11 7D 6B 18 50 38 6B 00 05 38 21 00 60 81 81 FF F8 7D 88 03 A6 4E 80 00 20")
------------------------------------------------------------------------------------
end


--enables 720P
function F720PMode()

	WriteVirtualBytes("0x82B3484C","00000500")
	WriteVirtualBytes("0x82B34850","00000000") -- suck only 0 
	WriteVirtualBytes("0X821A8BA8","00000500")
	WriteVirtualBytes("0X821A8BB8","00000500")

end



function Xenia_StuckFIX_Test_ENABLED(mode)

if (IsXbox360())  then return end
--WriteVirtualBytes("0x8244C368","4E800020") --(can fix soft locks but cause majors issues) , from far,wow it not stucking anymore o-o cool i wonder if i could fix it now
--WriteVirtualBytes("0x8244C3B8","4800") ----seems they GONE O_O (at least with protect_zero = true but for xenia it fine, and xbox 360 works fine without it)

--WriteVirtualBytes("0x8244C4A8","60000000") --THIS ONLY
--WriteVirtualBytes("0x8244C5D0","60000000") -- -
--WriteVirtualBytes("0X8244C530","60000000") --THIS ONLY

--183E53BE8
--183E53CA8
--183E53D04
--83E53CA8

--WriteVirtualBytes("0x8244C508","60000000")
--WriteVirtualBytes("0x8249AECC ","39 00 02 D0")

--WriteVirtualBytes("0x824F4858","4E800020")
--WriteVirtualBytes("0x8249AED0","38C00500")




--WriteVirtualBytes("0x82B34850","00000002")
--WriteVirtualBytes("0x8244C530","60000000")



--WriteVirtualBytes("0X82B3484C","0000050000000000")

if (mode == "FixedD3DReset") then
WriteVirtualBytes("0x824F4878","60000000") -- disable   D3DDevice_SetRingBufferParameters
WriteVirtualBytes("0x824F4888","60000000") -- disable   D3DDevice_BlockUntilIdle
WriteVirtualBytes("0x824F4880","60000000") -- bypass ==
end
if (mode == "IgnoreD3DReset") then
--
WriteVirtualBytes("0x8244C508","60000000")
end

end


function ForceJPDUB()
WriteVirtualBytes("0x8222AEE4","38800001") -- IsJapaneseDub
end

function ForceJPTEXT()
WriteVirtualBytes("0x8222AEE0","38A0004A") -- (45 = english,4a = JP)
end

--Supporte (EJGFSI)
function ForceTEXT(region)
if (region == "A") then return end
--WriteVirtualBytes("0x8222AEE0",Memory("38A00000"):OR(string.byte(region)):GetPTRHEX()) -- (45 = english,4a = JP)
end


function OFFKinectGuyICON()
WriteVirtualBytes("0x82432598","4E800020")
end

function CDisableHUD()
WriteVirtualBytes("0x823FAEC0","4E800020")
WriteVirtualBytes("0X823FB128","4E800020")
WriteVirtualBytes("0x8224A08C","60000000")	

end


function DeltaTimerFixes()

--THREE FOR DELTRA 
WriteVirtualBytes("0x824BB718","4E800020")
WriteVirtualBytes("0x824BB7C0","4E800020")
WriteVirtualBytes("0x82211E8C","60000000")
WriteVirtualBytes("0x82211E40","60000000")
WriteVirtualBytes("0x82211E10","60000000")
WriteVirtualBytes("0x824E8218","4E800020")
WriteVirtualBytes("0X824B0CF0","817F002C") --ye can breka camera ( yet neee float pls)
--824e5b98



--WriteVirtualBytes("0x82321370","4E800020") --Disable UP POOl
--WriteVirtualBytes("0x82321928","60000000") --ARMS UP TIMEr
--WriteVirtualBytes("0x82321BD8","4E800020") --HERE RORATE

--
--lfsx f12,r26,r31
--lfs f13,0X82183DC4@l(r11) # 95.0
--fcmpu cr6, f12, f13
--stfd f13,0x50(r1) 
--







--UPPOOL
WriteVirtualBytes("0x82321C88","7D9AFC2EC1AB3DC4FF0C6800D9A10050") -- lfsx f12,r26,r31
WriteVirtualBytes("0x82321C9C","C1AB3DC4") -- lfs f13,0X82183DC4@l(r11) # 95.0

WriteVirtualBytes("0x82321D1C","60000000")
WriteVirtualBytes("0x82321D2C","FD800090") -- fmr f12,f0
WriteVirtualBytes("0x82321D4C","7D1AFC2E") --lfsx f8,r26,r31
WriteVirtualBytes("0x82321D74","60000000")	
WriteVirtualBytes("0x82321D9C","7C5AFC2E")	 --lfsx f2,r26,r31

WriteVirtualBytes("0x8232207C","FDA00090") -- fmr f13,f0
	
WriteVirtualBytes("0x82322084","7D9AFC2E")	--lfsx f12,r26,r31
WriteVirtualBytes("0x82322088","FDAC682A")	--fadd f13,f12,f13
WriteVirtualBytes("0x8232208C","7DBAFD2E")	--stfsx f13,r26, r31


WriteVirtualBytes("0x8232211C","60000000")	
WriteVirtualBytes("0x8232212C","C0CB3DA0") --lfs f6,0x82183DA0@l(r11)
WriteVirtualBytes("0x82322140","7CBEFC2E") --lfsx f5,r30,r31
WriteVirtualBytes("0x82322144","FCA62828") --fsub f5,f6,f5
WriteVirtualBytes("0x82322150","FC802890") --fmr f4,f5


WriteVirtualBytes("0x82322134","3D008218")--lis r8,0x8218
--Because r8 need to load float
--lwz       r7, 8(r5)
--stw       r7, 8(r11)

WriteVirtualBytes("0x823221A8","80E5000890EB0008")
	
WriteVirtualBytes("0x823221C0","7CBEFC2E") --lfsx f5,r30,r31
WriteVirtualBytes("0x823221C4","C0C83DB8") --lfs f6,0x82183DA0@l(r8)
WriteVirtualBytes("0x823221C8","FF053000") --fcmpu cr6,f5,f6

WriteVirtualBytes("0x82322230","7CBEFC2E") --lfsx f5,r30,r31
WriteVirtualBytes("0x8232223C","FDA00090") --fmr f13,f0
WriteVirtualBytes("0x82322248","FDAD282A") --fadd f13,f13,f5
WriteVirtualBytes("0x8232224C","7DBEFD2E") --stfsx f13,r30,r31

--lis r11,0x82183F80@ha
--lfs f6,0x82183F80@l(r11)

WriteVirtualBytes("0x82322284","3D608218C0CB3F80") 
WriteVirtualBytes("0x8232228C","FF0D3000") --fcmpu cr6,f13,f6

--EXTRA
--WriteVirtualBytes("0x82322278","60000000") -- why? failed (temp disabled)

--LEFT RIGHT POLE (CRAZY)
--8231F5F8

WriteVirtualBytes("0x8231F7B4","7D6AFC2E") --     lfsx      f11, r10, r31
WriteVirtualBytes("0x8231F7C4","C1054060") --     lfs f8,0x82184060@l(r5)
WriteVirtualBytes("0x8231F7D4","FD685828") --     fsub f11,f8,f11
WriteVirtualBytes("0x8231F7F0","60000000") --     f11,
WriteVirtualBytes("0x8231F824","FD005890") --     fmr f8,f11,
WriteVirtualBytes("0x8231F830","FC804090") --     fmr f4,f8
WriteVirtualBytes("0x8231F8BC","7D6AF92E") --     stwx      r11, r10, r31
WriteVirtualBytes("0x8231F8C4","7D6AFC2E") --     lfsx      f11, r10, r31
WriteVirtualBytes("0x8231F8C8","C11C06D4") --     lfs f8,0x82197104-  0x82196A30(r28) 
WriteVirtualBytes("0x8231F8CC","FF0B4000") --     fcmpu cr6,f11,f8
WriteVirtualBytes("0x8231F8CC","FF0B4000") --     fcmpu cr6,f11,f8
WriteVirtualBytes("0x8231F8D8","C1A90028") --     lfs       f13, 0x28(r9)
WriteVirtualBytes("0x8231F8DC","60000000") --    
WriteVirtualBytes("0x8231F8E0","60000000") --    
WriteVirtualBytes("0x8231F8E8","FD6D582A") --   fadd f11,f13,f11 
WriteVirtualBytes("0x8231F8EC","7D6AFD2E") --   stfsx      f11, r10, r31

WriteVirtualBytes("0x8231F810","60000000") -- r6 (keep)
WriteVirtualBytes("0x8231F82C","C0A60028") -- lfs f5,0x28(r6)
--WriteVirtualBytes("0x8231F830","C0860028") -- lfs f4,0x28(r6)


--8240E4D0(INTERESTING)

--WriteVirtualBytes("0x8240E388","4E800020") -- For Clean Screen Used


--Play & Stop Character SFX 
--WriteVirtualBytes("0x8223075C","60000000") -- SOUND LVL PALY
--WriteVirtualBytes("0x822306F4","60000000") -- SOUND LVL PALY



--8240AD30 (Play Rank SFX END)

--RANK SFX CONTROLLER UI TOO
--WriteVirtualBytes("0x8240AB98","4E800020")
--822B38EC

--WriteVirtualBytes("0x822B3610","4E800020") --SPLINE MOVE CORRECTION (OR SOME??)

--0x822B6C28 ???? maybe this
--WriteVirtualBytes("0x822B68E8","4E800020") --Trick Perform JUMP ^^>^>^>

--822B9CB0  (LEFT RIGHT,ROTATION CONTROLLER MOVING)

--WriteVirtualBytes("0x822B9F48","4E800020")




end






--Get Rid of NUI Anyoing (XBOX 360 ONLY)
if (IsXbox360()) then 
WriteVirtualBytes("824D0D40","4E800020") --XMsgInProcessCall
WriteVirtualBytes("0x822130F0","39600001")
WriteVirtualBytes("0x8229AF6C","4800") --check once more later
WriteVirtualBytes("0x82222908","4E800020")
WriteVirtualBytes("0x82495950","60000000")
WriteVirtualBytes("0x8249595C","60000000")
end

--also this for xenia because :)
WriteVirtualBytes("0x82495950","60000000")
WriteVirtualBytes("0x8249595C","60000000")


dofile("game:\\common\\Core_INIT.lua")



--ItemNR States Table
--00000000 00000100 10001000 00100000  (Selected, ON)
--00000000 00000000 10001000 00100000  (Selected, OFF)


--00000000 00000101 10001000 10100101  (Selected, ON, CursorPlacedON

--00000000 00000001 10001000 10100101  (Selected, OFF, CursorPlacedON

--00000000 00000000 00001000 00101000  (NotSelected, OFF)


--0x4 << 16 - ON


--00008820
--00048820























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




--WriteVirtualBytes("0x82222B80","4E800020")

--WriteVirtualBytes("0x82222B80","4E800020")
--WriteVirtualBytes("0x822229F8","4E800020")
--WriteVirtualBytes("0x822229A0","48000000")
--WriteVirtualBytes("0x8222302C","60000000")
--WriteVirtualBytes("0x82223084","60000000")
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

--WriteVirtualBytes("0x82456B14","4800")  -- Sursor Break (i dont know here also 1558 is global input block other means cursor is not detected i guess) (DLL)


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
--WriteVirtualBytes("0x8222AEE4","38800001") -- IsJapaneseDub


--WriteVirtualBytes("0x82A54FD0","3C603E804E800020") -- IsJapaneseDub

--WriteVirtualBytes("0x8226086C","60000000") -- fix free hand timer (DLL)
--WriteVirtualBytes("0x8222CA38","4E800020") -- OTHER (DLL)






--WriteVirtualBytes("0x822130F8","39400001") -- fix free hand timer
--WriteVirtualBytes("0X82213144","60000000") -- fix free hand timer
--WriteVirtualBytes("0X82246BC8","60000000") -- Fix Crashesh ALLLLLLLLLLLLLLLLLLLLL (STORY MODE PLAYABLE)







--WriteVirtualBytes("0x82438CC8","4E800020") -- Disable Crash Func (DLL)
--WriteVirtualBytes("0X82438CF4","4800") -- Disable Crash Func(alternative)






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

--WriteVirtualBytes("0x822A4774","60000000")



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






--WriteVirtualBytes("0x8245DBEC","39600003") --default 3



--WriteVirtualBytes("0x8245E700","39200003") --Keeps game from soft lock(a little i guess?)
--WriteVirtualBytes("0x8245E704","60000000")

--WriteVirtualBytes("0X822C62E8","60000000") -- Block Move LEft Right (r3 +0x40 : -1 : 1) 

--acessers
--822a4520
--822c9328
--822c8974
--WriteVirtualBytes("0x822A4458","4E800020")
--WriteVirtualBytes("0x822C9300","4E800020")
--WriteVirtualBytes("0X822C8958","4E800020") -- All this fucking time was curve OMG


--WriteVirtualBytes("0x821A2484","822C8958") -- (Replace Bike Move To Normal One) (DLL SIDED NOW)



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
--8245D1B0
--82454648
--8245DDE0
--8245E434

--selected gear final
--WriteVirtualBytes("0x8245E440","60000000")

--from final

--82289ce4
--8227f7b0
--8227f7d0
--8227f7e4
--8222efc4
--8228893c
--82289ef4

--WriteVirtualBytes("0x82289CE4","39200000")
--WriteVirtualBytes("0X8227F7B0","38E00000")


--WriteVirtualBytes("0x8227F7D0","38800000")
--WriteVirtualBytes("0x8227F7F4","60000000")


--WriteVirtualBytes("0X8245E434","38C00001")


--InputSomeStatic 183E52FDC ,170182770 ,1FF6A24E0

--8228B718



--store gear part 1 8245DE50
--8245E460 load it	
--82288948
--82289CAC
--82288938





--WriteVirtualBytes("0x8245E4B4","4800")
--WriteVirtualBytes("0x8245E590","60000000")


-------------FREE RACE TAG EXP Test-------------------
--WriteVirtualBytes("0x82246BE4","600000004800")
--WriteVirtualBytes("0x82246858","3AE00002")
--WriteVirtualBytes("0x8224685C","3AA00000")
--WriteVirtualBytes("0x822C422C","60000000")
--WriteVirtualBytes("0x8245E140","60000000")
--WriteVirtualBytes("0x82246E44","39200001")
--WriteVirtualBytes("0x82246E48","39000000")


--MoveToLeftRight(ArmsUP)
--822A5278
--822A67D0
--822A4CD4
--822A4C84

--WriteVirtualBytes("0x822A6758","4E800020")
--WriteVirtualBytes("0x822A6758","4E800020")
--WriteVirtualBytes("0x822A4BC0","4E800020")

--824B2F9C TIME WRITE SOME (LR=824B2E70,822478A4 )


--WriteVirtualBytes("0x821A65F0","0000000000000000000000000000000000000000000000000000000000000000")






--CharacterRingTouch
--82328204,823282CC

--WriteVirtualBytes("0x82328288","4E800020") --Ring Collect and Distance Render


--82313950

--00000000823093A0(ITEM GET?)

--WriteVirtualBytes("0x82308038","4E800020")

--WriteVirtualBytes("0x82308528","4800")






--back to crashsesh agains
--8229FD90(+0X690 is zero) why????? (LRS = 8226d2d0,8229fd90,8229af40,822802b0,8249ef60,824dd0e0)

--WriteVirtualBytes("0x8249EF00","4E800020") -- Complete Character Break
--WriteVirtualBytes("0X82280270","4E800020") -- Complete Character Break(BUT good fps)



--WriteVirtualBytes("0x82461380","60000000")
--WriteVirtualBytes("0x82461310","60000000")


--WriteVirtualBytes("0x8244DC54","60000000")
--WriteVirtualBytes("0X8244DBCC","4800") -- (CRASH POINT = 0x82497B18)
--WriteVirtualBytes("0x8244DBD0","4800") -- (CRASH POINT = 0x82497B18)

--WriteVirtualBytes("0x8244DC90","60000000")



--WriteVirtualBytes("0x8244C368","4E800020") --(can fix soft locks but cause majors issues)



--WriteVirtualBytes("0x821A8B88","00000000")
--WriteVirtualBytes("0x821A8B8C","00000000")
--WriteVirtualBytes("0x821A8B90","00000000")
--WriteVirtualBytes("0x821A8B94","00000000")

--WriteVirtualBytes("0x821A8B98","00000000")
--WriteVirtualBytes("0x821A8B9C","00000000")
--WriteVirtualBytes("0x821A8BA0","00000000")
--WriteVirtualBytes("0x821A8BA4","00000000")



--WriteVirtualBytes("0x821A8BA8","00000500")
--WriteVirtualBytes("0x821A8BAC","000002D0")
--WriteVirtualBytes("0x821A8BB0","00000000")
--WriteVirtualBytes("0x821A8BB4","00000000")



--WriteVirtualBytes("0x821A8BB8","00000500")
--WriteVirtualBytes("0x821A8BBC","000002D0")
--WriteVirtualBytes("0x821A8BC0","3F800000")
--WriteVirtualBytes("0x821A8BC4","00000000")










--8244DBC8(some near to initiliaze title state)
--WriteVirtualBytes("0x8244C390","60000000")
--WriteVirtualBytes("0X8244C410","60000000")
--WriteVirtualBytes("0X824E96C8","4E800020") --RESO func


--82461308
--8246137C






--WriteVirtualBytes("0x824E8C70","4E800020")




--WriteVirtualBytes("0x82210788","60000000")
--WriteVirtualBytes("0x822107A4","4800")



--82764728 (ON kinncet fix button)
--82777C88

--IsAnimationPlayingAccesors
--82233c0c
--82234194
--82467fb4
--82491488


--WriteVirtualBytes("0X82233C00","4E800020")
--WriteVirtualBytes("0x82467DD0","4E800020")


--INTERESTING (A BUTTON REACT , SECOND GEAR , HOLD ) reacts at 24 of input


--8237ca38 HOLD
--822a53cc Second Gear 
--



--test(0)
