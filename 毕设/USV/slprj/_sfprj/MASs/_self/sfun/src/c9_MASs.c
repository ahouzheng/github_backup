/* Include files */

#include <stddef.h>
#include "blas.h"
#include "MASs_sfun.h"
#include "c9_MASs.h"
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
static const char * c9_debug_family_names[33] = { "P", "K", "dA", "df", "d1",
  "d2", "t", "U", "deta", "S", "vv", "Re", "Cf", "Ks", "deCf", "Xu", "Yv", "Yr",
  "Nv", "Nr", "nargin", "nargout", "B", "d", "L", "Cb", "m", "u", "v", "r", "Xs",
  "Ys", "Ns" };

/* Function Declarations */
static void initialize_c9_MASs(SFc9_MASsInstanceStruct *chartInstance);
static void initialize_params_c9_MASs(SFc9_MASsInstanceStruct *chartInstance);
static void enable_c9_MASs(SFc9_MASsInstanceStruct *chartInstance);
static void disable_c9_MASs(SFc9_MASsInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_MASs(SFc9_MASsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c9_MASs(SFc9_MASsInstanceStruct
  *chartInstance);
static void set_sim_state_c9_MASs(SFc9_MASsInstanceStruct *chartInstance, const
  mxArray *c9_st);
static void finalize_c9_MASs(SFc9_MASsInstanceStruct *chartInstance);
static void sf_gateway_c9_MASs(SFc9_MASsInstanceStruct *chartInstance);
static void mdl_start_c9_MASs(SFc9_MASsInstanceStruct *chartInstance);
static void c9_chartstep_c9_MASs(SFc9_MASsInstanceStruct *chartInstance);
static void initSimStructsc9_MASs(SFc9_MASsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_MASsInstanceStruct *chartInstance, const
  mxArray *c9_b_Ns, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_MASsInstanceStruct *chartInstance,
  const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static real_T c9_mpower(SFc9_MASsInstanceStruct *chartInstance, real_T c9_a);
static void c9_scalarEg(SFc9_MASsInstanceStruct *chartInstance);
static void c9_dimagree(SFc9_MASsInstanceStruct *chartInstance);
static boolean_T c9_fltpower_domain_error(SFc9_MASsInstanceStruct *chartInstance,
  real_T c9_a, real_T c9_b);
static void c9_error(SFc9_MASsInstanceStruct *chartInstance);
static real_T c9_b_mpower(SFc9_MASsInstanceStruct *chartInstance, real_T c9_a);
static void c9_b_error(SFc9_MASsInstanceStruct *chartInstance);
static real_T c9_c_mpower(SFc9_MASsInstanceStruct *chartInstance, real_T c9_a,
  real_T c9_b);
static real_T c9_d_mpower(SFc9_MASsInstanceStruct *chartInstance, real_T c9_a);
static real_T c9_log10(SFc9_MASsInstanceStruct *chartInstance, real_T c9_x);
static void c9_c_error(SFc9_MASsInstanceStruct *chartInstance);
static real_T c9_e_mpower(SFc9_MASsInstanceStruct *chartInstance, real_T c9_a);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_c_emlrt_marshallIn(SFc9_MASsInstanceStruct *chartInstance,
  const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_d_emlrt_marshallIn(SFc9_MASsInstanceStruct *chartInstance,
  const mxArray *c9_b_is_active_c9_MASs, const char_T *c9_identifier);
static uint8_T c9_e_emlrt_marshallIn(SFc9_MASsInstanceStruct *chartInstance,
  const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_log10(SFc9_MASsInstanceStruct *chartInstance, real_T *c9_x);
static void init_dsm_address_info(SFc9_MASsInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc9_MASsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c9_MASs(SFc9_MASsInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc9_MASs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_MASs = 0U;
}

static void initialize_params_c9_MASs(SFc9_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_MASs(SFc9_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_MASs(SFc9_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_MASs(SFc9_MASsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_MASs(SFc9_MASsInstanceStruct
  *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_d_y = NULL;
  uint8_T c9_d_hoistedGlobal;
  uint8_T c9_e_u;
  const mxArray *c9_e_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(4, 1), false);
  c9_hoistedGlobal = *chartInstance->c9_Ns;
  c9_b_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *chartInstance->c9_Xs;
  c9_c_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *chartInstance->c9_Ys;
  c9_d_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = chartInstance->c9_is_active_c9_MASs;
  c9_e_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_MASs(SFc9_MASsInstanceStruct *chartInstance, const
  mxArray *c9_st)
{
  const mxArray *c9_b_u;
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_b_u = sf_mex_dup(c9_st);
  *chartInstance->c9_Ns = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Ns", c9_b_u, 0)), "Ns");
  *chartInstance->c9_Xs = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Xs", c9_b_u, 1)), "Xs");
  *chartInstance->c9_Ys = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Ys", c9_b_u, 2)), "Ys");
  chartInstance->c9_is_active_c9_MASs = c9_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c9_MASs", c9_b_u, 3)),
    "is_active_c9_MASs");
  sf_mex_destroy(&c9_b_u);
  c9_update_debugger_state_c9_MASs(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_MASs(SFc9_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_MASs(SFc9_MASsInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_r, 7U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_v, 6U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_u, 5U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_m, 4U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Cb, 3U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_L, 2U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_d, 1U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_B, 0U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  chartInstance->c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_MASs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_MASsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Xs, 8U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Ys, 9U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Ns, 10U, 1U, 0U,
                        chartInstance->c9_sfEvent, false);
}

static void mdl_start_c9_MASs(SFc9_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_chartstep_c9_MASs(SFc9_MASsInstanceStruct *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_e_hoistedGlobal;
  real_T c9_f_hoistedGlobal;
  real_T c9_g_hoistedGlobal;
  real_T c9_h_hoistedGlobal;
  real_T c9_b_B;
  real_T c9_b_d;
  real_T c9_b_L;
  real_T c9_b_Cb;
  real_T c9_b_m;
  real_T c9_b_u;
  real_T c9_b_v;
  real_T c9_b_r;
  uint32_T c9_debug_family_var_map[33];
  real_T c9_P;
  real_T c9_K;
  real_T c9_dA;
  real_T c9_df;
  real_T c9_d1;
  real_T c9_d2;
  real_T c9_t;
  real_T c9_U;
  real_T c9_deta;
  real_T c9_S;
  real_T c9_vv;
  real_T c9_Re;
  real_T c9_Cf;
  real_T c9_Ks;
  real_T c9_deCf;
  real_T c9_Xu;
  real_T c9_Yv;
  real_T c9_Yr;
  real_T c9_Nv;
  real_T c9_Nr;
  real_T c9_nargin = 8.0;
  real_T c9_nargout = 3.0;
  real_T c9_b_Xs;
  real_T c9_b_Ys;
  real_T c9_b_Ns;
  real_T c9_A;
  real_T c9_c_B;
  real_T c9_x;
  real_T c9_y;
  real_T c9_b_x;
  real_T c9_b_y;
  real_T c9_b_A;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_c_A;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_c_y;
  real_T c9_d_A;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_d0;
  real_T c9_d_B;
  real_T c9_d_y;
  real_T c9_e_y;
  real_T c9_e_B;
  real_T c9_f_y;
  real_T c9_g_y;
  real_T c9_h_y;
  real_T c9_e_A;
  real_T c9_f_B;
  real_T c9_i_x;
  real_T c9_i_y;
  real_T c9_j_x;
  real_T c9_j_y;
  real_T c9_k_y;
  real_T c9_g_B;
  real_T c9_l_y;
  real_T c9_m_y;
  real_T c9_n_y;
  real_T c9_h_B;
  real_T c9_o_y;
  real_T c9_p_y;
  real_T c9_q_y;
  real_T c9_f_A;
  real_T c9_i_B;
  real_T c9_k_x;
  real_T c9_r_y;
  real_T c9_l_x;
  real_T c9_s_y;
  real_T c9_t_y;
  real_T c9_g_A;
  real_T c9_j_B;
  real_T c9_m_x;
  real_T c9_u_y;
  real_T c9_n_x;
  real_T c9_v_y;
  real_T c9_w_y;
  real_T c9_a;
  real_T c9_b_a;
  real_T c9_c_a;
  real_T c9_o_x;
  real_T c9_d_a;
  real_T c9_ar;
  real_T c9_c;
  real_T c9_k_B;
  real_T c9_x_y;
  real_T c9_y_y;
  real_T c9_ab_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *chartInstance->c9_B;
  c9_b_hoistedGlobal = *chartInstance->c9_d;
  c9_c_hoistedGlobal = *chartInstance->c9_L;
  c9_d_hoistedGlobal = *chartInstance->c9_Cb;
  c9_e_hoistedGlobal = *chartInstance->c9_m;
  c9_f_hoistedGlobal = *chartInstance->c9_u;
  c9_g_hoistedGlobal = *chartInstance->c9_v;
  c9_h_hoistedGlobal = *chartInstance->c9_r;
  c9_b_B = c9_hoistedGlobal;
  c9_b_d = c9_b_hoistedGlobal;
  c9_b_L = c9_c_hoistedGlobal;
  c9_b_Cb = c9_d_hoistedGlobal;
  c9_b_m = c9_e_hoistedGlobal;
  c9_b_u = c9_f_hoistedGlobal;
  c9_b_v = c9_g_hoistedGlobal;
  c9_b_r = c9_h_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 33U, 33U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_P, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_K, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_dA, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_df, 3U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_d1, 4U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_d2, 5U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_t, 6U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_U, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_deta, 8U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_S, 9U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_vv, 10U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Re, 11U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Cf, 12U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_Ks, 13U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_deCf, 14U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Xu, 15U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Yv, 16U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Yr, 17U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Nv, 18U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_Nr, 19U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 20U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 21U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_B, 22U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_d, 23U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_L, 24U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_Cb, 25U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_m, 26U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_u, 27U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_v, 28U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_r, 29U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_Xs, 30U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_Ys, 31U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_Ns, 32U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  c9_P = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_A = 2.0 * c9_b_d;
  c9_c_B = c9_b_L;
  c9_x = c9_A;
  c9_y = c9_c_B;
  c9_b_x = c9_x;
  c9_b_y = c9_y;
  c9_K = c9_b_x / c9_b_y;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_dA = 0.67;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_df = 0.72;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_d1 = -0.049999999999999933;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_d2 = 0.69500000000000006;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
  c9_t = -0.071942446043165367;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_U = c9_b_mpower(chartInstance, c9_mpower(chartInstance, c9_b_u) + c9_mpower
                     (chartInstance, c9_b_v));
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 11);
  c9_b_A = c9_b_m;
  c9_c_x = c9_b_A;
  c9_d_x = c9_c_x;
  c9_deta = c9_d_x / 1025.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  c9_c_A = c9_deta;
  c9_e_x = c9_c_A;
  c9_f_x = c9_e_x;
  c9_c_y = c9_f_x / 3.0;
  c9_S = c9_d_mpower(chartInstance, c9_c_mpower(chartInstance, 3.14, c9_c_y) +
                     0.5 * c9_b_L);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 13);
  c9_vv = 1.07854E-6;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 14);
  c9_d_A = c9_b_L * c9_U;
  c9_g_x = c9_d_A;
  c9_h_x = c9_g_x;
  c9_Re = c9_h_x / 1.07854E-6;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 15);
  c9_d0 = c9_Re;
  c9_b_log10(chartInstance, &c9_d0);
  c9_d_B = c9_mpower(chartInstance, c9_d0 - 2.0);
  c9_d_y = c9_d_B;
  c9_e_y = c9_d_y;
  c9_Cf = 0.075 / c9_e_y;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 16);
  c9_Ks = 0.00015;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 17);
  c9_e_B = c9_b_L;
  c9_f_y = c9_e_B;
  c9_g_y = c9_f_y;
  c9_h_y = 0.00015 / c9_g_y;
  c9_deCf = (105.0 * c9_d_mpower(chartInstance, c9_h_y) - 0.64) * c9_e_mpower
    (chartInstance, 10.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 19);
  c9_Xu = 0.5 * c9_P * c9_S * c9_mpower(chartInstance, c9_b_u) * (c9_Cf +
    c9_deCf);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 20);
  c9_e_A = 1.4 * c9_b_Cb * c9_b_B;
  c9_f_B = c9_b_L;
  c9_i_x = c9_e_A;
  c9_i_y = c9_f_B;
  c9_j_x = c9_i_x;
  c9_j_y = c9_i_y;
  c9_k_y = c9_j_x / c9_j_y;
  c9_g_B = c9_b_d;
  c9_l_y = c9_g_B;
  c9_m_y = c9_l_y;
  c9_n_y = -0.0482014388489208 / c9_m_y;
  c9_Yv = -0.5 * c9_P * c9_b_L * c9_b_d * c9_U * ((1.5707963267948966 * c9_K +
    c9_k_y) * (1.0 + c9_n_y));
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 21);
  c9_h_B = c9_b_d;
  c9_o_y = c9_h_B;
  c9_p_y = c9_o_y;
  c9_q_y = -0.057553956834532294 / c9_p_y;
  c9_Yr = 0.5 * c9_P * c9_b_L * c9_b_L * c9_b_d * c9_U * (0.78539816339744828 *
    c9_K * (1.0 + c9_q_y));
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 22);
  c9_f_A = 1.4 * c9_b_Cb * c9_b_B;
  c9_i_B = c9_b_L;
  c9_k_x = c9_f_A;
  c9_r_y = c9_i_B;
  c9_l_x = c9_k_x;
  c9_s_y = c9_r_y;
  c9_t_y = c9_l_x / c9_s_y;
  c9_g_A = 0.27 * (1.5707963267948966 + c9_t_y) * c9_t;
  c9_j_B = c9_b_d;
  c9_m_x = c9_g_A;
  c9_u_y = c9_j_B;
  c9_n_x = c9_m_x;
  c9_v_y = c9_u_y;
  c9_w_y = c9_n_x / c9_v_y;
  c9_Nv = -0.5 * c9_P * c9_b_L * c9_b_L * c9_b_d * c9_U * (c9_K - c9_w_y);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 23);
  c9_a = c9_b_L;
  c9_b_a = c9_a;
  c9_c_a = c9_b_a;
  c9_o_x = c9_c_a;
  c9_d_a = c9_o_x;
  c9_ar = c9_d_a;
  c9_c = muDoubleScalarPower(c9_ar, 3.0);
  if (c9_fltpower_domain_error(chartInstance, c9_c_a, 3.0)) {
    c9_error(chartInstance);
  }

  c9_k_B = c9_b_d;
  c9_x_y = c9_k_B;
  c9_y_y = c9_x_y;
  c9_ab_y = -0.02158273381294961 / c9_y_y;
  c9_Nr = 0.5 * c9_P * c9_c * c9_b_d * c9_U * (-(0.54 * c9_K - c9_mpower
    (chartInstance, c9_K)) * (1.0 + c9_ab_y));
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 25);
  c9_b_Xs = c9_Xu;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 26);
  c9_b_Ys = c9_Yv * c9_b_v + c9_Yr * c9_b_r;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 27);
  c9_b_Ns = c9_Nv * c9_b_v + c9_Nr * c9_b_r;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c9_Xs = c9_b_Xs;
  *chartInstance->c9_Ys = c9_b_Ys;
  *chartInstance->c9_Ns = c9_b_Ns;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_MASs(SFc9_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  (void)c9_chartNumber;
  (void)c9_instanceNumber;
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_b_u;
  const mxArray *c9_y = NULL;
  SFc9_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc9_MASsInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_b_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_MASsInstanceStruct *chartInstance, const
  mxArray *c9_b_Ns, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_Ns), &c9_thisId);
  sf_mex_destroy(&c9_b_Ns);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_MASsInstanceStruct *chartInstance,
  const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d1;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), &c9_d1, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d1;
  sf_mex_destroy(&c9_b_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_Ns;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc9_MASsInstanceStruct *)chartInstanceVoid;
  c9_b_Ns = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_Ns), &c9_thisId);
  sf_mex_destroy(&c9_b_Ns);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_MASs_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c9_nameCaptureInfo;
}

