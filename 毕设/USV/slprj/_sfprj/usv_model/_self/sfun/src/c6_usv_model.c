/* Include files */

#include <stddef.h>
#include "blas.h"
#include "usv_model_sfun.h"
#include "c6_usv_model.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "usv_model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[30] = { "Q", "A", "beita", "C", "g",
  "np", "Aj", "Ain", "Aw", "Ein", "En", "E0", "h", "Xt", "Vs", "p", "q", "r",
  "V", "Vj", "i", "nargin", "nargout", "n", "sita", "u", "v", "Xp", "Yp", "Np" };

/* Function Declarations */
static void initialize_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance);
static void initialize_params_c6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance);
static void enable_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance);
static void disable_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance);
static void set_sim_state_c6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance);
static void sf_gateway_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance);
static void mdl_start_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance);
static void c6_chartstep_c6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance);
static void initSimStructsc6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_Np, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, creal_T
  c6_inData_data[], int32_T *c6_inData_sizes);
static void c6_c_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_u, const emlrtMsgIdentifier *c6_parentId, creal_T
  c6_y_data[], int32_T *c6_y_sizes);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, creal_T c6_outData_data[],
  int32_T *c6_outData_sizes);
static real_T c6_rdivide(SFc6_usv_modelInstanceStruct *chartInstance, real_T
  c6_x, real_T c6_y);
static real_T c6_mpower(SFc6_usv_modelInstanceStruct *chartInstance, real_T c6_a);
static void c6_scalarEg(SFc6_usv_modelInstanceStruct *chartInstance);
static void c6_dimagree(SFc6_usv_modelInstanceStruct *chartInstance);
static boolean_T c6_fltpower_domain_error(SFc6_usv_modelInstanceStruct
  *chartInstance, real_T c6_a, real_T c6_b);
static void c6_error(SFc6_usv_modelInstanceStruct *chartInstance);
static real_T c6_b_mpower(SFc6_usv_modelInstanceStruct *chartInstance, real_T
  c6_a);
static real_T c6_sqrt(SFc6_usv_modelInstanceStruct *chartInstance, real_T c6_x);
static void c6_b_error(SFc6_usv_modelInstanceStruct *chartInstance);
static void c6_roots(SFc6_usv_modelInstanceStruct *chartInstance, real_T c6_c[4],
                     creal_T c6_r_data[], int32_T *c6_r_sizes);
static boolean_T c6_isfinite(SFc6_usv_modelInstanceStruct *chartInstance, real_T
  c6_x);
static void c6_c_error(SFc6_usv_modelInstanceStruct *chartInstance);
static real_T c6_abs(SFc6_usv_modelInstanceStruct *chartInstance, real_T c6_x);
static void c6_check_forloop_overflow_error(SFc6_usv_modelInstanceStruct
  *chartInstance, boolean_T c6_overflow);
static void c6_eig(SFc6_usv_modelInstanceStruct *chartInstance, creal_T
                   c6_A_data[], int32_T c6_A_sizes[2], creal_T c6_V_data[],
                   int32_T *c6_V_sizes);
static void c6_d_error(SFc6_usv_modelInstanceStruct *chartInstance);
static void c6_e_error(SFc6_usv_modelInstanceStruct *chartInstance, int32_T
  c6_varargin_2);
static void c6_warning(SFc6_usv_modelInstanceStruct *chartInstance);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_d_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_e_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_usv_model, const char_T *c6_identifier);
static uint8_T c6_f_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sqrt(SFc6_usv_modelInstanceStruct *chartInstance, real_T *c6_x);
static void init_dsm_address_info(SFc6_usv_modelInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc6_usv_modelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc6_usv_model(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_usv_model = 0U;
}

static void initialize_params_c6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_u;
  const mxArray *c6_c_y = NULL;
  real_T c6_c_hoistedGlobal;
  real_T c6_d_u;
  const mxArray *c6_d_y = NULL;
  uint8_T c6_d_hoistedGlobal;
  uint8_T c6_e_u;
  const mxArray *c6_e_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(4, 1), false);
  c6_hoistedGlobal = *chartInstance->c6_Np;
  c6_b_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = *chartInstance->c6_Xp;
  c6_c_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_c_hoistedGlobal = *chartInstance->c6_Yp;
  c6_d_u = c6_c_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_d_hoistedGlobal = chartInstance->c6_is_active_c6_usv_model;
  c6_e_u = c6_d_hoistedGlobal;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_b_u;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_b_u = sf_mex_dup(c6_st);
  *chartInstance->c6_Np = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Np", c6_b_u, 0)), "Np");
  *chartInstance->c6_Xp = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Xp", c6_b_u, 1)), "Xp");
  *chartInstance->c6_Yp = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Yp", c6_b_u, 2)), "Yp");
  chartInstance->c6_is_active_c6_usv_model = c6_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c6_usv_model", c6_b_u, 3)),
    "is_active_c6_usv_model");
  sf_mex_destroy(&c6_b_u);
  c6_update_debugger_state_c6_usv_model(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_v, 3U, 1U, 0U,
                        chartInstance->c6_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_u, 2U, 1U, 0U,
                        chartInstance->c6_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_sita, 1U, 1U, 0U,
                        chartInstance->c6_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_n, 0U, 1U, 0U,
                        chartInstance->c6_sfEvent, false);
  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_usv_model(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_usv_modelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_Xp, 4U, 1U, 0U,
                        chartInstance->c6_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_Yp, 5U, 1U, 0U,
                        chartInstance->c6_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_Np, 6U, 1U, 0U,
                        chartInstance->c6_sfEvent, false);
}

