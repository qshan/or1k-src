/* Simulator instruction semantics for or1k64bf.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright 1996-2010 Free Software Foundation, Inc.

This file is part of the GNU simulators.

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

*/

#define WANT_CPU or1k64bf
#define WANT_CPU_OR1K64BF

#include "sim-main.h"
#include "cgen-mem.h"
#include "cgen-ops.h"

#undef GET_ATTR
#define GET_ATTR(cpu, num, attr) CGEN_ATTR_VALUE (NULL, abuf->idesc->attrs, CGEN_INSN_##attr)

/* This is used so that we can compile two copies of the semantic code,
   one with full feature support and one without that runs fast(er).
   FAST_P, when desired, is defined on the command line, -DFAST_P=1.  */
#if FAST_P
#define SEM_FN_NAME(cpu,fn) XCONCAT3 (cpu,_semf_,fn)
#undef TRACE_RESULT
#define TRACE_RESULT(cpu, abuf, name, type, val)
#else
#define SEM_FN_NAME(cpu,fn) XCONCAT3 (cpu,_sem_,fn)
#endif

/* x-invalid: --invalid-- */

static SEM_PC
SEM_FN_NAME (or1k64bf,x_invalid) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
    /* Update the recorded pc in the cpu state struct.
       Only necessary for WITH_SCACHE case, but to avoid the
       conditional compilation ....  */
    SET_H_PC (pc);
    /* Virtual insns have zero size.  Overwrite vpc with address of next insn
       using the default-insn-bitsize spec.  When executing insns in parallel
       we may want to queue the fault and continue execution.  */
    vpc = SEM_NEXT_VPC (sem_arg, pc, 4);
    vpc = sim_engine_invalid_insn (current_cpu, pc, vpc);
  }

  return vpc;
#undef FLD
}

/* x-after: --after-- */

static SEM_PC
SEM_FN_NAME (or1k64bf,x_after) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
#if WITH_SCACHE_PBB_OR1K64BF
    or1k64bf_pbb_after (current_cpu, sem_arg);
#endif
  }

  return vpc;
#undef FLD
}

/* x-before: --before-- */

static SEM_PC
SEM_FN_NAME (or1k64bf,x_before) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
#if WITH_SCACHE_PBB_OR1K64BF
    or1k64bf_pbb_before (current_cpu, sem_arg);
#endif
  }

  return vpc;
#undef FLD
}

/* x-cti-chain: --cti-chain-- */

static SEM_PC
SEM_FN_NAME (or1k64bf,x_cti_chain) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
#if WITH_SCACHE_PBB_OR1K64BF
#ifdef DEFINE_SWITCH
    vpc = or1k64bf_pbb_cti_chain (current_cpu, sem_arg,
			       pbb_br_type, pbb_br_npc);
    BREAK (sem);
#else
    /* FIXME: Allow provision of explicit ifmt spec in insn spec.  */
    vpc = or1k64bf_pbb_cti_chain (current_cpu, sem_arg,
			       CPU_PBB_BR_TYPE (current_cpu),
			       CPU_PBB_BR_NPC (current_cpu));
#endif
#endif
  }

  return vpc;
#undef FLD
}

/* x-chain: --chain-- */

static SEM_PC
SEM_FN_NAME (or1k64bf,x_chain) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
#if WITH_SCACHE_PBB_OR1K64BF
    vpc = or1k64bf_pbb_chain (current_cpu, sem_arg);
#ifdef DEFINE_SWITCH
    BREAK (sem);
#endif
#endif
  }

  return vpc;
#undef FLD
}

/* x-begin: --begin-- */

static SEM_PC
SEM_FN_NAME (or1k64bf,x_begin) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 0);

  {
#if WITH_SCACHE_PBB_OR1K64BF
#if defined DEFINE_SWITCH || defined FAST_P
    /* In the switch case FAST_P is a constant, allowing several optimizations
       in any called inline functions.  */
    vpc = or1k64bf_pbb_begin (current_cpu, FAST_P);
#else
#if 0 /* cgen engine can't handle dynamic fast/full switching yet.  */
    vpc = or1k64bf_pbb_begin (current_cpu, STATE_RUN_FAST_P (CPU_STATE (current_cpu)));
#else
    vpc = or1k64bf_pbb_begin (current_cpu, 0);
#endif
#endif
#endif
  }

  return vpc;
#undef FLD
}