static real_T c9_mpower(SFc9_MASsInstanceStruct *chartInstance, real_T c9_a)
{
  real_T c9_c;
  real_T c9_b_a;
  real_T c9_c_a;
  real_T c9_x;
  real_T c9_d_a;
  c9_b_a = c9_a;
  c9_c_a = c9_b_a;
  c9_x = c9_c_a;
  c9_d_a = c9_x;
  c9_c = c9_d_a * c9_d_a;
  if (c9_fltpower_domain_error(chartInstance, c9_c_a, 2.0)) {
    c9_error(chartInstance);
  }

  return c9_c;
}

static void c9_scalarEg(SFc9_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_dimagree(SFc9_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c9_fltpower_domain_error(SFc9_MASsInstanceStruct *chartInstance,
  real_T c9_a, real_T c9_b)
{
  boolean_T c9_p;
  real_T c9_x;
  boolean_T c9_b_b;
  real_T c9_b_x;
  real_T c9_c_x;
  boolean_T c9_b0;
  boolean_T c9_b1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  (void)chartInstance;
  c9_p = false;
  if (c9_a < 0.0) {
    guard1 = false;
    if (c9_p) {
      guard1 = true;
    } else {
      c9_x = c9_b;
      c9_b_b = muDoubleScalarIsNaN(c9_x);
      guard2 = false;
      if (c9_b_b) {
        guard2 = true;
      } else {
        c9_b_x = c9_b;
        c9_c_x = c9_b_x;
        c9_c_x = muDoubleScalarFloor(c9_c_x);
        if (c9_c_x == c9_b) {
          guard2 = true;
        } else {
          c9_b0 = false;
        }
      }

      if (guard2 == true) {
        c9_b0 = true;
      }

      if (!c9_b0) {
        guard1 = true;
      } else {
        c9_b1 = false;
      }
    }

    if (guard1 == true) {
      c9_b1 = true;
    }

    c9_p = c9_b1;
  }

  return c9_p;
}

static void c9_error(SFc9_MASsInstanceStruct *chartInstance)
{
  const mxArray *c9_y = NULL;
  static char_T c9_b_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c9_y));
}