static void mdl_start_c6_usv_model(SFc6_usv_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_chartstep_c6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  real_T c6_d_hoistedGlobal;
  real_T c6_b_n;
  real_T c6_b_sita;
  real_T c6_b_u;
  real_T c6_b_v;
  uint32_T c6_debug_family_var_map[30];
  real_T c6_Q;
  real_T c6_A;
  real_T c6_beita;
  real_T c6_C;
  real_T c6_g;
  real_T c6_np;
  real_T c6_Aj;
  real_T c6_Ain;
  real_T c6_Aw;
  real_T c6_Ein;
  real_T c6_En;
  real_T c6_E0;
  real_T c6_h;
  real_T c6_Xt;
  real_T c6_Vs;
  real_T c6_p;
  real_T c6_q;
  real_T c6_r;
  int32_T c6_V_sizes;
  creal_T c6_V_data[3];
  real_T c6_Vj;
  real_T c6_i;
  real_T c6_nargin = 4.0;
  real_T c6_nargout = 3.0;
  real_T c6_b_Xp;
  real_T c6_b_Yp;
  real_T c6_b_Np;
  real_T c6_b_A;
  real_T c6_c_A;
  real_T c6_y;
  real_T c6_d_A;
  real_T c6_b_y;
  real_T c6_a;
  real_T c6_b_a;
  real_T c6_c_a;
  real_T c6_x;
  real_T c6_d_a;
  real_T c6_ar;
  real_T c6_c;
  real_T c6_dv0[4];
  int32_T c6_tmp_sizes;
  creal_T c6_tmp_data[3];
  int32_T c6_loop_ub;
  int32_T c6_i0;
  real_T c6_d0;
  int32_T c6_i1;
  int32_T c6_b_i;
  real_T c6_d1;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_e_x;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *chartInstance->c6_n;
  c6_b_hoistedGlobal = *chartInstance->c6_sita;
  c6_c_hoistedGlobal = *chartInstance->c6_u;
  c6_d_hoistedGlobal = *chartInstance->c6_v;
  c6_b_n = c6_hoistedGlobal;
  c6_b_sita = c6_b_hoistedGlobal;
  c6_b_u = c6_c_hoistedGlobal;
  c6_b_v = c6_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 30U, 30U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_Q, 0U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_A, 1U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_beita, 2U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_C, 3U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_g, 4U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_np, 5U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_Aj, 6U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_Ain, 7U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_Aw, 8U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_Ein, 9U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_En, 10U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_E0, 11U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h, 12U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_Xt, 13U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_Vs, 14U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_p, 15U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_q, 16U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_r, 17U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c6_V_data, (const int32_T *)
    &c6_V_sizes, NULL, 0, 18, (void *)c6_b_sf_marshallOut, (void *)
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_Vj, 19U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i, 20U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 21U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 22U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_b_n, 23U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_b_sita, 24U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_b_u, 25U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_b_v, 26U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_Xp, 27U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_Yp, 28U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_Np, 29U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_Q = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_A = 0.95;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_beita = 0.9025;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_C = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_g = 9.8;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_np = 0.8;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_Aj = 0.049087385212340517;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
  c6_Ain = 0.83200000000000007;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 11);
  c6_Aw = 0.78539816339744828;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 12);
  c6_Ein = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
  c6_En = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 14);
  c6_E0 = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 15);
  c6_h = 0.6;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 17);
  c6_Xt = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 19);
  c6_b_A = c6_b_sita * 3.1415926535897931;
  c6_b_sita = c6_rdivide(chartInstance, c6_b_A, 180.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 20);
  c6_Vs = c6_b_mpower(chartInstance, c6_mpower(chartInstance, c6_b_u) +
                      c6_mpower(chartInstance, c6_b_v));
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 21);
  c6_p = 25.036379540825354;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 22);
  c6_c_A = 0.9025 * c6_mpower(chartInstance, c6_Vs);
  c6_y = c6_rdivide(chartInstance, c6_c_A, 19.6);
  c6_q = 481.05637508093707 * (0.6 - c6_y);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 23);
  c6_d_A = c6_b_n;
  c6_b_y = c6_rdivide(chartInstance, c6_d_A, 1000.0);
  c6_a = c6_b_y;
  c6_b_a = c6_a;
  c6_c_a = c6_b_a;
  c6_x = c6_c_a;
  c6_d_a = c6_x;
  c6_ar = c6_d_a;
  c6_c = muDoubleScalarPower(c6_ar, 3.0);
  if (c6_fltpower_domain_error(chartInstance, c6_c_a, 3.0)) {
    c6_error(chartInstance);
  }

  c6_r = -10.0 * c6_c * 0.8;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 28);
  c6_dv0[0] = 25.036379540825354;
  c6_dv0[1] = 0.0;
  c6_dv0[2] = c6_q;
  c6_dv0[3] = c6_r;
  c6_roots(chartInstance, c6_dv0, c6_tmp_data, &c6_tmp_sizes);
  c6_V_sizes = c6_tmp_sizes;
  c6_loop_ub = c6_tmp_sizes - 1;
  for (c6_i0 = 0; c6_i0 <= c6_loop_ub; c6_i0++) {
    c6_V_data[c6_i0] = c6_tmp_data[c6_i0];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 29);
  c6_Vj = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 31);
  c6_d0 = (real_T)c6_V_sizes;
  c6_i1 = (int32_T)c6_d0 - 1;
  c6_i = 1.0;
  c6_b_i = 0;
  while (c6_b_i <= c6_i1) {
    c6_i = 1.0 + (real_T)c6_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 32);
    if (c6_fltpower_domain_error(chartInstance, 10.0, -10.0)) {
      c6_error(chartInstance);
    }

    c6_d1 = c6_V_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 868, 4, MAX_uint32_T, (int32_T)c6_i, 1, c6_V_sizes)
      - 1].im;
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c6_d1, 1.0E-10, -1, 2U,
          c6_d1 < 1.0E-10))) {
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 33);
      c6_Vj = c6_V_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 903, 4, MAX_uint32_T, (int32_T)c6_i, 1, c6_V_sizes)
        - 1].re;
    }

    c6_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 36);
  c6_b_x = c6_b_sita;
  c6_c_x = c6_b_x;
  c6_c_x = muDoubleScalarCos(c6_c_x);
  c6_b_Xp = 49.087385212340514 * c6_Vj * (c6_Vj - 0.95 * c6_Vs) * c6_c_x;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 37);
  c6_d_x = c6_b_sita;
  c6_e_x = c6_d_x;
  c6_e_x = muDoubleScalarSin(c6_e_x);
  c6_b_Yp = 49.087385212340514 * c6_Vj * (c6_Vj - 0.95 * c6_Vs) * c6_e_x;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 38);
  c6_b_Np = c6_b_Yp * 3.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -38);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c6_Xp = c6_b_Xp;
  *chartInstance->c6_Yp = c6_b_Yp;
  *chartInstance->c6_Np = c6_b_Np;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_usv_model(SFc6_usv_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  (void)c6_chartNumber;
  (void)c6_instanceNumber;
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_b_u;
  const mxArray *c6_y = NULL;
  SFc6_usv_modelInstanceStruct *chartInstance;
  chartInstance = (SFc6_usv_modelInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_b_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_Np, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Np), &c6_thisId);
  sf_mex_destroy(&c6_b_Np);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d2;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_b_u), &c6_d2, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d2;
  sf_mex_destroy(&c6_b_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_Np;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_usv_modelInstanceStruct *chartInstance;
  chartInstance = (SFc6_usv_modelInstanceStruct *)chartInstanceVoid;
  c6_b_Np = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Np), &c6_thisId);
  sf_mex_destroy(&c6_b_Np);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, creal_T
  c6_inData_data[], int32_T *c6_inData_sizes)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u_sizes;
  int32_T c6_loop_ub;
  int32_T c6_i2;
  creal_T c6_u_data[3];
  const mxArray *c6_y = NULL;
  SFc6_usv_modelInstanceStruct *chartInstance;
  chartInstance = (SFc6_usv_modelInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u_sizes = *c6_inData_sizes;
  c6_loop_ub = *c6_inData_sizes - 1;
  for (c6_i2 = 0; c6_i2 <= c6_loop_ub; c6_i2++) {
    c6_u_data[c6_i2] = c6_inData_data[c6_i2];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u_data, 0, 1U, 1U, 0U, 1,
    c6_u_sizes), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_c_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_u, const emlrtMsgIdentifier *c6_parentId, creal_T
  c6_y_data[], int32_T *c6_y_sizes)
{
  static uint32_T c6_uv0[1] = { 3U };

  uint32_T c6_uv1[1];
  static boolean_T c6_bv0[1] = { true };

  boolean_T c6_bv1[1];
  int32_T c6_tmp_sizes;
  creal_T c6_tmp_data[3];
  int32_T c6_loop_ub;
  int32_T c6_i3;
  (void)chartInstance;
  c6_uv1[0] = c6_uv0[0];
  c6_bv1[0] = c6_bv0[0];
  sf_mex_import_vs(c6_parentId, sf_mex_dup(c6_b_u), c6_tmp_data, 1, 0, 1U, 1, 0U,
                   1, c6_bv1, c6_uv1, &c6_tmp_sizes);
  *c6_y_sizes = c6_tmp_sizes;
  c6_loop_ub = c6_tmp_sizes - 1;
  for (c6_i3 = 0; c6_i3 <= c6_loop_ub; c6_i3++) {
    c6_y_data[c6_i3] = c6_tmp_data[c6_i3];
  }

  sf_mex_destroy(&c6_b_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, creal_T c6_outData_data[],
  int32_T *c6_outData_sizes)
{
  const mxArray *c6_V;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y_sizes;
  creal_T c6_y_data[3];
  int32_T c6_loop_ub;
  int32_T c6_i4;
  SFc6_usv_modelInstanceStruct *chartInstance;
  chartInstance = (SFc6_usv_modelInstanceStruct *)chartInstanceVoid;
  c6_V = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_V), &c6_thisId, c6_y_data,
                        &c6_y_sizes);
  sf_mex_destroy(&c6_V);
  *c6_outData_sizes = c6_y_sizes;
  c6_loop_ub = c6_y_sizes - 1;
  for (c6_i4 = 0; c6_i4 <= c6_loop_ub; c6_i4++) {
    c6_outData_data[c6_i4] = c6_y_data[c6_i4];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_usv_model_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static real_T c6_rdivide(SFc6_usv_modelInstanceStruct *chartInstance, real_T
  c6_x, real_T c6_y)
{
  real_T c6_b_x;
  real_T c6_b_y;
  (void)chartInstance;
  c6_b_x = c6_x;
  c6_b_y = c6_y;
  return c6_b_x / c6_b_y;
}

static real_T c6_mpower(SFc6_usv_modelInstanceStruct *chartInstance, real_T c6_a)
{
  real_T c6_c;
  real_T c6_b_a;
  real_T c6_c_a;
  real_T c6_x;
  real_T c6_d_a;
  c6_b_a = c6_a;
  c6_c_a = c6_b_a;
  c6_x = c6_c_a;
  c6_d_a = c6_x;
  c6_c = c6_d_a * c6_d_a;
  if (c6_fltpower_domain_error(chartInstance, c6_c_a, 2.0)) {
    c6_error(chartInstance);
  }

  return c6_c;
}

static void c6_scalarEg(SFc6_usv_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_dimagree(SFc6_usv_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c6_fltpower_domain_error(SFc6_usv_modelInstanceStruct
  *chartInstance, real_T c6_a, real_T c6_b)
{
  boolean_T c6_p;
  real_T c6_x;
  boolean_T c6_b_b;
  real_T c6_b_x;
  real_T c6_c_x;
  boolean_T c6_b0;
  boolean_T c6_b1;
  boolean_T guard1 = false;
  (void)chartInstance;
  c6_p = false;
  if (c6_a < 0.0) {
    c6_x = c6_b;
    c6_b_b = muDoubleScalarIsNaN(c6_x);
    guard1 = false;
    if (c6_b_b) {
      guard1 = true;
    } else {
      c6_b_x = c6_b;
      c6_c_x = c6_b_x;
      c6_c_x = muDoubleScalarFloor(c6_c_x);
      if (c6_c_x == c6_b) {
        guard1 = true;
      } else {
        c6_b0 = false;
      }
    }

    if (guard1 == true) {
      c6_b0 = true;
    }

    c6_b1 = !c6_b0;
    c6_p = c6_b1;
  }

  return c6_p;
}

static void c6_error(SFc6_usv_modelInstanceStruct *chartInstance)
{
  const mxArray *c6_y = NULL;
  static char_T c6_b_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c6_y));
}

static real_T c6_b_mpower(SFc6_usv_modelInstanceStruct *chartInstance, real_T
  c6_a)
{
  real_T c6_c;
  real_T c6_b_a;
  real_T c6_c_a;
  real_T c6_x;
  real_T c6_d_a;
  c6_b_a = c6_a;
  c6_c_a = c6_b_a;
  c6_x = c6_c_a;
  c6_d_a = c6_x;
  c6_c = c6_d_a;
  c6_b_sqrt(chartInstance, &c6_c);
  if (c6_fltpower_domain_error(chartInstance, c6_c_a, 0.5)) {
    c6_error(chartInstance);
  }

  return c6_c;
}

static real_T c6_sqrt(SFc6_usv_modelInstanceStruct *chartInstance, real_T c6_x)
{
  real_T c6_b_x;
  c6_b_x = c6_x;
  c6_b_sqrt(chartInstance, &c6_b_x);
  return c6_b_x;
}

static void c6_b_error(SFc6_usv_modelInstanceStruct *chartInstance)
{
  const mxArray *c6_y = NULL;
  static char_T c6_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c6_b_y = NULL;
  static char_T c6_c_u[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c6_y, 14, c6_b_y));
}

