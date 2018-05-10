#ifndef __c15_MASs_h__
#define __c15_MASs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stdlib.h>
#include "lapacke.h"
#ifndef typedef_SFc15_MASsInstanceStruct
#define typedef_SFc15_MASsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_isStable;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_MASs;
  real_T *c15_n;
  real_T *c15_Xp;
  real_T *c15_sita;
  real_T *c15_Yp;
  real_T *c15_Np;
  real_T *c15_u;
  real_T *c15_v;
} SFc15_MASsInstanceStruct;

#endif                                 /*typedef_SFc15_MASsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_MASs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_MASs_get_check_sum(mxArray *plhs[]);
extern void c15_MASs_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
