# RISC-V CPU Pipeline with Cache and TLB

SystemVerilog implementation of a small RISC-V CPU pipeline with instruction/data cache blocks, TLB blocks, hazard handling, memory refill control, and early support modules for AXI-style interconnect and atomic/exclusive operations.

The project is currently a work in progress. It builds and runs with Verilator, produces a VCD waveform, and passes a strict Verilator lint check. Functional CPU verification with real RISC-V programs is still the next major step.

## Project Structure

```text
src/
  riscv_cpu_top.sv       Top-level CPU integration
  decoder.sv             RISC-V instruction decoder
  alu.sv                 Integer ALU
  regfile.sv             Register file
  pipeline_regs.sv       Generic pipeline register
  hazard_unit.sv         Stall, flush, and forwarding control
  cache.sv               Simple direct-mapped cache block
  tlb.sv                 Simple TLB block
  mem_ctrl.sv            Miss/refill memory controller
  m_unit.sv              Early RV32M multiply/divide unit work
  axi_interconnect.sv    AXI-style interconnect helper
  axi_exclusive_ctrl.sv  LR/SC/AMO helper logic

tb/
  riscv_cpu_tb.sv        Verilator testbench

scripts/
  Makefile               Build, simulation, and waveform targets
```

## Requirements

- Verilator
- GTKWave
- `make`
- A C++ compiler supported by Verilator, such as `g++`

On Ubuntu/Debian-like systems:

```bash
sudo apt install verilator gtkwave make g++
```

## Build and Run

From the repository root:

```bash
make -f scripts/Makefile sim
```

This builds the Verilator model and runs the testbench. The simulation writes a waveform to:

```text
obj_dir/Vriscv_cpu_tb.vcd
```

Open the waveform:

```bash
make -f scripts/Makefile wave
```

The `wave` target clears common Snap environment variables before launching GTKWave. This avoids library conflicts when running from a Snap-packaged editor terminal.

## Lint

Run a stricter Verilator lint pass:

```bash
verilator --sv --timing --lint-only --top-module riscv_cpu_tb tb/riscv_cpu_tb.sv src/*.sv
```

Expected result: no warnings or errors.

## Current Status

Working:

- Verilator build flow
- Verilator lint flow
- Basic simulation testbench
- VCD waveform generation
- GTKWave launch target
- Basic module integration in `riscv_cpu_top.sv`

Known work still needed:

- Add a real instruction memory/program loader to the testbench
- Add assertions for register and memory results
- Complete branch and jump PC control
- Register all pipeline control signals through the correct stages
- Fix/complete R-type operand selection and forwarding behavior
- Complete load/store data path behavior
- Verify and harden cache/TLB refill behavior
- Complete RV32M and atomic operation support
- Add directed tests for ALU, decoder, cache, TLB, and full CPU execution

## Notes

Generated Verilator artifacts are intentionally ignored:

```text
obj_dir/
*.vcd
*.fst
*.vpd
```

These files can always be regenerated with `make -f scripts/Makefile sim` and should not be committed.