static real_T c9_b_mpower(SFc9_MASsInstanceStruct *chartInstance, real_T c9_a)
{
  real_T c9_c;
  real_T c9_b_a;
  real_T c9_c_a;
  real_T c9_x;
  real_T c9_d_a;
  real_T c9_b_x;
  real_T c9_c_x;
  boolean_T c9_b2;
  boolean_T c9_p;
  c9_b_a = c9_a;
  c9_c_a = c9_b_a;
  c9_x = c9_c_a;
  c9_d_a = c9_x;
  c9_b_x = c9_d_a;
  c9_c = c9_b_x;
  c9_c_x = c9_c;
  c9_b2 = (c9_c_x < 0.0);
  c9_p = c9_b2;
  if (c9_p) {
    c9_b_error(chartInstance);
  }

  c9_c = muDoubleScalarSqrt(c9_c);
  if (c9_fltpower_domain_error(chartInstance, c9_c_a, 0.5)) {
    c9_error(chartInstance);
  }

  return c9_c;
}

static void c9_b_error(SFc9_MASsInstanceStruct *chartInstance)
{
  const mxArray *c9_y = NULL;
  static char_T c9_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c9_b_y = NULL;
  static char_T c9_c_u[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c9_y, 14, c9_b_y));
}

static real_T c9_c_mpower(SFc9_MASsInstanceStruct *chartInstance, real_T c9_a,
  real_T c9_b)
{
  real_T c9_c;
  real_T c9_b_a;
  real_T c9_b_b;
  real_T c9_c_a;
  real_T c9_c_b;
  real_T c9_x;
  real_T c9_y;
  real_T c9_d_a;
  real_T c9_d_b;
  real_T c9_ar;
  real_T c9_br;
  c9_b_a = c9_a;
  c9_b_b = c9_b;
  c9_c_a = c9_b_a;
  c9_c_b = c9_b_b;
  c9_x = c9_c_a;
  c9_y = c9_c_b;
  c9_d_a = c9_x;
  c9_d_b = c9_y;
  c9_ar = c9_d_a;
  c9_br = c9_d_b;
  c9_c = muDoubleScalarPower(c9_ar, c9_br);
  if (c9_fltpower_domain_error(chartInstance, c9_c_a, c9_c_b)) {
    c9_error(chartInstance);
  }

  return c9_c;
}

