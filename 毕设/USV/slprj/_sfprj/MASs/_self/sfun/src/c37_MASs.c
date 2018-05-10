/* Include files */

#include <stddef.h>
#include "blas.h"
#include "MASs_sfun.h"
#include "c37_MASs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MASs_sfun_debug_macros.h"
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
static const char * c37_debug_family_names[33] = { "P", "K", "dA", "df", "d1",
  "d2", "t", "U", "deta", "S", "vv", "Re", "Cf", "Ks", "deCf", "Xu", "Yv", "Yr",
  "Nv", "Nr", "nargin", "nargout", "B", "d", "L", "Cb", "m", "u", "v", "r", "Xs",
  "Ys", "Ns" };

/* Function Declarations */
static void initialize_c37_MASs(SFc37_MASsInstanceStruct *chartInstance);
static void initialize_params_c37_MASs(SFc37_MASsInstanceStruct *chartInstance);
static void enable_c37_MASs(SFc37_MASsInstanceStruct *chartInstance);
static void disable_c37_MASs(SFc37_MASsInstanceStruct *chartInstance);
static void c37_update_debugger_state_c37_MASs(SFc37_MASsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c37_MASs(SFc37_MASsInstanceStruct
  *chartInstance);
static void set_sim_state_c37_MASs(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_st);
static void finalize_c37_MASs(SFc37_MASsInstanceStruct *chartInstance);
static void sf_gateway_c37_MASs(SFc37_MASsInstanceStruct *chartInstance);
static void mdl_start_c37_MASs(SFc37_MASsInstanceStruct *chartInstance);
static void c37_chartstep_c37_MASs(SFc37_MASsInstanceStruct *chartInstance);
static void initSimStructsc37_MASs(SFc37_MASsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c37_machineNumber, uint32_T
  c37_chartNumber, uint32_T c37_instanceNumber);
static const mxArray *c37_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData);
static real_T c37_emlrt_marshallIn(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_b_Ns, const char_T *c37_identifier);
static real_T c37_b_emlrt_marshallIn(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_b_u, const emlrtMsgIdentifier *c37_parentId);
static void c37_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData);
static real_T c37_mpower(SFc37_MASsInstanceStruct *chartInstance, real_T c37_a);
static void c37_scalarEg(SFc37_MASsInstanceStruct *chartInstance);
static void c37_dimagree(SFc37_MASsInstanceStruct *chartInstance);
static boolean_T c37_fltpower_domain_error(SFc37_MASsInstanceStruct
  *chartInstance, real_T c37_a, real_T c37_b);
static void c37_error(SFc37_MASsInstanceStruct *chartInstance);
static real_T c37_b_mpower(SFc37_MASsInstanceStruct *chartInstance, real_T c37_a);
static void c37_b_error(SFc37_MASsInstanceStruct *chartInstance);
static real_T c37_c_mpower(SFc37_MASsInstanceStruct *chartInstance, real_T c37_a,
  real_T c37_b);
