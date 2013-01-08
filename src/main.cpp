#include <stdio.h>
#include <stdlib.h>
#include <boost/program_options.hpp>
#include <Magick++.h>

namespace po = boost::program_options;

/* imagemosaic supports the following command-line arguments:
 *
 * --image-directories, -I : (required) path to directory containing images for creating the mosaic
 * --verbose               : (optional) enable verbosity
 * --version               : print version
 * --help, -h              : print usage
 */
struct globalArgs_t {
	std::string image_directory;
	std::string target_image;
	bool verbose;
};

po::options_description generic("Generic options");
po::options_description config("Configuration");
po::options_description hidden("Hidden");

/* print program usage and exit */
void display_usage(int exit_code) {
	printf("Usage:\n");
	generic.print(std::cout);
	config.print(std::cout);	
	exit(exit_code);
}

void display_usage() {
	display_usage(EXIT_FAILURE);
}

/* print version */
void display_version(int exit_code) {
	printf("imagemosaic version %i", 1);
	
	exit(exit_code);
}

void display_version() {
	display_version(EXIT_SUCCESS);
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
	
	generic.add_options()
		("help,h", "produce help message")
		("version,v", "show version")
		("verbose", po::value<bool>(&(globalArgs.verbose))->default_value(false)->zero_tokens(), "enable verbosity")
	;
	
	config.add_options()
		("image-directory,I", po::value< std::string >(&(globalArgs.image_directory))->required(), "image directory containing images to use")
	;
	
	hidden.add_options()
		("target-image,T", po::value< std::string >(&(globalArgs.target_image))->required(), "target image to produce")
	;
	
	po::positional_options_description pop;
	pop.add("target-image", 1);
	
	po::options_description cmdline_options;
	cmdline_options.add(generic).add(config).add(hidden);
	
	try {
		po::variables_map vm;
		po::store(po::command_line_parser(argc, argv).options(cmdline_options).positional(pop).run(), vm);
		po::notify(vm);
	} catch(const po::multiple_occurrences& e) {
		printf("multiple occurrences error: %s from option %s\n", e.what(), e.get_option_name().c_str());
		
		display_usage();
	} catch (std::logic_error& e) {
		printf("error: %s\n", e.what());
		
		display_usage();
	}
		
	if (globalArgs.verbose) {
		printf("received the following parameters:\n");
		printf("\tverbose: %s\n", globalArgs.verbose ? "true" : "false");
		printf("\timage-directories: %s\n", globalArgs.image_directory.c_str());
		printf("\ttarget-image: %s", globalArgs.target_image.c_str());
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