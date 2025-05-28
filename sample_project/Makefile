src = src/main.o
src_bootstrap = startup.o vectors.o

name = sample_project
config = gpmc.cfg

CA = ca65
LD = ld65
CPU = 65sc02

all: $(name).bin

%.o: %.s
	$(CA) --cpu $(CPU) -o $@ $^

$(name).out: $(src) $(src_bootstrap)
	$(LD) -C $(config) $(src) $(src_bootstrap) -m $(name).map -o $(name).out

$(name).bin: $(name).out
# Preappend 16384 bytes to accound for A14 being always high
	dd if=/dev/zero bs=16384 count=1 2>/dev/null | cat - $(name).out > $(name).bin

clean:
# Remove Assembler Output
	rm -f $(src) $(src_bootstrap) 
# Remove Linker Output
	rm -f $(name).out $(name).map
# Remove Binary FIle
	rm -f $(name).bin