static real_T c37_d_mpower(SFc37_MASsInstanceStruct *chartInstance, real_T c37_a);
static real_T c37_log10(SFc37_MASsInstanceStruct *chartInstance, real_T c37_x);
static void c37_c_error(SFc37_MASsInstanceStruct *chartInstance);
static real_T c37_e_mpower(SFc37_MASsInstanceStruct *chartInstance, real_T c37_a);
static const mxArray *c37_b_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData);
static int32_T c37_c_emlrt_marshallIn(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_b_u, const emlrtMsgIdentifier *c37_parentId);
static void c37_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData);
static uint8_T c37_d_emlrt_marshallIn(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_b_is_active_c37_MASs, const char_T *c37_identifier);
static uint8_T c37_e_emlrt_marshallIn(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_b_u, const emlrtMsgIdentifier *c37_parentId);
static void c37_b_log10(SFc37_MASsInstanceStruct *chartInstance, real_T *c37_x);
static void init_dsm_address_info(SFc37_MASsInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc37_MASsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c37_MASs(SFc37_MASsInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc37_MASs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c37_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c37_is_active_c37_MASs = 0U;
}

static void initialize_params_c37_MASs(SFc37_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c37_MASs(SFc37_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c37_MASs(SFc37_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c37_update_debugger_state_c37_MASs(SFc37_MASsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c37_MASs(SFc37_MASsInstanceStruct
  *chartInstance)
{
  const mxArray *c37_st;
  const mxArray *c37_y = NULL;
  real_T c37_hoistedGlobal;
  real_T c37_b_u;
  const mxArray *c37_b_y = NULL;
  real_T c37_b_hoistedGlobal;
  real_T c37_c_u;
  const mxArray *c37_c_y = NULL;
  real_T c37_c_hoistedGlobal;
  real_T c37_d_u;
  const mxArray *c37_d_y = NULL;
  uint8_T c37_d_hoistedGlobal;
  uint8_T c37_e_u;
  const mxArray *c37_e_y = NULL;
  c37_st = NULL;
  c37_st = NULL;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_createcellmatrix(4, 1), false);
  c37_hoistedGlobal = *chartInstance->c37_Ns;
  c37_b_u = c37_hoistedGlobal;
  c37_b_y = NULL;
  sf_mex_assign(&c37_b_y, sf_mex_create("y", &c37_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c37_y, 0, c37_b_y);
  c37_b_hoistedGlobal = *chartInstance->c37_Xs;
  c37_c_u = c37_b_hoistedGlobal;
  c37_c_y = NULL;
  sf_mex_assign(&c37_c_y, sf_mex_create("y", &c37_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c37_y, 1, c37_c_y);
  c37_c_hoistedGlobal = *chartInstance->c37_Ys;
  c37_d_u = c37_c_hoistedGlobal;
  c37_d_y = NULL;
  sf_mex_assign(&c37_d_y, sf_mex_create("y", &c37_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c37_y, 2, c37_d_y);
  c37_d_hoistedGlobal = chartInstance->c37_is_active_c37_MASs;
  c37_e_u = c37_d_hoistedGlobal;
  c37_e_y = NULL;
  sf_mex_assign(&c37_e_y, sf_mex_create("y", &c37_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c37_y, 3, c37_e_y);
  sf_mex_assign(&c37_st, c37_y, false);
  return c37_st;
}

static void set_sim_state_c37_MASs(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_st)
{
  const mxArray *c37_b_u;
  chartInstance->c37_doneDoubleBufferReInit = true;
  c37_b_u = sf_mex_dup(c37_st);
  *chartInstance->c37_Ns = c37_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Ns", c37_b_u, 0)), "Ns");
  *chartInstance->c37_Xs = c37_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Xs", c37_b_u, 1)), "Xs");
  *chartInstance->c37_Ys = c37_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Ys", c37_b_u, 2)), "Ys");
  chartInstance->c37_is_active_c37_MASs = c37_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c37_MASs", c37_b_u, 3)),
    "is_active_c37_MASs");
  sf_mex_destroy(&c37_b_u);
  c37_update_debugger_state_c37_MASs(chartInstance);
  sf_mex_destroy(&c37_st);
}

static void finalize_c37_MASs(SFc37_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c37_MASs(SFc37_MASsInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 29U, chartInstance->c37_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_r, 7U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_v, 6U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_u, 5U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_m, 4U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_Cb, 3U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_L, 2U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_d, 1U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_B, 0U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
  chartInstance->c37_sfEvent = CALL_EVENT;
  c37_chartstep_c37_MASs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_MASsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_Xs, 8U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_Ys, 9U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c37_Ns, 10U, 1U, 0U,
                        chartInstance->c37_sfEvent, false);
}

static void mdl_start_c37_MASs(SFc37_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c37_chartstep_c37_MASs(SFc37_MASsInstanceStruct *chartInstance)
{
  real_T c37_hoistedGlobal;
  real_T c37_b_hoistedGlobal;
  real_T c37_c_hoistedGlobal;
  real_T c37_d_hoistedGlobal;
  real_T c37_e_hoistedGlobal;
  real_T c37_f_hoistedGlobal;
  real_T c37_g_hoistedGlobal;
  real_T c37_h_hoistedGlobal;
  real_T c37_b_B;
  real_T c37_b_d;
  real_T c37_b_L;
  real_T c37_b_Cb;
  real_T c37_b_m;
  real_T c37_b_u;
  real_T c37_b_v;
  real_T c37_b_r;
  uint32_T c37_debug_family_var_map[33];
  real_T c37_P;
  real_T c37_K;
  real_T c37_dA;
  real_T c37_df;
  real_T c37_d1;
  real_T c37_d2;
  real_T c37_t;
  real_T c37_U;
  real_T c37_deta;
  real_T c37_S;
  real_T c37_vv;
  real_T c37_Re;
  real_T c37_Cf;
  real_T c37_Ks;
  real_T c37_deCf;
  real_T c37_Xu;
  real_T c37_Yv;
  real_T c37_Yr;
  real_T c37_Nv;
  real_T c37_Nr;
  real_T c37_nargin = 8.0;
  real_T c37_nargout = 3.0;
  real_T c37_b_Xs;
  real_T c37_b_Ys;
  real_T c37_b_Ns;
  real_T c37_A;
  real_T c37_c_B;
  real_T c37_x;
  real_T c37_y;
  real_T c37_b_x;
  real_T c37_b_y;
  real_T c37_b_A;
  real_T c37_c_x;
  real_T c37_d_x;
  real_T c37_c_A;
  real_T c37_e_x;
  real_T c37_f_x;
  real_T c37_c_y;
  real_T c37_d_A;
  real_T c37_g_x;
  real_T c37_h_x;
  real_T c37_d0;
  real_T c37_d_B;
  real_T c37_d_y;
  real_T c37_e_y;
  real_T c37_e_B;
  real_T c37_f_y;
  real_T c37_g_y;
  real_T c37_h_y;
  real_T c37_e_A;
  real_T c37_f_B;
  real_T c37_i_x;
  real_T c37_i_y;
  real_T c37_j_x;
  real_T c37_j_y;
  real_T c37_k_y;
  real_T c37_g_B;
  real_T c37_l_y;
  real_T c37_m_y;
  real_T c37_n_y;
  real_T c37_h_B;
  real_T c37_o_y;
  real_T c37_p_y;
  real_T c37_q_y;
  real_T c37_f_A;
  real_T c37_i_B;
  real_T c37_k_x;
  real_T c37_r_y;
  real_T c37_l_x;
  real_T c37_s_y;
  real_T c37_t_y;
  real_T c37_g_A;
  real_T c37_j_B;
  real_T c37_m_x;
  real_T c37_u_y;
  real_T c37_n_x;
  real_T c37_v_y;
  real_T c37_w_y;
  real_T c37_a;
  real_T c37_b_a;
  real_T c37_c_a;
  real_T c37_o_x;
  real_T c37_d_a;
  real_T c37_ar;
  real_T c37_c;
  real_T c37_k_B;
  real_T c37_x_y;
  real_T c37_y_y;
  real_T c37_ab_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 29U, chartInstance->c37_sfEvent);
  c37_hoistedGlobal = *chartInstance->c37_B;
  c37_b_hoistedGlobal = *chartInstance->c37_d;
  c37_c_hoistedGlobal = *chartInstance->c37_L;
  c37_d_hoistedGlobal = *chartInstance->c37_Cb;
  c37_e_hoistedGlobal = *chartInstance->c37_m;
  c37_f_hoistedGlobal = *chartInstance->c37_u;
  c37_g_hoistedGlobal = *chartInstance->c37_v;
  c37_h_hoistedGlobal = *chartInstance->c37_r;
  c37_b_B = c37_hoistedGlobal;
  c37_b_d = c37_b_hoistedGlobal;
  c37_b_L = c37_c_hoistedGlobal;
  c37_b_Cb = c37_d_hoistedGlobal;
  c37_b_m = c37_e_hoistedGlobal;
  c37_b_u = c37_f_hoistedGlobal;
  c37_b_v = c37_g_hoistedGlobal;
  c37_b_r = c37_h_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 33U, 33U, c37_debug_family_names,
    c37_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_P, 0U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_K, 1U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_dA, 2U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_df, 3U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_d1, 4U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_d2, 5U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_t, 6U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_U, 7U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_deta, 8U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_S, 9U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_vv, 10U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_Re, 11U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_Cf, 12U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_Ks, 13U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_deCf, 14U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_Xu, 15U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_Yv, 16U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_Yr, 17U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_Nv, 18U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_Nr, 19U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_nargin, 20U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_nargout, 21U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_b_B, 22U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_b_d, 23U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_b_L, 24U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_b_Cb, 25U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_b_m, 26U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_b_u, 27U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_b_v, 28U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_b_r, 29U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_b_Xs, 30U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_b_Ys, 31U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_b_Ns, 32U, c37_sf_marshallOut,
    c37_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 3);
  c37_P = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 4);
  c37_A = 2.0 * c37_b_d;
  c37_c_B = c37_b_L;
  c37_x = c37_A;
  c37_y = c37_c_B;
  c37_b_x = c37_x;
  c37_b_y = c37_y;
  c37_K = c37_b_x / c37_b_y;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 5);
  c37_dA = 0.67;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 6);
  c37_df = 0.72;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 7);
  c37_d1 = -0.049999999999999933;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 8);
  c37_d2 = 0.69500000000000006;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 9);
  c37_t = -0.071942446043165367;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 10);
  c37_U = c37_b_mpower(chartInstance, c37_mpower(chartInstance, c37_b_u) +
                       c37_mpower(chartInstance, c37_b_v));
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 11);
  c37_b_A = c37_b_m;
  c37_c_x = c37_b_A;
  c37_d_x = c37_c_x;
  c37_deta = c37_d_x / 1025.0;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 12);
  c37_c_A = c37_deta;
  c37_e_x = c37_c_A;
  c37_f_x = c37_e_x;
  c37_c_y = c37_f_x / 3.0;
  c37_S = c37_d_mpower(chartInstance, c37_c_mpower(chartInstance, 3.14, c37_c_y)
                       + 0.5 * c37_b_L);
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 13);
  c37_vv = 1.07854E-6;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 14);
  c37_d_A = c37_b_L * c37_U;
  c37_g_x = c37_d_A;
  c37_h_x = c37_g_x;
  c37_Re = c37_h_x / 1.07854E-6;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 15);
  c37_d0 = c37_Re;
  c37_b_log10(chartInstance, &c37_d0);
  c37_d_B = c37_mpower(chartInstance, c37_d0 - 2.0);
  c37_d_y = c37_d_B;
  c37_e_y = c37_d_y;
  c37_Cf = 0.075 / c37_e_y;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 16);
  c37_Ks = 0.00015;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 17);
  c37_e_B = c37_b_L;
  c37_f_y = c37_e_B;
  c37_g_y = c37_f_y;
  c37_h_y = 0.00015 / c37_g_y;
  c37_deCf = (105.0 * c37_d_mpower(chartInstance, c37_h_y) - 0.64) *
    c37_e_mpower(chartInstance, 10.0);
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 19);
  c37_Xu = 0.5 * c37_P * c37_S * c37_mpower(chartInstance, c37_b_u) * (c37_Cf +
    c37_deCf);
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 20);
  c37_e_A = 1.4 * c37_b_Cb * c37_b_B;
  c37_f_B = c37_b_L;
  c37_i_x = c37_e_A;
  c37_i_y = c37_f_B;
  c37_j_x = c37_i_x;
  c37_j_y = c37_i_y;
  c37_k_y = c37_j_x / c37_j_y;
  c37_g_B = c37_b_d;
  c37_l_y = c37_g_B;
  c37_m_y = c37_l_y;
  c37_n_y = -0.0482014388489208 / c37_m_y;
  c37_Yv = -0.5 * c37_P * c37_b_L * c37_b_d * c37_U * ((1.5707963267948966 *
    c37_K + c37_k_y) * (1.0 + c37_n_y));
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 21);
  c37_h_B = c37_b_d;
  c37_o_y = c37_h_B;
  c37_p_y = c37_o_y;
  c37_q_y = -0.057553956834532294 / c37_p_y;
  c37_Yr = 0.5 * c37_P * c37_b_L * c37_b_L * c37_b_d * c37_U *
    (0.78539816339744828 * c37_K * (1.0 + c37_q_y));
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 22);
  c37_f_A = 1.4 * c37_b_Cb * c37_b_B;
  c37_i_B = c37_b_L;
  c37_k_x = c37_f_A;
  c37_r_y = c37_i_B;
  c37_l_x = c37_k_x;
  c37_s_y = c37_r_y;
  c37_t_y = c37_l_x / c37_s_y;
  c37_g_A = 0.27 * (1.5707963267948966 + c37_t_y) * c37_t;
  c37_j_B = c37_b_d;
  c37_m_x = c37_g_A;
  c37_u_y = c37_j_B;
  c37_n_x = c37_m_x;
  c37_v_y = c37_u_y;
  c37_w_y = c37_n_x / c37_v_y;
  c37_Nv = -0.5 * c37_P * c37_b_L * c37_b_L * c37_b_d * c37_U * (c37_K - c37_w_y);
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 23);
  c37_a = c37_b_L;
  c37_b_a = c37_a;
  c37_c_a = c37_b_a;
  c37_o_x = c37_c_a;
  c37_d_a = c37_o_x;
  c37_ar = c37_d_a;
  c37_c = muDoubleScalarPower(c37_ar, 3.0);
  if (c37_fltpower_domain_error(chartInstance, c37_c_a, 3.0)) {
    c37_error(chartInstance);
  }

  c37_k_B = c37_b_d;
  c37_x_y = c37_k_B;
  c37_y_y = c37_x_y;
  c37_ab_y = -0.02158273381294961 / c37_y_y;
  c37_Nr = 0.5 * c37_P * c37_c * c37_b_d * c37_U * (-(0.54 * c37_K - c37_mpower
    (chartInstance, c37_K)) * (1.0 + c37_ab_y));
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 25);
  c37_b_Xs = c37_Xu;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 26);
  c37_b_Ys = c37_Yv * c37_b_v + c37_Yr * c37_b_r;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 27);
  c37_b_Ns = c37_Nv * c37_b_v + c37_Nr * c37_b_r;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c37_Xs = c37_b_Xs;
  *chartInstance->c37_Ys = c37_b_Ys;
  *chartInstance->c37_Ns = c37_b_Ns;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c37_sfEvent);
}

