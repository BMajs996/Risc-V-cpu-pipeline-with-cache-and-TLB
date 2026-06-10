VERILATOR = verilator
TOP       = riscv_cpu_tb
TB        = tb/riscv_cpu_tb.sv
SRC       = $(wildcard src/*.sv)
OBJ_DIR   = obj_dir
VCD       = $(OBJ_DIR)/V$(TOP).vcd
GTKWAVE_ENV = env -u SNAP -u SNAP_ARCH -u SNAP_INSTANCE_NAME -u SNAP_NAME \
	-u SNAP_REVISION -u SNAP_LIBRARY_PATH -u LD_LIBRARY_PATH \
	-u GTK_PATH -u GIO_MODULE_DIR

.PHONY: all sim wave clean

all: sim

sim: $(OBJ_DIR)/V$(TOP)
	@mkdir -p sim
	@echo "🚀 Running simulation..."
	@$(OBJ_DIR)/V$(TOP)
	@echo ""
	@echo "✅ Simulation finished. Waveform: $(VCD)"

wave: $(VCD)
	$(GTKWAVE_ENV) gtkwave $(VCD) &

$(OBJ_DIR)/V$(TOP): $(SRC) $(TB)
	@mkdir -p $(OBJ_DIR)
	$(VERILATOR) --sv --timing --cc --exe --main --trace --top-module $(TOP) \
		--converge-limit 50000 \
		-Wno-fatal -Wno-UNOPTFLAT -Wno-CASEINCOMPLETE -Wno-PINMISSING \
		-Wno-IMPLICIT -Wno-WIDTH -Wno-STMTDLY -Wno-UNSIGNED -Wno-INFINITELOOP \
		-Wno-BLKANDNBLK -Wno-BLKLOOPINIT -Wno-MULTIDRIVEN \
		--Mdir $(OBJ_DIR) $(TB) $(SRC)
	@make -j$(nproc) -C $(OBJ_DIR) -f V$(TOP).mk VM_PARALLEL_BUILDS=1

clean:
	rm -rf $(OBJ_DIR) sim/*.vcd
