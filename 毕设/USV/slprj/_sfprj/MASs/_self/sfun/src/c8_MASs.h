#ifndef __c8_MASs_h__
#define __c8_MASs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stdlib.h>
#include "lapacke.h"
#ifndef typedef_SFc8_MASsInstanceStruct
#define typedef_SFc8_MASsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_isStable;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_MASs;
  real_T *c8_n;
  real_T *c8_Xp;
  real_T *c8_sita;
  real_T *c8_Yp;
  real_T *c8_Np;
  real_T *c8_u;
  real_T *c8_v;
} SFc8_MASsInstanceStruct;

#endif                                 /*typedef_SFc8_MASsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_MASs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_MASs_get_check_sum(mxArray *plhs[]);
extern void c8_MASs_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
