/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2018-2022 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 **********************************************************************************************************************/
/**
 ***********************************************************************************************************************
 * @file  PatchLlvmIrInclusion.h
 * @brief LLPC header file: contains declaration of class lgc::PatchLlvmIrInclusion.
 ***********************************************************************************************************************
 */
#pragma once

#include "lgc/patch/Patch.h"
#include "llvm/IR/PassManager.h"

namespace lgc {

// =====================================================================================================================
// Represents the pass of LLVM patch operations of including LLVM IR as a separate section in the ELF binary.
class PatchLlvmIrInclusion : public Patch, public llvm::PassInfoMixin<PatchLlvmIrInclusion> {
public:
  llvm::PreservedAnalyses run(llvm::Module &module, llvm::ModuleAnalysisManager &analysisManager);

  bool runImpl(llvm::Module &module);

  static llvm::StringRef name() { return "Include LLVM IR as a separate section in the ELF binary"; }
};

// =====================================================================================================================
// Represents the pass of LLVM patch operations of including LLVM IR as a separate section in the ELF binary.
class LegacyPatchLlvmIrInclusion : public LegacyPatch {
public:
  LegacyPatchLlvmIrInclusion();

  bool runOnModule(llvm::Module &module) override;

  void getAnalysisUsage(llvm::AnalysisUsage &analysisUsage) const override { analysisUsage.setPreservesAll(); }

  static char ID; // ID of this pass

private:
  LegacyPatchLlvmIrInclusion(const LegacyPatchLlvmIrInclusion &) = delete;
  LegacyPatchLlvmIrInclusion &operator=(const LegacyPatchLlvmIrInclusion &) = delete;

  PatchLlvmIrInclusion m_impl;
};

} // namespace lgc