/* l-j: l.j ${disp26} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_j) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_j.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
  {
    UDI opval = FLD (i_disp26);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    TRACE_RESULT (current_cpu, abuf, "pc", 'D', opval);
  }
}
if (GET_H_SYS_CPUCFGR_ND ()) {
if (1)
  SEM_SKIP_INSN (current_cpu, sem_arg, vpc);
}
}

  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* l-jal: l.jal ${disp26} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_jal) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_j.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  {
    UDI opval = ADDDI (pc, ((GET_H_SYS_CPUCFGR_ND ()) ? (4) : (8)));
    SET_H_GPR (((UINT) 9), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
{
{
  {
    UDI opval = FLD (i_disp26);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    TRACE_RESULT (current_cpu, abuf, "pc", 'D', opval);
  }
}
if (GET_H_SYS_CPUCFGR_ND ()) {
if (1)
  SEM_SKIP_INSN (current_cpu, sem_arg, vpc);
}
}
}

  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* l-jr: l.jr $rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_jr) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
  {
    UDI opval = GET_H_GPR (FLD (f_r3));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    TRACE_RESULT (current_cpu, abuf, "pc", 'D', opval);
  }
}
if (GET_H_SYS_CPUCFGR_ND ()) {
if (1)
  SEM_SKIP_INSN (current_cpu, sem_arg, vpc);
}
}

  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* l-jalr: l.jalr $rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_jalr) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  {
    UDI opval = ADDDI (pc, ((GET_H_SYS_CPUCFGR_ND ()) ? (4) : (8)));
    SET_H_GPR (((UINT) 9), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
{
{
  {
    UDI opval = GET_H_GPR (FLD (f_r3));
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    TRACE_RESULT (current_cpu, abuf, "pc", 'D', opval);
  }
}
if (GET_H_SYS_CPUCFGR_ND ()) {
if (1)
  SEM_SKIP_INSN (current_cpu, sem_arg, vpc);
}
}
}

  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* l-bnf: l.bnf ${disp26} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_bnf) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_j.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
if (NOTDI (GET_H_SYS_SR_F ())) {
{
  {
    UDI opval = FLD (i_disp26);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 4);
    TRACE_RESULT (current_cpu, abuf, "pc", 'D', opval);
  }
}
} else {
if (GET_H_SYS_CPUCFGR_ND ()) {
{
  {
    UDI opval = ADDDI (pc, 4);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 4);
    TRACE_RESULT (current_cpu, abuf, "pc", 'D', opval);
  }
}
}
}
if (GET_H_SYS_CPUCFGR_ND ()) {
if (1)
  SEM_SKIP_INSN (current_cpu, sem_arg, vpc);
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* l-bf: l.bf ${disp26} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_bf) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_j.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_BRANCH_INIT
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
if (GET_H_SYS_SR_F ()) {
{
  {
    UDI opval = FLD (i_disp26);
    SEM_BRANCH_VIA_CACHE (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 4);
    TRACE_RESULT (current_cpu, abuf, "pc", 'D', opval);
  }
}
} else {
if (GET_H_SYS_CPUCFGR_ND ()) {
{
  {
    UDI opval = ADDDI (pc, 4);
    SEM_BRANCH_VIA_ADDR (current_cpu, sem_arg, opval, vpc);
    written |= (1 << 4);
    TRACE_RESULT (current_cpu, abuf, "pc", 'D', opval);
  }
}
}
}
if (GET_H_SYS_CPUCFGR_ND ()) {
if (1)
  SEM_SKIP_INSN (current_cpu, sem_arg, vpc);
}
}

  abuf->written = written;
  SEM_BRANCH_FINI (vpc);
  return vpc;
#undef FLD
}

/* l-trap: l.trap ${uimm16} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_trap) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

or1k64bf_exception (current_cpu, pc, EXCEPT_TRAP);

  return vpc;
#undef FLD
}

/* l-sys: l.sys ${uimm16} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sys) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

or1k64bf_exception (current_cpu, pc, EXCEPT_SYSCALL);

  return vpc;
#undef FLD
}

/* l-rfe: l.rfe */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_rfe) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

or1k64bf_rfe (current_cpu, pc);

  return vpc;
#undef FLD
}

/* l-nop-imm: l.nop ${uimm16} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_nop_imm) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_mfspr.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

or1k64bf_nop (current_cpu, ZEXTSIDI (FLD (f_uimm16)));

  return vpc;
#undef FLD
}

/* l-movhi: l.movhi $rD,$uimm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_movhi) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_mfspr.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = SLLDI (ZEXTSIDI (FLD (f_uimm16)), 16);
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-macrc: l.macrc $rD */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_macrc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  UDI temp0;UDI temp1;UDI temp2;
  temp0 = GET_H_MAC_MACLO ();
  temp1 = 0;
  temp2 = 0;
  {
    UDI opval = temp0;
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
  {
    UDI opval = temp1;
    SET_H_MAC_MACLO (opval);
    TRACE_RESULT (current_cpu, abuf, "mac-maclo", 'D', opval);
  }
  {
    UDI opval = temp2;
    SET_H_MAC_MACHI (opval);
    TRACE_RESULT (current_cpu, abuf, "mac-machi", 'D', opval);
  }
}

  return vpc;
#undef FLD
}

/* l-mfspr: l.mfspr $rD,$rA,${uimm16} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_mfspr) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_mfspr.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = or1k64bf_mfspr (current_cpu, pc, FLD (f_r1), ORDI (GET_H_GPR (FLD (f_r2)), ZEXTSIDI (FLD (f_uimm16))));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-mtspr: l.mtspr $rA,$rB,${uimm16-split} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_mtspr) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_mtspr.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

or1k64bf_mtspr (current_cpu, pc, ORDI (GET_H_GPR (FLD (f_r2)), ZEXTSIDI (FLD (f_uimm16_split))), GET_H_GPR (FLD (f_r3)));

  return vpc;
#undef FLD
}

/* l-lwz: l.lwz $rD,${simm16}($rA) */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_lwz) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = ZEXTSIDI (GETMEMUSI (current_cpu, pc, or1k64bf_make_load_store_addr (current_cpu, GET_H_GPR (FLD (f_r2)), EXTSISI (FLD (f_simm16)), 4)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-lws: l.lws $rD,${simm16}($rA) */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_lws) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DI opval = EXTSIDI (GETMEMSI (current_cpu, pc, or1k64bf_make_load_store_addr (current_cpu, GET_H_GPR (FLD (f_r2)), EXTSISI (FLD (f_simm16)), 4)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-lbz: l.lbz $rD,${simm16}($rA) */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_lbz) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = ZEXTQIDI (GETMEMUQI (current_cpu, pc, or1k64bf_make_load_store_addr (current_cpu, GET_H_GPR (FLD (f_r2)), EXTSISI (FLD (f_simm16)), 1)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-lbs: l.lbs $rD,${simm16}($rA) */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_lbs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DI opval = EXTQIDI (GETMEMQI (current_cpu, pc, or1k64bf_make_load_store_addr (current_cpu, GET_H_GPR (FLD (f_r2)), EXTSISI (FLD (f_simm16)), 1)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-lhz: l.lhz $rD,${simm16}($rA) */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_lhz) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = ZEXTHIDI (GETMEMUHI (current_cpu, pc, or1k64bf_make_load_store_addr (current_cpu, GET_H_GPR (FLD (f_r2)), EXTSISI (FLD (f_simm16)), 2)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-lhs: l.lhs $rD,${simm16}($rA) */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_lhs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DI opval = EXTHIDI (GETMEMHI (current_cpu, pc, or1k64bf_make_load_store_addr (current_cpu, GET_H_GPR (FLD (f_r2)), EXTSISI (FLD (f_simm16)), 2)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sw: l.sw ${simm16-split}($rA),$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sw) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sw.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    USI opval = TRUNCDISI (GET_H_GPR (FLD (f_r3)));
    SETMEMUSI (current_cpu, pc, or1k64bf_make_load_store_addr (current_cpu, GET_H_GPR (FLD (f_r2)), EXTSISI (FLD (f_simm16_split)), 4), opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* l-sb: l.sb ${simm16-split}($rA),$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sw.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UQI opval = TRUNCDIQI (GET_H_GPR (FLD (f_r3)));
    SETMEMUQI (current_cpu, pc, or1k64bf_make_load_store_addr (current_cpu, GET_H_GPR (FLD (f_r2)), EXTSISI (FLD (f_simm16_split)), 1), opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* l-sh: l.sh ${simm16-split}($rA),$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sh) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sw.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UHI opval = TRUNCDIHI (GET_H_GPR (FLD (f_r3)));
    SETMEMUHI (current_cpu, pc, or1k64bf_make_load_store_addr (current_cpu, GET_H_GPR (FLD (f_r2)), EXTSISI (FLD (f_simm16_split)), 2), opval);
    TRACE_RESULT (current_cpu, abuf, "memory", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* l-sll: l.sll $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sll) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = SLLDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-slli: l.slli $rD,$rA,${uimm6} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_slli) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = SLLDI (GET_H_GPR (FLD (f_r2)), FLD (f_uimm6));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-srl: l.srl $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_srl) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = SRLDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-srli: l.srli $rD,$rA,${uimm6} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_srli) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = SRLDI (GET_H_GPR (FLD (f_r2)), FLD (f_uimm6));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sra: l.sra $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sra) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = SRADI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-srai: l.srai $rD,$rA,${uimm6} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_srai) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = SRADI (GET_H_GPR (FLD (f_r2)), FLD (f_uimm6));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-ror: l.ror $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_ror) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = RORDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-rori: l.rori $rD,$rA,${uimm6} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_rori) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = RORDI (GET_H_GPR (FLD (f_r2)), FLD (f_uimm6));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-and: l.and $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_and) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = ANDDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-or: l.or $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_or) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = ORDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-xor: l.xor $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_xor) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = XORDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-add: l.add $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_add) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
  {
    BI opval = ADDCFDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)), 0);
    SET_H_SYS_SR_CY (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
  {
    BI opval = ADDOFDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)), 0);
    SET_H_SYS_SR_OV (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-ov", 'x', opval);
  }
  {
    UDI opval = ADDDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}