static real_T c9_d_mpower(SFc9_MASsInstanceStruct *chartInstance, real_T c9_a)
{
  real_T c9_c;
  real_T c9_b_a;
  real_T c9_c_a;
  real_T c9_x;
  real_T c9_d_a;
  real_T c9_ar;
  c9_b_a = c9_a;
  c9_c_a = c9_b_a;
  c9_x = c9_c_a;
  c9_d_a = c9_x;
  c9_ar = c9_d_a;
  c9_c = muDoubleScalarPower(c9_ar, 0.33333333333333331);
  if (c9_fltpower_domain_error(chartInstance, c9_c_a, 0.33333333333333331)) {
    c9_error(chartInstance);
  }

  return c9_c;
}

static real_T c9_log10(SFc9_MASsInstanceStruct *chartInstance, real_T c9_x)
{
  real_T c9_b_x;
  c9_b_x = c9_x;
  c9_b_log10(chartInstance, &c9_b_x);
  return c9_b_x;
}

static void c9_c_error(SFc9_MASsInstanceStruct *chartInstance)
{
  const mxArray *c9_y = NULL;
  static char_T c9_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c9_b_y = NULL;
  static char_T c9_c_u[5] = { 'l', 'o', 'g', '1', '0' };

  (void)chartInstance;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c9_y, 14, c9_b_y));
}

