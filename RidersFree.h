#ifndef __RIDERS__FREE__
#define __RIDERS__FREE__

#include "Basics.h"

#pragma once

struct LiveU1
{
	int count;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
};


struct __declspec(align(4)) XNLive
{
	_BYTE gap0[4];
	_DWORD dword4;
	_BYTE gap8[48];
	_DWORD dword38;
	_BYTE gap3C[8];
	_XSESSION_SEARCHRESULT_HEADER *XSessionSearchResuts;
	_BYTE gap48[16];
	_DWORD dword58;
	XNQOS *XNQOS;
};






struct __declspec(align(8)) struct_a11
{

	_DWORD MainMenuState;
	_BYTE gap8[12];
	_DWORD *pdword14;
	_BYTE gap18[20];
	int *pint2C;
	int *pint30;
	_BYTE gap34[8];
	_DWORD dword3C;
	_DWORD dword40;
	_DWORD dword44;
	_BYTE gap48[16];
	_BYTE byte58;
	_BYTE gap59[347];
	_DWORD dword1B4;
	_BYTE gap1B8[1372];
	_DWORD dword714;
	_DWORD dword718;
	__declspec(align(8)) _BYTE byte720;
	_BYTE gap721[181];
	_BYTE byte7D6;
	_BYTE byte7D7;
};


struct  __declspec(align(2)) struct_GameRootStateController
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int GameRootState;
	char field_68;
	int field_69;
	int field_6D;
	int field_71;
	int field_75;
	char field_79;
	char field_7A;
	char field_7B;
	char field_7C;
	char field_7D;
	char field_7E;
	char field_7F;
	char field_80;
	char field_81;
	char field_82;
	char field_83;
	char field_84;
	char field_85;
	char field_86;
	char field_87;
	char field_88;
	char field_89;
	char field_8A;
	char field_8B;
	char field_8C;
	char field_8D;
	char field_8E;
	char field_8F;
	_DWORD dword90;
	_BYTE gap94[4];
	char char98;
	_BYTE gap99[19];
	_WORD wordAC;
};

struct struct_v51
{
	_BYTE gap0[8];
	_DWORD *pdword8;
	_DWORD dwordC;
};




struct __declspec(align(4)) XGuidMenu
{
	int *vtable0;
	_DWORD dword4;
	_DWORD dword8;
	_DWORD dwordC;
	_DWORD dword10;
	_DWORD dword14;
	_DWORD dword18;
	_DWORD dword1C;
	_DWORD dword20;
	_DWORD dword24;
	_DWORD dword28;
	_DWORD dword2C;
	float float30;
	float float34;
	_DWORD dword38;
	_DWORD dword3C;
	_DWORD dword40;
	_DWORD dword44;
	_DWORD dword48;
	_DWORD dword4C;
	_DWORD dword50;
	_DWORD dword54;
	_DWORD dword58;
	_DWORD dword5C;
	_DWORD dword60;
	_DWORD dword64;
	_DWORD dword68;
	_BYTE gap6C[4];
	_DWORD vtable1Camera;
	_BYTE gap74[12];
	_DWORD dword80;
	_BYTE gap84[412];
	float float220;
	float float224;
	float float228;
	float float22C;
	float float230;
	float float234;
	float float238;
	float float23C;
	_DWORD dword240;
	_DWORD dword244;
	_DWORD dword248;
	_DWORD dword24C;
	_BYTE gap250[4];
	float float254;
	float float258;
	float float25C;
	_DWORD dword260;
	_BYTE gap264[220];
	_DWORD dword340;
	_DWORD dword344;
	_DWORD dword348;
	_BYTE gap34C[260];
	float float450;
	float float454;
	float float458;
	float float45C;
	float float460;
	_DWORD dword464;
	_DWORD dword468;
	float float46C;
	_DWORD dword470;
	_DWORD State;
	_DWORD dword478;
	float float47C;
	_BYTE gap480[8];
	_DWORD dword488;
	_BYTE gap48C[8];
	float float494;
	_BYTE gap498[4];
	float float49C;
	_BYTE byte4A0;
};


struct struc_field10
{
	int field_0;
	int flag0x4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
};


struct struc_C94U
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	struc_field10 *field_10;
	int field_14;
	int field_18;
	int field_1C;
};



struct __declspec(align(4)) struct_pfloat690
{
	float float0;
	int gap4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	char field_60[3044];
	float floatC44;
	float float_C48;
	int field_C4C;
	int field_C50;
	int field_C54;
	int field_C58;
	int field_C5C;
	int field_C60;
	int field_C64;
	int field_C68;
	int field_C6C;
	int field_C70;
	int field_C74;
	int field_C78;
	int field_C7C;
	int field_C80;
	int field_C84;
	int field_C88;
	int field_C8C;
	int field_C90;
	struc_C94U *field_C94;
};