if (ANDIF (GET_H_SYS_SR_OV (), GET_H_SYS_SR_OVE ())) {
or1k64bf_exception (current_cpu, pc, EXCEPT_RANGE);
}
}

  return vpc;
#undef FLD
}

/* l-sub: l.sub $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sub) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
  {
    BI opval = SUBCFDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)), 0);
    SET_H_SYS_SR_CY (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
  {
    BI opval = SUBOFDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)), 0);
    SET_H_SYS_SR_OV (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-ov", 'x', opval);
  }
  {
    UDI opval = SUBDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}
if (ANDIF (GET_H_SYS_SR_OV (), GET_H_SYS_SR_OVE ())) {
or1k64bf_exception (current_cpu, pc, EXCEPT_RANGE);
}
}

  return vpc;
#undef FLD
}

/* l-addc: l.addc $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_addc) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
  BI tmp_tmp_sys_sr_cy;
  tmp_tmp_sys_sr_cy = GET_H_SYS_SR_CY ();
  {
    BI opval = ADDCFDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)), GET_H_SYS_SR_CY ());
    SET_H_SYS_SR_CY (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
  {
    BI opval = ADDOFDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)), GET_H_SYS_SR_CY ());
    SET_H_SYS_SR_OV (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-ov", 'x', opval);
  }
  {
    UDI opval = ADDCDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)), tmp_tmp_sys_sr_cy);
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}
if (ANDIF (GET_H_SYS_SR_OV (), GET_H_SYS_SR_OVE ())) {
or1k64bf_exception (current_cpu, pc, EXCEPT_RANGE);
}
}

  return vpc;
#undef FLD
}

/* l-mul: l.mul $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_mul) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
  {
    BI opval = MUL2OFDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_OV (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-ov", 'x', opval);
  }
  {
    BI opval = MUL1OFDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_CY (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
  {
    UDI opval = MULDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}
if (ANDIF (GET_H_SYS_SR_OV (), GET_H_SYS_SR_OVE ())) {
or1k64bf_exception (current_cpu, pc, EXCEPT_RANGE);
}
}

  return vpc;
#undef FLD
}

/* l-mulu: l.mulu $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_mulu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
  {
    BI opval = 0;
    SET_H_SYS_SR_OV (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-ov", 'x', opval);
  }
  {
    BI opval = MUL1OFDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_CY (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
  {
    UDI opval = MULDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}
if (ANDIF (GET_H_SYS_SR_OV (), GET_H_SYS_SR_OVE ())) {
or1k64bf_exception (current_cpu, pc, EXCEPT_RANGE);
}
}

  return vpc;
#undef FLD
}

/* l-div: l.div $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_div) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
if (NEDI (GET_H_GPR (FLD (f_r3)), 0)) {
{
  {
    BI opval = 0;
    SET_H_SYS_SR_CY (opval);
    written |= (1 << 6);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
  {
    DI opval = DIVDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    written |= (1 << 5);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}
} else {
  {
    BI opval = 1;
    SET_H_SYS_SR_CY (opval);
    written |= (1 << 6);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
}
  {
    BI opval = 0;
    SET_H_SYS_SR_OV (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-ov", 'x', opval);
  }
if (ANDIF (GET_H_SYS_SR_CY (), GET_H_SYS_SR_OVE ())) {
or1k64bf_exception (current_cpu, pc, EXCEPT_RANGE);
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* l-divu: l.divu $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_divu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
if (NEDI (GET_H_GPR (FLD (f_r3)), 0)) {
{
  {
    BI opval = 0;
    SET_H_SYS_SR_CY (opval);
    written |= (1 << 6);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
  {
    UDI opval = DIVDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_GPR (FLD (f_r1), opval);
    written |= (1 << 5);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}
} else {
  {
    BI opval = 1;
    SET_H_SYS_SR_CY (opval);
    written |= (1 << 6);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
}
  {
    BI opval = 0;
    SET_H_SYS_SR_OV (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-ov", 'x', opval);
  }
if (ANDIF (GET_H_SYS_SR_CY (), GET_H_SYS_SR_OVE ())) {
or1k64bf_exception (current_cpu, pc, EXCEPT_RANGE);
}
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* l-ff1: l.ff1 $rD,$rA */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_ff1) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = or1k64bf_ff1 (current_cpu, GET_H_GPR (FLD (f_r2)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-fl1: l.fl1 $rD,$rA */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_fl1) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = or1k64bf_fl1 (current_cpu, GET_H_GPR (FLD (f_r2)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-andi: l.andi $rD,$rA,$uimm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_andi) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_mfspr.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = ANDDI (GET_H_GPR (FLD (f_r2)), ZEXTSIDI (FLD (f_uimm16)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-ori: l.ori $rD,$rA,$uimm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_ori) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_mfspr.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = ORDI (GET_H_GPR (FLD (f_r2)), ZEXTSIDI (FLD (f_uimm16)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-xori: l.xori $rD,$rA,$simm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_xori) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = XORDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-addi: l.addi $rD,$rA,$simm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_addi) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
  {
    BI opval = ADDCFDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)), 0);
    SET_H_SYS_SR_CY (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
  {
    BI opval = ADDOFDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)), 0);
    SET_H_SYS_SR_OV (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-ov", 'x', opval);
  }
  {
    UDI opval = ADDDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}