static real_T c9_e_mpower(SFc9_MASsInstanceStruct *chartInstance, real_T c9_a)
{
  real_T c9_c;
  real_T c9_b_a;
  real_T c9_c_a;
  real_T c9_x;
  real_T c9_d_a;
  real_T c9_ar;
  c9_b_a = c9_a;
  c9_c_a = c9_b_a;
  c9_x = c9_c_a;
  c9_d_a = c9_x;
  c9_ar = c9_d_a;
  c9_c = muDoubleScalarPower(c9_ar, -3.0);
  if (c9_fltpower_domain_error(chartInstance, c9_c_a, -3.0)) {
    c9_error(chartInstance);
  }

  return c9_c;
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_b_u;
  const mxArray *c9_y = NULL;
  SFc9_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc9_MASsInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_b_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_c_emlrt_marshallIn(SFc9_MASsInstanceStruct *chartInstance,
  const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), &c9_i0, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i0;
  sf_mex_destroy(&c9_b_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc9_MASsInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_d_emlrt_marshallIn(SFc9_MASsInstanceStruct *chartInstance,
  const mxArray *c9_b_is_active_c9_MASs, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_is_active_c9_MASs),
    &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_MASs);
  return c9_y;
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_MASsInstanceStruct *chartInstance,
  const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_b_u);
  return c9_y;
}

