#ifndef __c37_MASs_h__
#define __c37_MASs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc37_MASsInstanceStruct
#define typedef_SFc37_MASsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c37_sfEvent;
  boolean_T c37_isStable;
  boolean_T c37_doneDoubleBufferReInit;
  uint8_T c37_is_active_c37_MASs;
  real_T *c37_B;
  real_T *c37_Xs;
  real_T *c37_d;
  real_T *c37_L;
  real_T *c37_Cb;
  real_T *c37_m;
  real_T *c37_Ys;
  real_T *c37_Ns;
  real_T *c37_u;
  real_T *c37_v;
  real_T *c37_r;
} SFc37_MASsInstanceStruct;

#endif                                 /*typedef_SFc37_MASsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c37_MASs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c37_MASs_get_check_sum(mxArray *plhs[]);
extern void c37_MASs_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