if (ANDIF (GET_H_SYS_SR_OV (), GET_H_SYS_SR_OVE ())) {
or1k64bf_exception (current_cpu, pc, EXCEPT_RANGE);
}
}

  return vpc;
#undef FLD
}

/* l-addic: l.addic $rD,$rA,$simm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_addic) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
  BI tmp_tmp_sys_sr_cy;
  tmp_tmp_sys_sr_cy = GET_H_SYS_SR_CY ();
  {
    BI opval = ADDCFDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)), GET_H_SYS_SR_CY ());
    SET_H_SYS_SR_CY (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'x', opval);
  }
  {
    BI opval = ADDOFDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)), GET_H_SYS_SR_CY ());
    SET_H_SYS_SR_OV (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-ov", 'x', opval);
  }
  {
    DI opval = ADDCDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)), tmp_tmp_sys_sr_cy);
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}
if (ANDIF (GET_H_SYS_SR_OV (), GET_H_SYS_SR_OVE ())) {
or1k64bf_exception (current_cpu, pc, EXCEPT_RANGE);
}
}

  return vpc;
#undef FLD
}

/* l-muli: l.muli $rD,$rA,$simm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_muli) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
{
  {
    UDI opval = MUL2OFDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_SYS_SR_OV (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-ov", 'D', opval);
  }
  {
    UDI opval = MUL1OFDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_SYS_SR_CY (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-cy", 'D', opval);
  }
  {
    UDI opval = MULDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}
if (ANDIF (GET_H_SYS_SR_OV (), GET_H_SYS_SR_OVE ())) {
or1k64bf_exception (current_cpu, pc, EXCEPT_RANGE);
}
}

  return vpc;
#undef FLD
}

/* l-exths: l.exths $rD,$rA */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_exths) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = EXTHIDI (TRUNCDIHI (GET_H_GPR (FLD (f_r2))));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-extbs: l.extbs $rD,$rA */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_extbs) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = EXTQIDI (TRUNCDIQI (GET_H_GPR (FLD (f_r2))));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-exthz: l.exthz $rD,$rA */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_exthz) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = ZEXTHIDI (TRUNCDIHI (GET_H_GPR (FLD (f_r2))));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-extbz: l.extbz $rD,$rA */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_extbz) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = ZEXTQIDI (TRUNCDIQI (GET_H_GPR (FLD (f_r2))));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-extws: l.extws $rD,$rA */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_extws) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = EXTSIDI (TRUNCDISI (GET_H_GPR (FLD (f_r2))));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-extwz: l.extwz $rD,$rA */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_extwz) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = ZEXTSISI (TRUNCDISI (GET_H_GPR (FLD (f_r2))));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-cmov: l.cmov $rD,$rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_cmov) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

if (GET_H_SYS_SR_F ()) {
  {
    UDI opval = GET_H_GPR (FLD (f_r2));
    SET_H_GPR (FLD (f_r1), opval);
    written |= (1 << 3);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
} else {
  {
    UDI opval = GET_H_GPR (FLD (f_r3));
    SET_H_GPR (FLD (f_r1), opval);
    written |= (1 << 3);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }
}

  abuf->written = written;
  return vpc;
#undef FLD
}

/* l-sfgtu: l.sfgtu $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfgtu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = GTUDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfgeu: l.sfgeu $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfgeu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = GEUDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfltu: l.sfltu $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfltu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = LTUDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfleu: l.sfleu $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfleu) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = LEUDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfgts: l.sfgts $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfgts) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = GTDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfges: l.sfges $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfges) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = GEDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sflts: l.sflts $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sflts) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = LTDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfles: l.sfles $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfles) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = LEDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfgtui: l.sfgtui $rA,$uimm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfgtui) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_mfspr.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = GTUDI (GET_H_GPR (FLD (f_r2)), ZEXTSIDI (FLD (f_uimm16)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfgeui: l.sfgeui $rA,$uimm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfgeui) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_mfspr.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = GEUDI (GET_H_GPR (FLD (f_r2)), ZEXTSIDI (FLD (f_uimm16)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfltui: l.sfltui $rA,$uimm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfltui) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_mfspr.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = LTUDI (GET_H_GPR (FLD (f_r2)), ZEXTSIDI (FLD (f_uimm16)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfleui: l.sfleui $rA,$uimm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfleui) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_mfspr.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = LEUDI (GET_H_GPR (FLD (f_r2)), ZEXTSIDI (FLD (f_uimm16)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfgtsi: l.sfgtsi $rA,${simm16} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfgtsi) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = GTDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfgesi: l.sfgesi $rA,${simm16} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfgesi) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = GEDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfltsi: l.sfltsi $rA,${simm16} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfltsi) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = LTDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sflesi: l.sflesi $rA,${simm16} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sflesi) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = LEDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfeq: l.sfeq $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfeq) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = EQDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfeqi: l.sfeqi $rA,$simm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfeqi) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = EQDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfne: l.sfne $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfne) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = NEDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-sfnei: l.sfnei $rA,$simm16 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_sfnei) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_lwz.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    UDI opval = NEDI (GET_H_GPR (FLD (f_r2)), EXTSIDI (FLD (f_simm16)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* l-mac: l.mac $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_mac) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  DI tmp_prod;
  DI tmp_result;
  tmp_prod = MULDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
  tmp_result = ADDDI (JOINSIDI (GET_H_MAC_MACHI (), GET_H_MAC_MACLO ()), EXTDIDI (tmp_prod));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_MAC_MACHI (opval);
    TRACE_RESULT (current_cpu, abuf, "mac-machi", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_MAC_MACLO (opval);
    TRACE_RESULT (current_cpu, abuf, "mac-maclo", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* l-msb: l.msb $rA,$rB */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_msb) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  DI tmp_prod;
  DI tmp_result;
  tmp_prod = MULDI (GET_H_GPR (FLD (f_r2)), GET_H_GPR (FLD (f_r3)));
  tmp_result = SUBDI (JOINSIDI (GET_H_MAC_MACHI (), GET_H_MAC_MACLO ()), EXTDIDI (tmp_prod));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_MAC_MACHI (opval);
    TRACE_RESULT (current_cpu, abuf, "mac-machi", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_MAC_MACLO (opval);
    TRACE_RESULT (current_cpu, abuf, "mac-maclo", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* l-maci: l.maci $rA,${simm16-split} */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_maci) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sw.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

{
  DI tmp_prod;
  DI tmp_result;
  tmp_prod = MULDI (EXTSIDI (FLD (f_simm16_split)), GET_H_GPR (FLD (f_r2)));
  tmp_result = ADDDI (JOINSIDI (GET_H_MAC_MACHI (), GET_H_MAC_MACLO ()), EXTDIDI (tmp_prod));
  {
    SI opval = SUBWORDDISI (tmp_result, 0);
    SET_H_MAC_MACHI (opval);
    TRACE_RESULT (current_cpu, abuf, "mac-machi", 'x', opval);
  }
  {
    SI opval = SUBWORDDISI (tmp_result, 1);
    SET_H_MAC_MACLO (opval);
    TRACE_RESULT (current_cpu, abuf, "mac-maclo", 'x', opval);
  }
}

  return vpc;
#undef FLD
}

