#ifndef __RIDERS__FREE__
#define __RIDERS__FREE__

#include "Basics.h"

#pragma once








struct __declspec(align(8)) struct_a11
{
	_BYTE gap0[4];
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


struct  struct_GameRootStateController
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
	_BYTE gap68;
	int field_69;
	int field_6D;
	int field_71;
	int field_75;
	_BYTE gap79[23];
	_DWORD dword90;
	_BYTE gap94[4];
	char char98;
	_BYTE gap99[19];
	short wordAC;
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

struct struct_v1
{
  float float0;
  _BYTE gap4[140];
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
  _QWORD qword110;
  _QWORD qword118;
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
  _QWORD qword1D0;
  float float1D8;
  float float1DC;
  _QWORD qword1E0;
  _QWORD qword1E8;
  _BYTE gap1F0[16];
  float float200;
  _BYTE gap204[12];
  _QWORD qword210;
  _QWORD qword218;
  _BYTE gap220[224];
  _QWORD qword300;
  _QWORD qword308;
  _BYTE gap310[322];
  unsigned __int16 unsigned452;
  _BYTE gap454[28];
  _QWORD qword470;
  _QWORD qword478;
  _BYTE gap480[16];
  _QWORD qword490;
  _QWORD qword498;
  _BYTE gap4A0[40];
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
  _BYTE gap520[288];
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
  float *pfloat690;
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
  int field_724;
  int field_728;
  int field_72C;
  int field_730;
  int field_734;
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
  _BYTE gap7E0[88];
  _DWORD dword838;
  _DWORD dword83C;
  _DWORD dword840;
  _BYTE gap844[4];
  _DWORD dword848;
  _DWORD dword84C;
  _DWORD dword850;
  _DWORD dword854;
  _BYTE gap858[28];
  unsigned __int16 unsigned874;
  _WORD word876;
  _WORD word878;
  unsigned __int16 unsigned87A;
  _DWORD dword87C;
  _BYTE gap880[156];
  _DWORD dword91C;
  _BYTE gap920[4];
  float float924;
  _BYTE gap928[12];
  _DWORD dword934;
  float float938;
  _DWORD dword93C;
  _BYTE gap940[8];
  _DWORD ChrState;
  _BYTE gap94C[8];
  _DWORD dword954;
  _DWORD dword958;
  _BYTE gap95C[246];
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
	int field_304;
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
	_BYTE gap8[12];
	float CameraSpeed;
	_BYTE gap18[4];
	_DWORD dword1C;
	float float20;
	float float24;
	float SpeedSome;
	float float2C;
	float float30;
	float float34;
	_BYTE gap38[35];
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



struct struct_MBKinnectInput
{
	_BYTE gap0[24];
	struct_a1_4 *dword18;
	struct_field_1C *field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	struct_field_34 *field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
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

struct __declspec(align(8)) ItemNRElement
{
	_BYTE gap0[64];
	float float40;
	float float44;
	float float48;
	__declspec(align(8)) float float50;
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
	_DWORD dword11C;
	_DWORD dword120;
	_BYTE gap124[16];
	DWORD ItemState;
	__int16 field_138;
	_BYTE field_13A[54];
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
	_BYTE gap1C0[4];
	float float1C4;
	float float1C8;
	float float1CC;
	float float1D0;
	_BYTE gap1D4[76];
	float float220;
	float float224;
};

struct __declspec(align(4)) struct_UIRingController
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
	_DWORD dword140;
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
	_DWORD dword1E8;
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

namespace NearKinnectNuiBox{
DataPointer(int,Instance, 0x83E52F8C);
}
DataPointer(int,off_83E53128, 0x83E53128);


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
FastcallFunctionPointer(int*,sub_82211440,(),0x82211440);	
FastcallFunctionPointer(int*,RidersMemAlloc,(size_t a1),0x82497D68 );	
FastcallFunctionPointer(int*,ChrChangeState,(struct_v1 *a1, int a2),0x822B1818);	
FastcallFunctionPointer(int*,MAINMENUBIGSUB,(int a1, struct_a2 *a2, int a3),0x82460668);	
FastcallFunctionPointer(int*,IsUIRingCanBeChanged,(int a1),0x824573A8);	
FastcallFunctionPointer(int*,IsThatSelector_,(_DWORD *a1, int a2),0x824573A8);	


FastcallFunctionPointer(int*,sub_82A54330,(int *a1, int* a2,__int64 a3),0x82A54330);	



void*  RidersAlloc(size_t size){

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
		FastcallFunctionPointer(int,PlaySound,(int a1, int a2, int SoundID),0x824636A8);
		FastcallFunctionPointer(int,StopSound,(int a1, int a2),0x8222FAF8);

	};






}

#endif