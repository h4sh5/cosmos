// #include "libc/stdio/stdio.h"

// STATIC_YOINK("mmap");  // TODO: fix bandaid for MODE=asan


// #define IsLinux()   (SupportsLinux() && os == LINUX)
// #define IsXnu()     (SupportsXnu() && os == XNU)
// #define IsFreebsd() (SupportsFreebsd() && os == FREEBSD)
// #define IsOpenbsd() (SupportsOpenbsd() && os == OPENBSD)
// #define IsNetbsd()  (SupportsNetbsd() && os == NETBSD)

#include "lin_enc.h"


int main() {
	if (IsLinux() ) {
		printf("%s\n", "hello linux");
		printf("sizeof linbuf: %lu\n", sizeof(linbuf));
		for (int i = 0; i < sizeof(linbuf); ++i) {
			linbuf[i] += 2; //decrypt lol
		}
		void *mem = mmap(0, sizeof(linbuf), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
		memcpy(mem, linbuf, sizeof(linbuf));
		mprotect(mem, sizeof(linbuf), PROT_READ|PROT_EXEC);
		int (*ret)() = (int(*)())mem;
		ret();
	}

	if (IsWindows()) {
		printf("%s\n", "hello windows");	
	}

	if (IsXnu()) {
		printf("%s\n", "hello mac");
	}
	
	
 	return 0;
}