/* l-cust1: l.cust1 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_cust1) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* l-cust2: l.cust2 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_cust2) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* l-cust3: l.cust3 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_cust3) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* l-cust4: l.cust4 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_cust4) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* l-cust5: l.cust5 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_cust5) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* l-cust6: l.cust6 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_cust6) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* l-cust7: l.cust7 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_cust7) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* l-cust8: l.cust8 */

static SEM_PC
SEM_FN_NAME (or1k64bf,l_cust8) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* lf-add-s: lf.add.s $rDSF,$rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_add_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    SF opval = CGEN_CPU_FPU (current_cpu)->ops->addsf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_FSR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fsr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-add-d: lf.add.d $rDDF,$rADF,$rBDF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_add_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DF opval = CGEN_CPU_FPU (current_cpu)->ops->adddf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_FDR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fdr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-sub-s: lf.sub.s $rDSF,$rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_sub_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    SF opval = CGEN_CPU_FPU (current_cpu)->ops->subsf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_FSR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fsr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-sub-d: lf.sub.d $rDDF,$rADF,$rBDF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_sub_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DF opval = CGEN_CPU_FPU (current_cpu)->ops->subdf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_FDR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fdr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-mul-s: lf.mul.s $rDSF,$rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_mul_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    SF opval = CGEN_CPU_FPU (current_cpu)->ops->mulsf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_FSR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fsr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-mul-d: lf.mul.d $rDDF,$rADF,$rBDF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_mul_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DF opval = CGEN_CPU_FPU (current_cpu)->ops->muldf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_FDR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fdr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-div-s: lf.div.s $rDSF,$rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_div_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    SF opval = CGEN_CPU_FPU (current_cpu)->ops->divsf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_FSR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fsr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-div-d: lf.div.d $rDDF,$rADF,$rBDF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_div_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DF opval = CGEN_CPU_FPU (current_cpu)->ops->divdf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_FDR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fdr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-rem-s: lf.rem.s $rDSF,$rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_rem_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    SF opval = CGEN_CPU_FPU (current_cpu)->ops->remsf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_FSR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fsr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-rem-d: lf.rem.d $rDDF,$rADF,$rBDF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_rem_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DF opval = CGEN_CPU_FPU (current_cpu)->ops->moddf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_FDR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fdr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-itof-s: lf.itof.s $rDSF,$rA */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_itof_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    SF opval = CGEN_CPU_FPU (current_cpu)->ops->floatsisf (CGEN_CPU_FPU (current_cpu), (GET_H_SYS_FPCSR_RM () == 0) ? (1) : (GET_H_SYS_FPCSR_RM () == 1) ? (3) : (GET_H_SYS_FPCSR_RM () == 2) ? (4) : (5), TRUNCDISI (GET_H_GPR (FLD (f_r2))));
    SET_H_FSR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fsr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-itof-d: lf.itof.d $rDSF,$rA */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_itof_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DF opval = CGEN_CPU_FPU (current_cpu)->ops->floatdidf (CGEN_CPU_FPU (current_cpu), (GET_H_SYS_FPCSR_RM () == 0) ? (1) : (GET_H_SYS_FPCSR_RM () == 1) ? (3) : (GET_H_SYS_FPCSR_RM () == 2) ? (4) : (5), GET_H_GPR (FLD (f_r2)));
    SET_H_FDR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fdr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-ftoi-s: lf.ftoi.s $rD,$rASF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_ftoi_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DI opval = EXTSIDI (CGEN_CPU_FPU (current_cpu)->ops->fixsfsi (CGEN_CPU_FPU (current_cpu), (GET_H_SYS_FPCSR_RM () == 0) ? (1) : (GET_H_SYS_FPCSR_RM () == 1) ? (3) : (GET_H_SYS_FPCSR_RM () == 2) ? (4) : (5), GET_H_FSR (FLD (f_r2))));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* lf-ftoi-d: lf.ftoi.d $rD,$rADF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_ftoi_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DI opval = CGEN_CPU_FPU (current_cpu)->ops->fixdfdi (CGEN_CPU_FPU (current_cpu), (GET_H_SYS_FPCSR_RM () == 0) ? (1) : (GET_H_SYS_FPCSR_RM () == 1) ? (3) : (GET_H_SYS_FPCSR_RM () == 2) ? (4) : (5), GET_H_FDR (FLD (f_r1)));
    SET_H_GPR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "gpr", 'D', opval);
  }

  return vpc;
#undef FLD
}

