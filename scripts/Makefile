VERILATOR = verilator
TOP       = riscv_cpu_tb
TB        = tb/riscv_cpu_tb.sv
SRC       = $(wildcard src/*.sv)
OBJ_DIR   = obj_dir

.PHONY: all sim clean

all: sim

sim: $(OBJ_DIR)/V$(TOP)
	@mkdir -p sim
	@./$(OBJ_DIR)/V$(TOP) +trace
	@VCD=$$(find $(OBJ_DIR) -name "*.vcd" -type f 2>/dev/null | head -1); \
	if [ -z "$$VCD" ]; then \
		echo "⚠️ No VCD generated. Check +trace flag."; \
	else \
		echo "✅ Traces saved to $$VCD"; \
		echo "🖥️ Opening GTKWave..."; \
		gtkwave $$VCD & \
	fi

$(OBJ_DIR)/V$(TOP): $(SRC) $(TB)
	@mkdir -p $(OBJ_DIR)
	$(VERILATOR) --sv --cc --exe --main --trace --top-module $(TOP) \
		-Wno-fatal -Wno-UNOPTFLAT -Wno-CASEINCOMPLETE -Wno-PINMISSING \
		-Wno-IMPLICIT -Wno-WIDTH -Wno-STMTDLY -Wno-UNSIGNED -Wno-INFINITELOOP \
		-Wno-BLKANDNBLK -Wno-BLKLOOPINIT -Wno-MULTIDRIVEN \
		--Mdir $(OBJ_DIR) $(TB) $(SRC)
	@make -j$(nproc) -C $(OBJ_DIR) -f V$(TOP).mk VM_PARALLEL_BUILDS=1

clean:
	rm -rf $(OBJ_DIR) sim/*.vcd dump.vcd