static void c6_roots(SFc6_usv_modelInstanceStruct *chartInstance, real_T c6_c[4],
                     creal_T c6_r_data[], int32_T *c6_r_sizes)
{
  boolean_T c6_p;
  int32_T c6_k;
  int32_T c6_b_k;
  int32_T c6_i5;
  int32_T c6_k1;
  int32_T c6_a;
  int32_T c6_k2;
  int32_T c6_b_a;
  int32_T c6_b;
  int32_T c6_nTrailingZeros;
  int32_T c6_c_a;
  int32_T c6_b_b;
  int32_T c6_companDim;
  int32_T c6_j;
  int32_T c6_d_a;
  int32_T c6_c_b;
  int32_T c6_b_c;
  real_T c6_A;
  real_T c6_B;
  real_T c6_y;
  real_T c6_ctmp[4];
  real_T c6_x;
  boolean_T c6_d_b;
  int32_T c6_e_a;
  int32_T c6_f_a;
  int32_T c6_g_a;
  boolean_T c6_b2;
  boolean_T c6_b3;
  boolean_T c6_b4;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_a_sizes[2];
  int32_T c6_h_a;
  int32_T c6_i_a;
  int32_T c6_loop_ub;
  int32_T c6_i8;
  creal_T c6_a_data[9];
  int32_T c6_j_a;
  int32_T c6_i9;
  int32_T c6_e_b;
  int32_T c6_f_b;
  boolean_T c6_overflow;
  int32_T c6_c_k;
  int32_T c6_d_k;
  int32_T c6_k_a;
  int32_T c6_c_c;
  static creal_T c6_dc0 = { 1.0, 0.0 };

  int32_T c6_b_nTrailingZeros;
  int32_T c6_g_b;
  int32_T c6_h_b;
  boolean_T c6_b_overflow;
  int32_T c6_e_k;
  static creal_T c6_dc1 = { 0.0, 0.0 };

  int32_T c6_b_a_sizes[2];
  int32_T c6_l_a;
  int32_T c6_m_a;
  int32_T c6_b_loop_ub;
  int32_T c6_i10;
  creal_T c6_b_a_data[9];
  int32_T c6_eiga_sizes;
  creal_T c6_eiga_data[3];
  int32_T c6_b_companDim;
  int32_T c6_i_b;
  int32_T c6_j_b;
  boolean_T c6_c_overflow;
  int32_T c6_f_k;
  int32_T c6_n_a;
  int32_T c6_k_b;
  int32_T c6_d_c;
  int32_T c6_o_a;
  int32_T c6_l_b;
  int32_T c6_nRoots;
  const mxArray *c6_b_y = NULL;
  static char_T c6_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  int32_T c6_i11;
  boolean_T c6_b5;
  boolean_T c6_b6;
  boolean_T c6_b7;
  int32_T c6_i12;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  c6_p = false;
  c6_k = 1;
  exitg5 = false;
  while ((exitg5 == false) && (c6_k < 5)) {
    c6_b_k = c6_k - 1;
    if (!c6_isfinite(chartInstance, c6_c[c6_b_k])) {
      c6_p = true;
      exitg5 = true;
    } else {
      c6_k++;
    }
  }

  if (c6_p) {
    c6_c_error(chartInstance);
  }

  *c6_r_sizes = 3;
  for (c6_i5 = 0; c6_i5 < 3; c6_i5++) {
    c6_r_data[c6_i5].re = 0.0;
    c6_r_data[c6_i5].im = 0.0;
  }

  c6_k1 = 1;
  exitg4 = false;
  while ((exitg4 == false) && (c6_k1 <= 4)) {
    if (c6_c[c6_k1 - 1] != 0.0) {
      exitg4 = true;
    } else {
      c6_a = c6_k1 + 1;
      c6_k1 = c6_a;
    }
  }

  c6_k2 = 4;
  exitg3 = false;
  while ((exitg3 == false) && (c6_k2 >= c6_k1)) {
    if (c6_c[c6_k2 - 1] != 0.0) {
      exitg3 = true;
    } else {
      c6_b_a = c6_k2 - 1;
      c6_k2 = c6_b_a;
    }
  }

  c6_b = c6_k2;
  c6_nTrailingZeros = 4 - c6_b;
  if (c6_k1 < c6_k2) {
    c6_c_a = c6_k2;
    c6_b_b = c6_k1;
    c6_companDim = c6_c_a - c6_b_b;
    exitg1 = false;
    while ((exitg1 == false) && (c6_companDim > 0)) {
      c6_j = 1;
      exitg2 = false;
      while ((exitg2 == false) && (c6_j <= c6_companDim)) {
        c6_d_a = c6_k1;
        c6_c_b = c6_j;
        c6_b_c = (c6_d_a + c6_c_b) - 1;
        c6_A = c6_c[c6_b_c];
        c6_B = c6_c[c6_k1 - 1];
        c6_y = c6_rdivide(chartInstance, c6_A, c6_B);
        c6_ctmp[c6_j - 1] = c6_y;
        c6_x = c6_abs(chartInstance, c6_ctmp[c6_j - 1]);
        c6_d_b = muDoubleScalarIsInf(c6_x);
        if (c6_d_b) {
          exitg2 = true;
        } else {
          c6_e_a = c6_j + 1;
          c6_j = c6_e_a;
        }
      }

      if (c6_j > c6_companDim) {
        exitg1 = true;
      } else {
        c6_f_a = c6_k1 + 1;
        c6_k1 = c6_f_a;
        c6_g_a = c6_companDim - 1;
        c6_companDim = c6_g_a;
      }
    }

    if (c6_companDim < 1) {
      c6_b2 = (1 > c6_nTrailingZeros);
      c6_b3 = c6_b2;
      c6_b4 = c6_b3;
      if (c6_b4) {
        c6_i6 = 0;
      } else {
        c6_i6 = c6_nTrailingZeros;
      }

      *c6_r_sizes = c6_i6;
    } else {
      c6_i7 = c6_companDim;
      c6_a_sizes[0] = c6_i7;
      c6_a_sizes[1] = c6_i7;
      c6_h_a = c6_a_sizes[0];
      c6_i_a = c6_a_sizes[1];
      c6_loop_ub = c6_i7 * c6_i7 - 1;
      for (c6_i8 = 0; c6_i8 <= c6_loop_ub; c6_i8++) {
        c6_a_data[c6_i8].re = 0.0;
        c6_a_data[c6_i8].im = 0.0;
      }

      c6_j_a = c6_companDim - 1;
      c6_i9 = c6_j_a;
      c6_e_b = c6_i9;
      c6_f_b = c6_e_b;
      if (1 > c6_f_b) {
        c6_overflow = false;
      } else {
        c6_overflow = (c6_f_b > 2147483646);
      }

      if (c6_overflow) {
        c6_check_forloop_overflow_error(chartInstance, true);
      }

      for (c6_c_k = 1; c6_c_k <= c6_i9; c6_c_k++) {
        c6_d_k = c6_c_k - 1;
        c6_a_data[c6_a_sizes[0] * c6_d_k].re = -c6_ctmp[c6_d_k];
        c6_a_data[c6_a_sizes[0] * c6_d_k].im = 0.0;
        c6_k_a = c6_d_k + 2;
        c6_c_c = c6_k_a - 1;
        c6_a_data[c6_c_c + c6_a_sizes[0] * c6_d_k] = c6_dc0;
      }

      c6_a_data[c6_a_sizes[0] * (c6_companDim - 1)].re = -c6_ctmp[c6_companDim -
        1];
      c6_a_data[c6_a_sizes[0] * (c6_companDim - 1)].im = 0.0;
      c6_b_nTrailingZeros = c6_nTrailingZeros;
      c6_g_b = c6_b_nTrailingZeros;
      c6_h_b = c6_g_b;
      if (1 > c6_h_b) {
        c6_b_overflow = false;
      } else {
        c6_b_overflow = (c6_h_b > 2147483646);
      }

      if (c6_b_overflow) {
        c6_check_forloop_overflow_error(chartInstance, true);
      }

      for (c6_e_k = 1; c6_e_k <= c6_b_nTrailingZeros; c6_e_k++) {
        c6_d_k = c6_e_k - 1;
        c6_r_data[c6_d_k] = c6_dc1;
      }

      c6_b_a_sizes[0] = c6_a_sizes[0];
      c6_b_a_sizes[1] = c6_a_sizes[1];
      c6_l_a = c6_b_a_sizes[0];
      c6_m_a = c6_b_a_sizes[1];
      c6_b_loop_ub = c6_a_sizes[0] * c6_a_sizes[1] - 1;
      for (c6_i10 = 0; c6_i10 <= c6_b_loop_ub; c6_i10++) {
        c6_b_a_data[c6_i10] = c6_a_data[c6_i10];
      }

      c6_eig(chartInstance, c6_b_a_data, c6_b_a_sizes, c6_eiga_data,
             &c6_eiga_sizes);
      c6_b_companDim = c6_companDim;
      c6_i_b = c6_b_companDim;
      c6_j_b = c6_i_b;
      if (1 > c6_j_b) {
        c6_c_overflow = false;
      } else {
        c6_c_overflow = (c6_j_b > 2147483646);
      }

      if (c6_c_overflow) {
        c6_check_forloop_overflow_error(chartInstance, true);
      }

      for (c6_f_k = 1; c6_f_k <= c6_b_companDim; c6_f_k++) {
        c6_d_k = c6_f_k;
        c6_n_a = c6_d_k;
        c6_k_b = c6_nTrailingZeros;
        c6_d_c = (c6_n_a + c6_k_b) - 1;
        c6_r_data[c6_d_c] = c6_eiga_data[c6_d_k - 1];
      }

      c6_o_a = c6_nTrailingZeros;
      c6_l_b = c6_companDim;
      c6_nRoots = c6_o_a + c6_l_b;
      if (c6_nRoots <= 4) {
      } else {
        c6_b_y = NULL;
        sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c6_b_y));
      }

      c6_i11 = c6_nRoots;
      *c6_r_sizes = c6_i11;
    }
  } else {
    c6_b5 = (1 > c6_nTrailingZeros);
    c6_b6 = c6_b5;
    c6_b7 = c6_b6;
    if (c6_b7) {
      c6_i12 = 0;
    } else {
      c6_i12 = c6_nTrailingZeros;
    }

    *c6_r_sizes = c6_i12;
  }
}

