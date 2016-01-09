#pragma once


#include <wincrypt.h>

DWORD GetHash(LPCTSTR FileDirectory, ALG_ID algId, LPTSTR pszHash);