static void c9_b_log10(SFc9_MASsInstanceStruct *chartInstance, real_T *c9_x)
{
  real_T c9_b_x;
  boolean_T c9_b3;
  boolean_T c9_p;
  c9_b_x = *c9_x;
  c9_b3 = (c9_b_x < 0.0);
  c9_p = c9_b3;
  if (c9_p) {
    c9_c_error(chartInstance);
  }

  *c9_x = muDoubleScalarLog10(*c9_x);
}

static void init_dsm_address_info(SFc9_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc9_MASsInstanceStruct *chartInstance)
{
  chartInstance->c9_B = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c9_Xs = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_d = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c9_L = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c9_Cb = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
  chartInstance->c9_m = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c9_Ys = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_Ns = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c9_u = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    5);
  chartInstance->c9_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    6);
  chartInstance->c9_r = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
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

void sf_c9_MASs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3631436933U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(85359349U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(999221842U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1459522431U);
}

mxArray* sf_c9_MASs_get_post_codegen_info(void);
mxArray *sf_c9_MASs_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c9_MASs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_MASs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_MASs_jit_fallback_info(void)
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

mxArray *sf_c9_MASs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c9_MASs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c9_MASs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Ns\",},{M[1],M[5],T\"Xs\",},{M[1],M[8],T\"Ys\",},{M[8],M[0],T\"is_active_c9_MASs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_MASs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_MASsInstanceStruct *chartInstance = (SFc9_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _MASsMachineNumber_,
           9,
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
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
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
    SFc9_MASsInstanceStruct *chartInstance = (SFc9_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c9_B);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c9_Xs);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c9_d);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c9_L);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c9_Cb);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c9_m);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c9_Ys);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c9_Ns);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c9_u);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c9_v);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c9_r);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "szgERixxwJPfc78HRHoQdVF";
}

