// 2002.03.08 - created,
// 2005.04.09 - modified,
//              Dietrich Teickner e-mail:dietrich_teickner@arcor.de
// search for delphi class definitions
// at end of valid(known) definition it ask for continue
// 
#include <idc.idc>

#include "idc.idc"

// TestOutput by 1
#define t                1
// TestOutput procnamelength at Message
#define pnl              12
#define NameChars ".0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_"
//--------------------------------------------------------------------
static ltox(ea,n) {
  return rigthStr(ltoa(ea,16),n);
  }
//--------------------------------------------------------------------
static rigthStr(c,n) {
  auto x;
  x = "                                                         "+c;
  return substr(x,strlen(x)-n,-1);
  }
//--------------------------------------------------------------------
static leftStr(c,n) {
  return substr(c+"                                           ",0,n);
  }
//--------------------------------------------------------------------
static isNummer(x) {
  return (strstr("0123456789",substr(x,0,1)) > -1);
  }
//--------------------------------------------------------------------
static isHexa(x) {
  return (strstr("0123456789ABCDEF",substr(x,0,1)) > -1);
  }
//--------------------------------------------------------------------
static isNameStr(ea,e) {
  auto i;
  if (strstr(NameChars,(i = Byte(ea))) == -1) return -1;
  if ((i < 'A' || i > 'z') && (i != '.')) return -1;
  do {
	if (--e == 0) return 0; 
	if (strstr(NameChars,Byte(++ea)) == -1) return -1;
	} while (1);  
  }