struct __declspec(align(8)) struct_v1
{
	float float0;
	int gap4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int ChrModelPositionRelativeX;
	int ChrModelPositionRelativeY;
	int ChrModelPositionRelativeZ;
	int field_7C;
	_BYTE gap80[16];
	float float90;
	float float94;
	float float98;
	float float9C;
	_BYTE gapA0[32];
	float PositionX;
	float PositionY;
	float PositionZ;
	float floatCC;
	_BYTE gapD0[4];
	float floatD4;
	_BYTE gapD8[8];
	_QWORD qwordE0;
	_QWORD qwordE8;
	float floatF0;
	float floatF4;
	float floatF8;
	float floatFC;
	float float100;
	float float104;
	float float108;
	_BYTE gap10C[4];
	XMVECTOR qword110;
	_BYTE gap120[16];
	float float130;
	float float134;
	float float138;
	float float13C;
	float float140;
	float float144;
	float float148;
	float float14C;
	_BYTE gap150[48];
	float float180;
	float float184;
	float float188;
	_BYTE gap18C[4];
	_QWORD qword190;
	_QWORD qword198;
	_BYTE gap1A0[48];
	float float_1D0;
	float field_1D4;
	float float_1D8;
	float float1DC;
	float ForceVector1E0[4];
	_BYTE gap1F0[16];
	float struct_v1_200;
	_BYTE gap204[12];
	_QWORD qword210;
	_QWORD qword218;
	_BYTE gap220[224];
	_QWORD qword300;
	_QWORD qword308;
	int gap310;
	int field_314;
	int field_318;
	int field_31C;
	int field_320;
	int field_324;
	int field_328;
	int field_32C;
	int field_330;
	int field_334;
	int field_338;
	int field_33C;
	int field_340;
	int field_344;
	int field_348;
	int field_34C;
	int field_350;
	int field_354;
	int field_358;
	int field_35C;
	int field_360;
	int field_364;
	int field_368;
	int field_36C;
	int field_370;
	int field_374;
	int field_378;
	int field_37C;
	int field_380;
	int field_384;
	int field_388;
	int field_38C;
	int field_390;
	int field_394;
	int field_398;
	int field_39C;
	int field_3A0;
	int field_3A4;
	int field_3A8;
	int field_3AC;
	int field_3B0;
	int field_3B4;
	int field_3B8;
	int field_3BC;
	int field_3C0;
	int field_3C4;
	int field_3C8;
	int field_3CC;
	int field_3D0;
	int field_3D4;
	int field_3D8;
	int field_3DC;
	int field_3E0;
	int field_3E4;
	int field_3E8;
	int field_3EC;
	float field_3F0;
	int field_3F4;
	int field_3F8;
	int field_3FC;
	int field_400;
	int field_404;
	int field_408;
	int field_40C;
	float field_410;
	int field_414;
	int field_418;
	int field_41C;
	int field_420;
	int field_424;
	int field_428;
	int field_42C;
	float field_430;
	int field_434;
	int field_438;
	int field_43C;
	int field_440;
	int field_444;
	int field_448;
	int field_44C;
	__int16 field_450;
	unsigned __int16 unsigned452;
	_BYTE gap454[28];
	_QWORD qword470;
	_QWORD qword478;
	_BYTE gap480[16];
	float qword490;
	float field_494;
	float qword498;
	__declspec(align(8)) _BYTE gap4A0[40];
	_QWORD qword4C8;
	float float4D0;
	float float4D4;
	float float4D8;
	float float4DC;
	_BYTE gap4E0[32];
	_WORD word500;
	_BYTE gap502[2];
	unsigned __int16 unsigned504;
	unsigned __int16 unsigned506;
	unsigned __int16 unsigned508;
	unsigned __int16 unsigned50A;
	_BYTE gap50C[4];
	float float510;
	_BYTE gap514[4];
	_QWORD qword518;
	int gap520;
	int field_524;
	int field_528;
	int field_52C;
	int field_530;
	int field_534;
	int field_538;
	int field_53C;
	int field_540;
	int field_544;
	int field_548;
	int field_54C;
	int field_550;
	int field_554;
	int field_558;
	int field_55C;
	int field_560;
	int field_564;
	int field_568;
	int field_56C;
	int field_570;
	int field_574;
	int field_578;
	int field_57C;
	int field_580;
	int field_584;
	int field_588;
	int field_58C;
	int field_590;
	int field_594;
	int field_598;
	int field_59C;
	int field_5A0;
	int field_5A4;
	int field_5A8;
	int field_5AC;
	int field_5B0;
	int field_5B4;
	int field_5B8;
	int field_5BC;
	int field_5C0;
	int field_5C4;
	int field_5C8;
	int field_5CC;
	int field_5D0;
	int field_5D4;
	int field_5D8;
	int field_5DC;
	int field_5E0;
	int field_5E4;
	int field_5E8;
	int field_5EC;
	int field_5F0;
	int field_5F4;
	int field_5F8;
	int field_5FC;
	int field_600;
	int field_604;
	int field_608;
	int field_60C;
	int field_610;
	int field_614;
	int field_618;
	int field_61C;
	int field_620;
	int field_624;
	int field_628;
	int field_62C;
	int field_630;
	int field_634;
	int field_638;
	int field_63C;
	__int16 int16640;
	_BYTE gap642;
	unsigned __int8 unsigned643;
	_BYTE byte644;
	_BYTE byte645;
	_BYTE byte646;
	_BYTE gap647[4];
	_BYTE byte64B;
	_BYTE byte64C;
	_BYTE gap64D;
	_BYTE byte64E;
	_BYTE gap64F[65];
	struct_pfloat690 *pfloat690;
	_BYTE gap694[4];
	_DWORD dword698;
	_BYTE gap69C[48];
	_DWORD dword6CC;
	_DWORD dword6D0;
	_DWORD dword6D4;
	_BYTE gap6D8[56];
	float ConstantZForce;
	int PreZForceBuggy;
	int field_718;
	float ForceZ;
	int gap720;
	float field_724;
	int field_728;
	int field_72C;
	int CurrentSpeed1;
	int CurrentSpeed2;
	float float738;
	_BYTE gap73C[12];
	float float748;
	int gap74C;
	int field_750;
	int field_754;
	int field_758;
	int field_75C;
	int field_760;
	int field_764;
	int field_768;
	int field_76C;
	int field_770;
	int field_774;
	int field_778;
	int field_77C;
	int RotationZ;
	int RotationY;
	int RotationX;
	int field_78C;
	int field_790;
	int field_794;
	int field_798;
	int field_79C;
	int field_7A0;
	int field_7A4;
	int field_7A8;
	int field_7AC;
	int field_7B0;
	int field_7B4;
	int field_7B8;
	int field_7BC;
	int field_7C0;
	int field_7C4;
	int field_7C8;
	int field_7CC;
	int field_7D0;
	int field_7D4;
	int field_7D8;
	int field_7DC;
	int field_7E0;
	int field_7E4;
	int field_7E8;
	int field_7EC;
	int field_7F0;
	int field_7F4;
	int field_7F8;
	int field_7FC;
	int field_800;
	int field_804;
	int field_808;
	int field_80C;
	int field_810;
	int field_814;
	int field_818;
	int field_81C;
	int field_820;
	int field_824;
	int field_828;
	int field_82C;
	int field_830;
	int field_834;
	_DWORD dword838;
	_DWORD dword83C;
	_DWORD dword840;
	int gap844;
	_DWORD dword848;
	_DWORD dword84C;
	_DWORD dword850;
	_DWORD dword854;
	int gap858;
	int field_85C;
	int field_860;
	int field_864;
	int field_868;
	int field_86C;
	int field_870;
	unsigned __int16 unsigned874;
	_WORD word876;
	_WORD word878;
	unsigned __int16 unsigned87A;
	_DWORD dword87C;
	int gap880;
	int field_884;
	int field_888;
	int field_88C;
	int field_890;
	int field_894;
	int field_898;
	int field_89C;
	int field_8A0;
	int field_8A4;
	int field_8A8;
	int field_8AC;
	int field_8B0;
	int field_8B4;
	int field_8B8;
	int field_8BC;
	int field_8C0;
	int field_8C4;
	int field_8C8;
	int field_8CC;
	int field_8D0;
	int field_8D4;
	int field_8D8;
	int field_8DC;
	int field_8E0;
	int field_8E4;
	int field_8E8;
	int field_8EC;
	int field_8F0;
	int field_8F4;
	int field_8F8;
	int field_8FC;
	int field_900;
	int field_904;
	int field_908;
	int field_90C;
	int field_910;
	int field_914;
	int field_918;
	_DWORD dword91C;
	int gap920;
	float float924;
	int gap928;
	int field_92C;
	int field_930;
	_DWORD dword934;
	float float938;
	_DWORD dword93C;
	int gap940;
	int field_944;
	_DWORD ChrState;
	int gap94C;
	int field_950;
	_DWORD dword954;
	_DWORD dword958;
	int gap95C;
	int field_960;
	int field_964;
	int field_968;
	int field_96C;
	int field_970;
	int field_974;
	int field_978;
	int field_97C;
	int field_980;
	int field_984;
	int field_988;
	int field_98C;
	int field_990;
	int field_994;
	int field_998;
	int field_99C;
	int field_9A0;
	int field_9A4;
	int field_9A8;
	int field_9AC;
	int field_9B0;
	int field_9B4;
	int field_9B8;
	int field_9BC;
	int field_9C0;
	int field_9C4;
	int field_9C8;
	int field_9CC;
	int field_9D0;
	int field_9D4;
	int field_9D8;
	int field_9DC;
	int field_9E0;
	int field_9E4;
	int field_9E8;
	int field_9EC;
	int field_9F0;
	int field_9F4;
	int field_9F8;
	int field_9FC;
	int field_A00;
	int field_A04;
	int field_A08;
	int field_A0C;
	int field_A10;
	int field_A14;
	int field_A18;
	int field_A1C;
	int field_A20;
	int field_A24;
	int field_A28;
	int field_A2C;
	int field_A30;
	int field_A34;
	int field_A38;
	int field_A3C;
	int field_A40;
	int field_A44;
	int field_A48;
	int field_A4C;
	__int16 field_A50;
	_BYTE byteA52;
};



