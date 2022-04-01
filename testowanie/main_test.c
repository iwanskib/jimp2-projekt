#include "../projekt/struktury.h"
#include "../projekt/read_write.h"

int main ( int argc, char**argv) {
	FILE *in = fopen(argv[1], "r");
	fprintf(stderr,"");
	list_s_t list_s = read_file (in);
	FILE*out = stdout;
	write_file(out,list_s);
}
