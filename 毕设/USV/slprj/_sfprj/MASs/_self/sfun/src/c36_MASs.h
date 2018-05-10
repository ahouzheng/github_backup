#ifndef __c36_MASs_h__
#define __c36_MASs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stdlib.h>
#include "lapacke.h"
#ifndef typedef_SFc36_MASsInstanceStruct
#define typedef_SFc36_MASsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c36_sfEvent;
  boolean_T c36_isStable;
  boolean_T c36_doneDoubleBufferReInit;
  uint8_T c36_is_active_c36_MASs;
  real_T *c36_n;
  real_T *c36_Xp;
  real_T *c36_sita;
  real_T *c36_Yp;
  real_T *c36_Np;
  real_T *c36_u;
  real_T *c36_v;
} SFc36_MASsInstanceStruct;

#endif                                 /*typedef_SFc36_MASsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c36_MASs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c36_MASs_get_check_sum(mxArray *plhs[]);
extern void c36_MASs_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