struct  struct_dword300
{
	int gap0; //0 
	_DWORD dwTrackingID; //4
	_DWORD ConnectionStatus; //8	
	//Index(Icon Color,Human) 
	//17C Cursor(int32) (2)
	//17C + 0x20 , +0x24 able to move cursor but only with pause maybe requres additional value also RightStuckUP Currently Able to reset position
	_BYTE gapex[4000]; //C
	
};


struct  struct_v35
{

//	XMVECTOR field_0;
	float field_0;
	float field_4;
	float field_8;
	float field_C;
	float field_10;
	float field_14; // UP Corrector
	float field_18; // UP
	float field_1C;
	float field_20;
	float field_24;
	float field_28;
	float field_2C;
	float field_30;
	float field_34;
	float field_38;
	float field_3C;
	float field_40;
	float field_44;
	float field_48;
	float field_4C;
	float field_50;
	float field_54;
	float field_58;
	float field_5C;
	float field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	float field_84;
	float field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	float field_B0;
	float field_B4;
	float field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	int field_D4;
	int field_D8;
	int field_DC;
	int field_E0;
	int field_E4;
	int field_E8;
	int field_EC;
	int field_F0;
	int field_F4;
	int field_F8;
	int field_FC;
	int field_100;
	int field_104;
	int field_108;
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int field_128;
	int field_12C;
	int field_130;
	int field_134;
	int field_138;
	int field_13C;
	int field_140;
	int field_144;
	int field_148;
	int field_14C;
	int field_150;
	int field_154;
	int field_158;
	int field_15C;
	int field_160;
	int field_164;
	float field_168;
	int field_16C;
	int field_170;
	int field_174;
	int field_178;
	int field_17C;
	int field_180;
	int field_184;
	int field_188;
	int field_18C;
	int field_190;
	int field_194;
	int field_198;
	int field_19C;
	int field_1A0;
	int field_1A4;
	int field_1A8;
	int field_1AC;
	int field_1B0;
	int field_1B4;
	int field_1B8;
	int field_1BC;
	int field_1C0;
	int field_1C4;
	int field_1C8;
	int field_1CC;
	int field_1D0;
	int field_1D4;
	int field_1D8;
	int field_1DC;
	int field_1E0;
	int field_1E4;
	int field_1E8;
	int field_1EC;
	int field_1F0;
	int field_1F4;
	int field_1F8;
	int field_1FC;
	int field_200;
	int field_204;
	int field_208;
	int field_20C;
	int field_210;
	int field_214;
	int field_218;
	int field_21C;
	int field_220;
	int field_224;
	int field_228;
	int field_22C;
	int field_230;
	int field_234;
	int field_238;
	float field_23C;
	float field_240;
	float field_244;
	float field_248;
	int field_24C;
	int field_250;
	int field_254;
	int field_258;
	int field_25C;
	int field_260;
	int field_264;
	int field_268;
	int field_26C;
	int field_270;
	int field_274;
	int field_278;
	int field_27C;
	float field_280;
	float field_284;
	int field_288;
	int field_28C;
	int field_290;
	int field_294;
	int field_298;
	int field_29C;
	int field_2A0;
	int field_2A4;
	int field_2A8;
	int field_2AC;
	int field_2B0;
	int field_2B4;
	int field_2B8;
	int field_2BC;
	int field_2C0;
	int field_2C4;
	int field_2C8;
	int field_2CC;
	int field_2D0;
	int field_2D4;
	int field_2D8;
	int field_2DC;
	int field_2E0;
	int field_2E4;
	int field_2E8;
	int field_2EC;
	int field_2F0;
	int field_2F4;
	int field_2F8;
	int field_2FC;
	struct_dword300 *dword300;
	float field_304;
	int field_308;
	int field_30C;
	int dword310;
	_BYTE gapex[4000];//
};