static boolean_T c6_isfinite(SFc6_usv_modelInstanceStruct *chartInstance, real_T
  c6_x)
{
  real_T c6_b_x;
  boolean_T c6_b_b;
  boolean_T c6_b8;
  real_T c6_c_x;
  boolean_T c6_c_b;
  boolean_T c6_b9;
  (void)chartInstance;
  c6_b_x = c6_x;
  c6_b_b = muDoubleScalarIsInf(c6_b_x);
  c6_b8 = !c6_b_b;
  c6_c_x = c6_x;
  c6_c_b = muDoubleScalarIsNaN(c6_c_x);
  c6_b9 = !c6_c_b;
  return c6_b8 && c6_b9;
}

static void c6_c_error(SFc6_usv_modelInstanceStruct *chartInstance)
{
  const mxArray *c6_y = NULL;
  static char_T c6_b_u[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'o', 'o',
    't', 's', ':', 'N', 'o', 'n', 'F', 'i', 'n', 'i', 't', 'e', 'I', 'n', 'p',
    'u', 't' };

  (void)chartInstance;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c6_y));
}

static real_T c6_abs(SFc6_usv_modelInstanceStruct *chartInstance, real_T c6_x)
{
  real_T c6_b_x;
  real_T c6_c_x;
  (void)chartInstance;
  c6_b_x = c6_x;
  c6_c_x = c6_b_x;
  return muDoubleScalarAbs(c6_c_x);
}

