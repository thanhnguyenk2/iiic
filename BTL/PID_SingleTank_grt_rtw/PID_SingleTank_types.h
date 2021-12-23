/*
 * PID_SingleTank_types.h
 *
 * Code generation for model "PID_SingleTank".
 *
 * Model version              : 1.169
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Tue Nov 16 22:44:19 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PID_SingleTank_types_h_
#define RTW_HEADER_PID_SingleTank_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_SAyHbUuviDjROEq2OW81bG_
#define DEFINED_TYPEDEF_FOR_struct_SAyHbUuviDjROEq2OW81bG_

typedef struct {
  uint8_T SimulinkDiagnostic;
  uint8_T Model[14];
  uint8_T Block[38];
  uint8_T OutOfRangeInputValue;
  uint8_T NoRuleFired;
  uint8_T EmptyOutputFuzzySet;
} struct_SAyHbUuviDjROEq2OW81bG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nDiNttezQ8pHMZv76leKsH_
#define DEFINED_TYPEDEF_FOR_struct_nDiNttezQ8pHMZv76leKsH_

typedef struct {
  uint8_T type[6];
  int32_T origTypeLength;
  real_T params[4];
  int32_T origParamLength;
} struct_nDiNttezQ8pHMZv76leKsH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_lMtpFmLOVR7rlweqgH5LGF_
#define DEFINED_TYPEDEF_FOR_struct_lMtpFmLOVR7rlweqgH5LGF_

typedef struct {
  struct_nDiNttezQ8pHMZv76leKsH mf[7];
  int32_T origNumMF;
} struct_lMtpFmLOVR7rlweqgH5LGF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qH4Unbydb9KS7ehcrvtFcB_
#define DEFINED_TYPEDEF_FOR_struct_qH4Unbydb9KS7ehcrvtFcB_

typedef struct {
  uint8_T type[8];
  int32_T origTypeLength;
  real_T params;
  int32_T origParamLength;
} struct_qH4Unbydb9KS7ehcrvtFcB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4jAbFwbYM7t03eNKQxopsF_
#define DEFINED_TYPEDEF_FOR_struct_4jAbFwbYM7t03eNKQxopsF_

typedef struct {
  struct_qH4Unbydb9KS7ehcrvtFcB mf[7];
  int32_T origNumMF;
} struct_4jAbFwbYM7t03eNKQxopsF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_X5eRL6G3dln4D5EzoWXGSC_
#define DEFINED_TYPEDEF_FOR_struct_X5eRL6G3dln4D5EzoWXGSC_

typedef struct {
  uint8_T type[6];
  uint8_T andMethod[4];
  uint8_T orMethod[6];
  uint8_T defuzzMethod[6];
  uint8_T impMethod[4];
  uint8_T aggMethod[3];
  real_T inputRange[2];
  real_T outputRange[6];
  struct_lMtpFmLOVR7rlweqgH5LGF inputMF;
  struct_4jAbFwbYM7t03eNKQxopsF outputMF[3];
  real_T antecedent[7];
  real_T consequent[21];
  real_T connection[7];
  real_T weight[7];
  int32_T numSamples;
  int32_T numInputs;
  int32_T numOutputs;
  int32_T numRules;
  int32_T numInputMFs;
  int32_T numCumInputMFs;
  int32_T numOutputMFs[3];
  int32_T numCumOutputMFs[3];
  real_T outputSamplePoints;
  int32_T orrSize[2];
  int32_T aggSize[2];
} struct_X5eRL6G3dln4D5EzoWXGSC;

#endif

/* Custom Type definition for MATLAB Function: '<S1>/Evaluate Rule Consequents' */
#ifndef struct_tag_s5auVAtj0sXVTykAgnl5VDF
#define struct_tag_s5auVAtj0sXVTykAgnl5VDF

struct tag_s5auVAtj0sXVTykAgnl5VDF
{
  uint8_T type[6];
  int32_T origTypeLength;
  real_T params[4];
  int32_T origParamLength;
};

#endif                                 /*struct_tag_s5auVAtj0sXVTykAgnl5VDF*/

#ifndef typedef_s5auVAtj0sXVTykAgnl5VDF_PID_S_T
#define typedef_s5auVAtj0sXVTykAgnl5VDF_PID_S_T