struct  struct_a1_6
{
	char vtable;
	_BYTE gap1[15];
	_DWORD dword10;
	_DWORD dword14;
	_DWORD dword18;
	_DWORD dword1C;
	_DWORD dword20;
	_DWORD dword24;
	_DWORD dword28;
	_BYTE gap2C[4];
	_BYTE byte30;
	_BYTE byte31;
	_BYTE byte32;
	__declspec(align(2)) _DWORD dword34;
	_BYTE gap38[4];
	_BYTE byte3C;
	_BYTE byte3D;
	_BYTE byte3E;
	__declspec(align(2)) _DWORD dword40;
	_BYTE gap44[4];
	_BYTE byte48;
	_BYTE byte49;
	_BYTE byte4A;
	__declspec(align(2)) _DWORD dword4C;
	_BYTE gap50[4];
	_BYTE byte54;
	_BYTE byte55;
	_BYTE byte56;
	__declspec(align(2)) _DWORD dword58;
	_BYTE gap5C[4];
	_BYTE byte60;
	_BYTE byte61;
	_BYTE byte62;
	__declspec(align(2)) _DWORD dword64;
	_BYTE gap68[4];
	_BYTE byte6C;
	_BYTE byte6D;
	_BYTE byte6E;
	__declspec(align(2)) _DWORD dword70;
	_BYTE gap74[4];
	struct_v35 *dword78;
	struct_v35* dword7C;
	float dword80;
	_DWORD dword84;
	_DWORD dword88;
	_DWORD dword8C;
	_DWORD dword90;
	_DWORD dword94;
	_BYTE gap98[8];
	float floatA0;
	float floatA4;
	_DWORD dwordA8;
	_DWORD dwordAC;
	_DWORD dwordB0;
	_DWORD dwordB4;
	_DWORD dwordB8;
	float floatBC;
	float floatC0;
	_BYTE byteC4;
	_BYTE byteC5;
};




struct  struct_a1_4
{
	_BYTE gap0[4];
	float GameSpeed;
	int gap8;
	float MaxFpsFloat;
	float MaxFixedFps;
	float CameraSpeed;
	float gap18;
	_DWORD TicksLimit;
	float float20;
	float float24;
	float SpeedSome;
	float float2C;
	float float30;
	float float34;
	int gap38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	char FpsMaxInt;
	char field_59;
	char field_5A;
	_BYTE byte5B;
	_BYTE byte5C;
};

struct struct_field_1C
{
	_BYTE gap0[112];
	_DWORD dword70;
};
struct struct_field_34
{
	_BYTE gap0[192];
	_BYTE byteC0;
};

typedef struct clsOOSystemHeap;

struct /*VFT*/ clsOOSystemHeap_vtbl
{
	int (__fastcall *field_0)(clsOOSystemHeap *);
	int (__fastcall *field_4)(clsOOSystemHeap *);
	int (__fastcall *field_8)(clsOOSystemHeap *);
	int (__fastcall *field_C)(clsOOSystemHeap *);
	int (__fastcall *AllocMem)(clsOOSystemHeap *, int, int);
};



struct clsOOSystemHeap
{
	clsOOSystemHeap_vtbl *__vftable /*VFT*/;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
};

typedef struct clsOOTimer;
struct /*VFT*/ clsOOTimer_vtbl
{
	int (__fastcall *DestroyObject)(clsOOTimer *, uint);
	int (__fastcall *GetDeltaTime)(clsOOTimer *);
	int (__fastcall *GetDeltaTime2)(clsOOTimer *);
};


struct clsOOTimer
{
	clsOOTimer_vtbl *__vftable /*VFT*/;
	int TickCount;
	int field_8;
	int StartDeltaTime;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
};


typedef struct clsXbox360Timer;
struct /*VFT*/ clsXbox360Timer_vtbl
{
	int (__fastcall *DestroyObject)(clsXbox360Timer *, uint);
	int (__fastcall *GetDeltaTime)(clsXbox360Timer *);
	int (__fastcall *GetDeltaTime2)(clsXbox360Timer *);
};



struct __declspec(align(4)) clsXbox360Timer : clsOOTimer
{
	float field_2C;
	double TimerValue;
};



typedef struct clsXbox360System;

struct /*VFT*/ clsXbox360System_vtbl
{
	int (__fastcall *DestroyObject)(clsXbox360System *, uint);
	char (__fastcall *GetFlag5A)(clsXbox360System *);
};



struct clsXbox360System
{
	clsXbox360System_vtbl *__vftable /*VFT*/;
	float GameSpeed;
	int field_8;
	float RawFPS;
	float field_10;
	float CameraSpeed;
	float field_18;
	int TickPerSecond;
	float field_20;
	float field_24;
	float GameDelta;
	float field_2C;
	float field_30;
	float field_34;
	int field_38;
	int field_3C;
	float field_40;
	int field_44;
	float field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
};


typedef struct CamP0x1F0;
typedef struct clsXbox360Camera;

struct __declspec(align(4)) CamP0x1F0_vtbl
{
	int func0;
	void (__fastcall *func4)(CamP0x1F0 *thiss, int, int, int);
	int func8;
	void *(__fastcall *funcC)(CamP0x1F0 *thiss);
	void (__fastcall *func10)(CamP0x1F0 *);
	int func14;
	int func18;
};