/* lf-eq-s: lf.sfeq.s $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_eq_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->eqsf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-eq-d: lf.sfeq.d $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_eq_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->eqdf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-ne-s: lf.sfne.s $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_ne_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->nesf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-ne-d: lf.sfne.d $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_ne_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->nedf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-ge-s: lf.sfge.s $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_ge_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->gesf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-ge-d: lf.sfge.d $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_ge_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->gedf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-gt-s: lf.sfgt.s $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_gt_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->gtsf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-gt-d: lf.sfgt.d $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_gt_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->gtdf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-lt-s: lf.sflt.s $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_lt_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->ltsf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-lt-d: lf.sflt.d $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_lt_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->ltdf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-le-s: lf.sfle.s $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_le_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->lesf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-le-d: lf.sfle.d $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_le_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    BI opval = CGEN_CPU_FPU (current_cpu)->ops->ledf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1)));
    SET_H_SYS_SR_F (opval);
    TRACE_RESULT (current_cpu, abuf, "sys-sr-f", 'x', opval);
  }

  return vpc;
#undef FLD
}

/* lf-madd-s: lf.madd.s $rDSF,$rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_madd_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_sll.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    SF opval = CGEN_CPU_FPU (current_cpu)->ops->addsf (CGEN_CPU_FPU (current_cpu), CGEN_CPU_FPU (current_cpu)->ops->mulsf (CGEN_CPU_FPU (current_cpu), GET_H_FSR (FLD (f_r2)), GET_H_FSR (FLD (f_r3))), GET_H_FSR (FLD (f_r1)));
    SET_H_FSR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fsr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-madd-d: lf.madd.d $rDDF,$rADF,$rBDF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_madd_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_l_slli.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

  {
    DF opval = CGEN_CPU_FPU (current_cpu)->ops->adddf (CGEN_CPU_FPU (current_cpu), CGEN_CPU_FPU (current_cpu)->ops->muldf (CGEN_CPU_FPU (current_cpu), GET_H_FDR (FLD (f_r1)), GET_H_FDR (FLD (f_r1))), GET_H_FDR (FLD (f_r1)));
    SET_H_FDR (FLD (f_r1), opval);
    TRACE_RESULT (current_cpu, abuf, "fdr", 'f', opval);
  }

  return vpc;
#undef FLD
}

/* lf-cust1-s: lf.cust1.s $rASF,$rBSF */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_cust1_s) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* lf-cust1-d: lf.cust1.d */

static SEM_PC
SEM_FN_NAME (or1k64bf,lf_cust1_d) (SIM_CPU *current_cpu, SEM_ARG sem_arg)
{
#define FLD(f) abuf->fields.sfmt_empty.f
  ARGBUF *abuf = SEM_ARGBUF (sem_arg);
  int UNUSED written = 0;
  IADDR UNUSED pc = abuf->addr;
  SEM_PC vpc = SEM_NEXT_VPC (sem_arg, pc, 4);

((void) 0); /*nop*/

  return vpc;
#undef FLD
}

/* Table of all semantic fns.  */

