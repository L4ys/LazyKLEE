#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"


__int64  sub_4010B9(__int64 a1, __int64 a2)
{
  return a1 ^ a2;
}

unsigned __int64  sub_401259(unsigned __int64 a1, char a2, char a3)
{
  return ((unsigned __int64)(unsigned __int8)(a1 >> 8 * a2) << 8 * a3) | ((unsigned __int64)(unsigned __int8)(a1 >> 8 * a3) << 8 * a2) | ~(255LL << 8 * a2) & ~(255LL << 8 * a3) & a1;
}

unsigned __int64  sub_4010D2(unsigned __int64 a1, char a2)
{
  unsigned __int64 result; // rax@2

  if ( a2 & 0x3F )
    result = (a1 << (a2 & 0x3F)) | (a1 >> (64 - (a2 & 0x3Fu)));
  else
    result = a1;
  return result;
}

unsigned __int64  sub_40113E(unsigned __int64 a1, char a2)
{
  unsigned __int64 result; // rax@2

  if ( a2 & 0x3F )
    result = (a1 << (64 - (a2 & 0x3Fu))) | (a1 >> (a2 & 0x3F));
  else
    result = a1;
  return result;
}

unsigned __int64  sub_401326(__int64 a1)
{
  return (a1 << 56) ^ a1 & 0xFF00000000000000LL | ((unsigned __int64)((unsigned __int16)a1 & 0xFF00) >> 8) ^ (unsigned __int8)a1 | ((unsigned __int64)(a1 & 0xFF0000) >> 8) ^ (unsigned __int16)a1 & 0xFF00 | ((unsigned __int64)((unsigned int)a1 & 0xFF000000) >> 8) ^ a1 & 0xFF0000 | ((a1 & 0xFF00000000uLL) >> 8) ^ (unsigned int)a1 & 0xFF000000 | ((a1 & 0xFF0000000000uLL) >> 8) ^ a1 & 0xFF00000000LL | ((a1 & 0xFF000000000000uLL) >> 8) ^ a1 & 0xFF0000000000LL | ((a1 & 0xFF00000000000000LL) >> 8) ^ a1 & 0xFF000000000000LL;
}

unsigned __int64  sub_4011AA(__int64 a1)
{
  return ((a1 & 0xFF00000000000000LL) >> 8) | ((a1 & 0xFF000000000000uLL) >> 40) | ((a1 & 0xFF0000000000uLL) >> 40) | ((a1 & 0xFF00000000uLL) >> 16) | ((unsigned __int64)((unsigned int)a1 & 0xFF000000) << 16) | ((unsigned __int64)(a1 & 0xFF0000) << 40) | ((unsigned __int64)((unsigned __int16)a1 & 0xFF00) << 24) | ((_DWORD)a1 << 24);
}
  