static void sf_opaque_initialize_c9_MASs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_MASsInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c9_MASs((SFc9_MASsInstanceStruct*) chartInstanceVar);
  initialize_c9_MASs((SFc9_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_MASs(void *chartInstanceVar)
{
  enable_c9_MASs((SFc9_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_MASs(void *chartInstanceVar)
{
  disable_c9_MASs((SFc9_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_MASs(void *chartInstanceVar)
{
  sf_gateway_c9_MASs((SFc9_MASsInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_MASs(SimStruct* S)
{
  return get_sim_state_c9_MASs((SFc9_MASsInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_MASs(SimStruct* S, const mxArray *st)
{
  set_sim_state_c9_MASs((SFc9_MASsInstanceStruct*)sf_get_chart_instance_ptr(S),
                        st);
}

static void sf_opaque_terminate_c9_MASs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_MASsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_MASs_optimization_info();
    }

    finalize_c9_MASs((SFc9_MASsInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_MASs((SFc9_MASsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_MASs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_MASs((SFc9_MASsInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c9_MASs(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MASs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 9);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
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
        infoStruct,9,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
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

static void mdlRTW_c9_MASs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_MASs(SimStruct *S)
{
  SFc9_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc9_MASsInstanceStruct *)utMalloc(sizeof
    (SFc9_MASsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc9_MASsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c9_MASs;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c9_MASs;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c9_MASs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_MASs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_MASs;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c9_MASs;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c9_MASs;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c9_MASs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_MASs;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_MASs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c9_MASs;
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
  mdl_start_c9_MASs(chartInstance);
}

void c9_MASs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_MASs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_MASs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_MASs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_MASs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
