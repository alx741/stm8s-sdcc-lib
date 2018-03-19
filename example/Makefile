STM8SLIB_DIR = ..
SRC_DIR = .
BINARY = main

MMCU=stm8
PARTNO=stm8s103f3	# list valid parts with `stm8flash -l`
PROGRAMMER=stlinkv2


CFLAGS =
CFLAGS += -l$(MMCU)
CFLAGS += -m$(MMCU)
CFLAGS += -m$(MMCU)
CFLAGS += -I$(STM8SLIB_DIR) -L$(STM8SLIB_DIR)

OBJECTS=$(foreach c_file, $(wildcard $(SRC_DIR)/*.c), $(c_file:.c=.rel))

$(BINARY).ihx: $(OBJECTS)
	sdcc $(CFLAGS) --out-fmt-ihx $? -o $@

%.rel: %.c
	sdcc $(CFLAGS) -c stm8s.lib $< -o $@

burn: $(BINARY).ihx
	stm8flash -p$(PARTNO) -c$(PROGRAMMER) -w $<

clean:
	rm -f $(OBJECTS) $(BINARY).map $(BINARY).rst $(BINARY).ihx $(BINARY).cdb $(BINARY).asm $(BINARY).rel $(BINARY).lst $(BINARY).lk $(BINARY).sym $(BINARY).ihx
