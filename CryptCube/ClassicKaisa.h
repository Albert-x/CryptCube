#pragma once

TCHAR GetClassicKaisaChar(TCHAR cPlainChar,int nKey);

CString ClassicKaisaEncrypt(CString strPlainText,int nKey);

CString ClassicKaisaDecrypt(CString strCipherText,int nKey);