static const struct sem_fn_desc sem_fns[] = {
  { OR1K64BF_INSN_X_INVALID, SEM_FN_NAME (or1k64bf,x_invalid) },
  { OR1K64BF_INSN_X_AFTER, SEM_FN_NAME (or1k64bf,x_after) },
  { OR1K64BF_INSN_X_BEFORE, SEM_FN_NAME (or1k64bf,x_before) },
  { OR1K64BF_INSN_X_CTI_CHAIN, SEM_FN_NAME (or1k64bf,x_cti_chain) },
  { OR1K64BF_INSN_X_CHAIN, SEM_FN_NAME (or1k64bf,x_chain) },
  { OR1K64BF_INSN_X_BEGIN, SEM_FN_NAME (or1k64bf,x_begin) },
  { OR1K64BF_INSN_L_J, SEM_FN_NAME (or1k64bf,l_j) },
  { OR1K64BF_INSN_L_JAL, SEM_FN_NAME (or1k64bf,l_jal) },
  { OR1K64BF_INSN_L_JR, SEM_FN_NAME (or1k64bf,l_jr) },
  { OR1K64BF_INSN_L_JALR, SEM_FN_NAME (or1k64bf,l_jalr) },
  { OR1K64BF_INSN_L_BNF, SEM_FN_NAME (or1k64bf,l_bnf) },
  { OR1K64BF_INSN_L_BF, SEM_FN_NAME (or1k64bf,l_bf) },
  { OR1K64BF_INSN_L_TRAP, SEM_FN_NAME (or1k64bf,l_trap) },
  { OR1K64BF_INSN_L_SYS, SEM_FN_NAME (or1k64bf,l_sys) },
  { OR1K64BF_INSN_L_RFE, SEM_FN_NAME (or1k64bf,l_rfe) },
  { OR1K64BF_INSN_L_NOP_IMM, SEM_FN_NAME (or1k64bf,l_nop_imm) },
  { OR1K64BF_INSN_L_MOVHI, SEM_FN_NAME (or1k64bf,l_movhi) },
  { OR1K64BF_INSN_L_MACRC, SEM_FN_NAME (or1k64bf,l_macrc) },
  { OR1K64BF_INSN_L_MFSPR, SEM_FN_NAME (or1k64bf,l_mfspr) },
  { OR1K64BF_INSN_L_MTSPR, SEM_FN_NAME (or1k64bf,l_mtspr) },
  { OR1K64BF_INSN_L_LWZ, SEM_FN_NAME (or1k64bf,l_lwz) },
  { OR1K64BF_INSN_L_LWS, SEM_FN_NAME (or1k64bf,l_lws) },
  { OR1K64BF_INSN_L_LBZ, SEM_FN_NAME (or1k64bf,l_lbz) },
  { OR1K64BF_INSN_L_LBS, SEM_FN_NAME (or1k64bf,l_lbs) },
  { OR1K64BF_INSN_L_LHZ, SEM_FN_NAME (or1k64bf,l_lhz) },
  { OR1K64BF_INSN_L_LHS, SEM_FN_NAME (or1k64bf,l_lhs) },
  { OR1K64BF_INSN_L_SW, SEM_FN_NAME (or1k64bf,l_sw) },
  { OR1K64BF_INSN_L_SB, SEM_FN_NAME (or1k64bf,l_sb) },
  { OR1K64BF_INSN_L_SH, SEM_FN_NAME (or1k64bf,l_sh) },
  { OR1K64BF_INSN_L_SLL, SEM_FN_NAME (or1k64bf,l_sll) },
  { OR1K64BF_INSN_L_SLLI, SEM_FN_NAME (or1k64bf,l_slli) },
  { OR1K64BF_INSN_L_SRL, SEM_FN_NAME (or1k64bf,l_srl) },
  { OR1K64BF_INSN_L_SRLI, SEM_FN_NAME (or1k64bf,l_srli) },
  { OR1K64BF_INSN_L_SRA, SEM_FN_NAME (or1k64bf,l_sra) },
  { OR1K64BF_INSN_L_SRAI, SEM_FN_NAME (or1k64bf,l_srai) },
  { OR1K64BF_INSN_L_ROR, SEM_FN_NAME (or1k64bf,l_ror) },
  { OR1K64BF_INSN_L_RORI, SEM_FN_NAME (or1k64bf,l_rori) },
  { OR1K64BF_INSN_L_AND, SEM_FN_NAME (or1k64bf,l_and) },
  { OR1K64BF_INSN_L_OR, SEM_FN_NAME (or1k64bf,l_or) },
  { OR1K64BF_INSN_L_XOR, SEM_FN_NAME (or1k64bf,l_xor) },
  { OR1K64BF_INSN_L_ADD, SEM_FN_NAME (or1k64bf,l_add) },
  { OR1K64BF_INSN_L_SUB, SEM_FN_NAME (or1k64bf,l_sub) },
  { OR1K64BF_INSN_L_ADDC, SEM_FN_NAME (or1k64bf,l_addc) },
  { OR1K64BF_INSN_L_MUL, SEM_FN_NAME (or1k64bf,l_mul) },
  { OR1K64BF_INSN_L_MULU, SEM_FN_NAME (or1k64bf,l_mulu) },
  { OR1K64BF_INSN_L_DIV, SEM_FN_NAME (or1k64bf,l_div) },
  { OR1K64BF_INSN_L_DIVU, SEM_FN_NAME (or1k64bf,l_divu) },
  { OR1K64BF_INSN_L_FF1, SEM_FN_NAME (or1k64bf,l_ff1) },
  { OR1K64BF_INSN_L_FL1, SEM_FN_NAME (or1k64bf,l_fl1) },
  { OR1K64BF_INSN_L_ANDI, SEM_FN_NAME (or1k64bf,l_andi) },
  { OR1K64BF_INSN_L_ORI, SEM_FN_NAME (or1k64bf,l_ori) },
  { OR1K64BF_INSN_L_XORI, SEM_FN_NAME (or1k64bf,l_xori) },
  { OR1K64BF_INSN_L_ADDI, SEM_FN_NAME (or1k64bf,l_addi) },
  { OR1K64BF_INSN_L_ADDIC, SEM_FN_NAME (or1k64bf,l_addic) },
  { OR1K64BF_INSN_L_MULI, SEM_FN_NAME (or1k64bf,l_muli) },
  { OR1K64BF_INSN_L_EXTHS, SEM_FN_NAME (or1k64bf,l_exths) },
  { OR1K64BF_INSN_L_EXTBS, SEM_FN_NAME (or1k64bf,l_extbs) },
  { OR1K64BF_INSN_L_EXTHZ, SEM_FN_NAME (or1k64bf,l_exthz) },
  { OR1K64BF_INSN_L_EXTBZ, SEM_FN_NAME (or1k64bf,l_extbz) },
  { OR1K64BF_INSN_L_EXTWS, SEM_FN_NAME (or1k64bf,l_extws) },
  { OR1K64BF_INSN_L_EXTWZ, SEM_FN_NAME (or1k64bf,l_extwz) },
  { OR1K64BF_INSN_L_CMOV, SEM_FN_NAME (or1k64bf,l_cmov) },
  { OR1K64BF_INSN_L_SFGTU, SEM_FN_NAME (or1k64bf,l_sfgtu) },
  { OR1K64BF_INSN_L_SFGEU, SEM_FN_NAME (or1k64bf,l_sfgeu) },
  { OR1K64BF_INSN_L_SFLTU, SEM_FN_NAME (or1k64bf,l_sfltu) },
  { OR1K64BF_INSN_L_SFLEU, SEM_FN_NAME (or1k64bf,l_sfleu) },
  { OR1K64BF_INSN_L_SFGTS, SEM_FN_NAME (or1k64bf,l_sfgts) },
  { OR1K64BF_INSN_L_SFGES, SEM_FN_NAME (or1k64bf,l_sfges) },
  { OR1K64BF_INSN_L_SFLTS, SEM_FN_NAME (or1k64bf,l_sflts) },
  { OR1K64BF_INSN_L_SFLES, SEM_FN_NAME (or1k64bf,l_sfles) },
  { OR1K64BF_INSN_L_SFGTUI, SEM_FN_NAME (or1k64bf,l_sfgtui) },
  { OR1K64BF_INSN_L_SFGEUI, SEM_FN_NAME (or1k64bf,l_sfgeui) },
  { OR1K64BF_INSN_L_SFLTUI, SEM_FN_NAME (or1k64bf,l_sfltui) },
  { OR1K64BF_INSN_L_SFLEUI, SEM_FN_NAME (or1k64bf,l_sfleui) },
  { OR1K64BF_INSN_L_SFGTSI, SEM_FN_NAME (or1k64bf,l_sfgtsi) },
  { OR1K64BF_INSN_L_SFGESI, SEM_FN_NAME (or1k64bf,l_sfgesi) },
  { OR1K64BF_INSN_L_SFLTSI, SEM_FN_NAME (or1k64bf,l_sfltsi) },
  { OR1K64BF_INSN_L_SFLESI, SEM_FN_NAME (or1k64bf,l_sflesi) },
  { OR1K64BF_INSN_L_SFEQ, SEM_FN_NAME (or1k64bf,l_sfeq) },
  { OR1K64BF_INSN_L_SFEQI, SEM_FN_NAME (or1k64bf,l_sfeqi) },
  { OR1K64BF_INSN_L_SFNE, SEM_FN_NAME (or1k64bf,l_sfne) },
  { OR1K64BF_INSN_L_SFNEI, SEM_FN_NAME (or1k64bf,l_sfnei) },
  { OR1K64BF_INSN_L_MAC, SEM_FN_NAME (or1k64bf,l_mac) },
  { OR1K64BF_INSN_L_MSB, SEM_FN_NAME (or1k64bf,l_msb) },
  { OR1K64BF_INSN_L_MACI, SEM_FN_NAME (or1k64bf,l_maci) },
  { OR1K64BF_INSN_L_CUST1, SEM_FN_NAME (or1k64bf,l_cust1) },
  { OR1K64BF_INSN_L_CUST2, SEM_FN_NAME (or1k64bf,l_cust2) },
  { OR1K64BF_INSN_L_CUST3, SEM_FN_NAME (or1k64bf,l_cust3) },
  { OR1K64BF_INSN_L_CUST4, SEM_FN_NAME (or1k64bf,l_cust4) },
  { OR1K64BF_INSN_L_CUST5, SEM_FN_NAME (or1k64bf,l_cust5) },
  { OR1K64BF_INSN_L_CUST6, SEM_FN_NAME (or1k64bf,l_cust6) },
  { OR1K64BF_INSN_L_CUST7, SEM_FN_NAME (or1k64bf,l_cust7) },
  { OR1K64BF_INSN_L_CUST8, SEM_FN_NAME (or1k64bf,l_cust8) },
  { OR1K64BF_INSN_LF_ADD_S, SEM_FN_NAME (or1k64bf,lf_add_s) },
  { OR1K64BF_INSN_LF_ADD_D, SEM_FN_NAME (or1k64bf,lf_add_d) },
  { OR1K64BF_INSN_LF_SUB_S, SEM_FN_NAME (or1k64bf,lf_sub_s) },
  { OR1K64BF_INSN_LF_SUB_D, SEM_FN_NAME (or1k64bf,lf_sub_d) },
  { OR1K64BF_INSN_LF_MUL_S, SEM_FN_NAME (or1k64bf,lf_mul_s) },
  { OR1K64BF_INSN_LF_MUL_D, SEM_FN_NAME (or1k64bf,lf_mul_d) },
  { OR1K64BF_INSN_LF_DIV_S, SEM_FN_NAME (or1k64bf,lf_div_s) },
  { OR1K64BF_INSN_LF_DIV_D, SEM_FN_NAME (or1k64bf,lf_div_d) },
  { OR1K64BF_INSN_LF_REM_S, SEM_FN_NAME (or1k64bf,lf_rem_s) },
  { OR1K64BF_INSN_LF_REM_D, SEM_FN_NAME (or1k64bf,lf_rem_d) },
  { OR1K64BF_INSN_LF_ITOF_S, SEM_FN_NAME (or1k64bf,lf_itof_s) },
  { OR1K64BF_INSN_LF_ITOF_D, SEM_FN_NAME (or1k64bf,lf_itof_d) },
  { OR1K64BF_INSN_LF_FTOI_S, SEM_FN_NAME (or1k64bf,lf_ftoi_s) },
  { OR1K64BF_INSN_LF_FTOI_D, SEM_FN_NAME (or1k64bf,lf_ftoi_d) },
  { OR1K64BF_INSN_LF_EQ_S, SEM_FN_NAME (or1k64bf,lf_eq_s) },
  { OR1K64BF_INSN_LF_EQ_D, SEM_FN_NAME (or1k64bf,lf_eq_d) },
  { OR1K64BF_INSN_LF_NE_S, SEM_FN_NAME (or1k64bf,lf_ne_s) },
  { OR1K64BF_INSN_LF_NE_D, SEM_FN_NAME (or1k64bf,lf_ne_d) },
  { OR1K64BF_INSN_LF_GE_S, SEM_FN_NAME (or1k64bf,lf_ge_s) },
  { OR1K64BF_INSN_LF_GE_D, SEM_FN_NAME (or1k64bf,lf_ge_d) },
  { OR1K64BF_INSN_LF_GT_S, SEM_FN_NAME (or1k64bf,lf_gt_s) },
  { OR1K64BF_INSN_LF_GT_D, SEM_FN_NAME (or1k64bf,lf_gt_d) },
  { OR1K64BF_INSN_LF_LT_S, SEM_FN_NAME (or1k64bf,lf_lt_s) },
  { OR1K64BF_INSN_LF_LT_D, SEM_FN_NAME (or1k64bf,lf_lt_d) },
  { OR1K64BF_INSN_LF_LE_S, SEM_FN_NAME (or1k64bf,lf_le_s) },
  { OR1K64BF_INSN_LF_LE_D, SEM_FN_NAME (or1k64bf,lf_le_d) },
  { OR1K64BF_INSN_LF_MADD_S, SEM_FN_NAME (or1k64bf,lf_madd_s) },
  { OR1K64BF_INSN_LF_MADD_D, SEM_FN_NAME (or1k64bf,lf_madd_d) },
  { OR1K64BF_INSN_LF_CUST1_S, SEM_FN_NAME (or1k64bf,lf_cust1_s) },
  { OR1K64BF_INSN_LF_CUST1_D, SEM_FN_NAME (or1k64bf,lf_cust1_d) },
  { 0, 0 }
};

/* Add the semantic fns to IDESC_TABLE.  */

void
SEM_FN_NAME (or1k64bf,init_idesc_table) (SIM_CPU *current_cpu)
{
  IDESC *idesc_table = CPU_IDESC (current_cpu);
  const struct sem_fn_desc *sf;
  int mach_num = MACH_NUM (CPU_MACH (current_cpu));

  for (sf = &sem_fns[0]; sf->fn != 0; ++sf)
    {
      const CGEN_INSN *insn = idesc_table[sf->index].idata;
      int valid_p = (CGEN_INSN_VIRTUAL_P (insn)
		     || CGEN_INSN_MACH_HAS_P (insn, mach_num));
#if FAST_P
      if (valid_p)
	idesc_table[sf->index].sem_fast = sf->fn;
      else
	idesc_table[sf->index].sem_fast = SEM_FN_NAME (or1k64bf,x_invalid);
#else
      if (valid_p)
	idesc_table[sf->index].sem_full = sf->fn;
      else
	idesc_table[sf->index].sem_full = SEM_FN_NAME (or1k64bf,x_invalid);
#endif
    }
}
