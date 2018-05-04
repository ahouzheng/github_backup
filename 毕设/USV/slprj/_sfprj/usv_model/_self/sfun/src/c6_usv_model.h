#ifndef __c6_usv_model_h__
#define __c6_usv_model_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stdlib.h>
#include "lapacke.h"
#ifndef typedef_SFc6_usv_modelInstanceStruct
#define typedef_SFc6_usv_modelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_usv_model;
  real_T *c6_n;
  real_T *c6_Xp;
  real_T *c6_sita;
  real_T *c6_Yp;
  real_T *c6_Np;
  real_T *c6_u;
  real_T *c6_v;
} SFc6_usv_modelInstanceStruct;

#endif                                 /*typedef_SFc6_usv_modelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_usv_model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_usv_model_get_check_sum(mxArray *plhs[]);
extern void c6_usv_model_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