struct CamP0x1F0
{
	CamP0x1F0_vtbl *__vftable /*VFT*/;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	clsXbox360Camera *Camera1;
	clsXbox360Camera *Camera2;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;
	int field_B4;
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	int field_D4;
	int field_D8;
	int field_DC;
	int field_E0;
	int field_E4;
	int field_E8;
	int field_EC;
	int field_F0;
	int field_F4;
	int field_F8;
	int field_FC;
	int field_100;
	int field_104;
	int field_108;
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int field_128;
	int field_12C;
	int field_130;
	int field_134;
	int field_138;
	int field_13C;
	int field_140;
	int field_144;
	int field_148;
	int field_14C;
	int field_150;
	int field_154;
	int field_158;
	int field_15C;
	int field_160;
	int field_164;
	int field_168;
	int field_16C;
	int field_170;
	int field_174;
	int field_178;
	int field_17C;
	int field_180;
	int field_184;
	int field_188;
	int field_18C;
	int field_190;
	int field_194;
	int field_198;
	int field_19C;
	int field_1A0;
	int field_1A4;
	int field_1A8;
	int field_1AC;
	int field_1B0;
	int field_1B4;
	int field_1B8;
	int field_1BC;
	int field_1C0;
	int field_1C4;
	int field_1C8;
	int field_1CC;
	int field_1D0;
	int field_1D4;
	int field_1D8;
	int field_1DC;
	int field_1E0;
	int field_1E4;
	int field_1E8;
	int field_1EC;
	int field_1F0;
	int field_1F4;
	int field_1F8;
	int field_1FC;
	int field_200;
	int field_204;
	int field_208;
	int field_20C;
	int field_210;
	int field_214;
	int field_218;
	int field_21C;
	float float_220;
	int field_224;
	int field_228;
};

typedef struct clsXbox360Camera;

struct /*VFT*/ __declspec(align(4)) clsXbox360Camera_vtbl
{
	int (__fastcall *pfunc0)(clsXbox360Camera *_this);
	int (__fastcall *pfunc4)(clsXbox360Camera *_this);
	int (__fastcall *pfunc8)(clsXbox360Camera *_this);
	int (__fastcall *pfuncC)(clsXbox360Camera *_this);
	int (__fastcall *pfunc10)(clsXbox360Camera *_this, float);
	CamP0x1F0 *(__fastcall *pfunc14)(clsXbox360Camera *_this);
	CamP0x1F0 *(__fastcall *pfunc18)(clsXbox360Camera *_this);
	void *(__fastcall *pfunc1c)(clsXbox360Camera *_this);
	CamP0x1F0 *(__fastcall *pfunc20)(clsXbox360Camera *_this);
	void *(__fastcall *pfunc24)(clsXbox360Camera *_this);
	void *(__fastcall *pfunc28)(clsXbox360Camera *_this);
};



struct __declspec(align(4)) clsXbox360Camera
{
	clsXbox360Camera_vtbl *__vftable /*VFT*/;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	float field_20;
	float field_24;
	float field_28;
	int field_2C;
	float field_30;
	float field_34;
	float field_38;
	int field_3C;
	float field_40;
	float field_44;
	float field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	_BYTE gap98[264];
	_DWORD dword1A0;
	_BYTE gap1A4[12];
	float float1B0;
	float float1B4;
	float float1B8;
	float float1BC;
	float float1C0;
	float float1C4;
	float float1C8;
	float float1CC;
	_DWORD dword1D0;
	_DWORD dword1D4;
	_DWORD dword1D8;
	_DWORD dword1DC;
	float float1E0;
	float float1E4;
	float float1E8;
	float float1EC;
	CamP0x1F0 *PathCameraSettings;
	int field_1F4;
	int field_1F8;
	int field_1FC;
	int *field_200;
	int field_204;
	int field_208;
	int field_20C;
	int field_210;
	int field_214;
	int field_218;
	int field_21C;
	int field_220;
	int field_224;
	int field_228;
	int field_22C;
	_BYTE gap230[128];
	float float2B0;
	float float2B4;
	float float2B8;
	float float2BC;
	_DWORD dword2C0;
};


struct mki0x74
{
	int field_0;
	int field_4;
	clsXbox360Camera **PlayerXbox360CameraArray;
	int field_C;
};



struct __declspec(align(4)) struct_MBKinnectInput
{
	clsOOSystemHeap *clsOOSystemHeap;
	_BYTE gap4[20];
	clsXbox360System *PclsXbox360System;
	struct_field_1C *field_1C;
	int field_20;
	int field_24;
	int field_28;
	clsXbox360Timer *Xbox360Timer;
	int field_30;
	struct_field_34 *field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	mki0x74 *PlayerData;
	int field_78;
};



typedef struct struct_dword0 struct_dword0;
typedef struct struct_pdword0 struct_pdword0;

struct  struct_dword0
{
	_BYTE gap0[4];

	struct_v35 *(__fastcall *pfunc4)(struct_pdword0 *);
};


struct  struct_pdword0
{
	struct_dword0 *dword0;
	_BYTE gap4[12];
	_DWORD dword10;
};




struct __declspec(align(4)) struct_HipController
{
	float float0;
	float float4;
	float float8;
	float floatC;
	float float10;
	float float14;
	float float18;
	float float1C;
	float float20;
	float float24;
	float float28;
	float float2C;
	float float30;
	float float34;
	float float38;
	float float3C;
	float float40;
	float float44;
	float float48;
	float float4C;
	int gap50;
	int field_54;
	int field_58;
	int field_5C;
	float LeftMoveHowMuch;
	float RightMoveHowMuch;
	float LeftMoveHowMuchSecond;
	float RightMoveHowMuchSecond;
	_DWORD dword70;
	_DWORD JumpCrouchFloat;
	_DWORD dword78;
	_BYTE gap7C[8];
	float float84;
};


struct struct_field_60
{
	_BYTE gap0[20];
	_DWORD dword14;
};


struct __declspec(align(4)) struct_field_64
{
	_BYTE gap0[20];
	_DWORD dword14;
};


struct  StateA2P
{
	struct_pdword0 *pdword0;
	_BYTE gap4[88];
	struct_HipController *HipController;
	struct_field_60* field_60;
	struct_field_64* field_64;
	int field_68;
};


struct __declspec(align(4)) struct_dword11C
{
	_BYTE gap0[320];
	_DWORD dword140;
	_BYTE gap144[12];
	_DWORD GameMainMessagesOrSome;
};