static void c6_check_forloop_overflow_error(SFc6_usv_modelInstanceStruct
  *chartInstance, boolean_T c6_overflow)
{
  const mxArray *c6_y = NULL;
  static char_T c6_b_u[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c6_b_y = NULL;
  static char_T c6_c_u[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  (void)c6_overflow;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c6_y, 14, c6_b_y));
}

static void c6_eig(SFc6_usv_modelInstanceStruct *chartInstance, creal_T
                   c6_A_data[], int32_T c6_A_sizes[2], creal_T c6_V_data[],
                   int32_T *c6_V_sizes)
{
  static creal_T c6_dc2 = { 0.0, 0.0 };

  int32_T c6_lda;
  int32_T c6_b_n;
  int32_T c6_b_A_sizes[2];
  int32_T c6_A;
  int32_T c6_b_A;
  int32_T c6_loop_ub;
  int32_T c6_i13;
  creal_T c6_b_A_data[9];
  ptrdiff_t c6_ldvl_t;
  ptrdiff_t c6_ldvr_t;
  ptrdiff_t c6_n_t;
  ptrdiff_t c6_lda_t;
  creal_T c6_vr;
  creal_T c6_vl;
  ptrdiff_t c6_info_t;
  int32_T c6_info;
  int32_T c6_b_info;
  int32_T c6_c_info;
  boolean_T c6_p;
  boolean_T c6_b_p;
  int32_T c6_V;
  int32_T c6_b_loop_ub;
  int32_T c6_i14;
  int32_T c6_d_info;
  int32_T c6_e_info;
  c6_dc2.re = rtNaN;
  c6_lda = c6_A_sizes[0];
  c6_b_n = c6_A_sizes[1];
  c6_b_A_sizes[0] = c6_A_sizes[0];
  c6_b_A_sizes[1] = c6_A_sizes[1];
  c6_A = c6_b_A_sizes[0];
  c6_b_A = c6_b_A_sizes[1];
  c6_loop_ub = c6_A_sizes[0] * c6_A_sizes[1] - 1;
  for (c6_i13 = 0; c6_i13 <= c6_loop_ub; c6_i13++) {
    c6_b_A_data[c6_i13] = c6_A_data[c6_i13];
  }

  c6_ldvl_t = (ptrdiff_t)1;
  c6_ldvr_t = (ptrdiff_t)1;
  c6_n_t = (ptrdiff_t)c6_b_n;
  c6_lda_t = (ptrdiff_t)c6_lda;
  *c6_V_sizes = c6_b_n;
  c6_info_t = LAPACKE_zgeev(102, 'N', 'N', c6_n_t, (lapack_complex_double *)
    &c6_b_A_data[0], c6_lda_t, (lapack_complex_double *)&c6_V_data[0],
    (lapack_complex_double *)&c6_vl, c6_ldvl_t, (lapack_complex_double *)&c6_vr,
    c6_ldvr_t);
  c6_info = (int32_T)c6_info_t;
  c6_b_info = c6_info;
  c6_c_info = c6_b_info;
  c6_p = (c6_c_info < 0);
  if (c6_p) {
    if (c6_b_info == -1010) {
      c6_d_error(chartInstance);
    } else {
      c6_e_error(chartInstance, c6_b_info);
    }

    c6_b_p = true;
  } else {
    c6_b_p = false;
  }

  if (c6_b_p) {
    c6_V = *c6_V_sizes;
    *c6_V_sizes = c6_V;
    c6_b_loop_ub = c6_V - 1;
    for (c6_i14 = 0; c6_i14 <= c6_b_loop_ub; c6_i14++) {
      c6_V_data[c6_i14] = c6_dc2;
    }
  }

  c6_d_info = c6_info;
  c6_e_info = c6_d_info;
  if ((real_T)c6_e_info != 0.0) {
    c6_warning(chartInstance);
  }
}

