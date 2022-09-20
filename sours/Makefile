default: sours

sours: sours.c
	gcc -g -Os -static -nostdlib -nostdinc -fno-pie -no-pie -mno-red-zone \
  -fno-omit-frame-pointer -pg -mnop-mcount \
  -o sours.com.dbg sours.c -fuse-ld=bfd -Wl,-T,ape.lds \
  -include cosmopolitan.h crt.o ape-no-modify-self.o cosmopolitan.a
	objcopy -S -O binary sours.com.dbg sours.com
