#pragma once

//TCHAR GetClassicKaisaChar(TCHAR cPlainChar,int nKey);

CString ClassicDaihuanEncrypt(CString strPlainText,CString strAlphabetList);

CString ClassicDaihuanDecrypt(CString strCipherText,CString strAlphabetList);