static void c6_d_error(SFc6_usv_modelInstanceStruct *chartInstance)
{
  const mxArray *c6_y = NULL;
  static char_T c6_b_u[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  (void)chartInstance;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c6_y));
}

static void c6_e_error(SFc6_usv_modelInstanceStruct *chartInstance, int32_T
  c6_varargin_2)
{
  const mxArray *c6_y = NULL;
  static char_T c6_b_u[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  const mxArray *c6_b_y = NULL;
  static char_T c6_c_u[13] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z', 'g',
    'e', 'e', 'v' };

  int32_T c6_d_u;
  const mxArray *c6_c_y = NULL;
  (void)chartInstance;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_c_u, 10, 0U, 1U, 0U, 2, 1, 13),
                false);
  c6_d_u = c6_varargin_2;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c6_y, 14, c6_b_y, 14, c6_c_y));
}

static void c6_warning(SFc6_usv_modelInstanceStruct *chartInstance)
{
  const mxArray *c6_y = NULL;
  static char_T c6_b_u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c6_b_y = NULL;
  static char_T c6_c_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c6_c_y = NULL;
  static char_T c6_msgID[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'i',
    'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  (void)chartInstance;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_msgID, 10, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c6_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c6_b_y, 14, c6_c_y));
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_b_u;
  const mxArray *c6_y = NULL;
  SFc6_usv_modelInstanceStruct *chartInstance;
  chartInstance = (SFc6_usv_modelInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_b_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_d_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i15;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_b_u), &c6_i15, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i15;
  sf_mex_destroy(&c6_b_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_usv_modelInstanceStruct *chartInstance;
  chartInstance = (SFc6_usv_modelInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_usv_model, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_usv_model), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_usv_model);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_usv_modelInstanceStruct *chartInstance,
  const mxArray *c6_b_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_b_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_b_u);
  return c6_y;
}

