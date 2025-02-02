/* Include files */

#include "Exe30x2E1_cgxe.h"
#include "m_raCHpldexqYpqn6pvJMu3D.h"

unsigned int cgxe_Exe30x2E1_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 2912969227 &&
      ssGetChecksum1(S) == 1360765808 &&
      ssGetChecksum2(S) == 1201034380 &&
      ssGetChecksum3(S) == 231009272) {
    method_dispatcher_raCHpldexqYpqn6pvJMu3D(S, method, data);
    return 1;
  }

  return 0;
}