unsigned __int64  sub_401464(__int64 a1)
{
  __int64 v1; // rax@1
  __int64 v2; // rax@1
  __int64 v3; // rax@1
  __int64 v4; // rax@1
  __int64 v5; // rax@1
  __int64 v6; // rax@1
  unsigned __int64 v7; // rax@1
  unsigned __int64 v8; // rax@1
  __int64 v9; // rax@1
  unsigned __int64 v10; // rax@1
  unsigned __int64 v11; // rax@1
  unsigned __int64 v12; // rax@1
  __int64 v13; // rax@1
  __int64 v14; // rax@1
  __int64 v15; // rax@1
  unsigned __int64 v16; // rax@1
  __int64 v17; // rax@1
  __int64 v18; // rax@1
  __int64 v19; // rax@1
  __int64 v20; // rax@1
  __int64 v21; // rax@1
  __int64 v22; // rax@1
  __int64 v23; // rax@1
  __int64 v24; // rax@1
  __int64 v25; // rax@1
  unsigned __int64 v26; // rax@1
  unsigned __int64 v27; // rax@1
  unsigned __int64 v28; // rax@1
  unsigned __int64 v29; // rax@1
  unsigned __int64 v30; // rax@1
  __int64 v31; // rax@1
  __int64 v32; // rax@1
  __int64 v33; // rax@1
  unsigned __int64 v34; // rax@1
  unsigned __int64 v35; // rax@1
  __int64 v36; // rax@1
  __int64 v37; // rax@1
  __int64 v38; // rax@1
  unsigned __int64 v39; // rax@1
  __int64 v40; // rax@1
  __int64 v41; // rax@1
  unsigned __int64 v42; // rax@1
  __int64 v43; // rax@1
  unsigned __int64 v44; // rax@1
  unsigned __int64 v45; // rax@1
  __int64 v46; // rax@1
  __int64 v47; // rax@1
  __int64 v48; // rax@1
  __int64 v49; // rax@1
  unsigned __int64 v50; // rax@1
  unsigned __int64 v51; // rax@1
  __int64 v52; // rax@1
  unsigned __int64 v53; // rax@1
  __int64 v54; // rax@1
  __int64 v55; // rax@1
  __int64 v56; // rax@1
  unsigned __int64 v57; // rax@1

  v1 = sub_4010B9(a1, 0x35966A685C73335ALL);
  v2 = sub_401259(v1, 2, 0);
  v3 = sub_4010B9(v2, 0x89FDAF6604952DF1LL);
  v4 = sub_4010B9(v3, 0xE9F30F0CE704876ALL);
  v5 = sub_401259(v4, 2, 3);
  v6 = sub_4010B9(v5, 0xBDC5026D3C0B56E6LL);
  v7 = sub_4010D2(v6, 16);
  v8 = sub_4010D2(v7, 35);
  v9 = sub_40113E(v8, 19);
  v10 = sub_401326(v9);
  v11 = sub_4010D2(v10, 36);
  v12 = sub_40113E(v11, 40);
  v13 = sub_401259(v12, 1, 0);
  v14 = sub_4010B9(v13, 0x5DE229FB3804DB17LL);
  v15 = sub_4011AA(v14);
  v16 = sub_4011AA(v15);
  v17 = sub_401259(v16, 2, 1);
  v18 = sub_4010B9(v17, 0x6AAD877366E921F5LL);
  v19 = sub_401259(v18, 3, 0);
  v20 = sub_4011AA(v19);
  v21 = sub_4010B9(v20, 0x58D83E9D5E6D5083LL);
  v22 = sub_40113E(v21, 22);
  v23 = sub_401326(v22);
  v24 = sub_4010B9(v23, 0x47B4D980070A9B73LL);
  v25 = sub_401326(v24);
  v26 = sub_401326(v25);
  v27 = sub_401259(v26, 6, 5);
  v28 = sub_4010D2(v27, 59);
  v29 = sub_401259(v28, 5, 2);
  v30 = sub_401259(v29, 2, 3);
  v31 = sub_4010D2(v30, 12);
  v32 = sub_4010B9(v31, 0xAD25307F8E364B17LL);
  v33 = sub_4010B9(v32, 0x48A56D5AFE0DA4C2LL);
  v34 = sub_4010D2(v33, 6);
  v35 = sub_401259(v34, 6, 5);
  v36 = sub_40113E(v35, 11);
  v37 = sub_4011AA(v36);
  v38 = sub_4010B9(v37, 0x869365DB4C9F3CB6LL);
  v39 = sub_4011AA(v38);
  v40 = sub_40113E(v39, 2);
  v41 = sub_4010B9(v40, 0x4085AA8C0693425BLL);
  v42 = sub_4010D2(v41, 35);
  v43 = sub_4010D2(v42, 9);
  v44 = sub_401326(v43);
  v45 = sub_4010D2(v44, 7);
  v46 = sub_4010D2(v45, 38);
  v47 = sub_401326(v46);
  v48 = sub_4010B9(v47, 0xDEF2D72447EF4E1BLL);
  v49 = sub_4011AA(v48);
  v50 = sub_4011AA(v49);
  v51 = sub_401259(v50, 2, 7);
  v52 = sub_40113E(v51, 51);
  v53 = sub_4011AA(v52);
  v54 = sub_40113E(v53, 19);
  v55 = sub_4010B9(v54, 0x95DE49591A44EE21LL);
  v56 = sub_401326(v55);
  v57 = sub_4011AA(v56);
  return sub_40113E(v57, 16);
}

