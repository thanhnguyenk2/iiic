/*
 * PID_SingleTank.c
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

/* Block signals (default storage) */
B_PID_SingleTank_T PID_SingleTank_B;

/* Continuous states */
X_PID_SingleTank_T PID_SingleTank_X;

/* Block states (default storage) */
DW_PID_SingleTank_T PID_SingleTank_DW;

/* Real-time model */
RT_MODEL_PID_SingleTank_T PID_SingleTank_M_;
RT_MODEL_PID_SingleTank_T *const PID_SingleTank_M = &PID_SingleTank_M_;

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                 /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PID_SingleTank_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  PID_SingleTank_output();
  PID_SingleTank_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  PID_SingleTank_output();
  PID_SingleTank_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  PID_SingleTank_output();
  PID_SingleTank_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  PID_SingleTank_output();
  PID_SingleTank_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  PID_SingleTank_output();
  PID_SingleTank_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model output function */
void PID_SingleTank_output(void)
{
  real_T *lastU;
  real_T rtb_Product2;
  real_T tmp;
  if (rtmIsMajorTimeStep(PID_SingleTank_M)) {
    /* set solver stop time */
    if (!(PID_SingleTank_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PID_SingleTank_M->solverInfo,
                            ((PID_SingleTank_M->Timing.clockTickH0 + 1) *
        PID_SingleTank_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PID_SingleTank_M->solverInfo,
                            ((PID_SingleTank_M->Timing.clockTick0 + 1) *
        PID_SingleTank_M->Timing.stepSize0 +
        PID_SingleTank_M->Timing.clockTickH0 *
        PID_SingleTank_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PID_SingleTank_M)) {
    PID_SingleTank_M->Timing.t[0] = rtsiGetT(&PID_SingleTank_M->solverInfo);
  }

  /* Step: '<Root>/Step' */
  if (PID_SingleTank_M->Timing.t[0] < PID_SingleTank_P.Step_Time) {
    PID_SingleTank_B.Step = PID_SingleTank_P.Step_Y0;
  } else {
    PID_SingleTank_B.Step = PID_SingleTank_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* TransferFcn: '<Root>/Transfer Fcn' */
  PID_SingleTank_B.TransferFcn = 0.0;
  PID_SingleTank_B.TransferFcn += PID_SingleTank_P.TransferFcn_C *
    PID_SingleTank_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(PID_SingleTank_M)) {
    /* Scope: '<Root>/Scope' */
    if (rtmIsMajorTimeStep(PID_SingleTank_M)) {
      real_T u[3];
      u[0] = PID_SingleTank_M->Timing.t[1];
      ;
      u[1] = PID_SingleTank_B.Step;
      u[2] = PID_SingleTank_B.TransferFcn;
      rt_UpdateLogVar((LogVar *)PID_SingleTank_DW.Scope_PWORK.LoggedData, u, 0);
    }

    /* RandomNumber: '<Root>/Random Number' */
    PID_SingleTank_B.RandomNumber = PID_SingleTank_DW.NextOutput;
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  PID_SingleTank_B.Sum = PID_SingleTank_B.Step - (PID_SingleTank_B.TransferFcn +
    PID_SingleTank_B.RandomNumber);

  /* Derivative: '<S2>/Derivative' */
  tmp = PID_SingleTank_M->Timing.t[0];
  if ((PID_SingleTank_DW.TimeStampA >= tmp) && (PID_SingleTank_DW.TimeStampB >=
       tmp)) {
    rtb_Product2 = 0.0;
  } else {
    rtb_Product2 = PID_SingleTank_DW.TimeStampA;
    lastU = &PID_SingleTank_DW.LastUAtTimeA;
    if (PID_SingleTank_DW.TimeStampA < PID_SingleTank_DW.TimeStampB) {
      if (PID_SingleTank_DW.TimeStampB < tmp) {
        rtb_Product2 = PID_SingleTank_DW.TimeStampB;
        lastU = &PID_SingleTank_DW.LastUAtTimeB;
      }
    } else {
      if (PID_SingleTank_DW.TimeStampA >= tmp) {
        rtb_Product2 = PID_SingleTank_DW.TimeStampB;
        lastU = &PID_SingleTank_DW.LastUAtTimeB;
      }
    }

    rtb_Product2 = (PID_SingleTank_B.Sum - *lastU) / (tmp - rtb_Product2);
  }

  /* End of Derivative: '<S2>/Derivative' */

  /* Product: '<S2>/Product2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Product2 *= PID_SingleTank_P.Constant_Value[2];

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Integrator: '<S2>/Integrator'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   */
  PID_SingleTank_B.Sum_n = (PID_SingleTank_P.Constant_Value[0] *
    PID_SingleTank_B.Sum + PID_SingleTank_P.Constant_Value[1] *
    PID_SingleTank_X.Integrator_CSTATE) + rtb_Product2;
  if (rtmIsMajorTimeStep(PID_SingleTank_M)) {
    /* Scope: '<Root>/Scope1' */
    if (rtmIsMajorTimeStep(PID_SingleTank_M)) {
      real_T u[2];
      u[0] = PID_SingleTank_M->Timing.t[1];
      ;
      u[1] = PID_SingleTank_B.Sum_n;
      rt_UpdateLogVar((LogVar *)PID_SingleTank_DW.Scope1_PWORK.LoggedData, u, 0);
    }
  }

  /* TransportDelay: '<Root>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &PID_SingleTank_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &PID_SingleTank_DW.TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = PID_SingleTank_M->Timing.t[0];
    real_T tMinusDelay = simTime - PID_SingleTank_P.TransportDelay_Delay;
    PID_SingleTank_B.TransportDelay = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      PID_SingleTank_DW.TransportDelay_IWORK.CircularBufSize,
      &PID_SingleTank_DW.TransportDelay_IWORK.Last,
      PID_SingleTank_DW.TransportDelay_IWORK.Tail,
      PID_SingleTank_DW.TransportDelay_IWORK.Head,
      PID_SingleTank_P.TransportDelay_InitOutput,
      0,
      0);
  }
}

/* Model update function */
void PID_SingleTank_update(void)
{
  real_T *lastU;
  if (rtmIsMajorTimeStep(PID_SingleTank_M)) {
    /* Update for RandomNumber: '<Root>/Random Number' */
    PID_SingleTank_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&PID_SingleTank_DW.RandSeed) * PID_SingleTank_P.RandomNumber_StdDev +
      PID_SingleTank_P.RandomNumber_Mean;
  }

  /* Update for Derivative: '<S2>/Derivative' */
  if (PID_SingleTank_DW.TimeStampA == (rtInf)) {
    PID_SingleTank_DW.TimeStampA = PID_SingleTank_M->Timing.t[0];
    lastU = &PID_SingleTank_DW.LastUAtTimeA;
  } else if (PID_SingleTank_DW.TimeStampB == (rtInf)) {
    PID_SingleTank_DW.TimeStampB = PID_SingleTank_M->Timing.t[0];
    lastU = &PID_SingleTank_DW.LastUAtTimeB;
  } else if (PID_SingleTank_DW.TimeStampA < PID_SingleTank_DW.TimeStampB) {
    PID_SingleTank_DW.TimeStampA = PID_SingleTank_M->Timing.t[0];
    lastU = &PID_SingleTank_DW.LastUAtTimeA;
  } else {
    PID_SingleTank_DW.TimeStampB = PID_SingleTank_M->Timing.t[0];
    lastU = &PID_SingleTank_DW.LastUAtTimeB;
  }

  *lastU = PID_SingleTank_B.Sum;

  /* End of Update for Derivative: '<S2>/Derivative' */

  /* Update for TransportDelay: '<Root>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &PID_SingleTank_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &PID_SingleTank_DW.TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = PID_SingleTank_M->Timing.t[0];
    PID_SingleTank_DW.TransportDelay_IWORK.Head =
      ((PID_SingleTank_DW.TransportDelay_IWORK.Head <
        (PID_SingleTank_DW.TransportDelay_IWORK.CircularBufSize-1)) ?
       (PID_SingleTank_DW.TransportDelay_IWORK.Head+1) : 0);
    if (PID_SingleTank_DW.TransportDelay_IWORK.Head ==
        PID_SingleTank_DW.TransportDelay_IWORK.Tail) {
      PID_SingleTank_DW.TransportDelay_IWORK.Tail =
        ((PID_SingleTank_DW.TransportDelay_IWORK.Tail <
          (PID_SingleTank_DW.TransportDelay_IWORK.CircularBufSize-1)) ?
         (PID_SingleTank_DW.TransportDelay_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[PID_SingleTank_DW.TransportDelay_IWORK.Head] = simTime;
    (*uBuffer)[PID_SingleTank_DW.TransportDelay_IWORK.Head] =
      PID_SingleTank_B.Sum_n;
  }

  if (rtmIsMajorTimeStep(PID_SingleTank_M)) {
    rt_ertODEUpdateContinuousStates(&PID_SingleTank_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PID_SingleTank_M->Timing.clockTick0)) {
    ++PID_SingleTank_M->Timing.clockTickH0;
  }

  PID_SingleTank_M->Timing.t[0] = rtsiGetSolverStopTime
    (&PID_SingleTank_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++PID_SingleTank_M->Timing.clockTick1)) {
      ++PID_SingleTank_M->Timing.clockTickH1;
    }

    PID_SingleTank_M->Timing.t[1] = PID_SingleTank_M->Timing.clockTick1 *
      PID_SingleTank_M->Timing.stepSize1 + PID_SingleTank_M->Timing.clockTickH1 *
      PID_SingleTank_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void PID_SingleTank_derivatives(void)
{
  XDot_PID_SingleTank_T *_rtXdot;
  _rtXdot = ((XDot_PID_SingleTank_T *) PID_SingleTank_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += PID_SingleTank_P.TransferFcn_A *
    PID_SingleTank_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += PID_SingleTank_B.TransportDelay;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = PID_SingleTank_B.Sum;
}

/* Model initialize function */
void PID_SingleTank_initialize(void)
{
  /* Start for Scope: '<Root>/Scope' */
  {
    int_T numCols = 3;
    PID_SingleTank_DW.Scope_PWORK.LoggedData = rt_CreateLogVar(
      PID_SingleTank_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(PID_SingleTank_M),
      PID_SingleTank_M->Timing.stepSize0,
      (&rtmGetErrorStatus(PID_SingleTank_M)),
      "TankLevel",
      SS_DOUBLE,
      0,
      0,
      0,
      3,
      1,
      (int_T *)&numCols,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.1,
      1);
    if (PID_SingleTank_DW.Scope_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Scope1' */
  {
    int_T numCols = 2;
    PID_SingleTank_DW.Scope1_PWORK.LoggedData = rt_CreateLogVar(
      PID_SingleTank_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(PID_SingleTank_M),
      PID_SingleTank_M->Timing.stepSize0,
      (&rtmGetErrorStatus(PID_SingleTank_M)),
      "TankLevel1",
      SS_DOUBLE,
      0,
      0,
      0,
      2,
      1,
      (int_T *)&numCols,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.1,
      1);
    if (PID_SingleTank_DW.Scope1_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for TransportDelay: '<Root>/Transport Delay' */
  {
    real_T *pBuffer = &PID_SingleTank_DW.TransportDelay_RWORK.TUbufferArea[0];
    PID_SingleTank_DW.TransportDelay_IWORK.Tail = 0;
    PID_SingleTank_DW.TransportDelay_IWORK.Head = 0;
    PID_SingleTank_DW.TransportDelay_IWORK.Last = 0;
    PID_SingleTank_DW.TransportDelay_IWORK.CircularBufSize = 1024;
    pBuffer[0] = PID_SingleTank_P.TransportDelay_InitOutput;
    pBuffer[1024] = PID_SingleTank_M->Timing.t[0];
    PID_SingleTank_DW.TransportDelay_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    PID_SingleTank_DW.TransportDelay_PWORK.TUbufferPtrs[1] = (void *) &pBuffer
      [1024];
  }

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
    PID_SingleTank_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for RandomNumber: '<Root>/Random Number' */
    tmp = floor(PID_SingleTank_P.RandomNumber_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    PID_SingleTank_DW.RandSeed = tseed;
    PID_SingleTank_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&PID_SingleTank_DW.RandSeed) * PID_SingleTank_P.RandomNumber_StdDev +
      PID_SingleTank_P.RandomNumber_Mean;

    /* End of InitializeConditions for RandomNumber: '<Root>/Random Number' */

    /* InitializeConditions for Integrator: '<S2>/Integrator' */
    PID_SingleTank_X.Integrator_CSTATE = PID_SingleTank_P.Integrator_IC;

    /* InitializeConditions for Derivative: '<S2>/Derivative' */
    PID_SingleTank_DW.TimeStampA = (rtInf);
    PID_SingleTank_DW.TimeStampB = (rtInf);
  }
}

/* Model terminate function */
void PID_SingleTank_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  PID_SingleTank_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  PID_SingleTank_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  PID_SingleTank_initialize();
}

void MdlTerminate(void)
{
  PID_SingleTank_terminate();
}

/* Registration function */
RT_MODEL_PID_SingleTank_T *PID_SingleTank(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PID_SingleTank_M, 0,
                sizeof(RT_MODEL_PID_SingleTank_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PID_SingleTank_M->solverInfo,
                          &PID_SingleTank_M->Timing.simTimeStep);
    rtsiSetTPtr(&PID_SingleTank_M->solverInfo, &rtmGetTPtr(PID_SingleTank_M));
    rtsiSetStepSizePtr(&PID_SingleTank_M->solverInfo,
                       &PID_SingleTank_M->Timing.stepSize0);
    rtsiSetdXPtr(&PID_SingleTank_M->solverInfo, &PID_SingleTank_M->derivs);
    rtsiSetContStatesPtr(&PID_SingleTank_M->solverInfo, (real_T **)
                         &PID_SingleTank_M->contStates);
    rtsiSetNumContStatesPtr(&PID_SingleTank_M->solverInfo,
      &PID_SingleTank_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PID_SingleTank_M->solverInfo,
      &PID_SingleTank_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PID_SingleTank_M->solverInfo,
      &PID_SingleTank_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PID_SingleTank_M->solverInfo,
      &PID_SingleTank_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PID_SingleTank_M->solverInfo, (&rtmGetErrorStatus
      (PID_SingleTank_M)));
    rtsiSetRTModelPtr(&PID_SingleTank_M->solverInfo, PID_SingleTank_M);
  }

  rtsiSetSimTimeStep(&PID_SingleTank_M->solverInfo, MAJOR_TIME_STEP);
  PID_SingleTank_M->intgData.y = PID_SingleTank_M->odeY;
  PID_SingleTank_M->intgData.f[0] = PID_SingleTank_M->odeF[0];
  PID_SingleTank_M->intgData.f[1] = PID_SingleTank_M->odeF[1];
  PID_SingleTank_M->intgData.f[2] = PID_SingleTank_M->odeF[2];
  PID_SingleTank_M->intgData.f[3] = PID_SingleTank_M->odeF[3];
  PID_SingleTank_M->intgData.f[4] = PID_SingleTank_M->odeF[4];
  PID_SingleTank_M->intgData.f[5] = PID_SingleTank_M->odeF[5];
  PID_SingleTank_M->contStates = ((real_T *) &PID_SingleTank_X);
  rtsiSetSolverData(&PID_SingleTank_M->solverInfo, (void *)
                    &PID_SingleTank_M->intgData);
  rtsiSetSolverName(&PID_SingleTank_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PID_SingleTank_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    PID_SingleTank_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PID_SingleTank_M->Timing.sampleTimes =
      (&PID_SingleTank_M->Timing.sampleTimesArray[0]);
    PID_SingleTank_M->Timing.offsetTimes =
      (&PID_SingleTank_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PID_SingleTank_M->Timing.sampleTimes[0] = (0.0);
    PID_SingleTank_M->Timing.sampleTimes[1] = (0.1);

    /* task offsets */
    PID_SingleTank_M->Timing.offsetTimes[0] = (0.0);
    PID_SingleTank_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(PID_SingleTank_M, &PID_SingleTank_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PID_SingleTank_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    PID_SingleTank_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PID_SingleTank_M, 1000.0);
  PID_SingleTank_M->Timing.stepSize0 = 0.1;
  PID_SingleTank_M->Timing.stepSize1 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    PID_SingleTank_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(PID_SingleTank_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(PID_SingleTank_M->rtwLogInfo, (NULL));
    rtliSetLogT(PID_SingleTank_M->rtwLogInfo, "");
    rtliSetLogX(PID_SingleTank_M->rtwLogInfo, "");
    rtliSetLogXFinal(PID_SingleTank_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(PID_SingleTank_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(PID_SingleTank_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(PID_SingleTank_M->rtwLogInfo, 0);
    rtliSetLogDecimation(PID_SingleTank_M->rtwLogInfo, 1);
    rtliSetLogY(PID_SingleTank_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(PID_SingleTank_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(PID_SingleTank_M->rtwLogInfo, (NULL));
  }

  PID_SingleTank_M->solverInfoPtr = (&PID_SingleTank_M->solverInfo);
  PID_SingleTank_M->Timing.stepSize = (0.1);
  rtsiSetFixedStepSize(&PID_SingleTank_M->solverInfo, 0.1);
  rtsiSetSolverMode(&PID_SingleTank_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  PID_SingleTank_M->blockIO = ((void *) &PID_SingleTank_B);
  (void) memset(((void *) &PID_SingleTank_B), 0,
                sizeof(B_PID_SingleTank_T));

  /* parameters */
  PID_SingleTank_M->defaultParam = ((real_T *)&PID_SingleTank_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PID_SingleTank_X;
    PID_SingleTank_M->contStates = (x);
    (void) memset((void *)&PID_SingleTank_X, 0,
                  sizeof(X_PID_SingleTank_T));
  }

  /* states (dwork) */
  PID_SingleTank_M->dwork = ((void *) &PID_SingleTank_DW);
  (void) memset((void *)&PID_SingleTank_DW, 0,
                sizeof(DW_PID_SingleTank_T));

  /* Initialize Sizes */
  PID_SingleTank_M->Sizes.numContStates = (2);/* Number of continuous states */
  PID_SingleTank_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  PID_SingleTank_M->Sizes.numY = (0);  /* Number of model outputs */
  PID_SingleTank_M->Sizes.numU = (0);  /* Number of model inputs */
  PID_SingleTank_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PID_SingleTank_M->Sizes.numSampTimes = (2);/* Number of sample times */
  PID_SingleTank_M->Sizes.numBlocks = (23);/* Number of blocks */
  PID_SingleTank_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  PID_SingleTank_M->Sizes.numBlockPrms = (15);/* Sum of parameter "widths" */
  return PID_SingleTank_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
