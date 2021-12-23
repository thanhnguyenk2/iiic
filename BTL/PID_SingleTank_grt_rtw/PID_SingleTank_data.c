/*
 * PID_SingleTank_data.c
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

#include "PID_SingleTank.h"
#include "PID_SingleTank_private.h"

/* Block parameters (default storage) */
P_PID_SingleTank_T PID_SingleTank_P = {
  /* Expression: fis.outputSamplePoints
   * Referenced by: '<S1>/Output Sample Points'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 200
   * Referenced by: '<Root>/Step'
   */
  200.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -0.041666666666666664,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  0.0081666666666666658,

  /* Expression: [5.4 0.142 45]
   * Referenced by: '<Root>/Constant'
   */
  { 5.4, 0.142, 45.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Random Number'
   */
  0.0,

  /* Computed Parameter: RandomNumber_StdDev
   * Referenced by: '<Root>/Random Number'
   */
  0.22360679774997896,

  /* Expression: 0
   * Referenced by: '<Root>/Random Number'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: 20.7
   * Referenced by: '<Root>/Transport Delay'
   */
  20.7,

  /* Expression: 0
   * Referenced by: '<Root>/Transport Delay'
   */
  0.0
};