static void c6_b_sqrt(SFc6_usv_modelInstanceStruct *chartInstance, real_T *c6_x)
{
  real_T c6_b_x;
  boolean_T c6_b10;
  boolean_T c6_p;
  c6_b_x = *c6_x;
  c6_b10 = (c6_b_x < 0.0);
  c6_p = c6_b10;
  if (c6_p) {
    c6_b_error(chartInstance);
  }

  *c6_x = muDoubleScalarSqrt(*c6_x);
}

static void init_dsm_address_info(SFc6_usv_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_usv_modelInstanceStruct *chartInstance)
{
  chartInstance->c6_n = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c6_Xp = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_sita = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_Yp = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c6_Np = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c6_u = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c6_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c6_usv_model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1114386753U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1931466696U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3237860522U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1905110807U);
}

mxArray* sf_c6_usv_model_get_post_codegen_info(void);
mxArray *sf_c6_usv_model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("itCJfGC5kmbDMXRWmr9UeD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c6_usv_model_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_usv_model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.lapack.LAPACKApi"));
  return(mxcell3p);
}

mxArray *sf_c6_usv_model_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c6_usv_model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_usv_model_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c6_usv_model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Np\",},{M[1],M[5],T\"Xp\",},{M[1],M[8],T\"Yp\",},{M[8],M[0],T\"is_active_c6_usv_model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_usv_model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_usv_modelInstanceStruct *chartInstance = (SFc6_usv_modelInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _usv_modelMachineNumber_,
           6,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_usv_modelMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_usv_modelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _usv_modelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"n");
          _SFD_SET_DATA_PROPS(1,1,1,0,"sita");
          _SFD_SET_DATA_PROPS(2,1,1,0,"u");
          _SFD_SET_DATA_PROPS(3,1,1,0,"v");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Xp");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Yp");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Np");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1002);
        _SFD_CV_INIT_EML_IF(0,1,0,860,884,-1,917);
        _SFD_CV_INIT_EML_FOR(0,1,0,838,856,921);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,863,884,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _usv_modelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_usv_modelInstanceStruct *chartInstance = (SFc6_usv_modelInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c6_n);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c6_Xp);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c6_sita);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c6_Yp);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c6_Np);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c6_u);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c6_v);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sYPFvWHAEnJvdARW4g8QIMG";
}

