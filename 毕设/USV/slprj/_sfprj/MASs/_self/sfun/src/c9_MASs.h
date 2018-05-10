#ifndef __c9_MASs_h__
#define __c9_MASs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_MASsInstanceStruct
#define typedef_SFc9_MASsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_MASs;
  real_T *c9_B;
  real_T *c9_Xs;
  real_T *c9_d;
  real_T *c9_L;
  real_T *c9_Cb;
  real_T *c9_m;
  real_T *c9_Ys;
  real_T *c9_Ns;
  real_T *c9_u;
  real_T *c9_v;
  real_T *c9_r;
} SFc9_MASsInstanceStruct;

#endif                                 /*typedef_SFc9_MASsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_MASs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_MASs_get_check_sum(mxArray *plhs[]);
extern void c9_MASs_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
