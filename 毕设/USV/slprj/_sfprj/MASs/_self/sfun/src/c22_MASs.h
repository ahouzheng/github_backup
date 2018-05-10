#ifndef __c22_MASs_h__
#define __c22_MASs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stdlib.h>
#include "lapacke.h"
#ifndef typedef_SFc22_MASsInstanceStruct
#define typedef_SFc22_MASsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c22_sfEvent;
  boolean_T c22_isStable;
  boolean_T c22_doneDoubleBufferReInit;
  uint8_T c22_is_active_c22_MASs;
  real_T *c22_n;
  real_T *c22_Xp;
  real_T *c22_sita;
  real_T *c22_Yp;
  real_T *c22_Np;
  real_T *c22_u;
  real_T *c22_v;
} SFc22_MASsInstanceStruct;

#endif                                 /*typedef_SFc22_MASsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c22_MASs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c22_MASs_get_check_sum(mxArray *plhs[]);
extern void c22_MASs_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