static void initSimStructsc37_MASs(SFc37_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c37_machineNumber, uint32_T
  c37_chartNumber, uint32_T c37_instanceNumber)
{
  (void)c37_machineNumber;
  (void)c37_chartNumber;
  (void)c37_instanceNumber;
}

static const mxArray *c37_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData)
{
  const mxArray *c37_mxArrayOutData = NULL;
  real_T c37_b_u;
  const mxArray *c37_y = NULL;
  SFc37_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc37_MASsInstanceStruct *)chartInstanceVoid;
  c37_mxArrayOutData = NULL;
  c37_b_u = *(real_T *)c37_inData;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", &c37_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c37_mxArrayOutData, c37_y, false);
  return c37_mxArrayOutData;
}

static real_T c37_emlrt_marshallIn(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_b_Ns, const char_T *c37_identifier)
{
  real_T c37_y;
  emlrtMsgIdentifier c37_thisId;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_thisId.bParentIsCell = false;
  c37_y = c37_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c37_b_Ns),
    &c37_thisId);
  sf_mex_destroy(&c37_b_Ns);
  return c37_y;
}

static real_T c37_b_emlrt_marshallIn(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_b_u, const emlrtMsgIdentifier *c37_parentId)
{
  real_T c37_y;
  real_T c37_d1;
  (void)chartInstance;
  sf_mex_import(c37_parentId, sf_mex_dup(c37_b_u), &c37_d1, 1, 0, 0U, 0, 0U, 0);
  c37_y = c37_d1;
  sf_mex_destroy(&c37_b_u);
  return c37_y;
}