static void sf_opaque_initialize_c6_usv_model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_usv_modelInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c6_usv_model((SFc6_usv_modelInstanceStruct*)
    chartInstanceVar);
  initialize_c6_usv_model((SFc6_usv_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_usv_model(void *chartInstanceVar)
{
  enable_c6_usv_model((SFc6_usv_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_usv_model(void *chartInstanceVar)
{
  disable_c6_usv_model((SFc6_usv_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_usv_model(void *chartInstanceVar)
{
  sf_gateway_c6_usv_model((SFc6_usv_modelInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_usv_model(SimStruct* S)
{
  return get_sim_state_c6_usv_model((SFc6_usv_modelInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_usv_model(SimStruct* S, const mxArray *st)
{
  set_sim_state_c6_usv_model((SFc6_usv_modelInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c6_usv_model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_usv_modelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_usv_model_optimization_info();
    }

    finalize_c6_usv_model((SFc6_usv_modelInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_usv_model((SFc6_usv_modelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_usv_model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_usv_model((SFc6_usv_modelInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c6_usv_model(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_usv_model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 6);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(881712265U));
  ssSetChecksum1(S,(1274541913U));
  ssSetChecksum2(S,(980970117U));
  ssSetChecksum3(S,(550591941U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_usv_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_usv_model(SimStruct *S)
{
  SFc6_usv_modelInstanceStruct *chartInstance;
  chartInstance = (SFc6_usv_modelInstanceStruct *)utMalloc(sizeof
    (SFc6_usv_modelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc6_usv_modelInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_usv_model;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_usv_model;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_usv_model;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_usv_model;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_usv_model;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_usv_model;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_usv_model;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_usv_model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_usv_model;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_usv_model;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_usv_model;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c6_usv_model(chartInstance);
}

void c6_usv_model_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_usv_model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_usv_model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_usv_model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_usv_model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