unsigned __int64  sub_401960(unsigned __int64 a1)
{
  __int64 v1; // rax@1
  unsigned __int64 v2; // rax@1
  __int64 v3; // rax@1
  __int64 v4; // rax@1
  unsigned __int64 v5; // rax@1
  unsigned __int64 v6; // rax@1
  __int64 v7; // rax@1
  __int64 v8; // rax@1
  unsigned __int64 v9; // rax@1
  unsigned __int64 v10; // rax@1
  __int64 v11; // rax@1
  __int64 v12; // rax@1
  unsigned __int64 v13; // rax@1
  unsigned __int64 v14; // rax@1
  unsigned __int64 v15; // rax@1
  unsigned __int64 v16; // rax@1
  __int64 v17; // rax@1
  __int64 v18; // rax@1
  unsigned __int64 v19; // rax@1
  unsigned __int64 v20; // rax@1
  __int64 v21; // rax@1
  unsigned __int64 v22; // rax@1
  unsigned __int64 v23; // rax@1
  __int64 v24; // rax@1
  __int64 v25; // rax@1
  unsigned __int64 v26; // rax@1
  __int64 v27; // rax@1
  unsigned __int64 v28; // rax@1
  __int64 v29; // rax@1
  __int64 v30; // rax@1
  __int64 v31; // rax@1
  unsigned __int64 v32; // rax@1
  unsigned __int64 v33; // rax@1
  __int64 v34; // rax@1
  __int64 v35; // rax@1
  unsigned __int64 v36; // rax@1
  unsigned __int64 v37; // rax@1
  unsigned __int64 v38; // rax@1
  unsigned __int64 v39; // rax@1
  unsigned __int64 v40; // rax@1
  unsigned __int64 v41; // rax@1
  unsigned __int64 v42; // rax@1
  __int64 v43; // rax@1
  __int64 v44; // rax@1
  unsigned __int64 v45; // rax@1
  unsigned __int64 v46; // rax@1
  unsigned __int64 v47; // rax@1
  unsigned __int64 v48; // rax@1
  __int64 v49; // rax@1
  __int64 v50; // rax@1
  unsigned __int64 v51; // rax@1

  v1 = sub_4010D2(a1, 22);
  v2 = sub_4011AA(v1);
  v3 = sub_401259(v2, 4, 1);
  v4 = sub_4011AA(v3);
  v5 = sub_401326(v4);
  v6 = sub_4010D2(v5, 35);
  v7 = sub_401259(v6, 2, 6);
  v8 = sub_4010B9(v7, 0x80A9EA4F90944FEALL);
  v9 = sub_4010D2(v8, 3);
  v10 = sub_401259(v9, 0, 1);
  v11 = sub_401259(v10, 1, 2);
  v12 = sub_4011AA(v11);
  v13 = sub_401326(v12);
  v14 = sub_401259(v13, 5, 1);
  v15 = sub_40113E(v14, 24);
  v16 = sub_4010D2(v15, 39);
  v17 = sub_401259(v16, 2, 4);
  v18 = sub_4010B9(v17, 0x678E70A16230A437LL);
  v19 = sub_401259(v18, 4, 3);
  v20 = sub_401259(v19, 0, 7);
  v21 = sub_4010D2(v20, 62);
  v22 = sub_4011AA(v21);
  v23 = sub_401259(v22, 7, 6);
  v24 = sub_401259(v23, 2, 6);
  v25 = sub_4011AA(v24);
  v26 = sub_401326(v25);
  v27 = sub_401259(v26, 5, 2);
  v28 = sub_401326(v27);
  v29 = sub_401259(v28, 1, 7);
  v30 = sub_4010B9(v29, 0x41EA5CF418A918E7LL);
  v31 = sub_4011AA(v30);
  v32 = sub_401326(v31);
  v33 = sub_401259(v32, 1, 4);
  v34 = sub_4010D2(v33, 10);
  v35 = sub_4011AA(v34);
  v36 = sub_4011AA(v35);
  v37 = sub_40113E(v36, 24);
  v38 = sub_401259(v37, 0, 4);
  v39 = sub_40113E(v38, 61);
  v40 = sub_401259(v39, 3, 4);
  v41 = sub_40113E(v40, 35);
  v42 = sub_4010D2(v41, 55);
  v43 = sub_4010D2(v42, 34);
  v44 = sub_401326(v43);
  v45 = sub_401326(v44);
  v46 = sub_40113E(v45, 23);
  v47 = sub_4010D2(v46, 59);
  v48 = sub_40113E(v47, 20);
  v49 = sub_4010D2(v48, 28);
  v50 = sub_4010B9(v49, 0xC26499379C0927CDLL);
  v51 = sub_401326(v50);
  return sub_40113E(v51, 13);
}