static void c37_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData)
{
  const mxArray *c37_b_Ns;
  const char_T *c37_identifier;
  emlrtMsgIdentifier c37_thisId;
  real_T c37_y;
  SFc37_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc37_MASsInstanceStruct *)chartInstanceVoid;
  c37_b_Ns = sf_mex_dup(c37_mxArrayInData);
  c37_identifier = c37_varName;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_thisId.bParentIsCell = false;
  c37_y = c37_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c37_b_Ns),
    &c37_thisId);
  sf_mex_destroy(&c37_b_Ns);
  *(real_T *)c37_outData = c37_y;
  sf_mex_destroy(&c37_mxArrayInData);
}

const mxArray *sf_c37_MASs_get_eml_resolved_functions_info(void)
{
  const mxArray *c37_nameCaptureInfo = NULL;
  c37_nameCaptureInfo = NULL;
  sf_mex_assign(&c37_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c37_nameCaptureInfo;
}

static real_T c37_mpower(SFc37_MASsInstanceStruct *chartInstance, real_T c37_a)
{
  real_T c37_c;
  real_T c37_b_a;
  real_T c37_c_a;
  real_T c37_x;
  real_T c37_d_a;
  c37_b_a = c37_a;
  c37_c_a = c37_b_a;
  c37_x = c37_c_a;
  c37_d_a = c37_x;
  c37_c = c37_d_a * c37_d_a;
  if (c37_fltpower_domain_error(chartInstance, c37_c_a, 2.0)) {
    c37_error(chartInstance);
  }

  return c37_c;
}

static void c37_scalarEg(SFc37_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c37_dimagree(SFc37_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c37_fltpower_domain_error(SFc37_MASsInstanceStruct
  *chartInstance, real_T c37_a, real_T c37_b)
{
  boolean_T c37_p;
  real_T c37_x;
  boolean_T c37_b_b;
  real_T c37_b_x;
  real_T c37_c_x;
  boolean_T c37_b0;
  boolean_T c37_b1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  (void)chartInstance;
  c37_p = false;
  if (c37_a < 0.0) {
    guard1 = false;
    if (c37_p) {
      guard1 = true;
    } else {
      c37_x = c37_b;
      c37_b_b = muDoubleScalarIsNaN(c37_x);
      guard2 = false;
      if (c37_b_b) {
        guard2 = true;
      } else {
        c37_b_x = c37_b;
        c37_c_x = c37_b_x;
        c37_c_x = muDoubleScalarFloor(c37_c_x);
        if (c37_c_x == c37_b) {
          guard2 = true;
        } else {
          c37_b0 = false;
        }
      }

      if (guard2 == true) {
        c37_b0 = true;
      }

      if (!c37_b0) {
        guard1 = true;
      } else {
        c37_b1 = false;
      }
    }

    if (guard1 == true) {
      c37_b1 = true;
    }

    c37_p = c37_b1;
  }

  return c37_p;
}

static void c37_error(SFc37_MASsInstanceStruct *chartInstance)
{
  const mxArray *c37_y = NULL;
  static char_T c37_b_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", c37_b_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c37_y));
}

static real_T c37_b_mpower(SFc37_MASsInstanceStruct *chartInstance, real_T c37_a)
{
  real_T c37_c;
  real_T c37_b_a;
  real_T c37_c_a;
  real_T c37_x;
  real_T c37_d_a;
  real_T c37_b_x;
  real_T c37_c_x;
  boolean_T c37_b2;
  boolean_T c37_p;
  c37_b_a = c37_a;
  c37_c_a = c37_b_a;
  c37_x = c37_c_a;
  c37_d_a = c37_x;
  c37_b_x = c37_d_a;
  c37_c = c37_b_x;
  c37_c_x = c37_c;
  c37_b2 = (c37_c_x < 0.0);
  c37_p = c37_b2;
  if (c37_p) {
    c37_b_error(chartInstance);
  }

  c37_c = muDoubleScalarSqrt(c37_c);
  if (c37_fltpower_domain_error(chartInstance, c37_c_a, 0.5)) {
    c37_error(chartInstance);
  }

  return c37_c;
}

static void c37_b_error(SFc37_MASsInstanceStruct *chartInstance)
{
  const mxArray *c37_y = NULL;
  static char_T c37_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c37_b_y = NULL;
  static char_T c37_c_u[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", c37_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c37_b_y = NULL;
  sf_mex_assign(&c37_b_y, sf_mex_create("y", c37_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c37_y, 14, c37_b_y));
}

static real_T c37_c_mpower(SFc37_MASsInstanceStruct *chartInstance, real_T c37_a,
  real_T c37_b)
{
  real_T c37_c;
  real_T c37_b_a;
  real_T c37_b_b;
  real_T c37_c_a;
  real_T c37_c_b;
  real_T c37_x;
  real_T c37_y;
  real_T c37_d_a;
  real_T c37_d_b;
  real_T c37_ar;
  real_T c37_br;
  c37_b_a = c37_a;
  c37_b_b = c37_b;
  c37_c_a = c37_b_a;
  c37_c_b = c37_b_b;
  c37_x = c37_c_a;
  c37_y = c37_c_b;
  c37_d_a = c37_x;
  c37_d_b = c37_y;
  c37_ar = c37_d_a;
  c37_br = c37_d_b;
  c37_c = muDoubleScalarPower(c37_ar, c37_br);
  if (c37_fltpower_domain_error(chartInstance, c37_c_a, c37_c_b)) {
    c37_error(chartInstance);
  }

  return c37_c;
}

static real_T c37_d_mpower(SFc37_MASsInstanceStruct *chartInstance, real_T c37_a)
{
  real_T c37_c;
  real_T c37_b_a;
  real_T c37_c_a;
  real_T c37_x;
  real_T c37_d_a;
  real_T c37_ar;
  c37_b_a = c37_a;
  c37_c_a = c37_b_a;
  c37_x = c37_c_a;
  c37_d_a = c37_x;
  c37_ar = c37_d_a;
  c37_c = muDoubleScalarPower(c37_ar, 0.33333333333333331);
  if (c37_fltpower_domain_error(chartInstance, c37_c_a, 0.33333333333333331)) {
    c37_error(chartInstance);
  }

  return c37_c;
}

static real_T c37_log10(SFc37_MASsInstanceStruct *chartInstance, real_T c37_x)
{
  real_T c37_b_x;
  c37_b_x = c37_x;
  c37_b_log10(chartInstance, &c37_b_x);
  return c37_b_x;
}

static void c37_c_error(SFc37_MASsInstanceStruct *chartInstance)
{
  const mxArray *c37_y = NULL;
  static char_T c37_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c37_b_y = NULL;
  static char_T c37_c_u[5] = { 'l', 'o', 'g', '1', '0' };

  (void)chartInstance;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", c37_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c37_b_y = NULL;
  sf_mex_assign(&c37_b_y, sf_mex_create("y", c37_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c37_y, 14, c37_b_y));
}

static real_T c37_e_mpower(SFc37_MASsInstanceStruct *chartInstance, real_T c37_a)
{
  real_T c37_c;
  real_T c37_b_a;
  real_T c37_c_a;
  real_T c37_x;
  real_T c37_d_a;
  real_T c37_ar;
  c37_b_a = c37_a;
  c37_c_a = c37_b_a;
  c37_x = c37_c_a;
  c37_d_a = c37_x;
  c37_ar = c37_d_a;
  c37_c = muDoubleScalarPower(c37_ar, -3.0);
  if (c37_fltpower_domain_error(chartInstance, c37_c_a, -3.0)) {
    c37_error(chartInstance);
  }

  return c37_c;
}

static const mxArray *c37_b_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData)
{
  const mxArray *c37_mxArrayOutData = NULL;
  int32_T c37_b_u;
  const mxArray *c37_y = NULL;
  SFc37_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc37_MASsInstanceStruct *)chartInstanceVoid;
  c37_mxArrayOutData = NULL;
  c37_b_u = *(int32_T *)c37_inData;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", &c37_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c37_mxArrayOutData, c37_y, false);
  return c37_mxArrayOutData;
}

static int32_T c37_c_emlrt_marshallIn(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_b_u, const emlrtMsgIdentifier *c37_parentId)
{
  int32_T c37_y;
  int32_T c37_i0;
  (void)chartInstance;
  sf_mex_import(c37_parentId, sf_mex_dup(c37_b_u), &c37_i0, 1, 6, 0U, 0, 0U, 0);
  c37_y = c37_i0;
  sf_mex_destroy(&c37_b_u);
  return c37_y;
}

static void c37_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData)
{
  const mxArray *c37_b_sfEvent;
  const char_T *c37_identifier;
  emlrtMsgIdentifier c37_thisId;
  int32_T c37_y;
  SFc37_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc37_MASsInstanceStruct *)chartInstanceVoid;
  c37_b_sfEvent = sf_mex_dup(c37_mxArrayInData);
  c37_identifier = c37_varName;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_thisId.bParentIsCell = false;
  c37_y = c37_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c37_b_sfEvent),
    &c37_thisId);
  sf_mex_destroy(&c37_b_sfEvent);
  *(int32_T *)c37_outData = c37_y;
  sf_mex_destroy(&c37_mxArrayInData);
}