struct __declspec(align(4)) struct_a2
{
	_BYTE gap0[284];
	struct_dword11C *dword11C;
	_DWORD dword120;
	_BYTE gap124[16];
	_DWORD dword134;
	_DWORD dword138;
	_DWORD dword13C;
	_BYTE gap140[176];
	_BYTE byte1F0;
	_BYTE gap1F1[59];
	_DWORD dword22C;
};

struct struct_UIRingController;

struct ItemNRElementSub01
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int (__fastcall *ResultMethod)(char *);
	float SomeTime;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
};





#define IsUnk1 0x80000 //Type,Active,Status??? Move Back button to middle and disables it
#define IsUNK2 0x4000
#define IsUNK3 0x2000
#define IsUNK4 0x800
#define NR_IsButtonPressed 0x200
#define IsUNK6 0x8


struct __declspec(align(8)) ItemNRElement
{
	int vft;
	int ItemNRBaseFlag1;
	int ItemNRBaseFlag2;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	float float40;
	float float44;
	float float48;
	int field_4C;
	float float50;
	float float54;
	float float58;
	_DWORD dword5C;
	float float60;
	float float64;
	float float68;
	float float6C;
	float float70;
	_DWORD dword74;
	float float78;
	float float7C;
	float float80;
	float float84;
	float float88;
	_DWORD dword8C;
	float float90;
	float float94;
	float float98;
	float float9C;
	float floatA0;
	_DWORD dwordA4;
	float floatA8;
	float floatAC;
	float floatB0;
	float floatB4;
	float floatB8;
	_DWORD dwordBC;
	float floatC0;
	float floatC4;
	float floatC8;
	float floatCC;
	float floatD0;
	_DWORD dwordD4;
	float floatD8;
	float floatDC;
	float floatE0;
	float floatE4;
	float floatE8;
	_DWORD dwordEC;
	float floatF0;
	float floatF4;
	float floatF8;
	float floatFC;
	float float100;
	_DWORD dword104;
	float float108;
	float float10C;
	int gap110;
	int field_114;
	int ParentOrMainMenuNRInstance;
	struct_UIRingController *ParentUIRingController;
	_DWORD ButtonIconID;
	int gap124;
	int UnkOnOffFlag;
	int field_12C;
	int field_130;
	int ItemState;
	int ItemFlag;
	int field_13C;
	int field_140;
	XMVECTOR* SursorVectorPTR;
	int UnkSelectedIndexFlag;
	int field_14C;
	int field_150;
	int field_154;
	int UnKItemFlag1;
	int field_15C;
	int field_160;
	int field_164;
	int field_168;
	__int16 field_16C;
	__int16 field_16E;
	float float170;
	float float174;
	float float178;
	_DWORD dword17C;
	float float180;
	float float184;
	float float188;
	_DWORD dword18C;
	float float190;
	float float194;
	float float198;
	float float19C;
	float float1A0;
	float float1A4;
	float float1A8;
	float float1AC;
	float float1B0;
	float float1B4;
	float float1B8;
	float float1BC;
	int SelectedUnkFlag;
	float float1C4;
	float float1C8;
	float float1CC;
	float float1D0;
	int gap1D4;
	int field_1D8;
	int field_1DC;
	int field_1E0;
	int field_1E4;
	ItemNRElementSub01 SubStruct;
	int field_224;
	float TargetTimeDelta;
	int ItemIndexPos;
};



struct  struct_UIRingController
{
	_DWORD vtable;
	int gap4;
	int field_8;
	int UnkTag;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	_BYTE gap38[24];
	float float50;
	float float54;
	float float58;
	float float5C;
	float float60;
	float float64;
	float float68;
	float float6C;
	float float70;
	float float74;
	float float78;
	float float7C;
	float float80;
	float float84;
	float float88;
	float float8C;
	float float90;
	float float94;
	float float98;
	float float9C;
	float floatA0;
	float floatA4;
	float floatA8;
	float floatAC;
	float floatB0;
	float floatB4;
	float floatB8;
	float floatBC;
	float floatC0;
	float floatC4;
	float floatC8;
	float floatCC;
	float floatD0;
	float floatD4;
	_DWORD dwordD8;
	float floatDC;
	float floatE0;
	float floatE4;
	float floatE8;
	float floatEC;
	_DWORD dwordF0;
	float floatF4;
	float floatF8;
	float floatFC;
	float float100;
	float float104;
	_DWORD dword108;
	float float10C;
	float float110;
	float float114;
	float float118;
	float float11C;
	_DWORD dword120;
	float float124;
	float float128;
	_DWORD dword12C;
	_DWORD dword130;
	_DWORD dword134;
	int gap138;
	_DWORD dword13C;
	_DWORD Flag0x140;
	_DWORD dword144;
	_DWORD Tag01;
	_DWORD Tag02;
	_DWORD Tag1;
	_DWORD Tag2;
	_DWORD Tag3;
	_DWORD Tag4;
	int Tag5;
	int SpecialTag1;
	int field_168;
	int field_16C;
	int field_170;
	int field_174;
	int field_178;
	_BYTE gap17C[14];
	char field_18A;
	char field_18B;
	char field_18C;
	char field_18D;
	char field_18E;
	char field_18F;
	char field_190;
	char field_191;
	char field_192;
	char field_193;
	float float194;
	float float198;
	float float19C;
	float float1A0;
	_DWORD dword1A4;
	_DWORD dword1A8;
	_DWORD MoveDirectionAHowMuch;
	float float1B0;
	float float1B4;
	float float1B8;
	float float1BC;
	_DWORD dword1C0;
	_DWORD dword1C4;
	_DWORD dword1C8;
	_BYTE gap1CC[4];
	_DWORD dword1D0;
	_DWORD dword1D4;
	_DWORD dword1D8;
	_BYTE gap1DC[4];
	_DWORD dword1E0;
	_DWORD dword1E4;
	_DWORD UIRingInfoBox;
};

struct __declspec(align(4)) struct_dword2C
{
	_BYTE gap0[4];
	_DWORD TickCount;
};


