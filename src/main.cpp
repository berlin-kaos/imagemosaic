#include <stdio.h>
#include <stdlib.h>
#include <boost/program_options.hpp>
#include <Magick++.h>

namespace po = boost::program_options;

/* imagemosaic supports the following command-line arguments:
 *
 * --image-directory, -i : (required) path to directory containing images for creating the mosaic
 * --verbose, -v         : (optional) enable verbosity
 * --help, -h            : print usage
 */
struct globalArgs_t {
	const char *image_directory;
	bool verbose;
};

po::options_description generic("Generic options");
po::options_description config("Configuration");

/* print program usage and exit */
void display_usage(int exit_code) {
	printf("Usage:\n");
	
	exit(exit_code);
}

/* print program usage when something went wrong */
void display_usage() {
	display_usage(EXIT_FAILURE);
}

/* parse command-line arguments */
const globalArgs_t parse_arguments(const int argc, char* argv[]) {
	/*
	printf("received %i parameters\n", argc);
	
	for (int i = 0; i < argc; ++i) {
		printf("parameter %i: %s\n", i, argv[i]);
	}
	*/
	globalArgs_t globalArgs;
	
	// set default values for optional arguments
	globalArgs.verbose = true;
	globalArgs.image_directory = "";
		
	if (globalArgs.verbose) {
		printf("received the following parameters:\n");
		printf("\timage-directory: %s\n", globalArgs.image_directory);
		printf("\tverbose: %s\n", globalArgs.verbose ? "true" : "false");
	}
	
	return globalArgs;
}

/* MAIN METHDO */
int main(int argc, char* argv[]) {
	// parse optional and required program arguments
	const globalArgs_t args = parse_arguments(argc, argv);
	
	// test if setup is really working...
	Magick::Image image;
	
	// done!
	if (args.verbose) {
		puts("exiting program");
	}
	exit(EXIT_SUCCESS);
}