typedef struct tag_s5auVAtj0sXVTykAgnl5VDF s5auVAtj0sXVTykAgnl5VDF_PID_S_T;

#endif                               /*typedef_s5auVAtj0sXVTykAgnl5VDF_PID_S_T*/

#ifndef struct_tag_saoQgEtgnJF5rJMKF1uiX2D
#define struct_tag_saoQgEtgnJF5rJMKF1uiX2D

struct tag_saoQgEtgnJF5rJMKF1uiX2D
{
  s5auVAtj0sXVTykAgnl5VDF_PID_S_T mf[7];
  int32_T origNumMF;
};

#endif                                 /*struct_tag_saoQgEtgnJF5rJMKF1uiX2D*/

#ifndef typedef_saoQgEtgnJF5rJMKF1uiX2D_PID_S_T
#define typedef_saoQgEtgnJF5rJMKF1uiX2D_PID_S_T

typedef struct tag_saoQgEtgnJF5rJMKF1uiX2D saoQgEtgnJF5rJMKF1uiX2D_PID_S_T;

#endif                               /*typedef_saoQgEtgnJF5rJMKF1uiX2D_PID_S_T*/

#ifndef struct_tag_siJGctElGTS0kXoMHZvtx3D
#define struct_tag_siJGctElGTS0kXoMHZvtx3D

struct tag_siJGctElGTS0kXoMHZvtx3D
{
  uint8_T type[8];
  int32_T origTypeLength;
  real_T params;
  int32_T origParamLength;
};

#endif                                 /*struct_tag_siJGctElGTS0kXoMHZvtx3D*/

#ifndef typedef_siJGctElGTS0kXoMHZvtx3D_PID_S_T
#define typedef_siJGctElGTS0kXoMHZvtx3D_PID_S_T

typedef struct tag_siJGctElGTS0kXoMHZvtx3D siJGctElGTS0kXoMHZvtx3D_PID_S_T;

#endif                               /*typedef_siJGctElGTS0kXoMHZvtx3D_PID_S_T*/

#ifndef struct_tag_sJOrbxh8OHJGeBggmkvlZ4B
#define struct_tag_sJOrbxh8OHJGeBggmkvlZ4B

struct tag_sJOrbxh8OHJGeBggmkvlZ4B
{
  siJGctElGTS0kXoMHZvtx3D_PID_S_T mf[7];
  int32_T origNumMF;
};

#endif                                 /*struct_tag_sJOrbxh8OHJGeBggmkvlZ4B*/

#ifndef typedef_sJOrbxh8OHJGeBggmkvlZ4B_PID_S_T
#define typedef_sJOrbxh8OHJGeBggmkvlZ4B_PID_S_T

typedef struct tag_sJOrbxh8OHJGeBggmkvlZ4B sJOrbxh8OHJGeBggmkvlZ4B_PID_S_T;

#endif                               /*typedef_sJOrbxh8OHJGeBggmkvlZ4B_PID_S_T*/

#ifndef struct_tag_ss6rbcCAv8htXowxw389ceB
#define struct_tag_ss6rbcCAv8htXowxw389ceB

struct tag_ss6rbcCAv8htXowxw389ceB
{
  uint8_T type[6];
  uint8_T andMethod[4];
  uint8_T orMethod[6];
  uint8_T defuzzMethod[6];
  uint8_T impMethod[4];
  uint8_T aggMethod[3];
  real_T inputRange[2];
  real_T outputRange[6];
  saoQgEtgnJF5rJMKF1uiX2D_PID_S_T inputMF;
  sJOrbxh8OHJGeBggmkvlZ4B_PID_S_T outputMF[3];
  real_T antecedent[7];
  real_T consequent[21];
  real_T connection[7];
  real_T weight[7];
  int32_T numSamples;
  int32_T numInputs;
  int32_T numOutputs;
  int32_T numRules;
  int32_T numInputMFs;
  int32_T numCumInputMFs;
  int32_T numOutputMFs[3];
  int32_T numCumOutputMFs[3];
  real_T outputSamplePoints;
  int32_T orrSize[2];
  int32_T aggSize[2];
};

#endif                                 /*struct_tag_ss6rbcCAv8htXowxw389ceB*/