struct __declspec(align(4)) struct_v2
{
	_BYTE gap0[44];
	struct_dword2C *dword2C;
};


struct NUIP_RUNTIME_STATE
{
	unsigned int InitializationFlags;
	unsigned int HardwareThreadSkeleton;
	int RunningST;
	unsigned int ThreadId;
	unsigned int *Thread;
	void *TerminateThreadEvent;
	volatile int TerminateThread;
	D3DDevice *pDevice;
	unsigned int VideoRefreshRate;
	unsigned char BeginPreprocessingEvent[0x10];
	unsigned char GPUWorkCompletionEvent[0x10];
	unsigned char PresentNoGPUWorkEvent[0x10];
	unsigned int LastFence;
	int CameraPresent;
	int CameraReady;
	int SystemUIPresent;
	unsigned __int8 *ColorRawBufferMemory;
	unsigned __int8 *DepthRawBufferMemory;
	unsigned int BufferLock;
	int DepthTransferOutstanding;
	unsigned int FrameNumberBase;
	int RebaseFrameNumbers;
	int *LastCompletedDepthBuffer;
	char DepthBuffers[4*0x80];
	int ColorTransferOutstanding;
	int *LastCompletedColorBuffer;
	char ColorBuffers[4*0x80];
	char CameraSync[0x190];
	char OutstandingTransferCompleteEvent[0x10];
	char ColorBuffersTexture[0x34];
	char DepthBuffersTexture[0x34];
	char Camera[0x3B0];
	int SkeletonTrackingEnabled;
	char SkeletonCompletionEvent[0x10];
	char *UserSkeletonCompletionEvent;
	unsigned int SkeletonTrackingFlags;
	unsigned int InProgressFrameIndex;
	unsigned int LatestFrameIndex;
	char Frame[2*0xAE0];
	char SkeletonFrameReportingData[0xB0];
	volatile int TitleSetsTrackedSkeletons;
	int EtxProducer[0x40];
	int *StreamObjects[6];
	int *pAllFramesReadyEvent;
	int SuppressNoProcessForAllFramesReadyEvent;
	int RunningIdentity;
	int IdentityCompletionEvent[0x10];
	
};




struct EngineGlobalParams
{
	clsOOSystemHeap *clsOOSystemHeap;
	int clsOOMain360Heap;
	int field_8;
	int clsOOVramHeap;
	int field_10;
	int field_14;
	clsXbox360System *clsXbox360FPSSystem;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	clsOOTimer *clsOO360Timer;
	int clsXbox360VecCalc;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int clsOO360Print;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
};

struct HStruct
{
	std::string field_0;
	XSESSION_SEARCHRESULT *SearchResult;
	int field_20;
};


DataPointer(XGuidMenu*,KinnectGuidInstanceSome,0x83E52F80);
DataPointer(char,byte_83E515E7,0x83E515E7);
DataPointer(char,MainMenuCursorSome,0x83E515F6);
DataPointer(void*,off_83E52F7C,0x83E52F7C);
DataPointer(void*,MainInputRoot,0x83E52E24);
DataPointer(__int64,qword_83E51600,0x83E51600);
DataPointer(byte,byte_83E515F7,0x83E515F7);
DataPointer(byte,byte_83E515F8,0x83E515F8);
DataPointer(byte,byte_82B056A6,0x82B056A6);
DataPointer(void*,off_83E515FC,0x83E515FC);
DataPointer(int,IsCanGoBackOrSome,0x82B05698);
DataPointer(int,dword_82B05694,0x82B05694);

DataPointer(int,MainGameRooOrEnginetStaticInstance,0x83E52F6C);

DataPointer(int,Static_8219FB14,0x83E52FC4);

DataPointer(int,ChangeMenuNextMenuStartConst,0x82B05690);
DataPointer(int*,MainHeap,0x83E5160C);

DataPointer(int, off_83E5317C, 0x83E5317C);
DataPointer(int, MainTitlev144Actions, 0x83E52FB8);
DataPointer(byte, SomeByteIGuess, 0x83E515FB);
DataPointer(void*, off_83E52F88, 0x83E52F88);
DataPointer(struct_GameRootStateController*, GameRootStateController, 0x83E52E20);
DataPointer(int, dword_82B056B4, 0x82B056B4);
DataPointer(int*, off_83E52E28, 0x83E52E28);
DataPointer(int*, off_83E52FB4, 0x83E52FB4);
DataPointer(int*, off_83E52F8C, 0x83E52F8C);
DataPointer(struct_MBKinnectInput*, MBKinnectInput, 0x83E516A0);
DataPointer(int *, MainTitleAudioTableMbX, 0x83E536C0);
DataPointer(int , InputSomeUnkStatic, 0x83E52FDC);
DataPointer(int,seg_83E52F84, 0x83E52F84);
DataPointer(int,NuipInitialized, 0X82B5D2AC);
DataPointer(NUIP_RUNTIME_STATE,NuipRuntimeState, 0x82B5D2B0);


DataPointer(int,dword_83E53144, 0x83E53144);

namespace NearKinnectNuiBox{
DataPointer(int,Instance, 0x83E52F8C);
}
DataPointer(int,off_83E53128, 0x83E53128);


DataPointer(int,MessageBoxInputMB, 0x83E52F7C);
DataPointer(int,off_83E52FA0, 0x83E52FA0);
DataPointer(float,flt_82B34BD8, 0x82B34BD8);

DataPointer(int,XNLiveSomeStatic, 0x83E53138);
DataPointer(float,flt_83E519F0, 0x83E519F0);
DataPointer(float,flt_82B3BCE0, 0x82B3BCE0);

DataPointer(int*,dword_82B3FFF8, 0x82B3FFF8);
DataPointer(int*,dword_8218FFB4, 0x8218FFB4);

DataPointer(int *,D3D__CDevice__GAME, 0x83E50B30);