//--------------------------------------------------------------------
static Up_T_0(s_ea) {
  auto e_ea,ea,i,e,e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,eb;
	ea = s_ea;
    if ((e0=Dword(ea)) < MinEA() || e0 > MaxEA()) return s_ea;		// e0
	Message(" *** ea: %8x Code  T 0.0\n",ea);
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.1\n",ea);
    if (((e1=Dword(ea)) != 0) && (e1 < MinEA() || e1 > MaxEA())) return s_ea;	// e1
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.2\n",ea);
    if ((e2=Dword(ea)) != 0) return s_ea;							// e2
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.3\n",ea);
    if (((e3=Dword(ea)) != 0) && (e3 < MinEA() || e3 > MaxEA())) return s_ea;	// e3
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.4\n",ea);
    if (((e4=Dword(ea)) != 0) && (e4 < MinEA() || e4 > MaxEA())) return s_ea;	// e4
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.5\n",ea);
    if (((e5=Dword(ea)) != 0) && (e5 < MinEA() || e5 > MaxEA())) return s_ea;	// e5
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.6\n",ea);
    if (((e6=Dword(ea)) != 0) && (e6 < MinEA() || e6 > MaxEA())) return s_ea;	// e6
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.7\n",ea);
    if (((e7=Dword(ea)) != 0) && (e7 < MinEA() || e7 > MaxEA())) return s_ea;	// e7
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.8\n",ea);
    if (((e8=Dword(ea)) < MinEA() || e8 > MaxEA())) return s_ea;	// e8
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.9\n",ea);
    if (Dword(ea) == 0) return s_ea;
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.A\n",ea);
    if (((eb=Dword(ea)) != 0) && (eb < MinEA() || eb > MaxEA())) return s_ea;	// eb BasisTyp
	ea = ea + 4;
	Message(" *** ea: %8x Code  T 0.B\n",ea);
	if ((e=Byte(e8)) == 0) return s_ea; 
	Message(" *** ea: %8x Code  T 0.C\n",ea);
    if (isNameStr(e8 + 1,e) == -1) return s_ea;
	Message(" *** ea: %8x Code  T 0.D\n",ea);
	if (e4 != 0) {
	  if ((i=Byte(e4 + 1)) == 0) return s_ea; 
	  Message(" *** ea: %8x Code  T 0.E\n",ea);
      if (isNameStr(e4 + 2,i) == -1) return s_ea;
	  Message(" *** ea: %8x Code  T 0.F\n",ea);
      if (e4 >= s_ea && e4 <= e8) return s_ea;
	  Message(" *** ea: %8x Code  T 0.G\n",ea);
      if (i != e) return s_ea;
	  Message(" *** ea: %8x Code  T 0.H e: %d\n",ea,e);
	  for (;i>0;i--)
	  {
		if (Byte(e8 + 0 + i) != Byte(e4 + 1 + i)) return s_ea;
	  }
	}
	Message(" *** ea: %8x Code  T 0.I\n",ea);
	if (e3 != 0) {
	  if (e3 <= ea || e3 >= e8) return s_ea;
	  if ((i = Up_W_E(e3,0)) == e3 || i > e8) return s_ea;	// e_e3
	}
	Message(" *** ea: %8x Code  T 0.j\n",ea);
	if (e5 != 0) {
	  if (e5 <= ea || e5 >= e8) return s_ea;
	  if ((i = Up_N_X(e5,0)) == e5 || i > e8) return s_ea;	// e_e5
	}
	Message(" *** ea: %8x Code  T 0.k\n",ea);
	if (e6 != 0) {
	  if (e6 <= ea || e6 >= e8) return s_ea;
	  if ((i = Up_N_O(e6,0)) == e6 || i > e8) return s_ea;	// e_e6
	}
	Message(" *** ea: %8x Code  T 0.L\n",ea);
	if (e7 != 0) {
	  if (e7 <= ea || e7 >= e8) return s_ea;
	  if ((i = Up_W_X(e7,0)) == e7 || i > e8) return s_ea;	// e_e7
	}
	e9 = e8;
	if (e3 != 0 && e3 < e9) e9 = e3; 
	if (e5 != 0 && e5 < e9) e9 = e5; 
	if (e6 != 0 && e6 < e9) e9 = e6; 
	if (e7 != 0 && e7 < e9) e9 = e7; 
	for (;ea < e9;ea = ea + 4)
	{
      if ((i=Dword(ea)) < MinEA() || i > MaxEA()) {
		Message(" *** ea: %8x Code  T 0.M\n",ea);
		return s_ea;
	  }
	}
	e_ea = e8 + 1 + e;
	for (ea = s_ea;ea != e_ea;++ea) MakeUnkn(ea,0);
	ea = s_ea;
Message(" *** ea: %8x Start T 0\n",ea);
	MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;						// e0
	MakeDword(ea);if (Dword(ea) != 0) OpOff(ea,0,0);ea = ea + 4;	// e1
	MakeDword(ea);if (Dword(ea) != 0) OpOff(ea,0,0);ea = ea + 4;	// e2
	MakeDword(ea);if ((e3=Dword(ea)) != 0) {OpOff(ea,0,0);Up_W_E(e3,1);};ea = ea + 4;	// e3
	MakeDword(ea);if (Dword(ea) != 0) OpOff(ea,0,0);ea = ea + 4;	// e4
	MakeDword(ea);if ((e5=Dword(ea)) != 0) {OpOff(ea,0,0);Up_N_X(e5,1);};ea = ea + 4;	// e5
	MakeDword(ea);if ((e6=Dword(ea)) != 0) {OpOff(ea,0,0);Up_N_O(e6,1);};ea = ea + 4;	// e6
	MakeDword(ea);if ((e7=Dword(ea)) != 0) {OpOff(ea,0,0);Up_W_X(e7,1);};ea = ea + 4;	// e7
	MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;						// e8
	MakeDword(ea);ea = ea + 4;
	MakeDword(ea);if (Dword(ea) != 0) OpOff(ea,0,0);ea = ea + 4;	// ea BasisTyp
	for (;ea < e9;ea = ea + 4)
	{
	  MakeDword(ea);OpOff(ea,0,0);
	}
	MakeStr(e8,-1);
Message(" *** ea: %8x Ende  T 0\n",e_ea);
	if (e5 == 0) return e_ea;
	s_ea = Dword(e5 + 2);
	if (s_ea != e_ea) return e_ea;
	ea = s_ea;
	if ((i=Word(ea)) == 0) return s_ea;
	ea = ea + 2;
	for (;i>0;i--)
	{
      if ((e=Dword(ea)) < MinEA() || e > MaxEA()) return s_ea;
	  ea = ea + 4;
	}
	e_ea = ea;
	for (ea = s_ea;ea != e_ea;++ea) MakeUnkn(ea,0);
	ea = s_ea;
Message(" *** ea: %8x Start A 0\n",ea);
	i=Word(ea);
	MakeWord(ea);ea = ea + 2;
	for (;i>0;i--)
	{
	  MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
	}
Message(" *** ea: %8x Ende  A 0\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_W_X(s_ea,s) {
  auto e_ea,ea,i,e;
	ea = s_ea;
	Message(" *** ea: %8x Code  W X.0\n",ea);
	if ((i=Word(ea)) == 0) return s_ea;
	ea = ea + 2 + 2 * i;
	for (;i>0;i--)
	{
	  Message(" *** ea: %8x Code  W X.1\n",ea);
      if ((e=Dword(ea)) < MinEA() || e > MaxEA()) return s_ea;
	  ea = ea + 4;
	}
	e_ea = ea;
	if (s==0) return e_ea;
	for (ea = s_ea;ea != e_ea;++ea) MakeUnkn(ea,0);
	ea = s_ea;
Message(" *** ea: %8x Start W X\n",ea);
	i=Word(ea);
	MakeWord(ea);ea = ea + 2;
	MakeWord(ea);
	MakeArray(ea,i);ea = ea + 2*i;
	for (;i>0;i--)
	{
	  Message(" *** ea: %8x Code  W X.3\n",ea);
	  MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
	}
Message(" *** ea: %8x Ende  W X\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_N_X(s_ea,s) {
  auto e_ea,ea,i,e;
	ea = s_ea;
	Message(" *** ea: %8x Code N X.0\n",ea);
	if ((i=Word(ea)) == 0) return s_ea;
	ea = ea + 2;
	Message(" *** ea: %8x Code N X.1\n",ea);
    if ((e=Dword(ea)) < MinEA() || e > MaxEA()) return s_ea;
	ea = ea + 4;
	for (;i>0;i--)
	{
	  Message(" *** ea: %8x Code N X.2\n",ea);
      if (Dword(ea) == 0) return s_ea;
	  ea = ea + 4 + 2;
	  Message(" *** ea: %8x Code N X.3\n",ea);
      if ((e=Byte(ea)) == 0) return s_ea;
	  Message(" *** ea: %8x Code N X.4\n",ea);
      if (isNameStr(++ea,e) == -1) return s_ea;
	  ea = ea + e;
	};
	e_ea = ea;
	if (s==0) return e_ea;
	for (ea = s_ea;ea != e_ea;++ea) MakeUnkn(ea,0);
	ea = s_ea;
Message(" *** ea: %8x Start N X\n",ea);
	i=Word(ea);
	MakeWord(ea);ea = ea + 2;
	MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
	for (;i>0;i--)
	{
	  MakeDword(ea);ea = ea + 4;
	  MakeWord(ea);ea = ea + 2;
	  MakeStr(ea,-1);ea=ea + Byte(ea) + 1;
	}
Message(" *** ea: %8x Ende  N X\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_N_O(s_ea,s) {
  auto e_ea,ea,i,e;
	ea = s_ea;
	Message(" *** ea: %8x Code N O.0\n",ea);
	if ((i=Word(ea)) == 0) return s_ea;
	ea = ea + 2;
	for (;i>0;i--)
	{
	  Message(" *** ea: %8x Code N O.1\n",ea);
      if (Word(ea) == 0) return s_ea;
	  ea = ea + 2;
	  Message(" *** ea: %8x Code N O.2\n",ea);
      if ((e=Dword(ea)) < MinEA() || e > MaxEA()) return s_ea;  // Adresse einer wortliste 
	  ea = ea + 4;
	  Message(" *** ea: %8x Code N O.3\n",ea);
      if ((e=Byte(ea)) == 0) return s_ea;
	  Message(" *** ea: %8x Code N O.4\n",ea);
      if (isNameStr(++ea,e) == -1) return s_ea;
	  ea = ea + e;
	};
	e_ea = ea;
	if (s==0) return e_ea;
	for (ea = s_ea;ea != e_ea;++ea) MakeUnkn(ea,0);
	ea = s_ea;
Message(" *** ea: %8x Start N O\n",ea);
	i=Word(ea);
	MakeWord(ea);ea = ea + 2;
	for (;i>0;i--)
	{
	  MakeWord(ea);ea = ea + 2;
	  MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
	  MakeStr(ea,-1);ea=ea + Byte(ea) + 1;
	}
Message(" *** ea: %8x Ende  N O\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_W_E(s_ea,s) {
  auto e_ea,ea,i,e;
	ea = s_ea;
	Message(" *** ea: %8x Code  W E.0\n",ea);
	if (Word(ea) != 0x0e) return s_ea;
	ea = ea + 2;
	Message(" *** ea: %8x Code  W E.1\n",ea);
	if (Dword(ea) != 0) return s_ea;
	ea = ea + 4;
	Message(" *** ea: %8x Code  W E.2\n",ea);
	if ((i = Dword(ea)) == 0) return s_ea;
	ea = ea + 4;
	for (;i>0;i--)
	{
	  Message(" *** ea: %8x Code  W E.3\n",ea);
      if ((e=Dword(ea)) < MinEA() || e > MaxEA()) return s_ea;
	  ea = ea + 8;
	}
	e_ea = ea;
	if (s==0) return e_ea;
	for (ea = s_ea;ea != e_ea;++ea) MakeUnkn(ea,0);
	ea = s_ea;
Message(" *** ea: %8x Start W E\n",ea);
	MakeWord(ea);ea = ea + 2;
	MakeDword(ea);ea = ea + 4;
	i = Dword(ea);
	MakeDword(ea);ea = ea + 4;
	for (;i>0;i--)
	{
	  MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
	  MakeDword(ea);ea = ea + 4;
	}
Message(" *** ea: %8x Ende  W E\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_Head(s_ea,i,e_ea) {
	auto ea,e;
	ea = Dword(s_ea);
	if (e_ea == 0) Message(" *** ea: %8x Code %x.0\n",ea,i);
	if (ea != (s_ea + 4)) return s_ea;
	if (e_ea == 0) Message(" *** ea: %8x Code %x.1\n",ea,i);
	if (Byte(ea) != i) return s_ea;
	if (e_ea == 0) Message(" *** ea: %8x Code %x.2\n",ea,i);
    if ((e=Byte(++ea)) == 0) return s_ea;
	if (e_ea == 0) Message(" *** ea: %8x Code %x.3\n",ea,i);
    if (isNameStr(++ea,e) == -1) return s_ea;
	ea = ea + e;
	if (e_ea == 0) {
	  Message(" *** ea: %8x Code %x.4\n",ea,i);
	  return ea;
	  }
Message(" *** ea: %8x Start %x\n",s_ea,i);
	for (ea = s_ea;ea != e_ea;++ea) MakeUnkn(ea,0);
	MakeDword(s_ea);OpOff(s_ea,0,0);ea = s_ea + 4;
	MakeByte(ea);
	MakeStr(++ea,-1);
	return (ea + Byte(ea) + 1);
 }
//--------------------------------------------------------------------
static Up_1(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,1,0)) == s_ea) return s_ea;
    if (Byte(ea) == 0) return s_ea;
	Message(" *** ea: %8x Code 1.5\n",ea);
	e_ea = ++ea + 2 * 4;
	if ((ea = Up_Head(s_ea,1,e_ea)) == s_ea) return s_ea;
	MakeByte(ea);
	MakeDword(++ea);ea = ea + 4;
	MakeDword(ea);ea = ea + 4;
Message(" *** ea: %8x Ende  1\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_2(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,2,0)) == s_ea) return s_ea;
    if (Byte(ea) == 0) return s_ea;
    e_ea = ea + 1 + 2 * 4;
/*	Message(" *** ea: %8x Code 2.5\n",ea);
    if ((e=Dword(ea)) < MinEA() || e > MaxEA()) return s_ea;
	ea = ea + 4;
	Message(" *** ea: %8x Code 2.6\n",ea);
    if ((e=Byte(ea)) == 0) return s_ea;
    if (isNameStr(++ea,e) == -1) return s_ea;
    if ((e=Byte(ea=(ea + e))) == 0) return s_ea;
    if (isNameStr(++ea,e) == -1) return s_ea;
	e_ea = ea + e;
*/
	if ((ea = Up_Head(s_ea,2,e_ea)) == s_ea) return s_ea;
	MakeByte(ea);
	MakeDword(++ea);ea = ea + 4;
	MakeDword(ea);ea = ea + 4;
/*	MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
	MakeStr(ea,-1);ea=ea + Byte(ea) + 1;
*/	MakeStr(ea,-1);ea=ea + Byte(ea) + 1;
Message(" *** ea: %8x Ende  2\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_3(s_ea) {
	auto e_ea,ea,i,e,s;
	if ((ea = Up_Head(s_ea,3,0)) == s_ea) return s_ea;
	if (Byte(ea) == 0) return s_ea;
	ea++;
	s = Dword(ea);
	e = Dword(ea + 4);
	Message(" *** ea: %8x Code 3.6 %d,%d\n",ea,s,e);
        if (s == e) return s_ea;
	i = 1;
// ??
    ea = ea + 8;
	Message(" *** ea: %8x Code 3.7\n",ea);
    if ((e=Dword(ea)) < MinEA() || e > MaxEA()) return s_ea;
	ea = ea + 4;
	if (e != s_ea) i = -1;
	for (;i>=0;i--)
	{
	  Message(" *** ea: %8x Code 3.8 i:%d\n",ea,i);
	  if ((e=Byte(ea)) == 0) return s_ea;
	  Message(" *** ea: %8x Code 3.9\n",ea);
	  if (isNameStr(++ea,e) == -1) return s_ea;
	  ea = ea + e;
	}
	e_ea = ea;
	if ((ea = Up_Head(s_ea,3,e_ea)) == s_ea) return s_ea;
	MakeByte(ea);
	i = 0;if (Dword(++ea) != 0) i = 2;
	MakeDword(ea);ea = ea + 4;
    if (i == 0) i=Dword(ea);
	MakeDword(ea);ea = ea + 4;
    if (Dword(ea) != s_ea) i = -1;
	MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
	for (;i>=0;i--)
	{
	  MakeStr(ea,-1);ea=ea + Byte(ea) + 1;
	}
Message(" *** ea: %8x Ende  3\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_4(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,4,0)) == s_ea) return s_ea;
    if (Byte(ea) != 1) return s_ea;
	e_ea = ++ea;
	if ((ea = Up_Head(s_ea,4,e_ea)) == s_ea) return s_ea;
	MakeByte(ea);
Message(" *** ea: %8x Ende  4\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_6(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,6,0)) == s_ea) return s_ea;
	if (Byte(ea) == 0) return s_ea;ea++;
	Message(" *** ea: %8x Code 6.5\n",ea);
	if ((e=Dword(ea)) < MinEA() || e > MaxEA()) return s_ea;ea = ea + 4;
	e_ea = ea;
	for (ea = s_ea;ea != e_ea;++ea) MakeUnkn(ea,0);
	ea = s_ea;
Message(" *** ea: %8x Start 6\n",ea);
	MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
	MakeByte(ea);
	MakeStr(++ea,-1);ea=ea + Byte(ea);
	MakeByte(++ea);++ea;
	MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
Message(" *** ea: %8x Ende  6\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_7(s_ea) {
	auto e_ea,ea,i,j,k,l,e;
	if ((ea = Up_Head(s_ea,7,0)) == s_ea) return s_ea;
    if ((e=Dword(ea)) < MinEA() || e > MaxEA()) return s_ea;
	ea = ea + 4;
    e=Dword(ea);ea = ea + 4;
	j=Word(ea);
	Message(" *** ea: %8x Code 7.5\n",ea);
    if ((e != 0) && (e < MinEA() || e > MaxEA())) return s_ea;
	ea = ea + 2;
	Message(" *** ea: %8x Code 7.6\n",ea);
    if ((e=Byte(ea)) == 0) return s_ea;
	Message(" *** ea: %8x Code 7.7\n",ea);
    if (isNameStr(++ea,e) == -1) return s_ea;
	ea = ea + e;
	Message(" *** ea: %8x Code 7.8\n",ea);
	i=Word(ea);ea = ea + 2;
    for (;i>0;i--)
	{
	Message(" *** ea: %8x Code 7.9\n",ea);
	  if ((e=Dword(ea)) < MinEA() || e > MaxEA()) return s_ea;
	  ea = ea + 6 * 4;
	Message(" *** ea: %8x Code 7.10\n",ea);
//	  if (Word(ea) == 0) return s_ea;
	  ea = ea + 2;
	  e = Byte(ea);
	Message(" *** ea: %8x Code 7.11\n",ea);
      if (isNameStr(++ea,e) == -1) return s_ea;
	  ea = ea + e;
	}
	e_ea = ea;
	if ((ea = Up_Head(s_ea,7,e_ea)) == s_ea) return s_ea;
	MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
	MakeDword(ea);if (Dword(ea) != 0) OpOff(ea,0,0);ea = ea + 4;
	j=Word(ea);
	MakeWord(ea);ea = ea + 2;
	MakeStr(ea,-1);ea = ea + Byte(ea) + 1;
	i=Word(ea);
	MakeWord(ea);ea = ea + 2;
    for (;i>0;i--)
	{
	  MakeDword(ea);OpOff(ea,0,0);ea = ea + 4;
      for (k=5;k > 0;k--)
	  {
		MakeDword(ea);
		if ((e=Dword(ea)) > MinEA() && e < MaxEA()) OpOff(ea,0,0);
		ea = ea + 4;
	  }
	  MakeWord(ea);ea = ea + 2;
	  MakeStr(ea,-1);ea = ea + Byte(ea) + 1;
	}
Message(" *** ea: %8x Ende  7\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_8(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,8,0)) == s_ea) return s_ea;
	if ((i = Byte(++ea)) == 0) return s_ea;
    ea++;
	do {
      if ((e=Byte(++ea)) == 0) return s_ea;
      if (isNameStr(++ea,e) == -1) return s_ea;
      if ((e=Byte(ea=(ea + e))) == 0) return s_ea;
      if (isNameStr(++ea,e) == -1) return s_ea;
	  ea = ea + e;
	} while (--i != 0);
	e_ea = ea;
	if ((ea = Up_Head(s_ea,8,e_ea)) == s_ea) return s_ea;
	MakeByte(ea);
	i = Byte(++ea);
	MakeByte(ea);
    ea++;
	do {
	  MakeByte(ea);
	  MakeStr(++ea,-1);ea = ea + Byte(ea);
	  MakeStr(++ea,-1);ea = ea + Byte(ea) + 1;
	} while (--i != 0);
Message(" *** ea: %8x Ende  8\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_A(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,0xa,0)) == s_ea) return s_ea;
	e_ea = ea;
	if ((ea = Up_Head(s_ea,0xa,e_ea)) == s_ea) return s_ea;
Message(" ***ea: %8x Ende  A \n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_B(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,0xb,0)) == s_ea) return s_ea;
	e_ea = ea;
	if ((ea = Up_Head(s_ea,0xb,e_ea)) == s_ea) return s_ea;
Message(" *** ea: %8x Ende  B\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_C(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,0xc,0)) == s_ea) return s_ea;
	e_ea = ea;
	if ((ea = Up_Head(s_ea,0xc,e_ea)) == s_ea) return s_ea;
Message(" *** ea: %8x Ende  C\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_D(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,0xd,0)) == s_ea) return s_ea;
        if (Dword(ea) <= 0 || Dword(ea) > MinEA())  return s_ea;
	Message(" *** ea: %8x Code d.5\n",ea);
        ea = ea + 4; 
        if (Dword(ea) <= 0 || Dword(ea) > MinEA())  return s_ea;
	Message(" *** ea: %8x Code d.6\n",ea);
        ea = ea + 4;
        if (Dword(ea) < MinEA() || Dword(ea) > MaxEA()) return s_ea;
	Message(" *** ea: %8x Code d.7\n",ea);
        e_ea = ea + 4; 
	if ((ea = Up_Head(s_ea,0xd,e_ea)) == s_ea) return s_ea;
	MakeDword(ea);
	ea = ea + 4;
	MakeDword(ea);
	ea = ea + 4;
	MakeDword(ea);OpOff(ea,0,0);
Message(" *** ea: %8x Ende  d\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_E(s_ea) {
  auto e_ea,ea,i,e;
	ea = Dword(s_ea);
	if (ea != (s_ea + 4)) return s_ea;
//	Message(" *** ea: %8x Code E.0\n",ea);
	if (Byte(ea) != 0x0e) return s_ea;
//	Message(" *** ea: %8x Code E.1\n",ea);
	if ((e=Byte(++ea)) == 0) return s_ea;
//	Message(" *** ea: %8x Code E.2\n",ea);
	if (isNameStr(++ea,e) == -1) return s_ea;
//	Message(" *** ea: %8x Code E.4\n",ea);
	if ((Dword(ea=(ea + e))) == 0) return s_ea;
//	Message(" *** ea: %8x Code E.5\n",ea);
	if ((i = Dword(ea=(ea + 4))) == 0) return s_ea;
//	Message(" *** ea: %8x Code E.6\n",ea);
	ea = ea + 4;
	for (;i>0;i--) {
	  if (Dword(ea) == 0) return s_ea;
//	  Message(" *** ea: %8x Code E.7\n",ea);
	  ea = ea + 8;
	};
	e_ea = ea;
	for (ea = s_ea;ea != e_ea;++ea) MakeUnkn(ea,0);
	ea = s_ea;
Message(" *** ea: %8x Start E\n",ea);
	MakeDword(ea);OpOff(ea,0,0);
	ea = ea + 4;
	MakeByte(ea);
	MakeStr(++ea,-1);ea=ea + Byte(ea) + 1;
	MakeDword(ea);
	ea = ea + 4;
	i = Dword(ea);
	MakeDword(ea);
	ea = ea + 4;
	for (;i>0;i--) {
	  MakeDword(ea);OpOff(ea,0,0);
	  ea = ea + 4;
	  MakeDword(ea);
	  ea = ea + 4;
	};
Message(" *** ea: %8x Ende  E\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_F(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,0xf,0)) == s_ea) return s_ea;
    if (((e=Dword(ea)) != 0) && (e < MinEA() || e > MaxEA())) return s_ea;
	Message(" *** ea: %8x Code F.5\n",ea);
	ea = ea + 4;
	ea = ea +17;
	Message(" *** ea: %8x Code F.5\n",ea);
	if ((e=Byte(ea)) == 0) return s_ea;
	Message(" *** ea: %8x Code F.6\n",ea);
	if (isNameStr(++ea,e) == -1) return s_ea;
	Message(" *** ea: %8x Code F.7\n",ea);
	if ((Word(ea=(ea + e))) != 0) return s_ea;
	Message(" *** ea: %8x Code F.8\n",ea);
	e_ea = ea + 2;
	if ((ea = Up_Head(s_ea,0xf,e_ea)) == s_ea) return s_ea;
	MakeDword(ea);if (Dword(ea) != 0) OpOff(ea,0,0);ea = ea + 4;
	ea = ea +17;
	MakeStr(ea,-1);ea=ea + Byte(ea) + 1;
	MakeWord(ea);
	ea = ea + 2;
Message(" *** ea: %8x Ende  F\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_11(s_ea) {
	auto e_ea,ea,i,e;
	if ((ea = Up_Head(s_ea,0x11,0)) == s_ea) return s_ea;
    if (Dword(ea) == 0) return s_ea;ea = ea + 4;
	Message(" *** ea: %8x Code 11.5\n",ea);
    if (((e=Dword(ea)) != 0) && (e < MinEA() || e > MaxEA())) return s_ea;ea = ea + 4;
	Message(" *** ea: %8x Code 11.6\n",ea);
    if (Dword(ea) == 0) return s_ea;e_ea = ea + 4;
	if ((ea = Up_Head(s_ea,0x11,e_ea)) == s_ea) return s_ea;
	MakeDword(ea);ea = ea + 4;
	MakeDword(ea);if (Dword(ea) != 0) OpOff(ea,0,0);ea = ea + 4;
	MakeDword(ea);ea = ea + 4;
Message(" *** ea: %8x Ende  11\n",e_ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static Up_DelphiStr(s_ea) {
	auto e_ea,ea,i,e;
	e_ea = s_ea;
	for (i = ((4 -((ea = s_ea) & 3)) & 3);i>0;i--)
	  {
		if (Byte(ea) != 0) return s_ea;ea++;
	  }
	if (Dword(ea) != -1) return s_ea;ea = ea + 4;
	if ((e = Dword(ea)) <= 0) return s_ea;ea = ea + 4;
	if ((ea + e) >=  MaxEA()) return s_ea;
	if (Byte(ea=ea + e) !=  0) return s_ea;
	for (i = ((4 -(++ea & 3)) & 3);i>0;i--)
	  {
		if (Byte(ea) != 0) return s_ea;ea++;
	  }
	e_ea = ea;
        if (Byte(s_ea - 1) != 0 && Byte(s_ea - 2) == 0xc2) s_ea++;
Message(" *** ea: %8x Start DelphiStr\n",s_ea);
	for (ea = s_ea;ea != e_ea;++ea) MakeUnkn(ea,0);
	if ((i = ((4 -((ea = s_ea) & 3)) & 3)) > 0)
	{
	  MakeAlign(s_ea,i,2);ea = ea + i;
	}
	MakeDword(ea);MakeArray(ea,2);ea = ea + 8;
	SetLongPrm(INF_STRTYPE,ASCSTR_TERMCHR);
	MakeStr(ea,-1);
	SetLongPrm(INF_STRTYPE,ASCSTR_PASCAL);
	ea = ea + e + 1;
	if ((i = ((4 -(ea & 3)) & 3)) > 0)
	{
	  MakeAlign(ea,i,2);ea = ea + i;
	}
Message(" *** ea: %8x Ende  DelphiStr\n",ea);
  return e_ea;
 }
//--------------------------------------------------------------------
static main() {
  auto s_ea,e_ea,first_ea,ea,i,e,yn,b_nop;
  SetLongPrm(INF_STRTYPE,ASCSTR_PASCAL);
  yn = -1;
  e_ea = ScreenEA();
  first_ea = 0;
  b_nop = 0;
  do {
      s_ea = e_ea;
      if ((i = ((4 -((ea = s_ea) & 3)) & 3)) > 0)
      {
        if ((i == 1 && Byte(s_ea) == 0x90 && b_nop) ||
            (i == 2 && Byte(s_ea) == 0x8b && Byte(s_ea + 1) == 0xc0) ||
      	    (i == 3 && Byte(s_ea) == 0x8d && Byte(s_ea + 1) == 0x40 && Byte(s_ea + 2) == 0x00))
        {
		for (;ea != s_ea + i;++ea) MakeUnkn(ea,0);
		MakeAlign(s_ea,i,2);
                e_ea = s_ea = s_ea + i;
	}
        b_nop = 2;
      }  
	ea = Dword(s_ea);
	if (ea == (s_ea + 4)) {
	  i = Byte(ea);
	  if (i == 1) e_ea = Up_1(s_ea);
          else
	  if (i == 2) e_ea = Up_2(s_ea);
          else
	  if (i == 3) e_ea = Up_3(s_ea);
          else
	  if (i == 4) e_ea = Up_4(s_ea);
          else
	  if (i == 6) e_ea = Up_6(s_ea);
          else
	  if (i == 7) e_ea = Up_7(s_ea);
          else
	  if (i == 8) e_ea = Up_8(s_ea);
          else
	  if (i == 0x0a) e_ea = Up_A(s_ea);
          else
	  if (i == 0x0b) e_ea = Up_B(s_ea);
          else
	  if (i == 0x0c) e_ea = Up_C(s_ea);
          else
	  if (i == 0x0d) e_ea = Up_D(s_ea);
          else
	  if (i == 0x0e) e_ea = Up_E(s_ea);
          else
	  if (i == 0x0f) e_ea = Up_F(s_ea);
          else
	  if (i == 0x011) e_ea = Up_11(s_ea);
          else
Message(" *** ea: %8x Ubekanert Type %x\n",s_ea,i);
          if (b_nop == 0 && e_ea > s_ea && (s_ea & 3) == 0 && Byte(s_ea) == 0x90)
          {
		MakeUnkn(s_ea - 1,0);
		MakeAlign(s_ea - 1,1,2);
          }          
	};
	if (s_ea == e_ea) e_ea = Up_T_0(s_ea);
	if (s_ea == e_ea) e_ea = Up_DelphiStr(s_ea);
	if (s_ea == e_ea) {
		if (first_ea != 0) Jump(first_ea);
		first_ea = 0;
//		Wait();
 		if (yn == -1) yn = AskYN(-1,"Search next Borland-Values ?\n");
		if (yn == 0) yn = -1;
		if (yn != -1) {e_ea++;} else Message(" *** ea: %8x Ende\n",e_ea);
            b_nop = 0;
	  }
	else
        {
          if (e_ea > s_ea) b_nop = 1;
          yn = -1;
        }
	if (s_ea != e_ea && first_ea == 0 && yn == -1) first_ea = s_ea;
  } while (e_ea < MaxEA() && s_ea != e_ea);
  return 0;
 }