unsigned __int64  sub_401DC5(unsigned __int64 a1)
{
  unsigned __int64 v1; // rax@1
  unsigned __int64 v2; // rax@1
  unsigned __int64 v3; // rax@1
  unsigned __int64 v4; // rax@1
  __int64 v5; // rax@1
  __int64 v6; // rax@1
  unsigned __int64 v7; // rax@1
  __int64 v8; // rax@1
  unsigned __int64 v9; // rax@1
  unsigned __int64 v10; // rax@1
  unsigned __int64 v11; // rax@1
  __int64 v12; // rax@1
  __int64 v13; // rax@1
  __int64 v14; // rax@1
  unsigned __int64 v15; // rax@1
  unsigned __int64 v16; // rax@1
  unsigned __int64 v17; // rax@1
  unsigned __int64 v18; // rax@1
  unsigned __int64 v19; // rax@1
  __int64 v20; // rax@1
  unsigned __int64 v21; // rax@1
  unsigned __int64 v22; // rax@1
  unsigned __int64 v23; // rax@1
  __int64 v24; // rax@1
  unsigned __int64 v25; // rax@1
  __int64 v26; // rax@1
  unsigned __int64 v27; // rax@1
  __int64 v28; // rax@1
  __int64 v29; // rax@1
  unsigned __int64 v30; // rax@1
  unsigned __int64 v31; // rax@1
  unsigned __int64 v32; // rax@1
  __int64 v33; // rax@1
  __int64 v34; // rax@1
  __int64 v35; // rax@1
  __int64 v36; // rax@1
  __int64 v37; // rax@1
  unsigned __int64 v38; // rax@1
  unsigned __int64 v39; // rax@1
  unsigned __int64 v40; // rax@1
  unsigned __int64 v41; // rax@1
  __int64 v42; // rax@1
  __int64 v43; // rax@1
  __int64 v44; // rax@1
  __int64 v45; // rax@1
  __int64 v46; // rax@1
  unsigned __int64 v47; // rax@1
  __int64 v48; // rax@1
  unsigned __int64 v49; // rax@1
  unsigned __int64 v50; // rax@1
  __int64 v51; // rax@1

  v1 = sub_4010D2(a1, 18);
  v2 = sub_4010D2(v1, 29);
  v3 = sub_401259(v2, 5, 3);
  v4 = sub_401259(v3, 0, 7);
  v5 = sub_4010D2(v4, 18);
  v6 = sub_4010B9(v5, 0xC9AB604BB92038ADLL);
  v7 = sub_40113E(v6, 33);
  v8 = sub_401259(v7, 0, 4);
  v9 = sub_401326(v8);
  v10 = sub_401259(v9, 6, 2);
  v11 = sub_40113E(v10, 13);
  v12 = sub_40113E(v11, 20);
  v13 = sub_4010B9(v12, 0x58609BE21EB37866LL);
  v14 = sub_401326(v13);
  v15 = sub_4011AA(v14);
  v16 = sub_40113E(v15, 46);
  v17 = sub_401259(v16, 2, 3);
  v18 = sub_40113E(v17, 44);
  v19 = sub_40113E(v18, 3);
  v20 = sub_401259(v19, 4, 3);
  v21 = sub_401326(v20);
  v22 = sub_401259(v21, 7, 6);
  v23 = sub_40113E(v22, 59);
  v24 = sub_40113E(v23, 38);
  v25 = sub_4011AA(v24);
  v26 = sub_401259(v25, 1, 5);
  v27 = sub_4011AA(v26);
  v28 = sub_4010D2(v27, 27);
  v29 = sub_4010B9(v28, 0xBED577A97EB7966FLL);
  v30 = sub_40113E(v29, 14);
  v31 = sub_4010D2(v30, 7);
  v32 = sub_4010D2(v31, 18);
  v33 = sub_4010D2(v32, 57);
  v34 = sub_4010B9(v33, 0xB44427BE7889C31BLL);
  v35 = sub_4010B9(v34, 0xCE745C65ABECB66LL);
  v36 = sub_4010B9(v35, 0x94B1608ADB7F7221LL);
  v37 = sub_4010B9(v36, 0x85BEF139817EBC4ALL);
  v38 = sub_401259(v37, 5, 1);
  v39 = sub_4010D2(v38, 20);
  v40 = sub_4010D2(v39, 24);
  v41 = sub_40113E(v40, 46);
  v42 = sub_40113E(v41, 13);
  v43 = sub_4010B9(v42, 0xC95E5C35034B9775LL);
  v44 = sub_4010D2(v43, 7);
  v45 = sub_4010B9(v44, 0x8E60900383FA5EALL);
  v46 = sub_4010B9(v45, 0x59D5BCBF8B0CC9FDLL);
  v47 = sub_401326(v46);
  v48 = sub_401259(v47, 4, 7);
  v49 = sub_401326(v48);
  v50 = sub_40113E(v49, 22);
  v51 = sub_40113E(v50, 50);
  return sub_401326(v51);
}