FastcallFunctionPointer(int,sub_824573A8,(int a1),0x824573A8);
FastcallFunctionPointer(int,MessageBoxInpuResult,(int a1,int a2),0x823EF348);
FastcallFunctionPointer(int,sub_82487E80,(int a1, int a2, int a3),0x82487E80);
FastcallFunctionPointer(int,ChangeMenuNext,(DWORD *result, int a2, int GoBackForward, int MenuCase, int *a5),0x82454848);
FastcallFunctionPointer(int,sub_8248BF20,(_DWORD *a1, int a2, int a3),0x8248BF20);
FastcallFunctionPointer(int,sub_8245FDF0,(int result, _DWORD *a2),0x8245FDF0);
FastcallFunctionPointer(int,sub_82456D60,(int a1, int a2, __int64 a3),0x82456D60);
FastcallFunctionPointer(int,sub_82456E80,(_DWORD *a1),0x82456E80);
FastcallFunctionPointer(int,sub_82454320,(int a1),0x82454320);
FastcallFunctionPointer(int,sub_82477628,(int a1),0x82477628);
FastcallFunctionPointer(int,sub_82488C08,(int result, int a2, double a3, int a4, int a5, int a6),0x82488C08);
FastcallFunctionPointer(int,sub_82488960,(int result,int a2),0x82488960);
FastcallFunctionPointer(int,sub_8248AA00,(int a1,int a2),0x8248AA00);
FastcallFunctionPointer(int,sub_8245E6B0,(),0x8245E6B0);
FastcallFunctionPointer(int,sub_8243D1B8,(int a1, int a2, unsigned int a3, int a4, int a5, int a6, int a7),0x8243D1B8);
FastcallFunctionPointer(int,sub_8245C300,(int),0x8245C300);
FastcallFunctionPointer(int,sub_82452F48,(int),0x82452F48);
FastcallFunctionPointer(int,SwapOutWithinNextPlayerMSG,(),0x824636A8);
FastcallFunctionPointer(int*,sub_8246E7E8,(int),0x8246E7E8);

FastcallFunctionPointer(int*,sub_82240838,(int a1, int a2, __int64 a3),0x82240838);
FastcallFunctionPointer(EngineGlobalParams *,GetEngineGlobalParams,(),0x82211440);	
FastcallFunctionPointer(int*,RidersMemAlloc,(size_t a1),0x82497D68 );	
FastcallFunctionPointer(int*,ChrChangeState,(struct_v1 *a1, int a2),0x822B1818);	
FastcallFunctionPointer(int*,MAINMENUBIGSUB,(int a1, ItemNRElement *a2, int a3),0x82460668);	
FastcallFunctionPointer(bool,IsUIRingCanBeChanged,(int a1),0x824573A8);	
FastcallFunctionPointer(int*,IsThatSelector_,(_DWORD *a1, int a2),0x824790C8);	


FastcallFunctionPointer(int*,sub_82A54330,(int *a1, int* a2,__int64 a3),0x82A54330);	



FastcallFunctionPointer(int,sub_824D1B98,(int a1),0x824D1B98);	

FastcallFunctionPointer(int*,sub_8270CDD8,(int a1),0x8270CDD8);	
FastcallFunctionPointer(int*,boostsomex,(int* a1),0x822111D8);	
FastcallFunctionPointer(int*,sub_82230F38,(_DWORD *result, int a2),0x82230F38);	
FastcallFunctionPointer(int*,sub_82408998,(int result,int a2,int a3),0x82408998);	
FastcallFunctionPointer(int*,sub_8249F9C8,(int result, unsigned int a2, int a3),0x8249F9C8);	
FastcallFunctionPointer(int*,sub_8248B948,(int a1,int a2),0x8248B948);	
FastcallFunctionPointer(int*,sub_82299420,(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, double a9, double a10),0x82299420);	

	

const struct _ETX_DATA_FIELD
{
	unsigned __int8 Ordinal;
	unsigned __int8 DataFieldType;
};
struct _ETX_EVENT_STATISTICS
{
	volatile unsigned int LoggedEvents;
	volatile unsigned int DroppedEvents;
};


struct _ETX_EVENT_DESCRIPTOR
{
	unsigned int Reserved1;
	unsigned int EventFlags;
	const _ETX_DATA_FIELD *DataFieldArray;
	unsigned int ExplicitDataFieldCount;
	unsigned int ImplicitDataFieldCount;
	const char *LogStringId;
	unsigned int OmnitureFlags;
	_ETX_EVENT_STATISTICS Statistics;
	unsigned int Reserved2[2];
};

struct _ETX_COMPONENT_ID
{
	unsigned __int8 Data[16];
};


struct __declspec(align(8)) _ETX_PRODUCER
{
	unsigned int Size;
	unsigned int Flags;
	unsigned __int64 Keyword;
	_ETX_EVENT_DESCRIPTOR *EventDescriptorArray;
	unsigned int EventDescriptorCount;
	unsigned __int32 Reserved1 : 22;
	unsigned __int32 SlotIndex : 10;
	const _ETX_COMPONENT_ID *ComponentId;
	void *Reserved2;
	unsigned __int8 XwppTargetId;
	unsigned __int8 Reserved3[3];
	void *Reserved4[5];
};





static void*  RidersAlloc(size_t size){

	return (*(void* (__fastcall **)(void *, int, int))(*(_DWORD *)MainHeap + 16))(MainHeap, size, 16);
}

namespace NUI{

	namespace Input{
		DataPointer(int *,Instance,0x83E52E1C);
	}
}


namespace KinnectNuiBox{

DataPointer(struct_a1_6 *,Instance,0x83E52F88);

}

	struct  MainMenuNRStruct
	{
		int field_0;
		int field_4;
		int field_8;
		int field_C;
		int field_10;
		int field_14;
		int field_18;
		int field_1C;
		int field_20;
		struct_a11 field_24;
	};


namespace MainMenuNR{
	DataPointer(MainMenuNRStruct *,Instance,0x83E5312C);
};



namespace Riders
{

	namespace Sound{
		DataPointer(void*,Instance,0x83E52E18);
		FastcallFunctionPointer(int,PlaySound,(int a1, int a2, int SoundID),0x8222FA18);
		FastcallFunctionPointer(int,StopSound,(int a1, int a2),0x8222FAF8);

	};






}


DataPointer(clsXbox360Timer,SclsOOTimer, 0x83E54930);

#endif