static uint8_T c37_d_emlrt_marshallIn(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_b_is_active_c37_MASs, const char_T *c37_identifier)
{
  uint8_T c37_y;
  emlrtMsgIdentifier c37_thisId;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_thisId.bParentIsCell = false;
  c37_y = c37_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c37_b_is_active_c37_MASs), &c37_thisId);
  sf_mex_destroy(&c37_b_is_active_c37_MASs);
  return c37_y;
}

static uint8_T c37_e_emlrt_marshallIn(SFc37_MASsInstanceStruct *chartInstance,
  const mxArray *c37_b_u, const emlrtMsgIdentifier *c37_parentId)
{
  uint8_T c37_y;
  uint8_T c37_u0;
  (void)chartInstance;
  sf_mex_import(c37_parentId, sf_mex_dup(c37_b_u), &c37_u0, 1, 3, 0U, 0, 0U, 0);
  c37_y = c37_u0;
  sf_mex_destroy(&c37_b_u);
  return c37_y;
}

static void c37_b_log10(SFc37_MASsInstanceStruct *chartInstance, real_T *c37_x)
{
  real_T c37_b_x;
  boolean_T c37_b3;
  boolean_T c37_p;
  c37_b_x = *c37_x;
  c37_b3 = (c37_b_x < 0.0);
  c37_p = c37_b3;
  if (c37_p) {
    c37_c_error(chartInstance);
  }

  *c37_x = muDoubleScalarLog10(*c37_x);
}

