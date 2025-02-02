/* Include files */

#include "Ex3EMT_cgxe.h"
#include "m_dCPOFtT6tl0tahhA1iZ8uB.h"

unsigned int cgxe_Ex3EMT_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 2560978958 &&
      ssGetChecksum1(S) == 1326552260 &&
      ssGetChecksum2(S) == 3348400077 &&
      ssGetChecksum3(S) == 3217491289) {
    method_dispatcher_dCPOFtT6tl0tahhA1iZ8uB(S, method, data);
    return 1;
  }

  return 0;
}