unsigned __int64  sub_402252(unsigned __int64 a1)
{
  unsigned __int64 v1; // rax@1
  unsigned __int64 v2; // rax@1
  unsigned __int64 v3; // rax@1
  __int64 v4; // rax@1
  __int64 v5; // rax@1
  unsigned __int64 v6; // rax@1
  __int64 v7; // rax@1
  __int64 v8; // rax@1
  __int64 v9; // rax@1
  unsigned __int64 v10; // rax@1
  __int64 v11; // rax@1
  unsigned __int64 v12; // rax@1
  unsigned __int64 v13; // rax@1
  __int64 v14; // rax@1
  __int64 v15; // rax@1
  __int64 v16; // rax@1
  __int64 v17; // rax@1
  __int64 v18; // rax@1
  __int64 v19; // rax@1
  __int64 v20; // rax@1
  __int64 v21; // rax@1
  __int64 v22; // rax@1
  unsigned __int64 v23; // rax@1
  __int64 v24; // rax@1
  __int64 v25; // rax@1
  unsigned __int64 v26; // rax@1
  __int64 v27; // rax@1
  __int64 v28; // rax@1
  unsigned __int64 v29; // rax@1
  unsigned __int64 v30; // rax@1
  __int64 v31; // rax@1
  unsigned __int64 v32; // rax@1
  unsigned __int64 v33; // rax@1
  __int64 v34; // rax@1
  __int64 v35; // rax@1
  __int64 v36; // rax@1
  __int64 v37; // rax@1
  __int64 v38; // rax@1
  unsigned __int64 v39; // rax@1
  unsigned __int64 v40; // rax@1
  __int64 v41; // rax@1
  unsigned __int64 v42; // rax@1
  __int64 v43; // rax@1
  __int64 v44; // rax@1
  __int64 v45; // rax@1
  __int64 v46; // rax@1
  __int64 v47; // rax@1
  unsigned __int64 v48; // rax@1
  unsigned __int64 v49; // rax@1
  __int64 v50; // rax@1
  __int64 v51; // rax@1
  __int64 v52; // rax@1

  v1 = sub_401259(a1, 1, 7);
  v2 = sub_4010D2(v1, 6);
  v3 = sub_401259(v2, 2, 5);
  v4 = sub_40113E(v3, 57);
  v5 = sub_4010B9(v4, 0xC852FA4047662CELL);
  v6 = sub_401259(v5, 5, 1);
  v7 = sub_4010D2(v6, 1);
  v8 = sub_401326(v7);
  v9 = sub_4010B9(v8, 0x5DDFC2422C2A449ELL);
  v10 = sub_401326(v9);
  v11 = sub_4010D2(v10, 6);
  v12 = sub_401326(v11);
  v13 = sub_4010D2(v12, 33);
  v14 = sub_40113E(v13, 25);
  v15 = sub_401326(v14);
  v16 = sub_4010B9(v15, 0xA94A4C87A942C60LL);
  v17 = sub_401259(v16, 6, 2);
  v18 = sub_401326(v17);
  v19 = sub_4010B9(v18, 0xCC508FA31A0DA5ABLL);
  v20 = sub_4010B9(v19, 0x880218B9F910DCBCLL);
  v21 = sub_401326(v20);
  v22 = sub_4010B9(v21, 0x85D7E666ECDBA611LL);
  v23 = sub_40113E(v22, 8);
  v24 = sub_40113E(v23, 43);
  v25 = sub_4010B9(v24, 0x633A915BD59AC97BLL);
  v26 = sub_401259(v25, 3, 1);
  v27 = sub_401259(v26, 5, 7);
  v28 = sub_4011AA(v27);
  v29 = sub_401326(v28);
  v30 = sub_40113E(v29, 59);
  v31 = sub_40113E(v30, 10);
  v32 = sub_401326(v31);
  v33 = sub_401259(v32, 2, 1);
  v34 = sub_401259(v33, 7, 2);
  v35 = sub_401326(v34);
  v36 = sub_4010B9(v35, 0x648FFF323D235735LL);
  v37 = sub_4010B9(v36, 0xFC9F8D635FD85EB3LL);
  v38 = sub_4010B9(v37, 0xFF651571C16E5CB3LL);
  v39 = sub_401259(v38, 2, 4);
  v40 = sub_401259(v39, 5, 4);
  v41 = sub_40113E(v40, 11);
  v42 = sub_401326(v41);
  v43 = sub_4010D2(v42, 39);
  v44 = sub_4011AA(v43);
  v45 = sub_401326(v44);
  v46 = sub_4010B9(v45, 0xC798D4E5C0E97B1CLL);
  v47 = sub_4011AA(v46);
  v48 = sub_401326(v47);
  v49 = sub_4010D2(v48, 35);
  v50 = sub_401259(v49, 3, 5);
  v51 = sub_401326(v50);
  v52 = sub_4011AA(v51);
  return sub_401326(v52);
}

