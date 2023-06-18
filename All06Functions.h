#ifndef ALL
#define  ALL


FUNCTION_PTR(int,__fastcall,BasicsTest,0x82000000);



FUNCTION_PTR(int,__fastcall,ContextSonicIsCanDrain,0x82217FC0,int *a1, int a2);
FUNCTION_PTR(int,__fastcall,State_Common_Wait_Action_Mid,0x8220CF80,int *a1,double a2);
FUNCTION_PTR(int,__fastcall,State_Common_Wait_Action_Start,0x822090E0,int *a1);
FUNCTION_PTR(int,__fastcall,State_Common_Walk_Action_End,0x82209180,int *a1);


///XNCP FUNCTIONS(Load,Unload)
//a1 = XNCP CELL Only pointer
//a2 = XNCP Scene Name
//a3 = XNCP Scene Animation
FUNCTION_PTR(int,__fastcall,CellLoadSprite,0x824CE670,int* a1,int a2,int a3);
FUNCTION_PTR(int,__fastcall,sub_824EAF9C,0x824EAF9C,int* a1,int* a2,int* a3);



//Selector

FUNCTION_PTR(int,__fastcall,CharacterSelectorFunction,0x824FE310,int a1, int a2, int a3, int* a4);




FUNCTION_PTR(int,__fastcall,Increment,0x82659610,int a1);


FUNCTION_PTR(int,__fastcall,State_Base_Switcher,0x8220A938,int *a1); //Basics 06 State Connected to switch to others states like spring and some sheet 
FUNCTION_PTR(int,__fastcall,State_Base_FallSwitcher,0x8220AAF8,int *a1); // State_Base_Switcher + some code with fall detection




///TEMPLATED FUNCTIONS 






//Omega Hover Update
template <typename A1,typename A2> int __fastcall sub_821AA3D0(A1 a1,A2 a2){return ((int (__fastcall *)(A1,A2))0x821AA3D0)(a1,a2);}






template <typename A1,typename A2,typename A3,typename A4> int __fastcall sub_824FCFA0(A1 a1,A2 a2,A3 a3,A4 a4){return ((int (__fastcall *)(A1,A2,A3,A4))0x824FCFA0)(a1,a2,a3,a4);}


template <typename A1,typename A2,typename A3> int __fastcall sub_824FC880(A1 a1,A2 a2,A3 a3){return ((int (__fastcall *)(A1,A2,A3))0x824FC880)(a1,a2,a3);}

template <typename A1,typename A2,typename A3> int __fastcall sub_824FD5C0(A1 a1,A2 a2,A3 a3){return ((int (__fastcall *)(A1,A2,A3))0x824FD5C0)(a1,a2,a3);}



template <typename A1,typename A2> int __fastcall sub_824FD460(A1 a1,A2 a2){return ((int (__fastcall *)(A1,A2))0x824FD460)(a1,a2);}
template <typename A1> int __fastcall sub_82581078(A1 a1){return ((int (__fastcall *)(A1))0x82581078)(a1);}

template <typename A1,typename A2,typename A3> int __fastcall sub_824FD4F8(A1 a1,A2 a2,A3 a3){return ((int (__fastcall *)(A1,A2,A3))0x824FD4F8)(a1,a2,a3);}
template <typename A1,typename A2> int __fastcall BoostWeakPtr(A1 a1,A2 a2){return ((int (__fastcall *)(A1,A2))0x8221F3C8)(a1,a2);}
template <typename A1> int __fastcall sub_821601B8(A1 a1){return ((int (__fastcall *)(A1))0x821601B8)(a1);}
template <typename A1> int __fastcall sub_82160140(A1 a1){return ((int (__fastcall *)(A1))0x82160140)(a1);}

int __fastcall sub_821601B8(int a1){return ((int (__fastcall *)(int))0x821601B8)(a1);}
int __fastcall sub_82160140(int a1){return ((int (__fastcall *)(int))0x82160140)(a1);}



template <typename A1,typename A2,typename A3> int __fastcall GetSelectedCharacterLUA(A1 a1,A2 a2,A3 a3){return ((int (__fastcall *)(A1,A2,A3))0x824FD1F0)(a1,a2,a3);}





template <typename A1,typename A2> int __fastcall sub_824FCCD8(A1 a1,A2 a2){return ((int (__fastcall *)(A1,A2))0x824FCCD8)(a1,a2);}

template <typename A1,typename A2> int __fastcall sub_821EDDB0(A1 a1,A2 a2){return ((int (__fastcall *)(A1,A2))0x821EDDB0)(a1,a2);}

template <typename A1,typename A2> int __fastcall sub_826314F8(A1 a1,A2 a2){return ((int (__fastcall *)(A1,A2))0x826314F8)(a1,a2);}







template <typename A1,typename A2,typename A3> int __fastcall sub_82186138(A1 a1,A2 a2,A3 a3){return ((int (__fastcall *)(A1,A2,A3))0x82186138)(a1,a2,a3);}



template <typename A1> int __fastcall sub_82581380(A1 a1){return ((int (__fastcall *)(A1))0x82581380)(a1);}

template <typename A1> int __fastcall sub_82581E38(A1 a1){return ((int (__fastcall *)(A1))0x82581E38)(a1);}



template <typename A1> int __fastcall sub_82186068(A1 a1){return ((int (__fastcall *)(A1))0x82186068)(a1);}



template <typename A1,typename A2,typename A3> int __fastcall NewString(A1 a1,A2 a2,A3 a3){return ((int (__fastcall *)(A1,A2,A3))0x82161E08)(a1,a2,a3);}


template <typename A1,typename A2> int __fastcall sub_825EB070(A1 a1,A2 a2){return ((int (__fastcall *)(A1,A2))0x825EB070)(a1,a2);}


template <typename A1,typename A2,typename A3,typename A4> int __fastcall ArcHandle(A1 a1,A2 a2,A3 a3,A4 a4){return ((int (__fastcall *)(A1,A2,A3,A4))0x82583528)(a1,a2,a3,a4);}
template <typename A1> int __fastcall sub_82582C10(A1 a1){return ((int (__fastcall *)(A1))0x82582C10)(a1);}


template <typename A1> int __fastcall sub_824FDB20(A1 a1){return ((int (__fastcall *)(A1))0x824FDB20)(a1);}


template <typename A1,typename A2> int __fastcall sub_824FD388(A1 a1,A2 a2){return ((int (__fastcall *)(A1,A2))0x824FD388)(a1,a2);}


template <typename A1> int __fastcall sub_824FCDA0(A1 a1){return ((int (__fastcall *)(A1))0x824FCDA0)(a1);}


template <typename A1> int __fastcall sub_824FDD80(A1 a1){return ((int (__fastcall *)(A1))0x824FDD80)(a1);}



template <typename A1> int __fastcall sub_82170B68(A1 a1){return ((int (__fastcall *)(A1))0x82170B68)(a1);}





template <typename A1,typename A2,typename A3> int __fastcall sub_824CAC88(A1 a1,A2 a2,A3 a3){return ((int (__fastcall *)(A1,A2,A3))0x824CAC88)(a1,a2,a3);}

	




template <typename A1> int __fastcall sub_8216ECD8(A1 a1){return ((int (__fastcall *)(A1))0x8216ECD8)(a1);}










#endif
