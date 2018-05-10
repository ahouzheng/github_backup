#ifndef __c30_MASs_h__
#define __c30_MASs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc30_MASsInstanceStruct
#define typedef_SFc30_MASsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c30_sfEvent;
  boolean_T c30_isStable;
  boolean_T c30_doneDoubleBufferReInit;
  uint8_T c30_is_active_c30_MASs;
  real_T *c30_B;
  real_T *c30_Xs;
  real_T *c30_d;
  real_T *c30_L;
  real_T *c30_Cb;
  real_T *c30_m;
  real_T *c30_Ys;
  real_T *c30_Ns;
  real_T *c30_u;
  real_T *c30_v;
  real_T *c30_r;
} SFc30_MASsInstanceStruct;

#endif                                 /*typedef_SFc30_MASsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c30_MASs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c30_MASs_get_check_sum(mxArray *plhs[]);
extern void c30_MASs_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