static void init_dsm_address_info(SFc37_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc37_MASsInstanceStruct *chartInstance)
{
  chartInstance->c37_B = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c37_Xs = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c37_d = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c37_L = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c37_Cb = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c37_m = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c37_Ys = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c37_Ns = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c37_u = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    5);
  chartInstance->c37_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    6);
  chartInstance->c37_r = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    7);
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

void sf_c37_MASs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3631436933U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(85359349U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(999221842U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1459522431U);
}

mxArray* sf_c37_MASs_get_post_codegen_info(void);
mxArray *sf_c37_MASs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("8lzI7HIT1Nn9dVAUuTjloF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
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
    mxArray* mxPostCodegenInfo = sf_c37_MASs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c37_MASs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c37_MASs_jit_fallback_info(void)
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

mxArray *sf_c37_MASs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c37_MASs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c37_MASs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Ns\",},{M[1],M[5],T\"Xs\",},{M[1],M[8],T\"Ys\",},{M[8],M[0],T\"is_active_c37_MASs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c37_MASs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc37_MASsInstanceStruct *chartInstance = (SFc37_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _MASsMachineNumber_,
           37,
           1,
           1,
           0,
           11,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_MASsMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_MASsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _MASsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"B");
          _SFD_SET_DATA_PROPS(1,1,1,0,"d");
          _SFD_SET_DATA_PROPS(2,1,1,0,"L");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Cb");
          _SFD_SET_DATA_PROPS(4,1,1,0,"m");
          _SFD_SET_DATA_PROPS(5,1,1,0,"u");
          _SFD_SET_DATA_PROPS(6,1,1,0,"v");
          _SFD_SET_DATA_PROPS(7,1,1,0,"r");
          _SFD_SET_DATA_PROPS(8,2,0,1,"Xs");
          _SFD_SET_DATA_PROPS(9,2,0,1,"Ys");
          _SFD_SET_DATA_PROPS(10,2,0,1,"Ns");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,612);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)c37_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)c37_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)c37_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _MASsMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc37_MASsInstanceStruct *chartInstance = (SFc37_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c37_B);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c37_Xs);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c37_d);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c37_L);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c37_Cb);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c37_m);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c37_Ys);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c37_Ns);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c37_u);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c37_v);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c37_r);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "szgERixxwJPfc78HRHoQdVF";
}