__int64 Check(char *input)
{
  unsigned __int64 v2; // ST20_8@18
  unsigned __int64 v3; // ST28_8@18
  unsigned __int64 v4; // ST30_8@18
  signed int i; // [sp+14h] [bp-2Ch]@1

  // read(0, input, 32);
  // replace with klee symbolic
  klee_make_symbolic(input, 32, "input");

  for ( i = 0; i <= 31; ++i )
  {
    //if ( (input[i] <= '@' || input[i] > 'z') && input[i] != ' ' )
    //  return 0LL;
    //if ( input[i] == ']' )
    //  return 0LL;
    //if ( input[i] == '\\' )
    //  return 0LL;
    //if ( input[i] == '^' )
    //  return 0LL;
    //if ( input[i] == '`' )
    //  return 0LL;
    //if ( input[i] == '[' )
    //  return 0LL;

    // replace with klee constraint
    klee_assume( input[i] >= ' ' );
    klee_assume( input[i] <= 'z' );
    klee_assume( input[i] != ']' );
    klee_assume( input[i] != '\\' );
    klee_assume( input[i] != '^' );
    klee_assume( input[i] != '`' );
    klee_assume( input[i] != '[' );
    klee_assume( ((input[i] >= 'A') & (input[i] < 'z')) | input[i] == ' ' ) ;
  }
  v2 = sub_401464(*(_QWORD *)input);
  v3 = sub_401960(*((_QWORD *)input + 1));
  v4 = sub_401DC5(*((_QWORD *)input + 2));
  return (sub_402252(*((_QWORD *)input + 3)) ^ v4 ^ v2 ^ v3) == 0xB101124831C0110ALL;
}

int main(int argc, const char **argv, const char **envp)
{
  int result; // eax@3
  char buf[32]; // [sp+10h] [bp-30h]@1

  if ( Check(buf) )
    klee_assert(0); // PrintFlag();
  result = 0;
  return result;
}
