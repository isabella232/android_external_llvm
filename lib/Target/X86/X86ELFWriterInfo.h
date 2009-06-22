//===-- X86ELFWriterInfo.h - ELF Writer Info for X86 ------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements ELF writer information for the X86 backend.
//
//===----------------------------------------------------------------------===//

#ifndef X86_ELF_WRITER_INFO_H
#define X86_ELF_WRITER_INFO_H

#include "llvm/Target/TargetELFWriterInfo.h"

namespace llvm {

  class X86ELFWriterInfo : public TargetELFWriterInfo {

    // ELF Relocation types for X86
    enum X86RelocationType {
      R_386_NONE = 0,
      R_386_32   = 1,
      R_386_PC32 = 2
    };

    // ELF Relocation types for X86_64
    enum X86_64RelocationType {
      R_X86_64_NONE = 0,
      R_X86_64_64   = 1,
      R_X86_64_PC32 = 2,
      R_X86_64_32   = 10,
      R_X86_64_32S  = 11,
      R_X86_64_PC64 = 24
    };

  public:
    X86ELFWriterInfo(TargetMachine &TM);
    virtual ~X86ELFWriterInfo();

    /// getFunctionAlignment - Returns the alignment for function 'F', targets
    /// with different alignment constraints should overload this method
    virtual unsigned getFunctionAlignment(const Function *F) const;

    /// getRelocationType - Returns the target specific ELF Relocation type.
    /// 'MachineRelTy' contains the object code independent relocation type
    virtual unsigned getRelocationType(unsigned MachineRelTy) const;

    /// hasRelocationAddend - True if the target uses an addend in the
    /// ELF relocation entry.
    virtual bool hasRelocationAddend() const { return is64Bit ? true : false; }

    /// getAddendForRelTy - Gets the addend value for an ELF relocation entry
    /// based on the target relocation type
    virtual long int getAddendForRelTy(unsigned RelTy) const;
  };

} // end llvm namespace

#endif // X86_ELF_WRITER_INFO_H