#ifndef typedef_ss6rbcCAv8htXowxw389ceB_PID_S_T
#define typedef_ss6rbcCAv8htXowxw389ceB_PID_S_T

typedef struct tag_ss6rbcCAv8htXowxw389ceB ss6rbcCAv8htXowxw389ceB_PID_S_T;

#endif                               /*typedef_ss6rbcCAv8htXowxw389ceB_PID_S_T*/

/* Custom Type definition for MATLAB Function: '<S1>/Evaluate Rule Antecedents' */
#ifndef struct_tag_s51B4e5gNu4cy7zqy1dxig
#define struct_tag_s51B4e5gNu4cy7zqy1dxig

struct tag_s51B4e5gNu4cy7zqy1dxig
{
  uint8_T SimulinkDiagnostic;
  uint8_T Model[14];
  uint8_T Block[38];
  uint8_T OutOfRangeInputValue;
  uint8_T NoRuleFired;
  uint8_T EmptyOutputFuzzySet;
};

#endif                                 /*struct_tag_s51B4e5gNu4cy7zqy1dxig*/

#ifndef typedef_s51B4e5gNu4cy7zqy1dxig_PID_Si_T
#define typedef_s51B4e5gNu4cy7zqy1dxig_PID_Si_T

typedef struct tag_s51B4e5gNu4cy7zqy1dxig s51B4e5gNu4cy7zqy1dxig_PID_Si_T;

#endif                               /*typedef_s51B4e5gNu4cy7zqy1dxig_PID_Si_T*/

#ifndef struct_tag_sculW9uT2riFhoDCGUFgphB
#define struct_tag_sculW9uT2riFhoDCGUFgphB

struct tag_sculW9uT2riFhoDCGUFgphB
{
  uint8_T type[6];
  real_T params[4];
};

#endif                                 /*struct_tag_sculW9uT2riFhoDCGUFgphB*/

#ifndef typedef_sculW9uT2riFhoDCGUFgphB_PID_S_T
#define typedef_sculW9uT2riFhoDCGUFgphB_PID_S_T

typedef struct tag_sculW9uT2riFhoDCGUFgphB sculW9uT2riFhoDCGUFgphB_PID_S_T;

#endif                               /*typedef_sculW9uT2riFhoDCGUFgphB_PID_S_T*/

#ifndef struct_tag_sXsSeVB4E0ntMvFGNG3D1eC
#define struct_tag_sXsSeVB4E0ntMvFGNG3D1eC

struct tag_sXsSeVB4E0ntMvFGNG3D1eC
{
  uint8_T type[5];
  real_T params[3];
};

#endif                                 /*struct_tag_sXsSeVB4E0ntMvFGNG3D1eC*/

#ifndef typedef_sXsSeVB4E0ntMvFGNG3D1eC_PID_S_T
#define typedef_sXsSeVB4E0ntMvFGNG3D1eC_PID_S_T

typedef struct tag_sXsSeVB4E0ntMvFGNG3D1eC sXsSeVB4E0ntMvFGNG3D1eC_PID_S_T;

#endif                               /*typedef_sXsSeVB4E0ntMvFGNG3D1eC_PID_S_T*/

/* Custom Type definition for MATLAB Function: '<S1>/Evaluate Rule Consequents' */
#ifndef struct_tag_sOevUV89alhsoIw1mX6t0H
#define struct_tag_sOevUV89alhsoIw1mX6t0H

struct tag_sOevUV89alhsoIw1mX6t0H
{
  uint8_T type[8];
  real_T params;
};

#endif                                 /*struct_tag_sOevUV89alhsoIw1mX6t0H*/

#ifndef typedef_sOevUV89alhsoIw1mX6t0H_PID_Si_T
#define typedef_sOevUV89alhsoIw1mX6t0H_PID_Si_T

typedef struct tag_sOevUV89alhsoIw1mX6t0H sOevUV89alhsoIw1mX6t0H_PID_Si_T;

#endif                               /*typedef_sOevUV89alhsoIw1mX6t0H_PID_Si_T*/

/* Parameters (default storage) */
typedef struct P_PID_SingleTank_T_ P_PID_SingleTank_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_PID_SingleTank_T RT_MODEL_PID_SingleTank_T;

#endif                                 /* RTW_HEADER_PID_SingleTank_types_h_ */