static void sf_opaque_initialize_c37_MASs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc37_MASsInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c37_MASs((SFc37_MASsInstanceStruct*) chartInstanceVar);
  initialize_c37_MASs((SFc37_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c37_MASs(void *chartInstanceVar)
{
  enable_c37_MASs((SFc37_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c37_MASs(void *chartInstanceVar)
{
  disable_c37_MASs((SFc37_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c37_MASs(void *chartInstanceVar)
{
  sf_gateway_c37_MASs((SFc37_MASsInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c37_MASs(SimStruct* S)
{
  return get_sim_state_c37_MASs((SFc37_MASsInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c37_MASs(SimStruct* S, const mxArray *st)
{
  set_sim_state_c37_MASs((SFc37_MASsInstanceStruct*)sf_get_chart_instance_ptr(S),
    st);
}

static void sf_opaque_terminate_c37_MASs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc37_MASsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_MASs_optimization_info();
    }

    finalize_c37_MASs((SFc37_MASsInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc37_MASs((SFc37_MASsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c37_MASs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c37_MASs((SFc37_MASsInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c37_MASs(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MASs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      37);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,37,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 37);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,37);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,37,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,37,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,37);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1341359853U));
  ssSetChecksum1(S,(64740173U));
  ssSetChecksum2(S,(2753240075U));
  ssSetChecksum3(S,(1312549397U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c37_MASs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c37_MASs(SimStruct *S)
{
  SFc37_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc37_MASsInstanceStruct *)utMalloc(sizeof
    (SFc37_MASsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc37_MASsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c37_MASs;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c37_MASs;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c37_MASs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c37_MASs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c37_MASs;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c37_MASs;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c37_MASs;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c37_MASs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c37_MASs;
  chartInstance->chartInfo.mdlStart = mdlStart_c37_MASs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c37_MASs;
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
  mdl_start_c37_MASs(chartInstance);
}

void c37_MASs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c37_MASs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c37_MASs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c37_MASs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c37_MASs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
